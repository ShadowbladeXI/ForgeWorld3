#include "../include/Chunk.h"

Tile& Chunk::getTileAt(int inChunkX, int inChunkY) {
    return tiles[inChunkX][inChunkY];
}
const Tile& Chunk::getTileAt(int inChunkX, int inChunkY) const{
    return tiles[inChunkX][inChunkY];
}


