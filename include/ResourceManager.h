#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <string>


#include "dimensionUnitSystem/Dimensions.h"
#include "ResourceQuantity.h"
#include "ResourceList.h"

enum class ResourceManagerReturn : int { success = 0, errorNotEnoughResources = 1 };

class ResourceManager {
public:
	ResourceManager(const ResourceList&);

	const Resource_Abstract& get(size_t i) const;
	const Resource_Abstract& getResource_byName(std::string resourceName) const;

	ResourceManagerReturn add(size_t i, const Resource_Abstract& toAdd);

	//Debug Function
	void printResourceQuantities() const;

private:
	std::vector<std::unique_ptr<Resource_Abstract>> resourceQuantityList;
	const ResourceList& resourceList;
};

