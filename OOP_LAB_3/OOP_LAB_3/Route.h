#pragma once
#include <iostream>
#include <string>

using namespace std;

class Route {
public:
	int Number;
	int Duration;
	int Frequency;
	int AmountStops;
	string Stops[10];
};

int DemoRoute();

int ReadRouteFromConsole(Route& route);

int WriteRouteToConsole(Route& route);

int FindRouteTo(Route* routes, int routeCount, string stop, int stopCount);