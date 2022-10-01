#pragma once
#include <iostream>
#include<fstream>
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
	
	void display() {
		Person::display();
		cout << "Salary: " << getSalary();
	}
	void Addclient(Client s) {
		ofstream clientFile;
		clientFile.open("clients.txt", fstream::app);
		clientFile << s.getName() << " " << s.getID() << " " << s.getBalance() << " " << s.getPassword() << endl;
		clientFile.close();
	}
	void listclient() {
		vector<Client>allClients;
		ifstream clientFiles("clients.txt");
		string name, password;
		double balance;
		int id;
		while (clientFiles >> name >> id >> balance >> password) {
			Client c(name, password, id, balance);
			allClients.push_back(c);
		}
		for (int i = 0; i < allClients.size(); i++) {
			Client s = allClients[i];
			cout <<"Client name: " << s.getName() << ", ID: " << s.getID() << ", Password: " << s.getPassword() << ", Balance: " << s.getBalance() << endl;
		}
	}
	Client searchclient(int id) {
		bool found = false;
		ifstream clientFile;
		clientFile.open("clients.txt");
		string name;
		string pass;
		int oldid;
		double balance;
		Client returns;
		while (clientFile >> name >> oldid >> balance >> pass)
		{
			if (oldid == id) {
				found = true;
				returns.setName(name);
				returns.setPassword(pass);
				returns.setBalance(balance);
			}
		}
		if(found)
				return returns;
		else {
			cout << "Client ID not found.\n";
			return returns;
		}
	}
	void editclient(string newname, string newpass,int newid,double newbalance) {
	
		cout << "Enter The id Of The Client: ";
		int oldid;
		cin >> oldid;
		Client edit = searchclient(oldid);
		
		ifstream clientFile;
		clientFile.open("clients.txt");
		
		string oldName, oldPassword;
		int idd;
		double oldBalance;
	
		//saving new data in temp file
		ofstream tempFile("temp.txt");
		while (clientFile >>oldName >> idd >> oldBalance >> oldPassword) {
			if (idd == oldid) {
				tempFile << newname << " " << newid<<" " << newbalance << " " << newpass << endl;
			}
			else {
				tempFile << oldName << " " << idd << " " << oldBalance << " " << oldPassword << endl;
			}
			
		}
		//restoring data in clients.txt
		ifstream tempOpen("temp.txt");
		ofstream restore("clients.txt");
		string tempName, tempPassword;
		int tempID;
		double tempBalance;
		while (tempOpen >> tempName >> tempID >> tempBalance >> tempPassword) {
			restore << tempName << " " << tempID << " " << tempBalance << " " << tempPassword << endl;
		}
		
	}
};

