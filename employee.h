#pragma once
#include <iostream>
#include<vector>
#include "person.h"

using namespace std;


class Employee : public Person {
protected:
	double salary;
public:
	Employee() {
	}
	Employee(string name, string password, int id, double salary) :Person(name, password, id) {
		setSalary(salary);
	}
	//setter & getter
	void setSalary(double salary) {
		if (Validate::validateSalary(salary))
			this->salary = salary;
		else {
			cout << "Enter a new salary: ";
			double s;
			cin >> s;
			setSalary(s);
		}
	}
	double getSalary() {
		return salary;
	}
	//other functionalities
	/*Client addClient() {
		Client c;
		return c;
	}*/
	void display() {
		Person::display();
		cout << "Salary: " << getSalary();
	}
};

