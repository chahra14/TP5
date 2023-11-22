///////////////////////////////////////////////////////////
//  Drone.cpp
//  Implementation of the Class Drone
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "Drone.h"
#include <iostream>

Drone::Drone(std::string name, std::string escadron, std::string division)
	: AbsUnit(name), m_id(rand()) { 
	m_properties.insert(std::pair<std::string, std::string>("division", division));
	m_properties.insert(std::pair<std::string, std::string>("escadron", escadron));
}

Drone::Drone(std::string name, AbsUnit* parent)
	: AbsUnit(name, parent), m_id(rand())  
{
	m_properties.insert(std::pair<std::string, std::string>("division", parent->getProperties().at("division")));
	m_properties.insert(std::pair<std::string, std::string>("escadron", parent->getName()));
}

Drone* Drone::clone() const
{
	// À compléter}
	return new Drone(*this);
}

unsigned int Drone::getId(void) const
{
	// À compléter
	return (m_id);
}

std::ostream& Drone::printToStream(std::ostream& o) const
{
	// À compléter
	
	++m_indent;
	o << getName() << " [" << getId() << "] {" << getFullPath() << "}" << std::endl;
	--m_indent;
	return o;
}

//TODO

void Drone::accept(class AbsUnitVisitor& v)
{
	v.visitDrone(*this); 
}
void Drone::accept(class AbsUnitVisitor& v) const
{
	v.visitDrone(const_cast<const Drone&>(*this));
}
