import pagerank

#print(list(pagerank.crawl("corpus1").keys()))
print(pagerank.transition_model(pagerank.crawl("corpus0"), "1.html", 0.85))
