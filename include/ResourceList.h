#pragma once

#include <vector>
#include <iterator>

#include "MetricUnit.h"
#include "Dimension.h"
#include "Resource.h"
#include "ResourceQuantity.h"

typedef long ResourcesInternalType;//Specify the internal type used for all resources
class ResourceList {
public:
	ResourceList();

	size_t getSize() const;
	const Resource<ResourcesInternalType>& get(size_t) const;
	ResourceQuantity<ResourcesInternalType> generateNewResource(size_t, DimensionedQuantity<ResourcesInternalType>) const;

	~ResourceList();
private:
	std::vector<Resource<ResourcesInternalType>*> list;

private:
	MetricUnit gramm;
	Dimension<ResourcesInternalType> mass;
public:
	const DimensionedUnit<ResourcesInternalType>& massGramm;
};

