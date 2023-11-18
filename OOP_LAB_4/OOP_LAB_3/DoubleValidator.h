#pragma once
#include <iostream>
#include <string>

using namespace std;

static class DoubleValidator
{
public:
	static bool IsValuePositive(double value)
	{
		if (value >= 0) {
			return true;
		}
		return false;
	}

	static bool IsValueInRange(double value, double min, double max)
	{
		if (min <= value >= max) {
			return true;
		}
		return false;
	}

	static void AssertPositiveValue(double value)
	{
		bool positive = IsValuePositive(value);
		try {
			if (!positive) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nNumber cannot be negative!";
		}
	}

	static void AssertValueInRange(double value, double min, double max)
	{
		bool value_in_range = IsValueInRange(value, min, max);
		try {
			if (!value_in_range) {
				throw exception();
			}
		}
		catch (exception) {
			cout << "\nNumber out of range!";
		}
	}
};

