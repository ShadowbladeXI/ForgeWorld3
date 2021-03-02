#include <assert.h>
#include <algorithm>

#include "../include/Math.h"
#include "../include/Territory.h"

Territory::Territory(int width, int height) 
	: width(width), height(height)
	, chunks(std::vector<std::vector<Chunk>>()){
	assert(width>=0 && height>=0);


	//Create grid of chunks
	//
	int widthChunks = width/Chunk::CHUNK_SIZE + (width%Chunk::CHUNK_SIZE != 0);
	int heightChunks = height/Chunk::CHUNK_SIZE + (height%Chunk::CHUNK_SIZE != 0);

	chunkGridMinX = -widthChunks/2;
	chunkGridMaxX = chunkGridMinX + widthChunks-1;
	chunkGridMinY = -heightChunks/2;
	chunkGridMaxY = chunkGridMinY + heightChunks-1;

	tileGridMinX = -width/2;
	tileGridMaxX = tileGridMinX + width-1;
	tileGridMinY = -height/2;
	tileGridMaxY = tileGridMinY + height-1;

	chunks.reserve(widthChunks);
	for (int i = 0; i < widthChunks; ++i) {
		std::vector<Chunk> chunkRow = std::vector<Chunk>();
		chunkRow.reserve(heightChunks);
		for (int j = 0; j < heightChunks; ++j) {
			Chunk newChunk = Chunk();
			chunkRow.push_back(newChunk);
		}
		chunks.push_back(chunkRow);
	}

	//Test
	//
	Tile testTile;
	getTileAt(40, 90, testTile);
	Chunk testChunk;
	getChunkAt(40, 90, testChunk);

}

void Territory::getTileAt(int x, int y, Tile& tileOut) {
	Chunk chunk;
	Territory::getChunkAndTileAt(x, y, chunk, tileOut);
	return;
}

void Territory::getChunkAt(int x, int y, Chunk& chunkOut) {
	Tile tile;
	Territory::getChunkAndTileAt(x, y, chunkOut, tile);
	return;
}

void Territory::getChunkAndTileAt(int x, int y, Chunk& chunkOut, Tile& tileOut)
{
	int chunkX, chunkY, inChunkX, inChunkY;

	floor_div(x, Chunk::CHUNK_SIZE, chunkX, inChunkX);
	floor_div(y, Chunk::CHUNK_SIZE, chunkY, inChunkY);
	int chunkXIndex = chunkX-chunkGridMinX;
	int chunkYIndex = chunkY-chunkGridMinY;
	chunkOut = chunks[chunkXIndex][chunkYIndex];
	tileOut = chunkOut.getTileAt(inChunkX, inChunkY);

	return;
}
