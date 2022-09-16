#include <iostream>
#include "person.h"

using namespace std;

//finished
class Client : public Person {
private:
	double balance = 0;
public:
	static int clientCount; // static member to update the count of clients
	Client() {
		clientCount++;
	}

	//setter & getter
	void setBalance(double balance) {
		if (Validate::validateBalance(balance))
			this->balance = balance;
	}
	double getBalance() {
		return balance;
	}

	//other functionalities

	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			cout << amount << " Withdrawn successfully!\n";
		}
		else {
			cout << "Error, Your balance is not enough to complete this transaction."<<endl;
			cout << "Do you want to Withdraw another amount? (Y/N)\n";
			char choice;
			cin >> choice;
			if(choice=='Y' || choice=='y'){
				cout << "Enter amount to withdraw : ";
				double a;
				cin >> a;
				withdraw(a);
			}
			else {
				cout << "Going back. \n";
			}
			
		}
	}
	void checkBalance() {
		cout << "Your current balance is: " << balance << endl;
	}
	void transferTo(double amount, Client &reciever) {
		if (amount <= balance) {
			balance -= amount;
			reciever.deposit(amount);
		}
		else {
			cout << "Error, Your balance is not enough to complete this transaction." << endl;
		}
	}
	void display() {
		Person::display();
		cout << "Current Balance: " << getBalance() << endl;
	}
};
int Client::clientCount = 0;

class Employee : public Person {
private:
	double salary;
public:
	
	//setter & getter
	void setSalary(double salary) {
		if(Validate::validateSalary(salary))
		this->salary = salary;
	}
	double getSalary() {
		return salary;
	}
	//other functionalities
	Client addClient() {
		Client c;
		return c;
	}
	void display() {
		Person::display();
		cout << "Salary: " << getSalary();
	}
};

class Admin : public Employee {

};