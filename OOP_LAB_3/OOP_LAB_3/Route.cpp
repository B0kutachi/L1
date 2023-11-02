#include "Route.h"


int DemoRoute() {
	const int size = 3;
	Route route[size];
	for (int i = 0; i < size; i++) {
		cout << "\nEnter the route #" << i + 1 << ": ";
		ReadRouteFromConsole(route[i]);
	}
	for (int i = 0; i < size; i++) {
		cout << "\nThe route #" << i + 1 << ": ";
		WriteRouteToConsole(route[i]);
	}

	string stop;
	cout << "\nEnter the stop you want to find: ";
	getline(cin, stop);

	FindRouteTo(route, size, stop, route->AmountStops);

	return 0;
}

int ReadRouteFromConsole(Route& route)
{
	cout << "\nEnter the route number: ";
	cin >> route.Number;

	cout << "\nEnter the average duration of the route: ";
	cin >> route.Duration;
	while (route.Duration < 1 ) {
		cout << "\nInvalid avg duration. Enter avg duration(0+): ";
		cin >> route.Duration;
	}

	cout << "\nEnter the average frequency: ";
	cin >> route.Frequency;
	while (route.Frequency < 1) {
		cout << "\nInvalid frequency. Enter average frequency(0+): ";
		cin >> route.Frequency;
	}

	cout << "\nEnter amount of bus stops: ";
	cin >> route.AmountStops;
	while (route.AmountStops < 1 || route.AmountStops > 10)
	{
		cout << "\nInvalid amount. Enter amount of bus stops(1-10): ";
		cin >> route.AmountStops;
	}

	cin.ignore();
	for (int i = 0; i < route.AmountStops; i++) {
		cout << "\nEnter bus stop #" << i + 1 << ": ";
		getline(cin, route.Stops[i]);
	}

	cout << endl;
	return 0;
}

int WriteRouteToConsole(Route& route)
{
	cout << "\nRoute #" << route.Number << " have avg duration " << route.Duration << " min "
		<< "and avg frequency " << route.Frequency << "min. " << "This route has " << route.AmountStops
		<< " stops: " << endl;
	for (int i = 1; i < route.AmountStops; i++) {
		cout << route.Stops[i - 1] << ", ";
		if (i + 1 == route.AmountStops) {
			cout << route.Stops[i] << ".";
		}
	}

	cout << endl;
	return 0;
}

int FindRouteTo(Route* routes, int routeCount, string stop, int stopCount)
{
	for (int i = 0; i < routeCount; i++) 
	{
		Route* route = &routes[i];
		for (int j = 0; j < stopCount; j++)
		{
			if (route->Stops[j] == stop)
			{
				cout << "\nFounded route is ";
				WriteRouteToConsole(routes[i]);
				return 0;
			}
		}
	}
	cout << "\nThere's no route with that stop.";
	return -1;
}