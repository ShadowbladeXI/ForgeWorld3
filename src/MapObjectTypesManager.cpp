#include "..\include\MapObjectTypesManager.h"

MapObjectTypesManager::MapObjectTypesManager()
	: allMapObjectFactories(std::vector<MapObjectFactory>()) 	
{
	//TODO: Make real implementation
	//Create test map objects
	allMapObjectFactories.push_back(MapObjectFactory("Test Rock", std::vector<MapObjectTile>({ MapObjectTile(MapPosition(-1, -1)), MapObjectTile(MapPosition(0, -1)) , MapObjectTile(MapPosition(-1, 0)) , MapObjectTile(MapPosition(0, 0)) })));
	allMapObjectFactories.shrink_to_fit();
}

const MapObjectFactory& MapObjectTypesManager::getMapObjectFactory(size_t index) const {
	return allMapObjectFactories[index];
}
