#pragma once

#include <vector>

#include "Unit.h"

template <typename InternalType>
class Dimension {
public:
	Dimension<InternalType>(Unit<InternalType> standardUnit, InternalType standardUnitFactorToMinimalUnit)
	: standardUnitDim(DimensionedUnit<InternalType>(standardUnit, this, standardUnitFactorToMinimalUnit)),
	definedUnits(std::vector<DimensionedUnit<InternalType>>()) {
		
	}
private:
	std::vector<DimensionedUnit<InternalType>> definedUnits;
	DimensionedUnit<InternalType> standardUnitDim;
};

