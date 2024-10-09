# Prints all favorites in CSV using csv.DictReader
import csv


def main():
    # Open CSV file
    with open("./favorites.csv") as file:
        # Create DictReader
        file_reader = csv.DictReader(file)

        # Iterate over CSV file
        languages = {}

        for row in file_reader:
            language = row["language"]
            if language in languages:
                languages[language] += 1
            else:
                languages[language] = 1

    # Print counts sorted by value Z-A
    for language in sorted(languages, key=languages.get, reverse=True):
        print(f"{language}: {languages[language]}")


if __name__ == "__main__":
    main()
