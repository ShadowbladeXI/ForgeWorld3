#pragma once

#include <vector>
#include <string>

#include "Unit.h"

template <typename InternalType>
class Dimension {
public:
	Dimension<InternalType>(const Unit& standardUnit, InternalType standardUnitFactorToMinimalUnit)
		: standardUnitDim(DimensionedUnit<InternalType>(standardUnit, this, standardUnitFactorToMinimalUnit))
		,definedUnits(std::vector<DimensionedUnit<InternalType>>()) 
	{
		
	}

	const DimensionedUnit<InternalType>& getStandardDimensionedUnit () const{
		return standardUnitDim;
	}
	
private:
	std::vector<DimensionedUnit<InternalType>> definedUnits;
	DimensionedUnit<InternalType> standardUnitDim;
};

