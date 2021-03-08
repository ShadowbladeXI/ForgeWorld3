#pragma once

#include <string>
#include <iostream>

#include "Dimension.h"

template <typename InternalType>
class DimensionedQuantity {
public:
	DimensionedQuantity(const Dimension<InternalType>& dimension) 
		: dimension(dimension)
		, quantity(0)
	{

	}

	//Returns string representing this quantity, first in the dimensions standard unit and then in brackets in the minimal unit
	std::string toString() const {
		return " ("+std::to_string(quantity)+")";//TODO: Add string for standard unit
	}

	const Dimension<InternalType>& getDimension() {
		return dimension;
	}
private:
	const Dimension<InternalType>& dimension;
	InternalType quantity;
};

