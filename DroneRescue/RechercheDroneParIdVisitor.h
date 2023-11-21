///////////////////////////////////////////////////////////
//  RechercheDroneParIdVisitor.h
//  Interface of the Class RechercheDroneParIdVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(RECHERCHE_DRONE_PAR_ID_VISITOR__INCLUDED_)
#define RECHERCHE_DRONE_PAR_ID_VISITOR__INCLUDED_

#include <list>
#include <iostream>
#include <fstream>
#include <string>

#include "AbsUnitVisitor.h"
#include "UnitContainer.h"

using FoundDroneIterator = std::list<UnitIterator_const>::iterator;
using FoundDroneIterator_const = std::list<UnitIterator_const>::const_iterator;


class RechercheDroneParIdVisitor : public AbsUnitVisitor
{

public:
	RechercheDroneParIdVisitor(int id);
	virtual ~RechercheDroneParIdVisitor() = default;
	
	virtual void visitDivision(class Division& unit);
	virtual void visitDrone(class Drone& unit);
	virtual void visitEscadron(class Escadron& unit);
	virtual void visitEscadronMandataire(class EscadronMandataire& unit);
	virtual void visitQG(class QG& unit);

	virtual void visitDivision(const class Division& unit);
	virtual void visitDrone(const class Drone& unit);
	virtual void visitEscadron(const class Escadron& unit);
	virtual void visitEscadronMandataire(const class EscadronMandataire& unit);
	virtual void visitQG(const class QG& unit);

	virtual const AbsUnit* getDroneFound() { return m_droneFound; }
	virtual bool queryIsDroneFound() { return m_isDroneFound; }

private:
	template<typename T>
	void defaultVisitAdminUnit(const T& unit);
	
	int m_searchedId;
	UnitIterator_const* m_currentIterator;
	const AbsUnit* m_droneFound;
	bool m_isDroneFound;
};
#endif // !defined(RECHERCHE_DRONE_PAR_ID_VISITOR__INCLUDED_)
