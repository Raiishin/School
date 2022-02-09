import string

# (1) REPLACE THE STRING VARIABLE WITH YOUR NAME in string type
name = 'Tan Jun Yin, Gavin'
# (2) REPLACE THIS STRING VARIABLE WITH YOUR UOW ID in string type
student_num = '7573935'
subject_code = 'CSIT110'
# (3) let me get to know you!
hobbies = 'Struggle with LeetCode'

#========== insert solution here===========#


class Catalogue:
    tv_channels: dict = {
        "NetFlix": 12.98,
        "Amazon Prime Video": 2.99,
        "Apple TV+": 6.98,
        "Disney+": 11.98,
        "HBO Go": 13.98,
        "iQiyi": 8.98,
    }

    hotline: str = "1800-1234-4567"

    def __init__(self, serial_num: str):
        self.serial_num = serial_num

    @classmethod
    def display(cls):
        print("Available for subscription:")
        print(f'{"Channels":<22}', end=' ')
        print(f'{"Price/mth":>9}')

        for channel, price in cls.tv_channels.items():
            print(f'{channel:<22}', end=' ')
            formattedPrice = f'${price}'
            print(f'{formattedPrice:>9}')

    @classmethod
    def get_subscription(cls):
        subscriptions = []

        for channel in cls.tv_channels:
            output = input(f'Subscribe to {channel}? (Y/N): ')
            if output.upper() == "Y":
                subscriptions.append(channel)

        return subscriptions


class Customer:
    count: int = 0

    def __init__(self, name: str):
        self.name = name

        Customer.count += 1

        self.subscripton = Catalogue.get_subscription()


def generate_qns_from_list(qns: list):
    returnList = []

    for qn in qns:
        if len(qn) >= 2:  # Skip the lists that contain less than 2 integers
            listToStr = ' + '.join(map(str, qn))
            returnList.append({
                "qns": listToStr, "ans": sum(qn)
            })

    return returnList


def get_id_checksum(id: str):
    checksumList = [2, 7, 6, 5, 4, 3, 2]
    strToList = list(id)
    totalSum = 0

    for num1, num2 in zip(checksumList, strToList):
        totalSum = totalSum + (num1 * int(num2))

    d = totalSum % 11

    checkDigit = {
        10: "A",
        9: "B",
        8: "C",
        7: "D",
        6: "E",
        5: "F",
        4: "G",
        3: "H",
        2: "I",
        1: "Z",
        0: "J"
    }

    return checkDigit[d]


def get_car_plate_checksum(carplate: str):
    letterDict = dict(zip(string.ascii_uppercase, range(1, 27)))
    checksumList = [9, 4, 5, 4, 3, 2]
    strToList = list(carplate)

    alphaCount = 0
    numCount = 0
    for char in carplate:
        if char.isalpha():
            alphaCount += 1
        else:
            numCount += 1

    # Fill in placeholder for letters
    if alphaCount > 2:
        strToList.pop(0)
    elif alphaCount < 2:
        strToList.insert(0, "0")

    # Fill in placeholder for numbers
    while numCount < 4:
        strToList.insert(len(strToList)-numCount, "0")
        numCount += 1

    count = 0
    # Replace letters with numbers
    for letter in strToList:
        if letter.isalpha():
            num = str(letterDict.get(letter))
            strToList[count] = num
        count += 1

    totalSum = 0
    for num1, num2 in zip(checksumList, strToList):
        totalSum = totalSum + (num1 * int(num2))

    checkSum = totalSum % 19

    checkDigit = {
        0: "A",
        1: "Z",
        2: "Y",
        3: "X",
        4: "U",
        5: "T",
        6: "S",
        7: "R",
        8: "P",
        9: "M",
        10: "L",
        11: "K",
        12: "J",
        13: "H",
        14: "G",
        15: "E",
        16: "D",
        17: "C",
        18: "B",
    }

    return checkDigit[checkSum]


def main():  # DO NOT EDIT THESE TWO LINES.

    print("Assignment3")  # DO NOT EDIT THESE TWO LINES.

    # you can call your functions here to test that it works.
    # you do not have to comment your own test code

    # catalog = Catalogue("123")
    # catalog.display()
    # print(catalog.get_subscription())

    # sam = Customer("Sam")
    # print(sam.subscripton)

    # input_list = [[1, 3, 3], [2, 5, -1], [3, 2], [5],
    #               [4, 5, 3], [0, 23], [1, 2, 3, 4]]

    # print(generate_qns_from_list(input_list))

    # print(get_id_checksum("1234567"))  # 7 || D
    # print(get_id_checksum("2243212"))  # 6 || E

    print(get_car_plate_checksum("SBS3229"))  # 8 || P
    print(get_car_plate_checksum("E23"))  # 13 || H
    print(get_car_plate_checksum("SS11"))  # 5 || T


if __name__ == '__main__':  # DO NOT EDIT THESE TWO LINES.
    main()
