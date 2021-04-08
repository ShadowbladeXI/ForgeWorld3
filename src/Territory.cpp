#include <assert.h>
#include <algorithm>

#include "../include/Math.h"
#include "../include/Territory.h"

Territory::Territory(MapSizeType width, MapSizeType height)
	: chunks(std::vector<std::vector<Chunk>>())
	, allMapObjects(std::list<MapObject*>())
{
	assert(width>=0 && height>=0);


	//Create grid of chunks
	//
	MapSizeType widthChunks = width/Chunk::CHUNK_SIZE + (width%Chunk::CHUNK_SIZE != 0);
	MapSizeType heightChunks = height/Chunk::CHUNK_SIZE + (height%Chunk::CHUNK_SIZE != 0);

	chunkGridMinX = -widthChunks/2;
	chunkGridMaxX = chunkGridMinX + widthChunks-1;
	chunkGridMinY = -heightChunks/2;
	chunkGridMaxY = chunkGridMinY + heightChunks-1;

	tileGridMinX = std::max(-width/2, chunkGridMinX*Chunk::CHUNK_SIZE);
	tileGridMaxX = tileGridMinX + width-1;
	tileGridMinY = std::max(-height/2, chunkGridMinY*Chunk::CHUNK_SIZE);
	tileGridMaxY = tileGridMinY + height-1;

	chunks.reserve(widthChunks);
	for (size_t i = 0; i < widthChunks; ++i) {
		std::vector<Chunk> chunkRow = std::vector<Chunk>();
		chunkRow.reserve(heightChunks);
		for (size_t j = 0; j < heightChunks; ++j) {
			Chunk newChunk = Chunk();
			chunkRow.push_back(newChunk);
		}
		chunks.push_back(chunkRow);
	}
}

const Tile& Territory::getTileAt(MapSizeType x, MapSizeType y) const {
	int chunkX, chunkY, inChunkX, inChunkY;

	floor_div(x, Chunk::CHUNK_SIZE, chunkX, inChunkX);
	floor_div(y, Chunk::CHUNK_SIZE, chunkY, inChunkY);
	int chunkXIndex = chunkX-chunkGridMinX;
	int chunkYIndex = chunkY-chunkGridMinY;
	return chunks[chunkXIndex][chunkYIndex].getTileAt(inChunkX, inChunkY);
}

Tile& Territory::getTileAt(MapSizeType x, MapSizeType y) {
	int chunkX, chunkY, inChunkX, inChunkY;

	floor_div(x, Chunk::CHUNK_SIZE, chunkX, inChunkX);
	floor_div(y, Chunk::CHUNK_SIZE, chunkY, inChunkY);
	int chunkXIndex = chunkX-chunkGridMinX;
	int chunkYIndex = chunkY-chunkGridMinY;
	return chunks[chunkXIndex][chunkYIndex].getTileAt(inChunkX, inChunkY);
}

const Chunk& Territory::getChunkAt(MapSizeType x, MapSizeType y) const {
	int chunkX, chunkY, inChunkX, inChunkY;

	floor_div(x, Chunk::CHUNK_SIZE, chunkX, inChunkX);
	floor_div(y, Chunk::CHUNK_SIZE, chunkY, inChunkY);
	int chunkXIndex = chunkX-chunkGridMinX;
	int chunkYIndex = chunkY-chunkGridMinY;
	return chunks[chunkXIndex][chunkYIndex];
}

void Territory::putMapObject(MapObject* newMapObjectPtr) {
	const std::lock_guard<std::mutex> deleteMapObjectLock(mapObjectModificationMutex);
	newMapObjectPtr->getAssociatedMapObjectFactory().associateTiles(newMapObjectPtr, *this);
	allMapObjects.push_back(newMapObjectPtr);
	std::list<MapObject*>::iterator saveIterator = --allMapObjects.end();//Iterator pointing to the position in a linked list where the new map object is saved
	newMapObjectPtr->setSaveIterator(saveIterator);
}

void Territory::deleteMapObject(MapObject* mapObject) {
	const std::lock_guard<std::mutex> deleteMapObjectLock(mapObjectModificationMutex);
	allMapObjects.erase(mapObject->getSaveIterator());
	mapObject->getAssociatedMapObjectFactory().disassociateTiles(mapObject, *this);
	delete mapObject;
}

Territory::~Territory() {
	for (MapObject* mapObject : allMapObjects) 	{
		delete mapObject;
	}
}
