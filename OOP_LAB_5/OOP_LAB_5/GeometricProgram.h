#pragma once
#include "CollisionManager.h"

class GeometricProgram
{
public:
	void DemoCollision()
	{
		Rectangle rect1(0, 0, 2, 2);
		Rectangle rect2(1, 1, 2, 2);
		Rectangle rect3(5, 5, 14, 14);
		Rectangle rect4(6, 6, 2, 2);

		cout << "\nRectangle 1 and rectangle 2: ";
		cout << (CollisionManager::IsCollision(rect1, rect2) ? "Collision" : "No collision") << endl;

		cout << "\nRectangle 3 and rectangle 4: ";
		cout << (CollisionManager::IsCollision(rect3, rect4) ? "Collision" : "No collision") << endl;


		Ring ring1(0, 0, 2, 1);
		Ring ring2(2, 2, 1, 0.5);
		Ring ring3(5, 5, 22, 22);
		Ring ring4(8, 8, 2, 1);

		cout << "\nRing 1 and ring 2: ";
		cout << (CollisionManager::IsCollision(ring1, ring2) ? "Collision" : "No collision") << endl;

		cout << "\nRing 3 and ring 4: ";
		cout << (CollisionManager::IsCollision(ring3, ring4) ? "Collision" : "No collision") << endl;
	}

	void DemoRing()
	{
		cout << "\nNumber of rings before calling the constructor: " << Ring::GetAllRingsCount();

		Ring* ring1 = new Ring(15.2, 10.9, 6, 7);
		cout << "\nNumber of rings: " << Ring::GetAllRingsCount();
		Ring* ring2 = new Ring(48.7, 24.4, 420, 111);
		cout << "\nNumber of rings: " << Ring::GetAllRingsCount();
		Ring* ring3 = new Ring(98.1, 97.9, 47, 91);
		cout << "\nNumber of rings: " << Ring::GetAllRingsCount() << endl;

		cout << "Number of rings after calling the constructor: " << Ring::GetAllRingsCount() << endl;

		cout << "\nSquares:" << endl << ring1->GetArea() << endl << ring2->GetArea() << endl << ring3->GetArea() << endl;

		cout << "\nTrying to create a ring with an inner radius larger than the outer radius:";
		try {
			Ring ring4(10.5, 11.2, 18, 19);
			if (ring4.getInner() != 11.2) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nFailed to create this ring!";
		}

		cout << "\n\nTrying to create a negative ring:";
		try {
			Ring ring5(-90.3, -91.1, 11, 12);
			if (ring5.getOuter() != -90.3) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nFailed to create this ring!" << endl;
		}

		//ring1.AssertOnPositiveValue(ring1.getOuter());  // Error   // Task 4.2.3

		delete ring1; delete ring2; delete ring3;
		cout << "\nNumber of rings after calling the destructor: " << Ring::GetAllRingsCount();
	}

	void DemoRectangleWithPoint()
	{
		Rectangle rectangles[5];
		srand(time(0));

		for (int i = 0; i < 5; i++) {
			rectangles[i] = Rectangle(rand() / 100.0, rand() / 100.0, rand() / 100.0, rand() / 100.0);
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
};
