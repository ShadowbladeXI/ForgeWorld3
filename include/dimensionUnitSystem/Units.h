#pragma once

//TODO: Remove
//template<DummyBase T, size_t a_size>
//class DummyBase {
//public:
//	DummyBase() = delete;
//
//	constexpr DummyBase(const char (& i)[a_size]) {
//		for (int index = 0; index<a_size; ++index) {
//			a[index] = i[index];
//		}
//	}
//private:
//	char a[a_size];
//
//};
//template<size_t a_size>
//class Dummy : public DummyBase<dummy, a_size> {
//public:
//	constexpr Dummy(const char(&i)[a_size]) 
//		: DummyBase<dummy, a_size>(i)
//	{}
//};
//constexpr const auto dummy = Dummy{"f"};

//Length
class MeterBase {};//TODO: Maybe change to instance instead of class?
template<size_t name_size, size_t symbol_size>
class Unit_MeterBased : public Unit<MeterBase, name_size, symbol_size> {
public:

	//using Unit<Unit_Abstract<MeterBase>, name_size, symbol_size>::Unit;

	//For base unit
	constexpr Unit_MeterBased(const char(& name)[name_size], const char(& symbol)[symbol_size])
		: Unit<MeterBase, name_size, symbol_size>(name, symbol)
	{}

	//For derived unit
	constexpr Unit_MeterBased(const char(& name)[name_size], const char(& symbol)[symbol_size], const Unit_Abstract<MeterBase>& refUnit, const double& inRefUnit)
		: Unit<MeterBase, name_size, symbol_size>(name, symbol, refUnit, inRefUnit)
	{}

	//constexpr Unit_MeterBased() 
	//	: BaseUnit("meter", "m")
	//{}
};
constexpr Unit_MeterBased meter("meter", "m");

//Mass
class GrammBase {};//TODO: Maybe change to instance instead of class?
template<size_t name_size, size_t symbol_size>
class Unit_GrammBased : public Unit<GrammBase, name_size, symbol_size> {
public:

	//using Unit<Unit_Abstract<GrammBase>, name_size, symbol_size>::Unit;

	//For base unit
	constexpr Unit_GrammBased(const char(&name)[name_size], const char(&symbol)[symbol_size])
		: Unit<GrammBase, name_size, symbol_size>(name, symbol)
	{}

	//For derived unit
	constexpr Unit_GrammBased(const char(&name)[name_size], const char(&symbol)[symbol_size], const Unit_Abstract<GrammBase>& refUnit, const double& inRefUnit)
		: Unit<GrammBase, name_size, symbol_size>(name, symbol, refUnit, inRefUnit)
	{}

	//constexpr Unit_MeterBased() 
	//	: BaseUnit("meter", "m")
	//{}
};
constexpr Unit_GrammBased gramm("gramm", "g");

//Time
class SecondBase {};
template<size_t name_size, size_t symbol_size>
class Unit_SecondBased : public Unit<SecondBase, name_size, symbol_size> {
public:

	//For base unit
	constexpr Unit_SecondBased(const char(&name)[name_size], const char(&symbol)[symbol_size])
		: Unit<SecondBase, name_size, symbol_size>(name, symbol)
	{}

	//For derived unit
	constexpr Unit_SecondBased(const char(&name)[name_size], const char(&symbol)[symbol_size], const Unit_Abstract<SecondBase>& refUnit, const double& inRefUnit)
		: Unit<SecondBase, name_size, symbol_size>(name, symbol, refUnit, inRefUnit)
	{}
};
constexpr Unit_SecondBased second("second", "s");