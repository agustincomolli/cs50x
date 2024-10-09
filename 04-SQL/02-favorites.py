# Prints all favorites in CSV using csv.DictReader
import csv
from collections import Counter

def main():
    # Open CSV file
    with open("./favorites.csv") as file:
        # Create DictReader
        file_reader = csv.DictReader(file)
        languages = Counter()

        for row in file_reader:
            language = row["language"]
            languages[language] += 1

    # Print counts sorted by value Z-A
    for language, count in languages.most_common():
        print(f"{language}: {count}")


if __name__ == "__main__":
    main()
