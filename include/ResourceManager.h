#pragma once

#include <vector>
#include <iostream>

#include "Unit.h"
#include "Resource.h"
#include "ResourceQuantity.h"
#include "ResourceList.h"

enum ResourceManagerReturn :int { success = 0, errorNotEnoughResources = 1 };

class ResourceManager {
public:
	ResourceManager(const ResourceList&);

	const ResourceQuantity<ResourcesInternalType>& get(size_t i) const;

	ResourceManagerReturn add(size_t i, const ResourceQuantity<ResourcesInternalType>& toAdd);

	//Debug Function
	void printResourceQuantities() const;
private:
	

	
	std::vector<ResourceQuantity<ResourcesInternalType>> resourceQuantityList;
};

