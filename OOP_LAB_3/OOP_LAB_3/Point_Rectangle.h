#pragma once
#include <iostream>
#include <string>

using namespace std;


class Point {
public:
	double X;
	double Y;
};


class Rectangle {
private:
	double Length;
	double Width;
	Point CenterPoint;

public:
	Rectangle()
	{
		Length = Width = CenterPoint.X = CenterPoint.Y = 0;
	}

	Rectangle(double vLength,double vWidth,double X, double Y)
	{
		this->Length = vLength;
		this->Width = vWidth;
		this->CenterPoint.X = X;
		this->CenterPoint.Y = Y;
	}

	void setLength(double l) {
		if (l > 0)
			Length = l;
		else
			cout << "\nInvalid Length. Try set Length with value > 0.";
	}

	void setWidth(double w) {
		if (w > 0)
			Width = w;
		else
			cout << "\nInvalid Width. Try set Width with value > 0.";
	}

	void setCenterPoint(double x, double y) {
		CenterPoint.X = x;
		CenterPoint.Y = y;
	}

	double GetCenterPointX()
	{
		return CenterPoint.X;
	}

	double GetCenterPointY()
	{
		return CenterPoint.Y;
	}

	void Print()
	{
		cout << "\nLength = " << Length << ";  ";
		cout << "Width = " << Width << ";  ";
		cout << "X = " << CenterPoint.X << ";  ";
		cout << "Y = " << CenterPoint.Y << " ";
	}
};

void DemoRectangleWithPoint();