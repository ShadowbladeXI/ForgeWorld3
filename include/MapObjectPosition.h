#pragma once

#include <utility>

#include "Territory.fwd.h"

//Type to store rotation
typedef int RotationTypeFundamental;
enum class RotationType :RotationTypeFundamental {
	EAST = 0,
	WEST = -32768,//Minimum allowed int
	SOUTH = (EAST+WEST)/2,
	NORTH = -SOUTH,

	PI_HALF = NORTH,
};

class MapPosition {
private:
	MapSizeType x, y;
public:
	MapPosition(MapSizeType x, MapSizeType y);

	const MapSizeType& getX() const { return x; }
	const MapSizeType& getY() const { return y; }

	//Operators
	MapPosition operator+(const MapPosition&) const;
	MapPosition operator-(const MapPosition&) const;
	MapPosition& rotateArround0(const RotationType&);
	MapPosition getRotatedArround0(const RotationType&) const;
};

class MapPositionDirectional : public MapPosition {
private:
	RotationType rotation;
public:
	MapPositionDirectional(MapSizeType x, MapSizeType y, const RotationType& rotation);

	const RotationType& getRotzation() const { return rotation; }
};

