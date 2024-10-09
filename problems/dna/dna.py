import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print(f"ERROR: Usar {sys.argv[0]} <archivo.csv> <secuencia.txt>")
        return

    # TODO: Read database file into a variable
    sequences_names = []
    with open(f"{sys.argv[1]}") as file:
        file_reader = csv.DictReader(file)
        sequences_names = file_reader.fieldnames
        sequences_names.pop(0)

    database = []
    with open(f"{sys.argv[1]}") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            database.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(f"{sys.argv[2]}") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    results = {}
    for sequence_name in sequences_names:
        results[sequence_name] = longest_match(sequence, sequence_name)

    # TODO: Check database for matching profiles
    name = "No match"
    for row in database:
        is_match = True
        for key, value in results.items():
            if row[key] != str(value):
                is_match = False
                break
        if is_match:
            name = row["name"]
            break

    print(name)
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
