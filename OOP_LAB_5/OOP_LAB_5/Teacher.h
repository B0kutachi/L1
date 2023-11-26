#pragma once
#include "Student.h"

class Teacher : public Person
{
	string Position;

public:
	Teacher() : Person(), Position(" ") {}

	Teacher(string surname, string name, string patronymic, string position)
		: Person(surname, name, patronymic), Position(position) {}

	void setPosition(string pos)
	{
		Position = pos;
	}

	string getPosition()
	{
		return Position;
	}
};

