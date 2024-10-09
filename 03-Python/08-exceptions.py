def get_int(message: str) -> int:
    """
    Solicita al usuario que ingrese un número entero y devuelve el valor convertido a entero.

    Args:
        message (str): El mensaje que se mostrará al solicitar al usuario que ingrese el número.

    Returns:
        int: El número entero ingresado por el usuario.
    """

    while True:
        try:
            return int(input(message))
        except ValueError:
            print("No es un número entero.")


def main():
    print("*** Excepciones en Python ***\n")
    number_1 = get_int("Número 1: ")
    number_2 = get_int("Número 2: ")

    print(f"\n{number_1} + {number_2} = {number_1 + number_2}")


if __name__ == "__main__":
    main()
