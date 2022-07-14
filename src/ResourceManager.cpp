#include "../include/ResourceManager.h"

#include <string>

ResourceManager::ResourceManager(const ResourceList& resourceList) 
	: resourceList(resourceList)
	, resourceQuantityList(std::vector<std::unique_ptr<Resource_Abstract>>()) 
{
	resourceQuantityList.reserve(resourceList.getSize());

	for(std::size_t i = 0; i < resourceList.getSize(); i++) {
		//const Dimension<ResourcesInternalType>& dimension = resourceList.get(i).getDimension();
		auto newResourceQuantity_ptr = resourceList.generateNewResource(i);
		resourceQuantityList.push_back(std::move(newResourceQuantity_ptr));
	}

	resourceQuantityList.shrink_to_fit();//TODO: Check if this is necessary (due to reserve at the beginning)
}

const Resource_Abstract& ResourceManager::get(size_t i) const{
	return *resourceQuantityList.at(i);
}

const Resource_Abstract& ResourceManager::getResource_byName(std::string resourceName) const {
	return get(resourceList.getResourceID_byName(resourceName));
}

ResourceManagerReturn ResourceManager::add(size_t i, const Resource_Abstract& toAdd) {
	//TODO: Maybe replace by assert+static cast?
	ResourceQuantity<Mass>& resource = dynamic_cast<ResourceQuantity<Mass>&>(*resourceQuantityList.at(i));
	const ResourceQuantity<Mass>& toAdd_Specified = dynamic_cast<const ResourceQuantity<Mass>&>(toAdd);


	if(resource.getQuantity() < -toAdd_Specified.getQuantity()) {
		return ResourceManagerReturn::errorNotEnoughResources;
	} else {
		resource += toAdd_Specified;
		return ResourceManagerReturn::success;
	}
}

void ResourceManager::printResourceQuantities() const {

	for(size_t i = 0; i < resourceQuantityList.size(); i++) {
		std::cout << "n" << std::to_string(i) << ", " << resourceQuantityList.at(i)->toString() << std::endl;
		//std::cout << "n"+std::to_string(i)+", "+resourceQuantityList[i].getResource().getName()+": "+resourceQuantityList[i].getQuantity().toString();
	}
}
