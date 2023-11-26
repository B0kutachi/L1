#include "Product.h"

void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount)
{
	double fullcost = 0;
	for (int i = 0; i < productsCount; i++) {
		cout << products[i].getName() << "\t";
		cout << "Old cost: " << products[i].getCost();
		if (products[i].getCategory() == discount->getCategory()) {
			products[i].setCost(discount->Calculate(&products[i]));
		}
		cout << "\tNew cost: " << products[i].getCost() << endl;
		fullcost += products[i].getCost();
	}
	cout << "Full cost with discount: " << fullcost << endl;
}