#pragma once

#include "Dimension.h"

template<typename InternalType>
class Quantity {
public:

private:
	Dimension<InternalType> dimension;
	InternalType value;

};

