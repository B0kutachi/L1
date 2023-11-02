#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include "Point_Rectangle.h"

using namespace std;

class Ring
{
private:
	double OuterRadius;
	double InnerRadius;
	Point CenterPoint;

public:
	Ring()
	{
		this->OuterRadius = 0;
		this->InnerRadius = 0;
		this->CenterPoint.X = 0;
		this->CenterPoint.Y = 0;
	}

	Ring(double Outer, double Inner, double x, double y)
	{
		this->OuterRadius = Outer;
		this->InnerRadius = Inner;
		this->CenterPoint.X = x;
		this->CenterPoint.Y = y;
	}

	void setOuter(double Outer)
	{
		if (Outer <= 0 || Outer < this->InnerRadius) {
			throw exception();
		}

		this->OuterRadius = Outer;
	}

	void setInner(double Inner)
	{
		if (Inner <= 0 || Inner > this->OuterRadius) {
			throw exception();
		}

		this->InnerRadius = Inner;
	}

	void setCenterX(double x)
	{
		this->CenterPoint.X = x;
	}

	void setCenterY(double y)
	{
		this->CenterPoint.Y = y;
	}

	double getOuter()
	{
		return OuterRadius;
	}

	double getInner()
	{
		return InnerRadius;
	}

	double getCenterX()
	{
		return CenterPoint.X;
	}

	double getCenterY()
	{
		return CenterPoint.Y;
	}

	double GetArea()
	{
		const double pi = 3.14159265358979323846;
		double innerCircleArea = pi * InnerRadius * InnerRadius;
		double outerCircleArea = pi * OuterRadius * OuterRadius;
		return outerCircleArea - innerCircleArea;
	}
};

void DemoRing();