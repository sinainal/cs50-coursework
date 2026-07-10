import os
import random
import re
import sys

DAMPING = 0.85
SAMPLES = 10000


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python pagerank.py corpus")
    corpus = crawl(sys.argv[1])
    ranks = sample_pagerank(corpus, DAMPING, SAMPLES)
    print(f"PageRank Results from Sampling (n = {SAMPLES})")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")
    ranks = iterate_pagerank(corpus, DAMPING)
    print(f"PageRank Results from Iteration")
    for page in sorted(ranks):
        print(f"  {page}: {ranks[page]:.4f}")


def crawl(directory):
    """
    Parse a directory of HTML pages and check for links to other pages.
    Return a dictionary where each key is a page, and values are
    a list of all other pages in the corpus that are linked to by the page.
    """
    pages = dict()

    # Extract all links from HTML files
    for filename in os.listdir(directory):
        if not filename.endswith(".html"):
            continue
        with open(os.path.join(directory, filename)) as f:
            contents = f.read()
            links = re.findall(r"<a\s+(?:[^>]*?)href=\"([^\"]*)\"", contents)
            pages[filename] = set(links) - {filename}

    # Only include links to other pages in the corpus
    for filename in pages:
        pages[filename] = set(
            link for link in pages[filename]
            if link in pages
        )

    return pages


def transition_model(corpus, page, damping_factor):
    """
    Return a probability distribution over which page to visit next,
    given a current page.

    With probability `damping_factor`, choose a link at random
    linked to by `page`. With probability `1 - damping_factor`, choose
    a link at random chosen from all pages in the corpus.
    """
    connected = []
    all_pages = []
    dist = dict()
    a = corpus
    for i in a:
        all_pages.append(i)
        if i == page:
            for x in a[i]:
                connected.append(x)
    print(connected, all_pages)

    for i in all_pages:
        if i in connected:
            dist[i] = damping_factor/len(connected) + (1 - damping_factor)/ len(all_pages)
        else:
            dist[i] = (1 - damping_factor)/ len(all_pages)

    return dist
def sample_pagerank(corpus, damping_factor, n):
    """
    Return PageRank values for each page by sampling `n` pages
    according to transition model, starting with a page at random.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    a = corpus
    all_pages = list(a.keys())
    occurance = dict()
    page = random.choice(all_pages)
    for i in range(n):
        occurance[page] = occurance.get(page,0) + 1
        model = transition_model(corpus,page,damping_factor)
        page = random.choices(list(model.keys()), weights = list(model.values()), k=1)[0]
    for i in occurance.keys():
        occurance[i] = occurance[i]/n
    return occurance






def iterate_pagerank(corpus, damping_factor):
    """
    Return PageRank values for each page by iteratively updating
    PageRank values until convergence.

    Return a dictionary where keys are page names, and values are
    their estimated PageRank value (a value between 0 and 1). All
    PageRank values should sum to 1.
    """
    all_pages = list(corpus.keys())
    d = damping_factor
    n = len(all_pages)
    page_rank = dict()
    diff = 1
    max_diff = 1
    for page in all_pages:
        page_rank[page] = 1/n

    while max_diff > 0.001:
        max_diff = 0
        for i in page_rank.keys():
            connected = []
            for k,v in corpus.items():
                if i in list(v):
                    connected.append(k)
            sum_con = 0
            for a in connected:
                sum_con += page_rank[a]/len(corpus[a])

            for a in all_pages:
                if len(corpus[a]) == 0:
                    sum_con += page_rank[a]/len(all_pages)

            diff = abs(page_rank[i] - ((1-d)/n + d*sum_con))
            if diff > max_diff:
                max_diff = diff
            page_rank[i] = (1-d)/n + d*sum_con

    return page_rank









    raise NotImplementedError


if __name__ == "__main__":

    main()
