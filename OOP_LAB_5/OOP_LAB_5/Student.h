#pragma once
#include "Person.h"

class Student : public Person
{
	int Id;
	int EntryYear;

public:
	Student() : Person(), Id(0), EntryYear(0) {}

	Student(string surname, string name, string patronymic, int id, int year)
		: Person(surname, name, patronymic), Id(id), EntryYear(year) {}

	void setId(int id)
	{
		Id = id;
	}

	void setEntryYear(int year)
	{
		EntryYear = year;
	}

	int getId() const { return Id; }

	int getEntryYear() const { return EntryYear; }
};