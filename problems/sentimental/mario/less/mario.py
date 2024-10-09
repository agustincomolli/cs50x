def main():
    height = input_number("Height: ")
    print_stairs(height)


def input_number(message: str) -> int:
    """
    Solicita al usuario que ingrese un número entero entre 1 y 8.

    Args:
        message (str): Mensaje que se mostrará al usuario para solicitar un número.

    Returns:
        int: El número ingresado por el usuario.
    """

    MINIMUM = 1
    MAXIMUM = 8

    while True:
        # Intentar convertir el ingreso a número entero.
        try:
            number = int(input(message))
            # Si el valor es correcto salir del bucle.
            if number >= MINIMUM and number <= MAXIMUM:
                break
        except ValueError:
            pass
    return number


def print_stairs(height: int):
    """
    Imprime en la consola una escalera de la cantidad de escalones especificada.

    Args:
        height (int): Es la cantidad de escalones que tiene la escalera.
    """

    START = 1 # El 1° piso se debe contar como 1 y no como 0.
    STOP = height + 1
    for row in range(START, STOP):
        amount_spaces = " " * (height - row)
        amount_blocks = "#" * row
        print(amount_spaces + amount_blocks)


if __name__ == "__main__":
    main()
