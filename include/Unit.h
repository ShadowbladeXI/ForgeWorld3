#pragma once

#include <string>

//Forward declaration
template <typename InternalType>
class Dimension;

template <typename InternalType>
class Unit {
public:
	Unit<InternalType>(std::string unitSymbol)
	: unitSymbol(unitSymbol){

	}
private:
	std::string unitSymbol;

	std::string generateString(InternalType quantity);
};

template <typename InternalType>
class DimensionedUnit {
	template <typename T>
	friend class Dimension;
private:
	DimensionedUnit<InternalType>(Unit<InternalType>unit, Dimension<InternalType>* dimension, InternalType factorToMinimumUnit) 
	: unit(unit), dimension(dimension), factorToMinimumUnit(factorToMinimumUnit){

	}
	Unit<InternalType> unit;
	Dimension<InternalType>* dimension;
	InternalType factorToMinimumUnit;
};

template<typename InternalType>
inline std::string Unit<InternalType>::generateString(InternalType quantity) {
	return std::to_string(quantity) + " " + unitSymbol;
}