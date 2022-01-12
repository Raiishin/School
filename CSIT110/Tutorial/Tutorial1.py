def question2_to_question5():
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
    print(x, 2*x, 3*x, 4*x, 5*x, sep="---")


def display_text(txt: str):
    print(txt)


def duplicate_text(txt: str, x: int):
    return txt*x


def merge_text(txt1: str, txt2: int):
    return (txt1 + str(txt2))


def question12():
    number_of_items = int(input("Enter the number of items: "))

    cost_per_item = 3
    postage = 10

    if number_of_items > 50:
        cost_per_item = 2
        postage = 0

    total_item_cost = number_of_items * cost_per_item
    total_cost = total_item_cost + postage
    print("Receipt")
    print(f"{number_of_items} items x ${cost_per_item} = ${total_item_cost}")
    print(f"Postage: ${postage}")
    print(f"Total: ${total_cost}")


def question13():
    number_of_items = int(input("Enter the number of items: "))
    shipping_method = str(input("Enter shipping method (s/r/e): "))

    cost_per_item = 3
    standard_postage = 10
    registered_postage = 15
    express_postage = 20

    if number_of_items > 50:
        cost_per_item = 2
        standard_postage = 0
        registered_postage = 10
        express_postage = 17

    if shipping_method == "s":
        postage = standard_postage
    elif shipping_method == "r":
        postage = registered_postage
    else:
        shipping_method = express_postage

    total_item_cost = number_of_items * cost_per_item
    total_cost = total_item_cost + postage

    print("Receipt")
    print(f"{number_of_items} items x ${cost_per_item} = ${total_item_cost}")
    print(f"Postage: ${postage}")
    print(f"Total: ${total_cost}")


def question14():
    first_integer = int(input("Enter the first integer:"))

    largest_integer = first_integer
    smallest_integer = first_integer

    second_integer = int(input("Enter the second integer:"))

    if second_integer > largest_integer:
        largest_integer = second_integer

    if second_integer < smallest_integer:
        smallest_integer = second_integer

    third_integer = int(input("Enter the third integer:"))

    if third_integer > largest_integer:
        largest_integer = third_integer

    if third_integer < smallest_integer:
        smallest_integer = third_integer

    fourth_integer = int(input("Enter the fourth integer:"))

    if fourth_integer > largest_integer:
        largest_integer = fourth_integer

    if fourth_integer < smallest_integer:
        smallest_integer = fourth_integer

    print(
        f"The minimum number is {smallest_integer} and the maximum number is {largest_integer}")


def main():
    question2_to_question5()

    question6_compute = (512 - 2 ** 5) / (231 + 10)
    print(question6_compute)

    question7()

    display_text("Python")
    print(duplicate_text("Python", 4))
    print(merge_text("Python", 4))

    question12()
    question13()
    question14()


if __name__ == '__main__':
    main()
