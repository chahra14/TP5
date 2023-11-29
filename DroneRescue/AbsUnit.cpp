///////////////////////////////////////////////////////////
//  AbsUnit.cpp
//  Implementation of the Class AbsUnit
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
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

AbsUnit::AbsUnit(std::string name, std::string fp) : m_name(name), m_properties({})
{
	fullPath = fp; 
}

AbsUnit& AbsUnit::addUnit(const AbsUnit& unit)
{
	return *(*(m_emptyContainer.begin()));
}

UnitIterator AbsUnit::begin()
{
	// À compléter
	return UnitIterator(m_emptyContainer.begin()); 
}

UnitIterator AbsUnit::end()
{
	// À compléter
	return UnitIterator(m_emptyContainer.end());
}

UnitIterator_const AbsUnit::cbegin() const
{
	// À compléter
	return UnitIterator_const(m_emptyContainer.cbegin());
}

UnitIterator_const AbsUnit::cend() const
{
	// À compléter
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
	// À compléter
	
	return unit.printToStream(o); 
}
