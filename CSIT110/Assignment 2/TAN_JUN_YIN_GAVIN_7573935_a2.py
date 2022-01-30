# (1) REPLACE THE STRING VARIABLE WITH YOUR NAME in string type
name = 'Tan Jun Yin, Gavin'
# (2) REPLACE THIS STRING VARIABLE WITH YOUR UOW ID in string type
student_num = '7573935'
subject_code = 'CSIT110'
# (3) let me get to know you!
comfort_food = 'Cake'

#========== insert solution here===========#


def question_1():

    UPPERBOUND = int(input('Enter upper bound: '))
    GAP = int(input('Enter gap: '))

    forwards = []
    forwardSum = 0
    backwards = []
    backwardSum = 0
    i = 0

    # Moving Up
    while i <= UPPERBOUND:
        forwards.append(i)
        forwardSum = forwardSum + i
        i = i + GAP

    i = UPPERBOUND  # Reset count to start from UPPERBOUND

    # Moving Down
    while i > 0:
        backwards.append(i)
        backwardSum = backwardSum + i
        i = i - GAP

    print("Go forward: ", end="")
    print(*forwards, sep=', ')
    print(f"Sum of numbers = {forwardSum}")
    print("Go backward: ", end="")
    print(*backwards, sep=', ')
    print(f"Sum of numbers = {backwardSum}")


def question_2():

    AGE = int(input('Enter current age: '))
    oa = int(input('Enter current amount in OA: '))
    sa = int(input('Enter current amount in SA: '))
    ma = int(input('Enter current amount in MA: '))

    combinedSum = sa + ma
    accumulatedInterest = 0

    if AGE >= 55:
        # Account for AGE >= 55
        ra = int(input('Enter current amount in RA: '))
        combinedSum += ra

        # Calculating OA Interest
        if oa >= 20000:
            accumulatedInterest += (20000*0.045)
            oa = - 20000
            if oa >= 20000:
                accumulatedInterest += (20000*0.035) + ((oa-20000)*0.025)
            else:
                accumulatedInterest += (oa*0.035)

        else:
            accumulatedInterest += (oa*0.045)

        # Calculating SA + MA + RA Interest
        if combinedSum >= 20000:
            accumulatedInterest += (20000*0.06)
            combinedSum = combinedSum - 20000

            if combinedSum >= 40000:
                accumulatedInterest += (10000*0.05) + \
                    ((combinedSum-10000)*0.04)

            else:
                accumulatedInterest += (combinedSum*0.05)

        else:
            accumulatedInterest += (combinedSum*0.06)

    else:
        # Calculating OA Interest
        if oa >= 20000:
            accumulatedInterest += (20000*0.035) + ((oa-20000)*0.025)
        else:
            accumulatedInterest += (oa*0.035)

        # Calculating SA + MA Interest
        if combinedSum >= 40000:
            accumulatedInterest += (40000*0.05) + ((combinedSum-20000)*0.04)
        else:
            accumulatedInterest += (combinedSum*0.05)

    print(f"Your interest rate this year will be ${accumulatedInterest:.2f}")


def question_3():

    # User Inputs
    numberOfSingleRooms = int(input('Number of Single rooms: '))
    numberOfTwinRooms = int(input('Number of Twin rooms: '))
    numberOfDeluxeRooms = int(input('Number of Deluxe rooms: '))
    lengthOfStay = int(input('Length of stay(number of nights): '))

    # Calculating Cost of Rooms
    costOfSingleRooms = numberOfSingleRooms * lengthOfStay * 90
    costOfTwinRooms = numberOfTwinRooms * lengthOfStay * 150
    costOfDeluxeRooms = numberOfDeluxeRooms * lengthOfStay * 250

    # Formatting Cost of Rooms
    formattedCostOfSingleRooms = f"${costOfSingleRooms:.2f}"
    formattedCostOfTwinRooms = f"${costOfTwinRooms:.2f}"
    formattedCostOfDeluxeRooms = f"${costOfDeluxeRooms:.2f}"

    # Calculating Total Rooms and Total Cost
    totalRooms = numberOfSingleRooms + numberOfTwinRooms + numberOfDeluxeRooms
    totalCost = costOfSingleRooms + costOfTwinRooms + costOfDeluxeRooms
    totalCostWithGST = totalCost * 1.07

    # Formatting Total Cost
    formattedTotalCost = f"${totalCost:.2f}"
    formattedTotalCostWithGST = f"${totalCostWithGST:.2f}"

    print()
    print(f"Summary of your booking for {lengthOfStay} night(s)")
    print(f'{"Single room":<13}', end=' ')
    print(f'{numberOfSingleRooms:^3}', end=' ')
    print(f'{formattedCostOfSingleRooms:>8}')

    print(f'{"Twin room":<13}', end=' ')
    print(f'{numberOfTwinRooms:^3}', end=' ')
    print(f'{formattedCostOfTwinRooms:>8}')

    print(f'{"Deluxe room":<13}', end=' ')
    print(f'{numberOfDeluxeRooms:^3}', end=' ')
    print(f'{formattedCostOfDeluxeRooms:>8}')

    print(f'{"Subtotal":<13}', end=' ')
    print(f'{totalRooms:^3}', end=' ')
    print(f'{formattedTotalCost:>8}')

    print(f'{"Total(7% g.s.t)  ":<16}', end=' ')
    print(f'{formattedTotalCostWithGST:>8}')


def question_4():

    returnString = []

    def cleanString(dirty):
        clean = ""
        bad = 0

        for c in dirty:
            if c == '{':
                bad += 1
            elif c == '}':
                bad -= 1
            elif bad == 0:
                clean += c

        return clean

    while True:
        try:
            filename = str(input('Filename?'))
            if filename == '':
                break

            while "{" in filename:
                filename = cleanString(filename)

            returnString.append(filename.strip())

        except Exception as e:
            return e

    listToStr = ','.join(map(str, returnString))
    return listToStr


def main():  # DO NOT EDIT THESE TWO LINES.

    print("Assignment2")  # DO NOT EDIT THESE TWO LINES.

    # you can call your functions here to test that it works.
    # you do not have to comment your own test code

    # Note: print() was added for improved readability
    question_1()
    print()
    question_2()
    print()
    question_3()
    print()
    print(question_4())


if __name__ == '__main__':  # DO NOT EDIT THESE TWO LINES.
    main()
