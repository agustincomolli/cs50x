class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("La capacidad debe ser no negativa")
        self._capacity = capacity
        self._amount = 0

    def __str__(self):
        if self._amount == 0:
            return "🤷"
        return "🍪" * self._amount

    def deposit(self, n):
        if self._amount + n > self._capacity:
            raise ValueError(("Excede la capacidad del frasco"))
        self._amount += n

    def withdraw(self, n):
        if self._amount -n < 0:
            raise ValueError("No hay suficientes galletas en el frasco para retirar")
        self._amount -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._amount


def main():
    frasco = Jar()
    print(frasco.capacity)   # Accede a la propiedad de capacidad
    print(str(frasco))       # Llama a __str__ para imprimir el contenido del frasco
    frasco.deposit(2)        # Agrega 2 galletas
    print(str(frasco))       # Imprime el contenido del frasco después del depósito
    frasco.withdraw(1)       # Retira 1 galleta
    print(str(frasco))       # Imprime el contenido del frasco después de retirar


if __name__ == "__main__":
    main()
