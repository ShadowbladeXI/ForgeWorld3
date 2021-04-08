#include "../include/ResourceManager.h"

#include <string>

ResourceManager::ResourceManager(const ResourceList& resourceList) 
	: resourceQuantityList(std::vector<ResourceQuantity<ResourcesInternalType>>()) 
{
	resourceQuantityList.reserve(resourceList.getSize());

	for(int i = 0; i < resourceList.getSize(); i++) {
		const Dimension<ResourcesInternalType>& dimension = resourceList.get(i).getDimension();
		ResourceQuantity<ResourcesInternalType>* newResourceQuantity = new ResourceQuantity<ResourcesInternalType>(resourceList.get(i), DimensionedQuantity<ResourcesInternalType>(dimension));
		resourceQuantityList.push_back(*newResourceQuantity);
	}

	resourceQuantityList.shrink_to_fit();//TODO: Check if this is necessary (due to reserve at the beginning)
}

const ResourceQuantity<ResourcesInternalType>& ResourceManager::get(size_t i) const{
	return resourceQuantityList[i];
}

ResourceManagerReturn ResourceManager::add(size_t i, const ResourceQuantity<ResourcesInternalType>& toAdd) {
	ResourceQuantity<ResourcesInternalType>& resource = resourceQuantityList.at(i);
	if(resource.getQuantity() < -toAdd.getQuantity()) {
		return ResourceManagerReturn::errorNotEnoughResources;
	} else {
		resource += toAdd;
		return ResourceManagerReturn::success;
	}
}

void ResourceManager::printResourceQuantities() const {

	for(size_t i = 0; i < resourceQuantityList.size(); i++) {


		std::cout << "n" << std::to_string(i) << ", " << resourceQuantityList[i].getResource().getName() << resourceQuantityList[i].getQuantity().toString() << std::endl;
		//std::cout << "n"+std::to_string(i)+", "+resourceQuantityList[i].getResource().getName()+": "+resourceQuantityList[i].getQuantity().toString();
	}
}
