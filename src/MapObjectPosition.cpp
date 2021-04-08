#include "..\include\MapObjectPosition.h"

MapPosition::MapPosition(MapSizeType x, MapSizeType y) 
	: x(x), y(y)
{

}

MapPosition MapPosition::operator+(const MapPosition& b) const {
	return MapPosition(x+b.x, y+b.y);
}

MapPosition MapPosition::operator-(const MapPosition& b) const {
	return MapPosition(x-b.x, y-b.y);
}

//TODO: Test performance and improve if necessary
MapPosition& MapPosition::rotateArround0(const RotationType& rotation) {
	RotationTypeFundamental rotationPiHalfs = (RotationTypeFundamental)rotation/(RotationTypeFundamental)RotationType::PI_HALF;
	switch(rotationPiHalfs) {
		case 0: break;//Do nothing
		case 1: {
			MapSizeType xCache = x;
			x = -y;
			y = xCache;
			break;
		}
		case -2: {
			x *= -1;
			y *= -1;
			break;
		}
		case -1: {
			MapSizeType xCache = x;
			x = y;
			y = -xCache;
			break;
		}
	}
	return *this;
}

MapPosition MapPosition::getRotatedArround0(const RotationType& rot) const {
	MapPosition returnValue = MapPosition(*this);
	return returnValue.rotateArround0(rot);
}

MapPositionDirectional::MapPositionDirectional(MapSizeType x, MapSizeType y, const RotationType& rotation) 
	: MapPosition(x, y)
	, rotation(rotation)
{

}
