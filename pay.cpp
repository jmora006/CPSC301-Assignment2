//Jason Mora-Mendoza
//Section 1

#include "person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void readData(vector<Person> &employees)
{
	string fName;
	string lName;
	float rate;
	float hours;

	ifstream file("input.txt");
	if(file.is_open())
	{
		file>>fName;
		while(!file.eof())
		{
			//file>>fName;
			file>>lName;
			file>>rate;
			file>>hours;
			employees.emplace_back(fName, lName, rate, hours);
		}
	}
	file.close();
}

void writeData(vector<Person> &employees)
{
	string fullName;
	float total;
	
	ofstream file("output.txt");
	if(file.is_open())
	{
		for(int i = 0; i < employees.size(); i++)
		{
			fullName = employees[i].fullName();
			total = employees[i].totalPay();
			file<<fullName<<" "<<fixed<<setprecision(2)<<total<<endl;
			//Printing out the output to check on Terminal window
			cout<<fullName<<" "<<fixed<<setprecision(2)<<total<<endl;
		}
		file.close(); 
	}
}

int main()
{
	vector<Person> employees;
	readData(employees);
	writeData(employees);
	
	cin.get();
	return 0;
}
