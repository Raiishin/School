

def postfix(string):
    arr = string.split(" ")
    stack = []

    for i in range(0, len(arr)):
        char = arr[i]

        if char == "+" or char == "-" or char == "*" or char == "/":
            num1 = stack.pop()
            num2 = stack.pop()
            combined = 0

            if (char == "+"):
                combined = float(num2) + float(num1)
            if (char == "-"):
                combined = float(num2) - float(num1)
            if (char == "*"):
                combined = float(num2) * float(num1)
            if (char == "/"):
                combined = float(num2) / float(num1)

            stack.append(combined)
        else:
            stack.append(char)

    return float(stack[0])


test_string = "5 2 + 8 3 - * 7 /"
print(postfix(test_string))

test_string = "3 2 * 8 3 * * 10 /"
print(postfix(test_string))
