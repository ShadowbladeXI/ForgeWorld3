#pragma once

#include <string>
#include <assert.h>

#include "ResourceType.fwd.h"

class Resource_Abstract {
public:
	
	virtual const ResourceType_Abstract& getResourceType() const = 0;
	
	virtual std::string toString() const = 0;

	//TODO: Add other functions as virtual parent class functions
};

//TODO: Rename to "Resource"?
template <typename Dimension>
class ResourceQuantity : public Resource_Abstract{
public:
	ResourceQuantity(const ResourceType<Dimension>& resourceType, Dimension quantity)
		: resourceType(resourceType), quantity(quantity) 
	{

	}

	ResourceQuantity(const ResourceType<Dimension>& resourceType)
		: resourceType(resourceType), quantity(Dimension()) 
	{
		
	}

	const ResourceType<Dimension>& getResourceType() const override{
		return resourceType;
	}
	const Dimension& getQuantity() const {
		return quantity;
	}

	std::string toString() const override {
		return getResourceType().getName() + getQuantity().toString();
	}

	//Math Functions
	ResourceQuantity<Dimension> operator+() const {
		return ResourceQuantity<Dimension>(resourceType, +quantity);
	}
	ResourceQuantity<Dimension> operator-() const {
		return ResourceQuantity<Dimension>(resourceType, -quantity);
	}
	ResourceQuantity<Dimension> operator+(const ResourceQuantity<Dimension>& b) const {
		assert(&resourceType == &b.resourceType);
		return ResourceQuantity<Dimension>(resourceType, quantity+b.quantity);
	}
	ResourceQuantity<Dimension> operator-(const ResourceQuantity<Dimension>& b) const {
		assert(&resourceType == &b.resourceType);
		return ResourceQuantity<Dimension>(resourceType, quantity-b.quantity);
	}
	ResourceQuantity<Dimension>& operator+=(const ResourceQuantity<Dimension>& b) {
		assert(&resourceType == &b.resourceType);
		quantity += b.quantity;
		return *this;
	}
	ResourceQuantity<Dimension>& operator-=(const ResourceQuantity<Dimension>& b) {
		assert(&resourceType == &b.resourceType);
		quantity -= b.quantity;
		return *this;
	}
	ResourceQuantity<Dimension>& operator+=(const Dimension& b) {
		quantity += b;
		return *this;
	}
	ResourceQuantity<Dimension>& operator-=(const Dimension& b) {
		quantity -= b;
		return *this;
	}

private:
	const ResourceType<Dimension>& resourceType;
	Dimension quantity;
};

