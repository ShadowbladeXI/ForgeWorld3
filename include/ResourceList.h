#pragma once

#include <vector>

#include "Unit.h"
#include "Dimension.h"
#include "Resource.h"

typedef long ResourcesInternalType;//Specify the internal type used for all resources
class ResourceList {
public:
	ResourceList();

	size_t getSize() const;
	const Resource<ResourcesInternalType>& get(size_t) const;
private:
	Unit<ResourcesInternalType> kilogramm;
	Dimension<ResourcesInternalType> mass;
	std::vector<Resource<ResourcesInternalType>> list;
};

