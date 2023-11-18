#pragma once
#include "DoubleValidator.h"

class Point {
private:
	double X;
	double Y;

public:
	Point()
	{
		this->X = 0;
		this->Y = 0;
	}

	Point(double x, double y)
	{
		this->X = x;
		this->Y = y;
	}

	double getX()
	{
		return this->X;
	}

	double getY()
	{
		return this->Y;
	}
};


class Rectangle {
private:
	double Length;
	double Width;
	Point CenterPoint;

public:
	Rectangle()
	{
		Length = Width = 0;
		setCenterPoint(0, 0);
	}

	Rectangle(double vLength, double vWidth, double X, double Y)
	{
		this->setLength(vLength);
		this->setWidth(vWidth);
		this->setCenterPoint(X, Y);
	}

	void setLength(double l) {
		try {
			DoubleValidator::AssertPositiveValue(l);
		}
		catch (exception) {
		}
		this->Length = l;
	}

	void setWidth(double w) {
		try {
			DoubleValidator::AssertPositiveValue(w);
		}
		catch (exception) {
		}
		this->Width = w;
	}

	void setCenterPoint(double x, double y) {
		Point newCenter(x, y);
		CenterPoint = newCenter;
	}

	double GetCenterPointX()
	{
		return CenterPoint.getX();
	}

	double GetCenterPointY()
	{
		return CenterPoint.getY();
	}

	void Print()
	{
		cout << "\nLength = " << Length << ";  ";
		cout << "Width = " << Width << ";  ";
		cout << "X = " << CenterPoint.getX() << ";  ";
		cout << "Y = " << CenterPoint.getY() << " ";
	}
};

