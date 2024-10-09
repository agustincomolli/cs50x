def main():
    # Obtener la entrada del usuario
    text = input("Texto: ")

    letters = 0
    words = 0
    sentences = 0

    # Calcular total de letras, palabras y oraciones.
    for character in text:
        # Contar letras: Excluye números, caracteres de puntuación y espacios.
        if character.isalpha():
            letters += 1

        # Contar palabras: Secuencia de caracteres separados por un espacio.
        # Nota: La última palabra no se cuenta porque no termina en espacio.
        if character.isspace():
            words += 1

        # Contar oraciones: Los '.', '?', '!' indican que empieza una nueva
        # oración.
        if character == "." or character == "?" or character == "!":
            sentences += 1

    # Contar la última palabra del texto porque no termina con un espacio.
    words += 1

    coleman_liau = calculate_coleman_liau(letters, words, sentences)

    # Mostrar el resultado.
    show_grade(coleman_liau)


def calculate_coleman_liau(letters: int, words: int, sentences: int) -> int:
    ONE_HUNDRED_WORDS = 100
    # Calcular los promedios por regla de 3 simple.
    average_letters = (ONE_HUNDRED_WORDS * letters) / words
    average_sentences = (ONE_HUNDRED_WORDS * sentences) / words
    # Calcular la fórmula.
    coleman_liau = 0.0588 * average_letters - 0.296 * average_sentences - 15.8
    # Devolver el número entero más cercano al resultado de la fórmula
    return round(coleman_liau)


def show_grade(coleman_liau: int):
    if coleman_liau < 1:
        print("Before Grade 1")
    elif coleman_liau >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {coleman_liau}")


if __name__ == "__main__":
    main()
