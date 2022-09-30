#pragma once
#include "dataSourceInterface.h"
#include <iostream>
#include <fstream>
#include <vector>

class FileManager : public DataSourceInterface {
public:
	static void addClient(Client c) {

		//write client data to text file
		ofstream clientFile;
		clientFile.open("clients.txt", fstream::app);
		clientFile << c.getName() << " " << c.getID() << " " << c.getBalance() << " " << c.getPassword() << endl;
		clientFile.close();

	}
	static vector<Client> getAllClients() {
		vector<Client>allClients;
		//open txt file to read from
		ifstream clientFiles("clients.txt");
		string name, password;
		double balance;
		int id;
		//take input from txt file
		while (clientFiles >> name >> id >> balance >> password) {
			Client c(name, password, id, balance);
			allClients.push_back(c);
		}
		return allClients;
	}
	static void addEmployee(Employee e) {

		//write client data to text file
		ofstream empFile;
		empFile.open("employees.txt", fstream::app);
		empFile << e.getName() << " " << e.getID() << " " << e.getSalary() << " " << e.getPassword() << endl;
		empFile.close();

	}
	static vector<Employee> getAllEmployees() {
		vector<Employee>allEmployees;
		//open txt file to read from
		ifstream empFiles("employees.txt");
		string name, password;
		double salary;
		int id;
		//take input from txt file
		while (empFiles >> name >> id >> salary >> password) {
			Employee e(name, password, id, salary);
			allEmployees.push_back(e);
		}
		return allEmployees;
	}
	static void addAdmin(Admin a) {

		//write admin data to text file
		ofstream adminFile;
		adminFile.open("admins.txt", fstream::app);
		adminFile << a.getName() << " " << a.getID() << " " << a.getSalary() << " " << a.getPassword() << endl;
		adminFile.close();

	}
	static vector<Admin> getAllAdmins() {
		vector<Admin>allAdmins;
		//open txt file to read from
		ifstream adminFiles("admins.txt");
		string name, password;
		double salary;
		int id;
		//take input from txt file
		while (adminFiles >> name >> id >> salary >> password) {
			Admin a(name, password, id, salary);
			allAdmins.push_back(a);
		}
		return allAdmins;
	}
	static void removeAllClients() {
		ofstream clientFile("clients.txt");
		clientFile << "";
	}
	static void removeAllEmployees() {
		ofstream empFile("employees.txt");
		empFile << "";
	}
	static void removeAllAdmins() {
		ofstream adminFile("admins.txt");
		adminFile << "";
	}
};