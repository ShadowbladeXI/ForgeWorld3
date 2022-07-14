#pragma once

#include <vector>
#include <iterator>
#include <memory>

#include "dimensionUnitSystem/Dimensions.h"
#include "ResourceType.h"
#include "ResourceQuantity.h"
#include "ResourceFileHandler.h"

class ResourceList {
public:
	ResourceList(const ResourceFileHandler& resFileHandler);

	size_t getSize() const;
	
	const ResourceType_Abstract& get(size_t) const;
	const size_t getResourceID_byName(std::string resourceName) const;
	const ResourceType_Abstract& getResource_byName(std::string resourceName) const;


	std::unique_ptr<Resource_Abstract> generateNewResource(size_t) const;
	ResourceQuantity<Mass> generateNewResource(size_t, Mass) const;

	~ResourceList();

private:
	std::vector<ResourceType_Abstract*> list;
	std::unordered_map<std::string, size_t> resourceIDs;
	//TODO: Add unordered map for direct resource acess?
	

	//std::unordered_map<std::string, Unit> units;
	//std::unordered_map<std::string, Dimension<ResourcesInternalType>> dimensions;

};

