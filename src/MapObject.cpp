class MapObject;
#include "..\include\MapObject.h"


////Assign values to the error variables
//Error types whith a fixed value (do not include this in derived classes)
const ErrorType MapObject::ERROR_NO_ERROR(0);
const ErrorType MapObject::ERROR_UNKNOWN_ERROR(1);
//Value generation preparation (do not include this in derived calsses)
const ErrorType MapObject::generateNextErrorNumber(ErrorType& errorNumberCounter) { return ErrorType(++errorNumberCounter); }
//Value generation preparation (Include this in derived classes with "errorNumberCounter(*ParentClass*::maxErrorNumber)" and "*DerivedClass*::maxErrorNumber = errorNUmberCounter")
static ErrorType errorNumberCounter(1);//Start with 1 to account for the two fixed error types "ERROR_NO_ERROR" and "ERROR_UNKNOWN_ERROR"
const ErrorType& MapObject::maxErrorNumber = errorNumberCounter;
//Error types with a generated value (include this in derived calss with own error variables)
const ErrorType MapObject::ERROR_OUTSIDE_OF_BOUNDARIES = MapObject::generateNextErrorNumber(errorNumberCounter);
const ErrorType MapObject::ERROR_SPACE_NOT_AVAILABLE = MapObject::generateNextErrorNumber(errorNumberCounter);

//Values for null iterators
const std::list<MapObject*>::iterator MapObject::NULL_ITERATOR = std::list<MapObject*>({ nullptr }).begin();


const MapObjectFactory& MapObject::getAssociatedMapObjectFactory() const {
	return associatedMapObjectFactory;
}

MapObject::MapObject(const MapObjectFactory& associatedMapObjectFactory, const MapPositionDirectional& position)
	: associatedMapObjectFactory(associatedMapObjectFactory)
	, position(position)
	, saveIterator(NULL_ITERATOR)
{
	
}

void MapObject::setSaveIterator(const std::list<MapObject*>::iterator& newSaveIterator) {
	saveIterator = newSaveIterator;
}
const std::list<MapObject*>::iterator& MapObject::getSaveIterator() {
	assert(*saveIterator != nullptr);
	return saveIterator;
}

MapObjectFactory::MapObjectFactory(std::string mapObjectTypeName, std::vector<MapObjectTile> mapObjectTiles)
	: mapObjectTypeName(mapObjectTypeName)
	, mapObjectTiles(mapObjectTiles)
{

}

const MapObject* MapObjectFactory::createObject(Territory& territory, const MapPositionDirectional& position, ErrorType& error) const{
	if(isCreatable(territory, position, error)) {
		assert(!error);//Ensure that no error is returned if no map object is created
		MapObject* newMapObject = new MapObject(*this, position);
		territory.putMapObject(newMapObject);//Give the new map object over to the territory (gives away all responsibility)
		return newMapObject;
	} else {
		assert(error);//Ensure that an error is returned if no map object is created
		return nullptr;//no map object created
	}
	
}

void MapObjectFactory::associateTiles(MapObject* mapObjectToAssociate, Territory& territory) const {
	//TODO: Move loop in a centralized function with a function argument
	for(size_t i = 0; i<mapObjectTiles.size(); ++i) {
		const MapPositionDirectional& position = mapObjectToAssociate->position;
		const MapObjectTile& occupyingObjectTile = mapObjectTiles[i];
		MapPosition occupyingPositionRelative = occupyingObjectTile.getRelativeMapPosition();
		MapPosition occupyingPositionRelativeRotated = occupyingPositionRelative.getRotatedArround0(position.getRotzation());
		MapPosition occupyingPosition = position + occupyingPositionRelativeRotated;

		occupyingObjectTile.associateTile(mapObjectToAssociate, territory.getTileAt(occupyingPosition.getX(), occupyingPosition.getY()));
	}
}

void MapObjectFactory::disassociateTiles(MapObject* mapObjectToAssociate, Territory& territory) const {
	//TODO: Move loop in a centralized function with a function argument
	for(size_t i = 0; i<mapObjectTiles.size(); ++i) {
		const MapPositionDirectional& position = mapObjectToAssociate->position;
		const MapObjectTile& occupyingObjectTile = mapObjectTiles[i];
		MapPosition occupyingPositionRelative = occupyingObjectTile.getRelativeMapPosition();
		MapPosition occupyingPositionRelativeRotated = occupyingPositionRelative.getRotatedArround0(position.getRotzation());
		MapPosition occupyingPosition = position + occupyingPositionRelativeRotated;

		occupyingObjectTile.disassociateTile(territory.getTileAt(occupyingPosition.getX(), occupyingPosition.getY()));
	}
}

bool MapObjectFactory::isCreatable(const Territory& territory, const MapPositionDirectional& position, ErrorType& error) const{
	//Check space on the map
	//TODO: Move loop in a centralized function with a function argument
	for(size_t i = 0; i<mapObjectTiles.size(); ++i) {
		const MapObjectTile& occupyingObjectTile = mapObjectTiles[i];
		MapPosition occupyingPositionRelative = occupyingObjectTile.getRelativeMapPosition();
		MapPosition occupyingPositionRelativeRotated = occupyingPositionRelative.getRotatedArround0(position.getRotzation());
		MapPosition occupyingPosition = position + occupyingPositionRelativeRotated;
		if(occupyingPosition.getX()<territory.getTileGridMinX() || occupyingPosition.getX()>territory.getTileGridMaxX() || occupyingPosition.getY()<territory.getTileGridMinY() || occupyingPosition.getY()>territory.getTileGridMaxY()) {
			error = MapObject::ERROR_OUTSIDE_OF_BOUNDARIES;
			break;
		} else {
			Tile occupyingTile = territory.getTileAt(occupyingPosition.getX(), occupyingPosition.getY());
			error = checkCreatableMapObjectTile(occupyingObjectTile, occupyingTile);
			if(error) {break;}
		}
	}

	return !error;
}

ErrorType MapObjectFactory::checkCreatableMapObjectTile(const MapObjectTile& mapObjectTile, const Tile& mapTile) const {
	return mapObjectTile.checkCreatable(mapTile);
}

MapObjectTile::MapObjectTile(const MapPosition& relativeMapPosition) 
	: relativeMapPosition(relativeMapPosition)
{

}

void MapObjectTile::associateTile(MapObject* mapObjectToAssociate, Tile& tileToAssociate) const{
	tileToAssociate.steOccupyingMapObject(mapObjectToAssociate);
}
void MapObjectTile::disassociateTile(Tile& tileToDisassociate) const {
	tileToDisassociate.unsetOccupyingMapObject();
}

ErrorType MapObjectTile::checkCreatable(const Tile& mapTile) const{
	if(mapTile.getOccupyingMapObject() == nullptr) {
		return MapObject::ERROR_NO_ERROR;
	} else {
		return MapObject::ERROR_SPACE_NOT_AVAILABLE;
	}
}
