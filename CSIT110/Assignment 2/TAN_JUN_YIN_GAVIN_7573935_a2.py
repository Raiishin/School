name = 'Tan Jun Yin, Gavin'
student_num = '7573935'  # Student number
subject_code = 'CSIT110'


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

    i = UPPERBOUND
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

    # Calculate RA Interest
    if AGE >= 55:
        ra = int(input('Enter current amount in RA: '))
        combinedSum += ra

    # Calculate OA Interest
    if AGE >= 55:
        if oa >= 20000:
            accumulatedInterest += (20000*0.045)
            oa = - 20000
            if oa >= 20000:
                accumulatedInterest += (20000*0.035) + ((oa-20000)*0.025)
            else:
                accumulatedInterest += (oa*0.035)

        else:
            accumulatedInterest += (oa*0.045)

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
        if oa >= 20000:
            accumulatedInterest += (20000*0.035) + ((oa-20000)*0.025)
        else:
            accumulatedInterest += (oa*0.035)

        if combinedSum >= 40000:
            accumulatedInterest += (40000*0.05) + ((combinedSum-20000)*0.04)
        else:
            accumulatedInterest += (combinedSum*0.05)

    print(f"Your interest rate this year will be ${accumulatedInterest:.2f}")
    return accumulatedInterest


def question_3():
    numberOfSingleRooms = int(input('Number of Single rooms: '))
    numberOfTwinRooms = int(input('Number of Twin rooms: '))
    numberOfDeluxeRooms = int(input('Number of Deluxe rooms: '))
    lengthOfStay = int(input('Length of stay(number of nights): '))

    costOfSingleRooms = numberOfSingleRooms * lengthOfStay * 90
    costOfTwinRooms = numberOfTwinRooms * lengthOfStay * 150
    costOfDeluxeRooms = numberOfDeluxeRooms * lengthOfStay * 250

    formattedCostOfSingleRooms = f"${costOfSingleRooms:.2f}"
    formattedCostOfTwinRooms = f"${costOfTwinRooms:.2f}"
    formattedCostOfDeluxeRooms = f"${costOfDeluxeRooms:.2f}"

    totalRooms = numberOfSingleRooms + numberOfTwinRooms + numberOfDeluxeRooms
    totalCost = costOfSingleRooms + costOfTwinRooms + costOfDeluxeRooms
    totalCostWithGST = totalCost * 1.07

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


def main():
    question_1()
    question_2()
    question_3()
    print(question_4())


if __name__ == '__main__':
    main()
