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
	Admin(string name, string password, int id, double salary) :Employee(name,password,id,salary) {
	
	}
};

