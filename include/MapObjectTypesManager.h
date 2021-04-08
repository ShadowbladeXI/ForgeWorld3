#pragma once

#include <vector>

class MapObject;
#include "MapObject.h"

class MapObjectTypesManager {
public:
	MapObjectTypesManager();

	const MapObjectFactory& getMapObjectFactory(size_t index) const;
private:
	std::vector<MapObjectFactory> allMapObjectFactories;

};

