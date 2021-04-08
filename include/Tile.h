#pragma once

#include <assert.h>

class MapObject;//Forward Declaration

class Tile{
public:
	Tile();

	MapObject* getOccupyingMapObject();
	const MapObject* getOccupyingMapObject() const;
	void steOccupyingMapObject(MapObject*);
	void unsetOccupyingMapObject();
private:
	MapObject* occupyingMapObject;//Pointer to the map object which occupies this position or nullpointer if not occupied
};

