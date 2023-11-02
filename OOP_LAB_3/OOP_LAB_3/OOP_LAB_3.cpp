#include "Book.h"
#include "Route.h"
#include "Point_Rectangle.h"
#include "Time_Flight.h"
#include "Music.h"


void Breakpoints1()
{
	DemoBook();
}

void Breakpoints2()
{
	DemoRoute();
}

void Breakpoints3()
{
	DemoRectangleWithPoint();
}

void Breakpoints4()
{
	DemoFlightWithTime();
	
	cout << endl << endl;
	Flight flight;
	FlightBuild(flight);
}

void Breakpoints5()
{
	DemoBand();
}

int main()
{
	int x = 0;
	cout << "\nEnter the case: ";
	cin >> x;
	switch (x) {
	case 1:
		Breakpoints1();   // Tasks #3.2.1 - 3.2.5
		break;
	case 2:
		Breakpoints2();   // Task #3.2.6
		break;
	case 3:
		Breakpoints3();   // Tasks #3.3.1 - 3.3.5
		break;
	case 4:
		Breakpoints4();   // Tasks 3.3.7 - 3.3.11
		break;
	case 5:
		Breakpoints5();   // Tasks 3.4.1 - 3.4.6
		break;
	default:
		cout << "Invalid value. Try again.";
	}

	cout << endl << endl;
	return 0;
}

