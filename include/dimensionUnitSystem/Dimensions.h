#pragma once

#include "DimensionedQuantity.h"
#include "Units.h"

typedef long InternalType;

class Length : public DimensionedQuantity<Length, InternalType, Unit_Abstract<MeterBase>, meter> {
	Length()
		: DimensionedQuantity<Length, InternalType, Unit_Abstract<MeterBase>, meter>()
	{}

	Length(double amount, const Unit_Abstract<MeterBase>& unit)
		: DimensionedQuantity<Length, InternalType, Unit_Abstract<MeterBase>, meter>(amount, unit)
	{}

	Length(InternalType quantity)
		: DimensionedQuantity<Length, InternalType, Unit_Abstract<MeterBase>, meter>(quantity)
	{}
};

class Mass : public DimensionedQuantity<Mass, InternalType, Unit_Abstract<GrammBase>, gramm> {
public:

	Mass()
		: DimensionedQuantity<Mass, InternalType, Unit_Abstract<GrammBase>, gramm>()
	{}

	Mass(double amount, const Unit_Abstract<GrammBase>& unit)
		: DimensionedQuantity<Mass, InternalType, Unit_Abstract<GrammBase>, gramm>(amount, unit)
	{}

	Mass(InternalType quantity)
		: DimensionedQuantity<Mass, InternalType, Unit_Abstract<GrammBase>, gramm>(quantity)
	{}
};
