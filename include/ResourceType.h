#pragma once

#include <string>
#include <memory>

#include "dimensionUnitSystem/DimensionedQuantity.h"
#include "ResourceQuantity.h"

class ResourceType_Abstract {
public:

	virtual const std::string& getName() const = 0;

	virtual std::unique_ptr<Resource_Abstract> createNewResource() const = 0;
};

template <typename Dimension>//TODO: Add check that dimension has type of DimensionedQuantity
class ResourceType : public ResourceType_Abstract{
public:
	ResourceType(std::string name) 
		: name(name)
	{

	}

	const std::string& getName() const override {
		return name;
	}

	std::unique_ptr<Resource_Abstract> createNewResource() const override{
		return std::unique_ptr<ResourceQuantity<Dimension>>(new ResourceQuantity<Dimension>(*this));
		//return std::make_unique<ResourceQuantity<Dimension>>(*this);
	}

	std::unique_ptr<ResourceQuantity<Dimension>> createNewResource(Dimension quantity) const {
		return std::unique_ptr<ResourceQuantity<Dimension>>(new ResourceQuantity<Dimension>(*this, quantity));
	}

private:
	std::string name;
};

