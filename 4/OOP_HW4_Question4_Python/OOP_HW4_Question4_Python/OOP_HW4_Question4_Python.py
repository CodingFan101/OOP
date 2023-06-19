from abc import ABC, abstractmethod
class Employee(ABC):
    def __init__(self, name, ssn):
        self.name = name
        self.ssn = ssn
    def setname(self, name):
        self.name = name
    def setssn(self, ssn):
        self.ssn = ssn
    def getname(self):
        return self.name
    def getssn(self):
        return self.ssn
    def validatessn(self):
        if len(self.ssn) == 11:
            if self.ssn[3] == "-" and self.ssn[6] == "-":
                return True
            else:
                return False
        else:
            return False
    @abstractmethod
    def printout(self):
        print("Name: " + self.getname())
        print("SSN: " + self.getssn())

class Hourly(Employee):
    def __init__(self, name, ssn, hours, wage):
        Employee.__init__(self, name, ssn)
        self.hours = hours
        self.wage = wage
    def sethours(self, hours):
        self.hours = hours
    def setwage(self, wage):
        self.wage = wage
    def gethours(self):
        return self.hours
    def getwage(self):
        return self.wage
    def moneyearned(self):
        if self.hours > 40:
            return (40 * self.wage) + ((self.hours - 40) * (self.wage * 1.5))
        else:
            return self.hours * self.wage
    def printout(self):
        super().printout()
        print("Wage: ", self.getwage())
        print("Hours: ", self.gethours())
        print("Money Earned: ", self.moneyearned())

class Salaried(Employee):
    def __init__(self, name, ssn, yearlysalary):
        Employee.__init__(self, name, ssn)
        self.yearlysalary = yearlysalary
    def setyearlysalary(self, salary):
        self.yearlysalary = salary
    def yearlysalary(self):
        return self.yearlysalary
    def weeklysalary(self):
        return self.yearlysalary / 52
    def printout(self):
        super().printout()
        print("Yearly Salary: ", self.yearlysalary)
        print("Weekly Salary: ", self.weeklysalary())

h = Hourly("John", "123-45-6789", 45, 10)
h.printout()
print()
s = Salaried("Jane", "845-11-9827", 50000)
s.printout()
print()
print("Is John's SSN valid? ", h.validatessn())
print("Is Jane's SSN valid? ", s.validatessn())