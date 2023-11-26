#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stuff
{
public:
	double virtual CalculateSalary(int hours) = 0;
};

class Teacher1 : public Stuff
{
	double Salary;
public:
	void setSalary(double salary) {
		if (salary < 0)
			cout << "\nSalary can't be less than 0!";
		this->Salary = salary;
	}
	double getSalary() { return this->Salary; }

	double CalculateSalary(int hours) override 
	{
		cout << "\nSalary before: " << this->Salary;
		this->Salary = (this->Salary * hours);
		cout << "\nSalary after: " << this->Salary;
		return this->Salary;
	}
};

class MasterTeacher1 : public Stuff
{
	double Salary;
public:
	void setSalary(double salary) {
		if (salary < 0)
			cout << "\nSalary can't be less than 0!";
		this->Salary = salary;
	}
	double getSalary() { return this->Salary; }

	double CalculateSalary(int hours) override
	{
		cout << "\nSalary before: " << this->Salary;
		this->Salary = (this->Salary * hours * 1.3);
		cout << "\nSalary after: " << this->Salary;
		return this->Salary;
	}
};