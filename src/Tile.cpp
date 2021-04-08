#include "../include/Tile.h"

Tile::Tile() 
	: occupyingMapObject(nullptr)
{

}

MapObject* Tile::getOccupyingMapObject() {
	return occupyingMapObject;
}

const MapObject* Tile::getOccupyingMapObject() const {
	return occupyingMapObject;
}

void Tile::steOccupyingMapObject(MapObject* mapObject) {
	assert(occupyingMapObject == nullptr);
	occupyingMapObject = mapObject;
}

void Tile::unsetOccupyingMapObject() {
	assert(occupyingMapObject != nullptr);
	occupyingMapObject = nullptr;
}
