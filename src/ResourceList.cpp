#include "..\include\ResourceList.h"

ResourceList::ResourceList() 
	: gramm(MetricUnit("g"))
	, mass(Dimension<ResourcesInternalType>(gramm, 1000))//Initialize mass dimension with mg as smalles unit)$
	, massGramm(mass.getStandardDimensionedUnit())
	, list(std::vector<Resource<ResourcesInternalType>>())
{
	//TODO: Add capacity reserve for "list"
	
	//HACK: Test initialization with some example resources
	list.push_back(*(new Resource<ResourcesInternalType>("Coal", mass)));
	list.push_back(*(new Resource<ResourcesInternalType>("Iron", mass)));
	list.push_back(*(new Resource<ResourcesInternalType>("Steel", mass)));

	list.shrink_to_fit();
	
}

size_t ResourceList::getSize() const{
	return list.size();
}

const Resource<ResourcesInternalType>& ResourceList::get(size_t i) const {
	return list[i];
}

ResourceQuantity<ResourcesInternalType> ResourceList::generateNewResource(size_t i, DimensionedQuantity<ResourcesInternalType> quantity) const {
	return ResourceQuantity<ResourcesInternalType>(get(i), quantity);
}
