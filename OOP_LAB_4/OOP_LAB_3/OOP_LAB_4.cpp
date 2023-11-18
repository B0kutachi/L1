#include "Book.h"
#include "Route.h"
#include "Time_Flight.h"
#include "Music.h"
#include "GeometricProgram.h"

GeometricProgram GProgram;

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
	GProgram.DemoRectangleWithPoint();
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
	GProgram.DemoRing();
}

void Breakpoints7()
{
	GProgram.DemoCollision();
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
		Breakpoints5(); // Tasks 4.1.1 - 4.1.3
		break;
	case 6:
		Breakpoints6(); // Tasks 4.1.4 - 4.1.6 - 4.2.3 - 4.3.3 - 4.4.7
		break;
	case 7:
		Breakpoints7(); // Tasks 4.5.1 - 4.5.7
		break;
	default:
		cout << "Invalid value. Try again.";
	}
	cout << endl << endl;
	return 0;
}

