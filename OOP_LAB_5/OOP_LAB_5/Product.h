#pragma once
#include <iostream>
#include <string>

using namespace std;

enum CategoryType
{
	fake = 0,
	TV,
	Micromax,
	Pantum,
	HP
};

class Product
{
	string Name;
	CategoryType Category;
	double Cost;

public:
	Product() {
		Name = " ";
		Category = fake;
		Cost = 0.0;
	}

	Product(string name, CategoryType category, double cost) {
		setName(name);
		setCategory(category);
		setCost(cost);
	}

	void setName(string name) {
		this->Name = name;
	}

	void setCategory(CategoryType category) {
		this->Category = category;
	}

	void setCost(double cost) {
		if (cost < 0)
			cout << "\nCost can't be negative!";
		if (cost > 100000)
			cout << "\nCost can't exceed 100,000!";
		this->Cost = cost;
	}

	string getName() {
		return this->Name;
	}

	CategoryType getCategory() {
		return this->Category;
	}

	double getCost() {
		return this->Cost;
	}

};

class DiscountBase
{
	CategoryType _category;
	void setCategory(CategoryType category) { this->_category = category; }
protected:
	//DiscountBase() { _category = name1; }
	DiscountBase(CategoryType category) { setCategory(category); }

public:
	CategoryType getCategory() { return this->_category; }
	double virtual Calculate(Product* product) = 0;
};

class PercentDiscount : public DiscountBase
{
	int _percent;
public:
	//PercentDiscount() : DiscountBase() { _percent = 0; }
	PercentDiscount(CategoryType category, int percent) : DiscountBase(category), _percent(percent) {}

	void setPercent(int percent) { this->_percent = percent; }
	int getPercent() { return this->_percent; }
	
	double Calculate(Product* product) override
	{
		if (product->getCategory() == this->getCategory()) {
			double pdiscount = (100 - _percent) / 100.0;
			double newcost = product->getCost() * pdiscount;
			product->setCost(newcost);
		}
		return product->getCost();
	}
};

class CertificateDiscount : public DiscountBase
{
	double _amount;
public:
	CertificateDiscount(CategoryType category, double amount) : DiscountBase(category) 
	{
		setAmount(amount);
	}

	void setAmount(double amount) {
		if (amount < 0)
			cout << "\nAmount can't be negative!";
		if (amount > 10000)
			cout << "\nCost can't exceed 10,000!";
		this->_amount = amount;
	}
	double getAmount() { return this->_amount; }

	double Calculate(Product* product) override
	{
		if (product->getCategory() == this->getCategory()) {
			if (_amount < product->getCost()) {
				double newcost = product->getCost() - _amount;
				product->setCost(newcost);
				this->_amount = 0;
			}
			if (_amount == product->getCost()) {
				product->setCost(0);
				this->_amount = 0;
			}
			if (_amount > product->getCost()) {
				double newamount = _amount - product->getCost();
				product->setCost(0);
				setAmount(newamount);
			}
		}
		return product->getCost();
	}
};

void ShowCheckWithDiscount(DiscountBase* discount, Product* products, int productsCount);