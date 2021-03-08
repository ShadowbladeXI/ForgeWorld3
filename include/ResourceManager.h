#pragma once

#include <vector>
#include <iostream>

#include "Unit.h"
#include "Resource.h"
#include "ResourceQuantity.h"
#include "ResourceList.h"

class ResourceManager {
public:
	ResourceManager(const ResourceList&);

	//Debug Function
	void printResourceQuantities() const;
private:
	

	
	std::vector<ResourceQuantity<ResourcesInternalType>> resourceQuantityList;
};

