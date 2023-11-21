///////////////////////////////////////////////////////////
//  AbsUnit.cpp
//  Implementation of the Class AbsUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain basÚ sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "AbsUnit.h"

int AbsUnit::m_indent = 0;
UnitContainer AbsUnit::m_emptyContainer;

AbsUnit::AbsUnit(std::string name, AbsUnit* parent) : m_name(name), m_properties({})
{
	if (parent == nullptr)
		fullPath = "/";
	else
		fullPath = parent->getFullPath() + name + "/";
}

AbsUnit& AbsUnit::addUnit(const AbsUnit& unit)
{
	return *(*(m_emptyContainer.begin()));
}

UnitIterator AbsUnit::begin()
{
	// └ complÚter
	return UnitIterator(m_emptyContainer.begin()); 
}

UnitIterator AbsUnit::end()
{
	// └ complÚter
	return UnitIterator(m_emptyContainer.end());
}

UnitIterator_const AbsUnit::cbegin() const
{
	// └ complÚter
	return UnitIterator_const(m_emptyContainer.cbegin());
}

UnitIterator_const AbsUnit::cend() const
{
	// └ complÚter
	return UnitIterator_const(m_emptyContainer.cend());
}

void AbsUnit::deleteUnit(UnitIterator_const child)
{
	// Echoue silencieusement ???????
}

std::ostream& AbsUnit::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}

std::ostream& operator<<(std::ostream& o, const AbsUnit& unit)
{
	// └ complÚter
	
	return unit.printToStream(o); 
}
