def question2_to_question6():
    RAD = 3
    PI = 3.142
    LEN = 4
    BREADTH = 2.5

    circle_circumference = 2 * PI * RAD
    circle_area = PI * RAD ** 2
    rectangle_perimeter = 2 * (LEN + BREADTH)
    rectangle_area = LEN * BREADTH

    print(circle_area, circle_circumference,
          rectangle_area, rectangle_perimeter)


def question7():
    x = int(input("Enter an integer: "))
    count = 1

    while count <= 5:
        print(x * count)
        print("---")
        count += 1


def display_text(txt):
    print(txt)


def duplicate_text(txt, x):
    return txt*x


def main():
    question6_compute = (512 - 2 ** 5) / (231 + 10)
    print(question6_compute)

    display_text("Python")
    duped_text = duplicate_text("Python", 4)
    print(duped_text)


if __name__ == '__main__':
    main()
