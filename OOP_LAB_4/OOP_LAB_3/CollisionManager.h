#pragma once
#include "Point_Rectangle.h"
#include "Ring.h"
#include <cmath>

static class CollisionManager
{
public:
	static bool IsCollision(Rectangle& rect1, Rectangle& rect2)
	{
		double rect1_half_width = rect1.GetCenterPointX() / 2;
		double rect2_half_width = rect2.GetCenterPointX() / 2;
		double rect1_half_height = rect1.GetCenterPointY() / 2;
		double rect2_half_height = rect2.GetCenterPointY() / 2;

		double diff_x = abs(rect1.GetCenterPointX() - rect2.GetCenterPointX());
		double diff_y = abs(rect1.GetCenterPointY() - rect2.GetCenterPointY());

		if ((diff_x < (rect1_half_width + rect2_half_width)) && (diff_y < (rect1_half_height + rect2_half_height))) {
			return true;
		}
		return false;
	}

	static bool IsCollision(Ring& ring1, Ring& ring2)
	{
		double dX = ring2.getCenterX() - ring1.getCenterX();
		double dY = ring2.getCenterY() - ring1.getCenterY();

		double distance = sqrt(dX * dX + dY * dY);

		double sumOuter = ring1.getOuter() + ring2.getOuter();

		if (distance < sumOuter) {
			return true;
		}
		return false;
	}
};
