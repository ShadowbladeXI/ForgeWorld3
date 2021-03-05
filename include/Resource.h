#pragma once

#include <string>

#include "Dimension.h"

template <typename InternalType>
class Resource {
public:
	Resource(std::string name, const Dimension<InternalType>& dimension) 
	: name(name), dimension(dimension){

	}
	const std::string& getName() const {
		
		return name;
	}
	const Dimension<InternalType>& getDimension() const {
		return dimension;
	}
private:
	std::string name;
	const Dimension<InternalType>& dimension;
};

