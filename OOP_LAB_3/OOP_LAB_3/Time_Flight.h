#pragma once
#include <iostream>
#include <string>

using namespace std;

class Time
{
private:
	int Year;
	int Month;
	int Day;
	int Hours;
	int Minutes;

public:
	void setYear(int y) {
		while (y < 0 || y > 2023) {
			cout << "\nInvalid value. Enter value from 0 to 2023." << endl;
			cin >> y;
		}
		Year = y;
	}

	void setMonth(int m) {
		while (m < 1 || m > 12) {
			cout << "\nInvalid value. Enter value from 1 to 12." << endl;
			cin >> m;
		}
		Month = m;
	}

	void setDay(int d) {
		while (d < 1 || d > 30) {
			cout << "\nInvalid value. Enter value from 1 to 30." << endl;
			cin >> d;
		}
		Day = d;
	}

	void setHours(int h) {
		while (h < 0 || h > 24) {
			cout << "\nInvalud value. Enter value from 0 to 24." << endl;
			cin >> h;
		}
		Hours = h;
	}

	void setMinutes(int m) {
		while (m < 0 || m > 60) {
			cout << "\nInvalid value. Enter value from 0 to 60." << endl;
			cin >> m;
		}
		Minutes = m;
	}
	
	int getYear() {
		return Year;
	}

	int getMonth() {
		return Month;
	}

	int getDay() {
		return Day;
	}

	int getHours() {
		return Hours;
	}

	int getMinutes() {
		return Minutes;
	}
};

void TimeBuildConsole(Time& time);


class Flight
{
private:
	int Number;
	string Start;
	string End;
	Time TimeStart;
	Time TimeEnd;

public:
	void setNumber(int n) {
		Number = n;
	}

	void setStart(string s) {
		Start = s;
	}

	void setEnd(string e) {
		End = e;
	}

	void setTimeStart(int ye, int mon, int da, int ho, int min) {
		TimeStart.setYear(ye);
		TimeStart.setMonth(mon);
		TimeStart.setDay(da);
		TimeStart.setHours(ho);
		TimeStart.setMinutes(min);
	}

	void setTimeEnd(int ye, int mon, int da, int ho, int min) {
		TimeEnd.setYear(ye);
		TimeEnd.setMonth(mon);
		TimeEnd.setDay(da);
		TimeEnd.setHours(ho);
		TimeEnd.setMinutes(min);
	}

	int getNumber() {
		return Number;
	}

	string getStart() {
		return Start;
	}

	string getEnd() {
		return End;
	}

	Time getTimeStart() {
		return TimeStart;
	}

	Time getTimeEnd() {
		return TimeEnd;
	}

	void FlightBuild(int n, string s, string e, int ye1, int mon1, int da1, int ho1, int min1, int ye2, int mon2, int da2, int ho2, int min2)
	{
		Number = n;
		Start = s;
		End = e;
		TimeStart.setYear(ye1);
		TimeStart.setMonth(mon1);
		TimeStart.setDay(da1);
		TimeStart.setHours(ho1);
		TimeStart.setMinutes(min1);
		TimeEnd.setYear(ye2);
		TimeEnd.setMonth(mon2);
		TimeEnd.setDay(da2);
		TimeEnd.setHours(ho2);
		TimeEnd.setMinutes(min2);
	}

	int getTimeStartYear() {
		return TimeStart.getYear();
	}

	int getTimeStartMonth() {
		return TimeStart.getMonth();
	}

	int getTimeStartDay() {
		return TimeStart.getDay();
	}

	int getTimeStartHours() {
		return TimeStart.getHours();
	}

	int getTimeStartMinutes() {
		return TimeStart.getMinutes();
	}

	int getTimeEndYear() {
		return TimeEnd.getYear();
	}

	int getTimeEndMonth() {
		return TimeEnd.getMonth();
	}

	int getTimeEndDay() {
		return TimeEnd.getDay();
	}

	int getTimeEndHours() {
		return TimeEnd.getHours();
	}

	int getTimeEndMinutes() {
		return TimeEnd.getMinutes();
	}

	//
	void printNumber() {
		cout << Number;
	}

	void printStart() {
		cout << Start;
	}

	void printEnd() {
		cout << End;
	}

	void printTimeStartYear() {
		cout << TimeStart.getYear();
	}

	void printTimeStartMonth() {
		int m = TimeStart.getMonth();
		cout << m;
	}

	void printTimeStartDay() {
		cout << TimeStart.getDay();
	}

	void printTimeStartHours() {
		cout << TimeStart.getHours();
	}

	void printTimeStartMinutes() {
		cout << TimeStart.getMinutes();
	}

	void printTimeEndYear() {
		cout << TimeEnd.getYear();
	}

	void printTimeEndMonth() {
		cout << TimeEnd.getMonth();
	}

	void printTimeEndDay() {
		cout << TimeEnd.getDay();
	}

	void printTimeEndHours() {
		cout << TimeEnd.getHours();
	}

	void printTimeEndMinutes() {
		cout << TimeEnd.getMinutes();
	}

	int GetFlightTimeMinutes()
	{
		int h = 0, m = 0;
		m = this->getTimeEndMinutes() - this->getTimeStartMinutes();
		h = this->getTimeEndHours() - this->getTimeStartHours();
		int falsem = 0;
		if (m < 0) {
			h -= 1;
			falsem = m;
			m = 60 + falsem;
		}

		cout << "\n " << this->getNumber() << "  " << this->getStart() << "-" << this->getEnd() << "  flight time: " <<
			h << "h " << m << "m";
		return 0;
	}
};

void FlightBuild(Flight& flight);

void DemoFlightWithTime();