#include "..\include\ResourceList.h"

ResourceList::ResourceList() 
	: kilogramm(Unit<ResourcesInternalType>("kg"))
	, mass(Dimension<ResourcesInternalType>(kilogramm, 1000000))//Initialize mass dimension with mg as smalles unit)$
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
