def main():
    scores = [72, 73, 33]
    average = sum(scores) / len(scores)
    print(f"El promedio de la lista es: {average:.2f}")

    average_user_prompt()


def average_user_prompt():
    """
    Solicita una serie de números al usuario y calcula el promedio.

    """
    scores = []
    AMOUNT = 3
    for i in range(AMOUNT):
        score = int(input(f"Puntuación {i + 1}: "))
        scores.append(score)

    average = sum(scores) / len(scores)
    print(f"El promedio de la lista es: {average:.2f}")


if __name__ == "__main__":
    main()
