#pragma once
#include <exception>
#include "Point_Rectangle.h"

class Ring
{
private:
	static int AllRingsCount;
	double OuterRadius;
	double InnerRadius;
	Point CenterPoint;

public:
	Ring()
	{
		this->OuterRadius = 0;
		this->InnerRadius = 0;
		this->setCenterPoint(0, 0);
	}

	Ring(double Outer, double Inner, double x, double y)
	{
		setOuter(Outer);
		setInner(Inner);
		setCenterPoint(x, y);
		this->AllRingsCount++;
	}

	~Ring()
	{
		AllRingsCount--;
	}

	void setOuter(double Outer)
	{
		this->OuterRadius = Outer;
		try {
			bool positive = DoubleValidator::IsValuePositive(Outer);
			if (!positive) {
				throw exception();
			}
		}
		catch (exception) {
			this->OuterRadius = 0;
		}

		try {
			if (this->InnerRadius > Outer) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nException catched! Wrong value in Outer radius!";
			this->OuterRadius = 0;
		}
	}

	void setInner(double Inner)
	{
		this->InnerRadius = Inner;
		try {
			DoubleValidator::AssertPositiveValue(Inner);
		}
		catch (exception) {
			this->InnerRadius = 0;
		}

		try {
			if (Inner > this->OuterRadius) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nException catched! Wrong value in Inner radius!";
			this->InnerRadius = 0;
		}
	}

	void setCenterPoint(double x, double y) {
		Point newCenter(x, y);
		CenterPoint = newCenter;
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
		return CenterPoint.getX();
	}

	double getCenterY()
	{
		return CenterPoint.getY();
	}

	double GetArea()
	{
		const double pi = 3.14159265358979323846;
		double innerCircleArea = pi * InnerRadius * InnerRadius;
		double outerCircleArea = pi * OuterRadius * OuterRadius;
		return outerCircleArea - innerCircleArea;
	}

	static int GetAllRingsCount()
	{
		return AllRingsCount;
	}

	//private:
	//	double AssertOnPositiveValue(double& value)       // более не нужно
	//	{
	//		try {
	//			if (value < 0) {
	//				throw exception();
	//			}
	//		}
	//		catch (exception) {
	//			cout << "\nException catched! Value cannot be less than 0!";
	//			value = 0;
	//		}
	//		return 1;
	//	}
};
