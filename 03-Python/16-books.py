def main():
    shelf = []

    print("📖 Libros 📘")

    # Agregar 3 libros a la biblioteca.
    for i in range(3):
        book = {}
        book["author"] = input("Autor: ")
        book["title"] = input("Título: ")
        shelf.append(book)
        print()

    # Imprimir la lista de libros
    for book in shelf:
        print(f"{book['title']} de {book['author']}")

if __name__ == "__main__":
    main()
