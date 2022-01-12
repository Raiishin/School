# (1) REPLACE THE STRING VARIABLE WITH YOUR NAME in string type
name = 'Tan Jun Yin, Gavin'
# (2) REPLACE THIS STRING VARIABLE WITH YOUR UOW ID in string type
student_num = '7573935'
subject_code = 'CSIT110'
# (3) let me get to know you!
fav_cartoon = 'Crayon Shin-chan'

#========== insert solution here===========#


def x100(num):  # Question 1 Solution:
    return float(num * 100)


def get_type(var):  # Question 2 Solution:
    return type(var)


def get_equation():  # Question 3 Solution:
    firstNum = int(input("Enter first number: "))
    secondNum = int(input("Enter second number: "))

    returnNum = firstNum + secondNum
    returnStr = f"{firstNum} + {secondNum}"

    return returnNum, returnStr


def to_bool(num):  # Question 4 Solution:
    return bool(num)


def format_price(num):  # Question 5 Solution:
    roundoff = "{:.2f}".format(num)
    price = f"${roundoff}"

    print(price)

    return price


def main():  # DO NOT EDIT THESE TWO LINES.
    print("Assignment1")  # DO NOT EDIT THESE TWO LINES.

    # you can call your functions here to test that it works.
    # you do not have to comment your own test code

    num = x100(5.123)
    print(num)

    type = get_type("string")
    print(type)

    x, y = get_equation()
    print(x)
    print(y)

    boolNum = to_bool(-1)
    print(boolNum)

    boolNum2 = to_bool(3123123)
    print(boolNum2)

    boolNum3 = to_bool(0)
    print(boolNum3)

    price = format_price(1.234)
    print(price)


if __name__ == '__main__':  # DO NOT EDIT THESE TWO LINES.
    main()
