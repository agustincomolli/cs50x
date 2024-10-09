class Student:
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def change_id(self, id):
        self.id = id

    def print_student(self):
        print(f"{self.name} - {self.id}")


def main():
    agustin = Student("Agustín", 1234)
    agustin.print_student()
    agustin.change_id(1977)
    agustin.print_student()


if __name__ == "__main__":
    main()
