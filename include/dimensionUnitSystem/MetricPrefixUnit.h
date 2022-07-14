#pragma once

#include <string>
#include <tuple>
#include <unordered_map>
#include <memory>


#include "Unit.h"

template<typename BaseUnitClass>
class MetricPrefixUnit {

public:
	MetricPrefixUnit(const std::string& anchorUnit_name, const std::string& anchorUnit_symbol) {

		BaseUnitClass baseUnit(anchorUnit_name, anchorUnit_symbol);

		for (auto prefixInfo : prefixMap) {
			double prefixFactor = std::get<0>(prefixInfo);

			auto prefixNameAndSymbol = std::get<1>(prefixInfo);
			std::string prefixName = std::get<0>(prefixNameAndSymbol);
			std::string prefixSymbol = std::get<1>(prefixNameAndSymbol);

			auto newUnit = new DerivedUnit<BaseUnitClass>(prefixName+anchorUnit_name, prefixSymbol+anchorUnit_symbol);
			unitsWithPrefixMap.insert({prefixName, std::unique_ptr<DerivedUnit>(newUnit)});
		}
	}

protected:
	static const std::unordered_map<double, std::tuple<std::string, std::string>> prefixMap = {
		{1.0e3, {"kilo", "k"}},
		{1.0e6, {"mega", "M"}}
	};

	const std::unordered_map<std::string, Unit<BaseUnitClass>*> unitsWithPrefixMap;

};