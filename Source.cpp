#include <iostream>
#include <fstream>
#include "person.h"
#include "client.h"
#include "admin.h"
#include "employee.h"
#include "fileManager.h"
using namespace std;



int main() {
	/*ofstream file;
	file.open("data.txt", fstream::app);

	if (file.is_open()) {
		cout << "Enter player name and ID\n";
		string n;
		int id;
		cout << "press ctrl+z to stop inputting \n";
		while (cin >> n >> id) {

		file << n <<" " << id<<endl;
		}
	}
	file.close();
	ifstream files("data.txt");
	string n;
	int id;
	while (files >> n >> id) {
		cout << n << " " << id << endl;
	}
	
	Client c("shetiah", "1243546325313524", 12, 2000);
	FileManager::addClient(c);
	
	vector<Client>v;
	v = FileManager::getAllClients();
	cout << v.size();
	for (auto it : v) {
		cout << it.getName() << endl;
	}
	
	Employee e("shetiah", "124532teg", 12, 246356);
	FileManager::addEmployee(e);

	Employee q("ashd", "4135esaad", 12, 2143546356);
	FileManager::addEmployee(q);
	
	
	Admin a("SHetiah", "12435tsds", 1, 2143526);
	FileManager::addAdmin(a);
	vector<Admin>aa = FileManager::getAllAdmins();
	for (auto it : aa) {
		cout << it.getPassword();
	}
	*/
	
}