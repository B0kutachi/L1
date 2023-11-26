#include "Time_Flight.h"


void TimeBuildConsole(Time& time)
{
	int y, mo, d, h, mi;
	cout << "\nEnter year: ";
	cin >> y;
	time.setYear(y);
	cout << "\nEnter month: ";
	cin >> mo;
	time.setMonth(mo);
	cout << "\nEnter day: ";
	cin >> d;
	time.setDay(d);
	cout << "\nEnter hours: ";
	cin >> h;
	time.setHours(h);
	cout << "\nEnter minutes: ";
	cin >> mi;
	time.setMinutes(mi);
}


void FlightBuild(Flight& flight)
{
	int n;
	string Start, End;
	cout << "\nEnter the flight number: ";
	cin >> n;
	flight.setNumber(n);
	cout << "\nEnter point of departure: ";
	cin.ignore();
	getline(cin, Start);
	flight.setStart(Start);
	cout << "\nEnter point of destination: ";
	cin.ignore();
	getline(cin, End);
	flight.setEnd(End);

	int ye, mon, da, ho, min;
	cout << "\nEnter start time ";
	cout << "\nEnter year: "; cin >> ye;
	cout << "\nEnter month: "; cin >> mon;
	cout << "\nEnter day: "; cin >> da;
	cout << "\nEnter hours: "; cin >> ho;
	cout << "\nEnter minutes: "; cin >> min;
	flight.setTimeStart(ye, mon, da, ho, min);

	int y, mo, d, h, mi;
	cout << "\nEnter end time ";
	cout << "\nEnter year: ";
	cin >> y;
	while (y < flight.getTimeStart().getYear()) {
		cout << "\nInvalid year(the time of destination cannot be earlier than the time of departure). "
			<< "Enter year again: ";
		cin >> y;
	}
	flight.getTimeEnd().setYear(y);

	cout << "\nEnter month: ";
	cin >> mo;
	if (mo <= mon) {
		while (mo < flight.getTimeStart().getMonth()) {
			cout << "\nInvalid month(the time of destination cannot be earlier than the time of departure). "
				<< "Enter month again: ";
			cin >> mo;
		}
	}
	flight.getTimeEnd().setMonth(mo);

	cout << "\nEnter day: ";
	cin >> d;
	if (mo <= mon && d <= da) {
		while (d < flight.getTimeStart().getDay()) {
			cout << "\nInvalid day(the time of destination cannot be earlier than the time of departure). "
				<< "Enter day again: ";
			cin >> d;
		}
	}
	flight.getTimeEnd().setDay(d);

	cout << "\nEnter hours: ";
	cin >> h;
	if (mo <= mon && d <= da && h <= ho) {
		while (h < flight.getTimeStart().getHours()) {
			cout << "\nInvalid month(the time of destination cannot be earlier than the time of departure). "
				<< "Enter hours again: ";
			cin >> h;
		}
	}
	flight.getTimeEnd().setHours(h);

	cout << "\nEnter minutes: ";
	cin >> mi;
	if (mo <= mon && d <= da && h <= ho && mi <= min) {
		while (mi < flight.getTimeStart().getMinutes()) {
			cout << "\nInvalid month(the time of destination cannot be earlier than the time of departure). "
				<< "Enter minutes again: ";
			cin >> mi;
		}
	}
	flight.getTimeEnd().setMinutes(mi);
}

void DemoFlightWithTime()
{
	Flight flights[5];
	flights[0].FlightBuild(901, "Tomsk", "Moscow", 2018, 6, 15, 8, 10, 2018, 6, 15, 13, 20);
	flights[1].FlightBuild(777, "Moscow", "Tomsk", 2020, 9, 3, 14, 35, 2020, 9, 3, 18, 18);
	flights[2].FlightBuild(666, "Omsk", "Tyumen", 2010, 4, 20, 5, 40, 2010, 4, 20, 8, 55);
	flights[3].FlightBuild(401, "Barnaul", "Omsk", 2022, 11, 20, 14, 15, 2022, 11, 20, 19, 45);
	flights[4].FlightBuild(122, "Krasnoyarsk", "Tomsk", 2001, 2, 23, 6, 14, 2001, 2, 23, 10, 55);

	for (int i = 0; i < 5; i++) {
		cout << "\n "; flights[i].printNumber(); cout << "  "; flights[i].printStart(); cout << "-"; flights[i].printEnd(); cout << "  "
			<< " Flight "; flights[i].printTimeStartMonth(); cout << "."; flights[i].printTimeStartDay(); cout << "  " <<
			flights[i].getTimeStartHours() << ":" << flights[i].getTimeStartMinutes() << "   Arrival " <<
			flights[i].getTimeEndMonth() << "." << flights[i].getTimeEndDay() << "  " << flights[i].getTimeEndHours()
			<< ":" << flights[i].getTimeEndMinutes();
	}

	cout << endl;
	for (int i = 0; i < 5; i++) {
		flights[i].GetFlightTimeMinutes();
	}
}
