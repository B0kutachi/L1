#include "Book.h"
#include "Route.h"
#include "Point_Rectangle.h"
#include "Time_Flight.h"
#include "Music.h"
#include "Ring.h"


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

void Breakpoints6()
{
	DemoRing();
}

int main()
{
	int x = 0;
	cout << "\nEnter the case: ";
	cin >> x;
	switch (x) {
	case 1:
		Breakpoints1(); 
		break;
	case 2:
		Breakpoints2();  
		break;
	case 3:
		Breakpoints3(); 
		break;
	case 4:
		Breakpoints4();
		break;
	case 5:
		Breakpoints5();   
		break;
	case 6:
		Breakpoints6();
		break;
	default:
		cout << "Invalid value. Try again.";
	}

	cout << endl << endl;
	return 0;
}

