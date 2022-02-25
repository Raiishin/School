# (1) REPLACE THE STRING VARIABLE WITH YOUR NAME in string type
name = 'Tan Jun Yin, Gavin'
# (2) REPLACE THIS STRING VARIABLE WITH YOUR UOW ID in string type
student_num = '7573935'
subject_code = 'CSIT110'
# (3) let me get to know you!
someone_who_inspires_you = 'Elon Musk'

#=========insert solution to question 1 here=============#


class Student:
    def __init__(self, Dict: dict):
        self.name = Dict['name']
        self.results = Dict['results']

    def __str__(self):
        return self.name

    @classmethod
    def dict_to_class_obj(cls, list_of_dicts: list):
        studentList = []
        for student in list_of_dicts:
            studentList.append(Student(student))

        return studentList

    def get_weighted_results(self, weights: dict):
        weighted_sum = 0
        for key, weightage in weights.items():
            if key in self.results:
                result = self.results[key] * weightage
                weighted_sum = weighted_sum + result

            else:
                raise RecordNotFoundError(key, self.name)
        return weighted_sum
#============end of solution to question 1===============#

#=========insert solution to question 2 here=============#


class RecordNotFoundError(Exception):
    def __init__(self, name_assignment: str, name_student: str):
        self.name_assignment = name_assignment
        self.name_student = name_student

    def __str__(self):
        return_string = f"There is no record of {self.name_assignment} in {self.name_student}'s results"
        return return_string
#============end of solution to question 2===============#

#=========insert solution to question 3 here=============#


class testClass():
    def __init__(self):
        pass


def count_presents_unit_test(inputClass):
    try:
        obj = inputClass()
        return obj.count_presents()

    except ValueError as e:
        return -1

    except AttributeError as e:
        return 400

    except Exception:
        return 404
#============end of solution to question 3===============#

#=========insert solution to question 4 here=============#


class InvalidDepthError(Exception):
    def __str__(self):
        return "Invalid Depth"


class WaterBody:
    RHO = 997
    G = 9.81

    def __init__(self, volume):
        self.volume = volume

    @classmethod
    def get_hydrostatic_pressure(cls, depth: float):
        if depth < 0:
            raise InvalidDepthError

        hydrostatic_pressure: float = cls.RHO * cls.G * depth
        return hydrostatic_pressure

    @staticmethod
    def compute_density(mass: float, volume: float):
        density: float = mass / volume
        return density

    def get_water_mass(self):
        mass: float = self.RHO * self.volume
        return mass
#============end of solution to question 4===============#


def myClass_demo_unit_test(inputClass):
    """ This example takes in a class definition as input,
        then instantiates a class object and test its method
        in a try except system.
    """
    try:
        obj = inputClass()
        obj.demo()
    except ValueError as e:
        print('A ValueError was raised because ' + str(e))


def example():
    # A class with one method
    class MyClass():
        def __init__(self):
            pass

        def demo(self):
            raise ValueError('Wrong input given!')
    # test the demo method
    myClass_demo_unit_test(MyClass)

    test = {
        "name": "Test",
        "results": {
            "assignment_1": 10,
            "assignment_2": 10,
        }
    }
    student = Student(test)
    print(student.name)
    print(student.results)

    testList = [{"name": "Fus Ro Dah",
                 "results": {"assignment_1": 10,
                             "assignment_2": 10,
                             "examination_1": 10,
                             },
                 }, {"name": "Foo Barry",
                     "results": {"assignment_1": 3,
                                 "assignment_2": 2,
                                 "examination_1": 4,
                                 }, }]
    students = Student.dict_to_class_obj(testList)

    for student in students:
        print(student)

    # Raises RecordNotFoundError
    weights = {"assignment_1": 1.0, "examination_1": 3.0, "examination_2": 3.0}
    students[0].get_weighted_results(weights)

    print(count_presents_unit_test(Student))
    print(count_presents_unit_test(testClass))

    water_body = WaterBody(10.12/3.12)
    print(water_body.volume)

    depth = water_body.get_hydrostatic_pressure(1)
    print(depth)

    # Raises InvalidDepthError
    water_body.get_hydrostatic_pressure(-1)

    density = water_body.compute_density(100, 20)
    print(density)

    water_mass = water_body.get_water_mass()
    print(water_mass)


def main():
    print("Assignment4")
    example()
    # an example function that creates a class and feeds into
    # the class into the myClass_demo_unit_test for testing
    # You are free to create your own test subjects that raise
    # errors to test your code here.


if __name__ == '__main__':  # DO NOT EDIT THESE TWO LINES.Y
    main()
