# (1) REPLACE THE STRING VARIABLE WITH YOUR NAME in string type
name = 'Tan Jun Yin, Gavin'
# (2) REPLACE THIS STRING VARIABLE WITH YOUR UOW ID in string type
student_num = '7573935'
subject_code = 'CSIT110'
# (3) let me get to know you!
fav_cartoon = 'Crayon Shin-chan'

#========== insert solution here===========#


def x100(num: float):  # Question 1 Solution:
    return num * 100


def get_type(var: any):  # Question 2 Solution:
    return type(var)


def get_equation():  # Question 3 Solution:
    firstNum = int(input("Enter first number: "))
    secondNum = int(input("Enter second number: "))

    # Add the first and second number together
    returnNum = firstNum + secondNum

    # Concat the first and second number together
    returnStr = f"{firstNum} + {secondNum}"

    return returnNum, returnStr


def to_bool(num: int):  # Question 4 Solution:
    return bool(num)


def format_price(num: int):  # Question 5 Solution:
    roundoff = "{:.2f}".format(num)  # Round off the number to 2 decimal places
    price = f"${roundoff}"

    print(price)

    return price


def run_tests():
    # Test Code
    x = x100(43.1)
    print(x)
    x = x100(123.567)
    print(x)

    print(get_type(123))
    print(get_type("hohoho"))
    print(get_type(True))

    x, y = get_equation()
    print(x)
    print(y)

    x = to_bool(-123)
    y = to_bool(0)
    z = to_bool(684.43)
    print(x)
    print(y)
    print(z)

    x = format_price(2.3)
    print(x)
    x = format_price(5.15)
    print(x)
    x = format_price(572.40982)
    print(x)


def main():  # DO NOT EDIT THESE TWO LINES.
    print("Assignment1")  # DO NOT EDIT THESE TWO LINES.

    # you can call your functions here to test that it works.
    # you do not have to comment your own test code

    run_tests()


if __name__ == '__main__':  # DO NOT EDIT THESE TWO LINES.
    main()
