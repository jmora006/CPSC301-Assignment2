#include "person.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void readData(Person array[], int size)
{
	string fName;
	string lName;
	float rate;
	float hours;

	ifstream file("input.txt");
	for(int i = 0; i < size; i++)
	{
		if(!file.eof())
		{
			file>>fName;
			file>>lName;
			file>>hours;
			file>>rate;
			array[i].setFirstName(fName);
			array[i].setLastName(lName);
			array[i].setHoursWorked(hours);
			array[i].setPayRate(rate);
		}
	}
	file.close();
}

void writeData(Person array[], int size)
{
	string fullName;
	float total;
	
	ofstream file("output.txt");
	if(file.is_open())
	{
		for(int i = 0; i < size; i++)
		{
			cout<<setprecision(2)<<fixed;
			fullName = array[i].fullName();
			total = array[i].totalPay();
			file<<fullName<<" "<<total<<endl;
			cout<<fullName<<" "<<total<<endl; 
		}
		file.close(); 
	}
}

int main()
{
	int size = 20;
	Person employees[size];
	
	readData(employees, 6);
	writeData(employees, 6);
	
	cin.get();
	return 0;
}
