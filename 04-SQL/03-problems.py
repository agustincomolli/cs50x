# Prints all favorites in CSV using csv.DictReader
import csv
from collections import Counter

def main():
    # Open CSV file
    with open("./favorites.csv") as file:
        # Create DictReader
        file_reader = csv.DictReader(file)
        form_data = Counter()

        for row in file_reader:
            problem = row["problem"]
            form_data[problem] += 1

    favorite = input("Favorito: ")
    print(f"{favorite}: {form_data[favorite]}")

if __name__ == "__main__":
    main()
