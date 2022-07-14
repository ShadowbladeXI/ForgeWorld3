#pragma once

#include <string>
#include <array>

//This class should only be used if the type of unit does not matter
class Unit_Abstract_NoBase {
public:
	virtual constexpr std::string getName() const = 0;
	virtual constexpr std::string getSymbol() const = 0;
};

//This class should generally be used unless it is for the instantiation of new units
//Base Unit should be a class such that all instances of Unit_Abstract<BaseUnit> are of the same type (e.g. conversion makes sense) 
template <typename BaseUnit>
class Unit_Abstract : public Unit_Abstract_NoBase {
public:
	Unit_Abstract() = delete;

	constexpr Unit_Abstract(const double& inBaseUnit)
		: inBaseUnit(inBaseUnit)
	{}

	virtual constexpr double getInBaseUnit() const = 0;//TODO: Make protected?
	
	virtual constexpr std::string generateString_fromBaseUnitAmount(double amount_baseUnit) const = 0;//TODO: Make protected?

protected:
	const double inBaseUnit;
};

//Implementation to create new units
template <typename BaseUnit, std::size_t name_size, std::size_t symbol_size>
class Unit : public Unit_Abstract<BaseUnit>{

public:
	Unit() = delete;

	//For base unit
	constexpr Unit(const char(& name)[name_size], const char(& symbol)[symbol_size])
		: Unit(name, symbol, 1.0)
	{
		//TODO: Add check that baseUnit points to this
	}

	//For derived unit
	template<std::size_t refUnit_name_size, std::size_t refUnit_symbol_size>
	constexpr Unit(const char(& name)[name_size], const char(& symbol)[symbol_size], const Unit_Abstract<BaseUnit>& refUnit, const double& inRefUnit)
		: Unit(name, symbol, refUnit.getInBaseUnit()* inRefUnit)
	{}

	constexpr double getInBaseUnit() const {
		return this->inBaseUnit;
	}

	constexpr std::string getName() const {
		std::string out(name.begin(), name.end());
		return out;
	}
	constexpr std::string getSymbol() const {
		return std::string(symbol.begin(), symbol.end());
	}

	constexpr std::string generateString_fromBaseUnitAmount(double amount_baseUnit) const {
		return std::to_string(amount_baseUnit/getInBaseUnit()) + " " + getSymbol();
	}

protected:
	//Helper Constructor
	constexpr Unit(const char(& name)[name_size], const char(& symbol)[symbol_size], const double& inBaseUnit)
		: Unit_Abstract<BaseUnit>(inBaseUnit)
		//, name()
		//, symbol()
		, name(createStdArray<name_size>(name))
		, symbol(createStdArray<symbol_size>(symbol))
	{
		//TODO: Maybe include default based on symbol?
		//for (int i = 0; i<name_size; ++i) {
		//	this->name[i] = name[i];
		//}

		//for (int i = 0; i<symbol_size; ++i) {
		//	this->symbol[i] = symbol[i];
		//}

	}
	//Helper function to create std:array of chars
	template<std::size_t n>
	static constexpr const std::array<char, n> createStdArray(const char(& in)[n]) {
		std::array<char, n> out{};
		for (int i = 0; i<n; ++i) {
			out[i] = in[i];
		}
		return out;
	}

	const std::array<char, name_size> name;
	const std::array<char, symbol_size> symbol;
};