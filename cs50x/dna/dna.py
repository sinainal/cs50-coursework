import csv
import sys


def main():
    n = 0
    while n == 0:
        try:
            data = sys.argv[1]
            seq = sys.argv[2]
            n = 1
        except:
            print("err")

    datalist = []
    with open(data) as data1:
        reader = csv.DictReader(data1)
        subsequances = reader.fieldnames[1:]
        for i in reader:
            datalist.append(i)

    with open(seq) as f:
        sequance = f.read()

    sublist = []
    for i in subsequances:
        sublist.append(longest_match(sequance, i))

    for i in range(len(datalist)):
        n = 0
        for j in range(len(sublist)):
            a = int(datalist[i][subsequances[j]])
            if a == sublist[j]:
                n += 1
        if n == len(sublist):
            print(datalist[i]['name'])
            break
    if n != len(sublist):
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
