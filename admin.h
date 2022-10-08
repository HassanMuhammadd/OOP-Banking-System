#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "employee.h"
using namespace std;



class Admin : public Employee {
public:
	Admin() {

	};
	Admin(string name, string password, int id, double salary) :Employee(name, password, id, salary) {

	}

	void addemployee(Employee s) {
		ofstream Employeefile;
		Employeefile.open("employees.txt", fstream::app);
		Employeefile << s.getName() << " " << s.getID() << " " << s.getSalary() << " " << s.getPassword() << endl;
		Employeefile.close();
	}
	Employee searchemployee(int id) {
		bool found = false;
		ifstream Employeefile;
		Employeefile.open("clients.txt");
		string name;
		string pass;
		int oldid;
		double salary;
		Employee returns;
		while (Employeefile >> name >> oldid >> salary >> pass)
		{
			if (oldid == id) {
				found = true;
				returns.setName(name);
				returns.setPassword(pass);
				returns.setID(id);
				returns.setSalary(salary);
			}
		}
		if(found)
				return returns;
		else {
			cout << "Employee ID not found.\n";
			return returns;
		}
	}
	void listEmployeefile() {
		vector<Employee>allemployes;
		ifstream Employeefile("employees.txt");
		string name, password;
		double salary;
		int id;
		while (Employeefile >> name >> id >> salary >> password) {
			Employee c(name, password, id, salary);
			allemployes.push_back(c);
		}
		for (int i = 0; i < allemployes.size(); i++) {
			Employee s = allemployes[i];
			cout << s.getName() << ' ' << s.getID() << ' ' << s.getPassword() << ' ' << s.getSalary() << endl;
		}
	}
};