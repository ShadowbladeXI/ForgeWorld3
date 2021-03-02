#include <assert.h>
#include <algorithm>

#include "Territory.h"

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

	spotGridMinX = -width/2;
	spotGridMaxX = spotGridMinX + width-1;
	spotGridMinY = -height/2;
	spotGridMaxY = spotGridMinY + height-1;

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
}

Spot Territory::getSpotAt(int x, int y) {
	return Spot();
}

Chunk Territory::getChunkAt(int x, int y)
{
	return Chunk();
}

std::tuple<Chunk, Spot> Territory::getChunkAndSpotAt(int x, int y)
{
	return std::tuple<Chunk, Spot>();
}
