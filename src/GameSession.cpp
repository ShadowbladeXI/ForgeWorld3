#include "../include/GameSession.h"

#include "../include/ResourceFileHandler.h"
#include "../include/dimensionUnitSystem/Dimensions.h"
#include "../include/dimensionUnitSystem/Units.h"
#include <iostream>


GameSession::GameSession()
	: universe() 
	, resourceList(ResourceFileHandler())//TODO: Remove, for test purposes only
	, mapObjectTypesManager()
{
	//TODO: Remove, only to test for memory leaks
	/*for(int i = 0; i<1000000; ++i) {
		ResourceList testList = ResourceList();
		std::cout<<testList.getSize();
	}*/

	//TODO: Remove
	//Only for test purposes of the resource management system
	ResourceManager testResourceManager = ResourceManager(resourceList);
	testResourceManager.printResourceQuantities();
	std::string testString = testResourceManager.getResource_byName("Coal").toString();

	ResourceManagerReturn errFlag;
	auto coal100g = resourceList.generateNewResource(resourceList.getResourceID_byName("Coal"), Mass(100, gramm));//Create a resource quantity which represents 100 g
	errFlag = testResourceManager.add(0, coal100g);
	testString = testResourceManager.get(0).toString();

	auto coal200g = resourceList.generateNewResource(resourceList.getResourceID_byName("Coal"), Mass(200, gramm));//Create a resource quantity which represents 200 g
	errFlag = testResourceManager.add(0, -coal200g);
	testString = testResourceManager.get(0).toString();







	//TODO: Remove
	//Only for test purposes of the map object placing system
	ErrorType error;
	bool testBool = mapObjectTypesManager.getMapObjectFactory(0).isCreatable(universe.testPlanet.testTerritory, MapPositionDirectional(51, 102, RotationType::SOUTH), error);

	mapObjectTypesManager.getMapObjectFactory(0).createObject(universe.testPlanet.testTerritory, MapPositionDirectional(51, 102, RotationType::SOUTH), error);

	
	//TODO: Remove, only to test for memory leaks
	/*for(int i = 0; i<1000000; ++i) {
		const MapObject* testMapObject = mapObjectTypesManager.getMapObjectFactory(0).createObject(universe.testPlanet.testTerritory, MapPositionDirectional(51, 100, RotationType::SOUTH), error);
		universe.testPlanet.testTerritory.deleteMapObject(universe.testPlanet.testTerritory.getTileAt(51, 100).getOccupyingMapObject());
		std::cout<<testMapObject;
	}*/

	


	


}
