#include <iostream>
#include "validate.h"
using namespace std;

class Person {
protected:

	//default values to prevent garbage values
	
	string name =" ", password= " ";
	int id = 0;
	
public:
	Person() {

	}
	Person(string name, string password, int id) {
		this->name = name;
		this->password = password;
		this->id = id;
	}
	//setters & getters
	void setName(string name) {
		if (Validate::validateName(name))
			this->name = name;
		else {
			cout << "Enter your name again: ";
			string n;
			cin >> n;
			setName(n);
		}
	}
	string getName() {
		return name;
	}

	void setPassword(string password) {
		if (Validate::validatePassword(password))
			this->password = password;
		else {
			cout << "Enter another password: ";
			string p;
			cin >> p;
			setPassword(p);
		}
	}
	string getPassword() {
		return password;
	}

	void setID(int id) {
		this->id = id;
	}
	int getID() {
		return id;
	}
	void display() {
		cout << "Name: " << getName() << endl;
		cout << "ID: " << getID() << endl;
	}
};