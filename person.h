#include <iostream>
#include "validate.h"
using namespace std;

class Person {
protected:

	//default values to prevent garbage values
	
	string name =" ", password= " ";
	int id = 0;
	
public:
	
	//setters & getters
	
	void setName(string name) {
		if (Validate::validateName(name))
			this->name = name;
	}
	string getName() {
		return name;
	}

	void setPassword(string password) {
		if (Validate::validatePassword(password))
			this->password = password;
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