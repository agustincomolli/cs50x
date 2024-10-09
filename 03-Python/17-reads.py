import csv


def main():
    books = []

    # Add books to your shelf by reading from books.csv
    with open("./books.csv") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            books.append(row)

    # Print books
    for book in books:
        print(f"{book['title']} de {book['author']}")


if __name__ == "__main__":
    main()
