#pragma once

#include <assert.h>

#include "Resource.h"
#include "DimensionedQuantity.h"

template <typename InternalType>
class ResourceQuantity {
public:
	ResourceQuantity(const Resource<InternalType>& resource, DimensionedQuantity<InternalType> quantity)
		: resource(resource), quantity(quantity) {
		assert(&(resource.getDimension()) == &(quantity.getDimension()));
	}

	const Resource<InternalType>& getResource() const {
		return resource;
	}
	const DimensionedQuantity<InternalType>& getQuantity() const {
		return quantity;
	}

	//Math Functions
	ResourceQuantity<InternalType> operator+() const {
		return ResourceQuantity<InternalType>(resource, +quantity);
	}
	ResourceQuantity<InternalType> operator-() const {
		return ResourceQuantity<InternalType>(resource, -quantity);
	}
	ResourceQuantity<InternalType> operator+(const ResourceQuantity<InternalType>& b) const {
		assert(&resource == &b.resource);
		return ResourceQuantity<InternalType>(resource, quantity+b.quantity);
	}
	ResourceQuantity<InternalType> operator-(const ResourceQuantity<InternalType>& b) const {
		assert(&resource == &b.resource);
		return ResourceQuantity<InternalType>(resource, quantity-b.quantity);
	}
	ResourceQuantity<InternalType>& operator+=(const ResourceQuantity<InternalType>& b) {
		assert(&resource == &b.resource);
		quantity += b.quantity;
		return *this;
	}
	ResourceQuantity<InternalType>& operator-=(const ResourceQuantity<InternalType>& b) {
		assert(&resource == &b.resource);
		quantity -= b.quantity;
		return *this;
	}
	ResourceQuantity<InternalType>& operator+=(const DimensionedQuantity<InternalType>& b) {
		assert(&resource.dimension == &b.dimension);
		quantity += b;
		return *this;
	}
	ResourceQuantity<InternalType>& operator-=(const DimensionedQuantity<InternalType>& b) {
		assert(&resource.dimension == &b.dimension);
		quantity -= b;
		return *this;
	}

private:
	const Resource<InternalType>& resource;
	DimensionedQuantity<InternalType> quantity;
};

