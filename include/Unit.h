#pragma once

#include <string>

//Forward declaration
template <typename InternalType>
class Dimension;
template <typename InternalType>
class DimensionedQuantity;

class Unit {
	//template <typename T>
	//friend class DimensionedUnit;
public:
	Unit(std::string unitSymbol)
	: unitSymbol(unitSymbol){

	}
	virtual std::string generateString(double quantity) const;
protected:
	std::string unitSymbol;

	
};

template <typename InternalType>
class DimensionedUnit {
	friend class Dimension<InternalType>;
	friend class DimensionedQuantity<InternalType>;
public:
	const Dimension<InternalType>& getDimension() const {
		return *dimension;
	}

	DimensionedQuantity<InternalType> generateQuantity(double amount) const;
private:
	DimensionedUnit<InternalType>(const Unit& unit, Dimension<InternalType>* dimension, InternalType factorToMinimumUnit) 
		: unit(unit), dimension(dimension), factorToMinimumUnit(factorToMinimumUnit)
	{

	}

	const Unit& unit;
	Dimension<InternalType>* dimension;
	InternalType factorToMinimumUnit;

	std::string generateString(const InternalType& quantity) const;
};

inline std::string Unit::generateString(double quantity) const {
	return std::to_string(quantity) + " " + unitSymbol;
}

template <typename InternalType>
inline std::string DimensionedUnit<InternalType>::generateString(const InternalType& quantity) const {
	return unit.generateString((double)quantity/(double)factorToMinimumUnit);
}

template<typename InternalType>
inline DimensionedQuantity<InternalType> DimensionedUnit<InternalType>::generateQuantity(double amount) const {
	InternalType amountInMinUnit = factorToMinimumUnit*amount;
	return DimensionedQuantity<InternalType>(*dimension, amountInMinUnit);
}