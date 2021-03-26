#include "..\include\MetricUnit.h"

#include <algorithm>
#include <cmath>

MetricUnit::MetricUnit(std::string unitBaseString) 
	:Unit(unitBaseString)
{

}

//TODO: Might need replacement with higher performance
std::string MetricUnit::generateString(double quantity) const {
	double exp1000 = floor(std::log10(quantity)/3);//exponent of 1000 such that the remaining multiplyer is between 1 and 1000
	double exp1000inRange = std::min(std::max(exp1000, min1000Exp), max1000Exp);//exponent which lies within the region where prefixes are defined
	
	return std::to_string(quantity/std::pow(1000, exp1000inRange)) + " " + prefixMap.at(exp1000inRange) + unitSymbol;
}

//first entry is the 1000 exponent, the secon one the corresponding prefix
const std::unordered_map<double, std::string> MetricUnit::prefixMap = {
	{6, "E"},
	{5, "P"},
	{4, "T"},
	{3, "G"},
	{2, "M"},
	{1, "k"},
	{0, ""},
	{-1, "m"},
	{-2, "\u03BC"},
	{-3, "n"},
	{-4, "p"},
	{-5, "f"},
	{-6, "a"}
};

//Initialize with lambda functions
const double MetricUnit::min1000Exp = []() -> double {
	double min = (*(prefixMap.cbegin())).first;
	for(auto it = ++prefixMap.begin(); it != prefixMap.end(); ++it) {
		min = std::min((*it).first, min);
	}
	return min;
}();
const double MetricUnit::max1000Exp = []() -> double {
	double max = (*(prefixMap.cbegin())).first;
	for(auto it = ++prefixMap.begin(); it != prefixMap.end(); ++it) {
		max = std::max((*it).first, max);
	}
	return max;
}();