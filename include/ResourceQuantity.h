#pragma once

#include <assert.h>

#include "Resource.h"
#include "DimensionedQuantity.h"

template <typename InternalType>
class ResourceQuantity {
public:
	ResourceQuantity(const Resource<InternalType>& resource, DimensionedQuantity<InternalType> quantity) 
	: resource(resource), quantity(quantity){
		assert(&(resource.getDimension()) == &(quantity.getDimension()));
	}

	const Resource<InternalType>& getResource() const {
		return resource;
	}
	const DimensionedQuantity<InternalType>& getQuantity() const{
		return quantity;
	}
private:
	const Resource<InternalType>& resource;
	DimensionedQuantity<InternalType> quantity;
};

