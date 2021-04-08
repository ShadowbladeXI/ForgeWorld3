#pragma once



#include <vector>
#include <string>

#include <assert.h>

#include "MapObject.fwd.h"

#include "Tile.h"
#include "Territory.h"
#include "MapObjectPosition.h"

class MapObject {
	friend class MapObjectFactory;

public:
	const MapObjectFactory& getAssociatedMapObjectFactory() const;

protected:
	const MapObjectFactory& associatedMapObjectFactory;//Reference to the map object which created this object
	MapPositionDirectional position;

	MapObject(const MapObjectFactory& accociatedMapObjectFactory, const MapPositionDirectional& position);//Protected constructor, use MapObjectFactory to instantiate

//Definition of possible errors
public:
	static const ErrorType
		ERROR_NO_ERROR,
		ERROR_UNKNOWN_ERROR,
		ERROR_OUTSIDE_OF_BOUNDARIES,
		ERROR_SPACE_NOT_AVAILABLE;
protected:
	static const ErrorType& maxErrorNumber;//Always updated to the maximum number which is ued for errors for this class
	static const ErrorType generateNextErrorNumber(ErrorType& counter);

//Handling the ability for a map object to remember where it is saved
private:
	const static std::list<MapObject*>::iterator NULL_ITERATOR;//iterator which symbolizes that this map object has not yet been assigned an iterator
	std::list<MapObject*>::iterator saveIterator;//Iterator pointing to the position in a linked list where the new map object is saved. NULL_ITERATOR if this map object has not yet been added to a linked list.
public:
	void setSaveIterator(const std::list<MapObject*>::iterator& newSaveIterator);
	const std::list<MapObject*>::iterator& getSaveIterator();
};

//Factory class to create map objects and store common values
class MapObjectFactory {
public:
	MapObjectFactory(std::string mapObjectName, std::vector<MapObjectTile> mapObjectTiles);

	virtual bool isCreatable(const Territory&, const MapPositionDirectional& position, ErrorType&) const;
	virtual const MapObject* createObject(Territory&, const MapPositionDirectional& position, ErrorType&) const;//Factory method for map objects (creates map objects on the heap)
	virtual void associateTiles(MapObject*, Territory&) const;
	virtual void disassociateTiles(MapObject*, Territory&) const;
	
protected:
	std::vector<MapObjectTile> mapObjectTiles;
	std::string mapObjectTypeName;

	ErrorType checkCreatableMapObjectTile(const MapObjectTile& mapObjectTile, const Tile& mapTile) const;//Returns the error (if any) for creating the specified map object tile on the specified map tile
};

class MapObjectTile {
public:
	MapObjectTile(const MapPosition& relativeMapPosition);

	const MapPosition& getRelativeMapPosition() const { return relativeMapPosition; }
	virtual ErrorType checkCreatable(const Tile& mapTile) const;
	virtual void associateTile(MapObject* mapObjectToAssociate, Tile& tileToAssociate) const;
	virtual void disassociateTile(Tile& tileToDisassociate) const;
protected:
	MapPosition relativeMapPosition;//Position relative to the root position of the map object the tile belongs to
};