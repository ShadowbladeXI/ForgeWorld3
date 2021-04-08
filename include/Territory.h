#pragma once



#include <vector>
#include <tuple>
#include <list>
#include <mutex>

#include "Territory.fwd.h"

class MapObject;
#include "MapObject.h"
#include "Chunk.h"
#include "Tile.h"

class Territory
{
public:
	Territory(MapSizeType width, MapSizeType height);

	const Tile& getTileAt(MapSizeType x, MapSizeType y) const;
	Tile& getTileAt(MapSizeType x, MapSizeType y);

	const Chunk& getChunkAt(MapSizeType x, MapSizeType y) const;

	//Adds a map object to this territory. Also takes control over the map object.
	void putMapObject(MapObject*);

	void deleteMapObject(MapObject*);

	~Territory();

	//Getters
	const MapSizeType& getTileGridMinX() const { return tileGridMinX; }
	const MapSizeType& getTileGridMaxX() const { return tileGridMaxX; }
	const MapSizeType& getTileGridMinY() const { return tileGridMinY; }
	const MapSizeType& getTileGridMaxY() const { return tileGridMaxY; }

private:
	MapSizeType chunkGridMinX, chunkGridMaxX, chunkGridMinY, chunkGridMaxY;
	MapSizeType tileGridMinX, tileGridMaxX, tileGridMinY, tileGridMaxY;
	std::vector<std::vector<Chunk>> chunks;

	std::list<MapObject*> allMapObjects;

	std::mutex mapObjectModificationMutex;//Mutex to protect against race conditions for creating and destroying map objects
};

