#include "..\include\ResourceList.h"

ResourceList::ResourceList(const ResourceFileHandler& resFileHandler)
	: list(std::vector<ResourceType_Abstract*>())
	//, units()
	//, dimensions()
{
	//MetricUnit gramm("g");
	//Dimension<ResourcesInternalType> mass(gramm, 1000000);//Initialize mass dimension with ug as smalles unit)$
	//DimensionedUnit<ResourcesInternalType> massGramm(mass.getStandardDimensionedUnit());
	
	//TODO: Add capacity reserve for "list"
	
	resFileHandler.getAllResources_fromFiles(list);
	
	resourceIDs = std::unordered_map<std::string, size_t>();
	for (int i = 0; i<list.size(); ++i) {
		const ResourceType_Abstract* resType(list.at(i));
		auto insertRes = resourceIDs.insert(std::pair(resType->getName(), i));
		if (!insertRes.second) {
			//Could not insert element
			//TODO: Insert code for error handling
		}
	}
}

size_t ResourceList::getSize() const{
	return list.size();
}

const ResourceType_Abstract& ResourceList::get(size_t i) const {
	return *list[i];
}

const size_t ResourceList::getResourceID_byName(std::string resourceName) const{
	return resourceIDs.find(resourceName)->second;
}

const ResourceType_Abstract& ResourceList::getResource_byName(std::string resourceName) const{
	return get(getResourceID_byName(resourceName));
}

std::unique_ptr<Resource_Abstract> ResourceList::generateNewResource(size_t index) const{
	return list.at(index)->createNewResource();
}

ResourceQuantity<Mass> ResourceList::generateNewResource(size_t i, Mass mass) const {
	const auto& resourceType = dynamic_cast<const ResourceType<Mass>&>(get(i));//TODO: Replace with assert + static cast for speed in production version?
	return ResourceQuantity<Mass>(resourceType, mass);
}

ResourceList::~ResourceList() {
	for(size_t i = 0; i<list.size(); ++i) {
		delete list[i];
	}
}
