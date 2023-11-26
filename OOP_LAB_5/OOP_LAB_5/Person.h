#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
	string Name;
	string Surname;
	string Patronymic;

public:
	Person()
	{
		Name = " ";
		Surname = " ";
		Patronymic = " ";
	}

	Person(string surname, string name, string patr)
	{
		setName(name);
		setSurname(surname);
		setPatronymic(patr);
	}

	void setName(string name)
	{
		Name = name;
	}

	void setSurname(string surname)
	{
		Surname = surname;
	}

	void setPatronymic(string patr)
	{
		Patronymic = patr;
	}

	string getName() { return Name; }

	string getSurname() { return Surname; }

	string getPatronymic() { return Patronymic; }

	void ShowName(Person* person)
	{
		cout << person->getSurname() << " " << person->getName() << " " << person->getPatronymic() << endl;
	}
};
