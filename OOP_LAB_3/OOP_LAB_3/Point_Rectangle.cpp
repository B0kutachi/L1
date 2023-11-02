#include "Point_Rectangle.h"


void DemoRectangleWithPoint()
{
	Rectangle rectangles[5];
	srand(time(0));

	for (int i = 0; i < 5; i++) {
		rectangles[i] = Rectangle(rand()/100.0, rand()/100.0, rand()/100.0, rand()/100.0);
	}

	for (int i = 0; i < 5; i++) {
		rectangles[i].Print();
	}

	double Xcenter = 0, Ycenter = 0;
	for (int i = 0; i < 5; i++) {
		Xcenter += rectangles[i].GetCenterPointX();
		Ycenter += rectangles[i].GetCenterPointY();
	}
	Xcenter /= 5;
	Ycenter /= 5;

	cout << "\n\nXcenter = " << Xcenter << ";  " << "Ycenter = " << Ycenter;

}


// Task 3.3.6:
// 
// + -----------------+
// |   <<struct>>     |
// |    Rectangle     |
// +------------------+
// | Length: double   |
// | Width: double    |
// | CenterPoint:     +----------------+
// +------------------+				   |
//									  _|_
//									  \ /
//				   			  +-----------------+
//							  |    <<struct>>   |
//							  |      Point      |
//							  +-----------------+
//							  | X: double       |
//							  | Y: double       |
//							  +-----------------+

//	����� ����� �����������:
//	���������: ��������� Rectangle �������� ������ ��������� Point � ����� ������� (Rectangle ���������� Point) (����� ���� � ������)
//	���������: ���� Rectangle ����� ���� Point � �������� ����� CenterPoint

