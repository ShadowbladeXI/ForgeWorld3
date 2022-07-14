#pragma once

#include "Unit.h"

template <typename SameDimensionQuantity, typename InternalType, typename BaseUnit, const auto& baseQuantity_unit> //SameDimensionQuantity is highest class which should be considered to save a quantity of the same dimension (addition should work for example)
class DimensionedQuantity {
	//TODO: Add stactic_assert to check that baseQuantity_unit is an instance of BaseUnit
	
public:


	//Construct zero valued dimensioned quantity
	DimensionedQuantity()
		: quantity(0)
	{}
	
	DimensionedQuantity(double amount, const BaseUnit& unit)
		: quantity(0)
	{
		//quantity = (amount*unit.inBaseUnit()) / (getBaseQuantity_amount()*getBaseQuantity_unit().inBaseUnit());
		quantity = (amount*unit.getInBaseUnit()) / (getBaseQuantity_amount()*baseQuantity_unit.getInBaseUnit());
	}

	//Discouraged to use outside of the package
	DimensionedQuantity(const InternalType& quantity)
		:quantity(quantity)
	{}

	//
	//String Representation and Parsing
	//
	std::string getString() const {
		return getString(this->getStandardUnit());
	}
	std::string getString(const BaseUnit& unit) const {
		double amount_baseUnit = this->quantity * (baseQuantity_unit.getInBaseUnit()*getBaseQuantity_amount());
		return unit.generateString_fromBaseUnitAmount(amount_baseUnit);
	}
	//Returns string representing this quantity, first in the dimensions standard unit and then in brackets in the minimal unit
	std::string toString() const {
		return getString() + " ("+std::to_string(quantity)+" *"+std::to_string(getBaseQuantity_amount())+baseQuantity_unit.getSymbol()+")";
	}

	//
	// Additive Inverse
	//
	SameDimensionQuantity operator+ () const {
		return SameDimensionQuantity(+quantity);
	}
	SameDimensionQuantity operator- () const {
		return SameDimensionQuantity(-quantity);
	}

	//
	// Addition and Subtraction
	//
	SameDimensionQuantity operator+ (const SameDimensionQuantity& other) const {
		return SameDimensionQuantity(quantity + other.quantity);
	}
	SameDimensionQuantity operator- (const SameDimensionQuantity& other) const {
		return SameDimensionQuantity(quantity - other.quantity);
	}

	//
	// Increment and Decrement
	//
	auto& operator+= (const SameDimensionQuantity& other) {
		quantity += other.quantity;
		return *this;
	}
	auto& operator-= (const SameDimensionQuantity& other) {
		quantity -= other.quantity;
		return *this;
	}

	//
	// Comparison
	//
	bool operator< (const SameDimensionQuantity& other) const {
		return quantity < other.quantity;
	}
	bool operator> (const SameDimensionQuantity& other) const {
		return quantity > other.quantity;
	}
	bool operator<= (const SameDimensionQuantity& other) const {
		return quantity <= other.quantity;
	}
	bool operator>= (const SameDimensionQuantity& other) const {
		return quantity >= other.quantity;
	}

	//
	// Division by same Dimension Qunatity
	//
	InternalType operator/ (const SameDimensionQuantity& other) const {
		return quantity/other.quantity;
	}//TODO: Maybe add double result version?
	InternalType operator% (const SameDimensionQuantity& other) const {
		return quantity%other.quantity;
	}//TODO: Maybe add variant for floating point internal types?

	//
	// Scalar Division
	//
	SameDimensionQuantity operator/ (const InternalType& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	SameDimensionQuantity operator/ (const double& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	SameDimensionQuantity operator/ (const float& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	
	//
	// Scalar Multiplication
	//
	SameDimensionQuantity operator* (const InternalType& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	//friend SameDimensionQuantity operator* (const InternalType& a, const DimensionedQuantity<SameDimensionQuantity, InternalType, BaseUnit, baseQuantity_unit>& b) {
	//	return SameDimensionQuantity(a*b.quantity);
	//}
	SameDimensionQuantity operator* (const double& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	//friend SameDimensionQuantity operator* (const double& a, const DimensionedQuantity<SameDimensionQuantity, InternalType, BaseUnit, baseQuantity_unit>& b) {
	//	return SameDimensionQuantity(a*b.quantity);
	//}
	SameDimensionQuantity operator* (const float& other) const {
		return SameDimensionQuantity(quantity/other);
	}
	//friend SameDimensionQuantity operator* (const float& a, const DimensionedQuantity<SameDimensionQuantity, InternalType, BaseUnit, baseQuantity_unit>& b) {
	//	return SameDimensionQuantity(a*b.quantity);
	//}

protected:
	InternalType quantity;//in getBaseQuantity_unit() times getBaseQuantity_amount()

	//For subclasses to override to define their base quantity. In case of integer internal type, this is the minimal quantity.
	//virtual constexpr const BaseUnit& getBaseQuantity_unit() const = 0;
	virtual constexpr const double getBaseQuantity_amount() const {
		return 1.0;
	}

	//Returns the standard unit for displaying the value (base unit by default)
	virtual constexpr const BaseUnit& getStandardUnit() const{
		return baseQuantity_unit;
	}

};