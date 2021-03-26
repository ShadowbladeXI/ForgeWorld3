#pragma once

#include "Unit.h"

#include <unordered_map>

class MetricUnit : public Unit {
public:
	MetricUnit(std::string unitBaseString);
	std::string generateString(double quantity) const;

private:
	//use doubles to avoid conversion later (only integer double values are used)
	static const std::unordered_map<double, std::string> prefixMap;
	static const double min1000Exp;
	static const double max1000Exp;
};

