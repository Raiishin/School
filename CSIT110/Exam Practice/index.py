import random
name = 'Tan Jun Yin, Gavin'
student_uow_id = "7573935"  # UOW student number
course_code = "CSIT110"  # CSIT110 or SP420

#========= Question 1 =============#


def question1():
    def question_1a(question_list_1: list, question_list_2: list):
        for question in question_list_2:
            question_list_1.append(question)
        return question_list_1

    correct_answer = [1, "asd", 234, ["ewq", 32], True]
    if question_1a([1, "asd", 234], [["ewq", 32], True]) == correct_answer:
        print(True)

    def question_1b(question_list_1: list, item):
        return question_list_1.index(int(item))

    correct_answer = 1
    if question_1b([1, 4, "abc", 3, 2, 9, -1, 4], 4) == correct_answer:
        print(True)

    def question_1c(x: int, N: int):
        return_list = []
        for n in range(0, N, 1):
            return_list.append(x)

        return return_list

    correct_answer = [15, 15, 15]
    if question_1c(15, 3) == correct_answer:
        print(True)

    def question_1d(question_list_1: list, question_integer_1: int):
        counter = 0
        for integer in question_list_1:
            if integer == question_integer_1:
                counter += 1

        return counter

    correct_answer = 1
    if question_1d([1, 5, 2, -1, 99, 5, 0], -1) == correct_answer:
        print(True)

    def dot_product(list_of_integers_1: list, list_of_integers_2: list):
        return_integer = 0
        for i in range(len(list_of_integers_1)):
            return_integer += list_of_integers_1[i] * list_of_integers_2[i]

        return return_integer

    correct_answer = 45
    if dot_product([1, 2, 3, 4, 5], [9, 8, 7, 6, -5]) == correct_answer:
        print(True)

    def root_mean_square(list_of_integers_1: list):
        answer = 0
        for num in list_of_integers_1:
            answer += num**2

        answer = (1/len(list_of_integers_1)) * answer

        return answer**0.5

    correct_answer = 4.47213595499958
    if root_mean_square([1, 2, 3, 4, 5, 6, 7]) == correct_answer:
        print(True)

    def list_to_dict(l: list):
        return_dict = {}
        for item in l:
            return_dict.update({item[0]: item[1]})

        return return_dict

    correct_answer = {"eg1": 123, "eg2": 234, "eg3": 345}
    if list_to_dict([["eg1", 123], ["eg2", 234], ["eg3", 345]]) == correct_answer:
        print(True)

    def question_1h(a: str):
        raise ValueError(a)

    # question_1h("Error error 1")

    def question_1i():
        size = int(input("Enter size: "))

        if size < 8:
            return "XS"
        elif size < 10:
            return "S"
        elif size < 14:
            return "M"

        return "L"

    print(question_1i())

    def question_1j(N: int):
        answer = 1
        return_string = ""
        for i in range(N):
            gen = random.randint(1, 100)
            return_string += str(gen)
            if i != N-1:
                return_string += " x "
            answer = answer * gen

        return {"qns": return_string, "ans": answer}

    print(question_1j(3))

#========= Question 2 =============#


def question2():

    class Product:
        def __init__(self, name, price):
            self.name = name
            self.price = price

        @classmethod
        def from_dict(cls, args):
            return cls(args["name"], args["price"])

    soap = Product("Johnson Baby Bath", 12.34)
    print(soap.name)
    print(soap.price)

    new_product = Product.from_dict({"name": "hand sanitizer", "price": 1.75})
    print(new_product.name)
    print(new_product.price)

#========= Question 3 =============#


def question3():

    class NoGradesError(Exception):
        pass

    class Student():
        def __init__(self, name="", grades=None):
            self.__grades = grades

        def get_grades(self):
            if self.__grades == None:
                raise NoGradesError()
            return self.__grades

    def get_class_statistics(students):
        statistics = {
            "pass_count": 0,
            "fail_count": 0,
            "invalid_count": 0,
        }
        for student in students:
            try:
                grades = student.get_grades()

                total = 0
                for grade in grades:
                    total += grade

                if total >= 50:
                    statistics["pass_count"] += 1
                else:
                    statistics["fail_count"] += 1

            except NoGradesError as e:
                statistics["invalid_count"] += 1

        return statistics

    students = [
        Student("StudentA"),  # Invalid
        Student("StudentB", [10, 2, 3]),  # Fail
        Student("StudentC", [11, 4, 5]),  # Fail
        Student("StudentD", [20, 30, 40]),  # Pass
        Student("StudentE", [30, 40, 50]),  # Pass
        Student("StudentF", [10, 15, 25]),  # Pass
    ]
    print(get_class_statistics(students))

#========= Question 4 =============#


def question4():
    class Staff:
        def __init__(self, name, staff_num, salary, staff_benefits=True):
            self.name = name
            self.staff_num = staff_num
            self.salary = float(salary)
            self.staff_benefits = staff_benefits

        def get_paycheck(cls):
            return cls.salary

    jane = Staff("Jane Doe", "EB4034", 2500)
    tom = Staff("Tom Harris", "663D5E", 2950, False)
    print(jane.staff_benefits)
    print(tom.staff_benefits)
    print(jane.get_paycheck())
    print(tom.get_paycheck())

    class ContractStaff(Staff):
        def __init__(self, name, staff_num, hourly_rate):
            super().__init__(name, staff_num, 0, False)
            self.hours_worked = 0
            self.hourly_rate = hourly_rate

        def add_hours_worked(self, hours):
            self.hours_worked += hours

        def get_paycheck(self):
            return self.hours_worked * self.hourly_rate

    ashlyn = ContractStaff("Ashlyn Hennessy", "9423c4", 8.5)
    print(ashlyn.staff_benefits)
    ashlyn.add_hours_worked(8.5)
    print(ashlyn.hours_worked)
    print(ashlyn.get_paycheck())

#========= Question 5 =============#


def question5():
    class HighSchoolStudent():
        def __init__(self, name, grades):
            # READ ME!
            # the parameter, name, will be of str type.
            # the parameter, grades, will be a dictionary with string as keys and float as values.
            #         e.g. {"qwe": 1.1, "asd":5.9}
            self.__name = name
            self.__grades = grades

        def get_name(self):  # The function will return a string
            return self.__name

        # The function returns a dictionary with string as keys and float as values.
        def get_grades(self):
            return self.__grades

    def get_student_report(student):
        report = student.get_name() + "\n"
        student_grades = student.get_grades()

        total = 0.0
        width_column1 = 0
        width_column2 = 0

        for subject, grade in student_grades.items():
            total += float(grade)
            if len(subject) > width_column1:
                width_column1 = len(subject)
        width_column2 = len(f"{total:>.1f}")

        for subject, grade in student_grades.items():
            report += f"{subject:>{width_column1}}: {grade:>{width_column2}.1f}\n"

        report += '-'*(width_column1 + width_column2 + 2) + "\n"
        report += f"{'Total Grade':>{width_column1}}: {total:>{width_column2}.1f}"

        return report

    student = HighSchoolStudent(
        "StudentA",
        {
            "Art History": 1.2,
            "Spanish": 23.4,
            "Computer Science": 45,
        }
    )
    print(get_student_report(student))

    student = HighSchoolStudent(
        "StudentB",
        {
            "Combinatorics": 99.91,
            "Literature": 0.1,
        }
    )
    print(get_student_report(student))

    student = HighSchoolStudent(
        "StudentC",
        {
            "Environmental Management - 5014": 2000.5,
            "French": 10.1,
        }
    )
    print(get_student_report(student))


question5()
