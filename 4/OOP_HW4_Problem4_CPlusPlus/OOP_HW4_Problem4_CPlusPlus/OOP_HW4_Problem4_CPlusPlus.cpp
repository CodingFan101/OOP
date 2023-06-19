// OOP_HW4_Problem4_CPlusPlus.cpp : Christopher Hainzl

#include <iostream>
using namespace std;
class Employee {
private:
    string name, ssn;
public:
Employee(string name, string ssn) {
		this->name = name;
		this->ssn = ssn;
	}
	string getName() {
		return name;
	}
	string getSSN() {
		return ssn;
	}
	void setName(string name) {
		this->name = name;
	}
	void setSSN(string ssn) {
		this->ssn = ssn;
	}
	bool validateSSN() {
		if (ssn.length() != 11) {
			return false;
		}
		else {
			for (int i = 0; i < ssn.length(); i++) {
				if (i == 3 || i == 6) {
					if (ssn[i] != '-') {
						return false;
					}
				}
				else {
					if (!isdigit(ssn[i])) {
						return false;
					}
				}
			}
			return true;
		}
	}
	// Pure virtual function
	virtual void printout() = 0;
};

class Hourly : public Employee {
private:
	int wage, hours;
public:
	Hourly(string name, string ssn, int wage, int hours) : Employee(name, ssn) {
		this->wage = wage;
		this->hours = hours;
	}
	int getWage() {
		return wage;
	}
	int getHours() {
		return hours;
	}
	int getMoneyEarned() {
		if (hours > 40) {
			int overtimepay = (hours - 40) * (wage * 1.5);
			return (wage * 40) + overtimepay;
		}
		else {
			return wage * hours;
		}
	}
	void setWage(int wage) {
		this->wage = wage;
	}
	void setHours(int hours) {
		this->hours = hours;
	}
	void printout() {
		cout << "Name: " << getName() << endl;
		cout << "SSN: " << getSSN() << endl;
		cout << "Wage: " << getWage() << endl;
		cout << "Hours: " << getHours() << endl;
		cout << "Money Earned: " << getMoneyEarned() << endl;
	}
};

class Salaried : public Employee {
private:
	int yearlysalary;
public:
Salaried(string name, string ssn, int yearlysalary) : Employee(name, ssn) {
		this->yearlysalary = yearlysalary;
	}
	int getWeeklySalary() {
		return yearlysalary / 52;
	}
	int getYearlySalary(){
		return yearlysalary;
	}
	void setYearlySalary(int salary) {
		this->yearlysalary = salary;
	}
	void printout() {
		cout << "Name: " << getName() << endl;
		cout << "SSN: " << getSSN() << endl;
		cout << "Yearly Salary: " << getYearlySalary() << endl;
		cout << "Weekly Salary: " << getWeeklySalary() << endl;
	}
};

int main()
{
    Employee *h = new Hourly("John", "123-45-6789", 10, 45);
	Employee *s = new Salaried("Jane", "987-65-4321", 52000);
	h->printout();
	cout << endl;
	s->printout();
	cout << endl;
	cout << "Is John's SSN valid? " << h->validateSSN() << endl;
	cout << "Is Jane's SSN valid? " << s->validateSSN() << endl;
	return 0;
}