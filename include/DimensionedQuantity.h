#pragma once

#include <string>
#include <iostream>
#include <assert.h>

#include "Dimension.h"

template <typename InternalType>
class DimensionedQuantity {
public:
	DimensionedQuantity(const Dimension<InternalType>& dimension) 
		: dimension(dimension)
		, quantity(0)
	{

	}
	DimensionedQuantity(const Dimension<InternalType>& dimension, InternalType quantity)
		: dimension(dimension)
		, quantity(quantity) 	
	{

	}

	std::string getString() const {
		return getString(dimension.getStandardDimensionedUnit());
	}
	std::string getString(const DimensionedUnit<InternalType>& unit) const {
		assert(&unit.getDimension() == &dimension);
		return unit.generateString(quantity);
	}
	//Returns string representing this quantity, first in the dimensions standard unit and then in brackets in the minimal unit
	std::string toString() const {
		return getString() + " ("+std::to_string(quantity)+")";
	}

	const Dimension<InternalType>& getDimension() {
		return dimension;
	}

	DimensionedQuantity<InternalType> operator+ () const {
		return DimensionedQuantity<InternalType>(dimension, +quantity);
	}
	DimensionedQuantity<InternalType> operator- () const {
		return DimensionedQuantity<InternalType>(dimension, -quantity);
	}
	DimensionedQuantity<InternalType> operator+ (const DimensionedQuantity<InternalType>& b) const {
		assert(&dimension == &b.dimension);
		return DimensionedQuantity<InternalType>(dimension, quantity+b.quantity);
	}
	DimensionedQuantity<InternalType> operator- (const DimensionedQuantity<InternalType>& b) const {
		assert(&dimension == &b.dimension);
		return DimensionedQuantity<InternalType>(dimension, quantity-b.quantity);
	}
	DimensionedQuantity<InternalType>& operator+= (const DimensionedQuantity<InternalType>& b) {
		assert(&dimension == &b.dimension);
		quantity += b.quantity;
		return *this;
	}
	DimensionedQuantity<InternalType>& operator-= (const DimensionedQuantity<InternalType>& b) {
		assert(&dimension == &b.dimension);
		quantity -= b.quantity;
		return *this;
	}
	bool operator< (const DimensionedQuantity<InternalType>& b) const {		
		assert(&dimension == &b.dimension);
		return quantity < b.quantity;
	}
	bool operator> (const DimensionedQuantity<InternalType>& b) const {
		assert(&dimension == &b.dimension);
		return quantity > b.quantity;
	}
	bool operator<= (const DimensionedQuantity<InternalType>& b) const {
		assert(&dimension == &b.dimension);
		return quantity <= b.quantity;
	}
	bool operator>= (const DimensionedQuantity<InternalType>& b) const {
		assert(&dimension == &b.dimension);
		return quantity >= b.quantity;
	}

private:
	const Dimension<InternalType>& dimension;
	InternalType quantity;
};

