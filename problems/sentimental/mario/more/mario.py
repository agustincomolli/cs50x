def main():
    height = input_number("Height: ")
    print_pyramid(height)


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


def print_pyramid(height: int):
    """
    Imprime en la consola una pirámide de la cantidad de escalones especificada.

    Args:
        height (int): Es la cantidad de escalones que tiene la escalera.
    """

    START = 1  # El 1° piso se debe contar como 1 y no como 0.
    STOP = height + 1
    for row in range(START, STOP):
        # El lado izquierdo debe tener tantos espacios como el alto de la pirámide
        # menos el número de la fila actual.
        amount_spaces = " " * (height - row)
        amount_blocks = "#" * row
        left_side = amount_spaces + amount_blocks
        right_side = amount_blocks
        print(f"{left_side}  {right_side}")


if __name__ == "__main__":
    main()
