///////////////////////////////////////////////////////////
//  RechercheUniteParNomVisitor.h
//  Interface of the Class RechercheUniteParNomVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(RECHERCHE_UNITE_PAR_NOM_VISITOR__INCLUDED_)
#define RECHERCHE_UNITE_PAR_NOM_VISITOR__INCLUDED_

#include <list>
#include <iostream>
#include <fstream>
#include <string>

#include "AbsUnitVisitor.h"
#include "UnitContainer.h"

using FoundDroneIterator = std::list<UnitIterator_const>::iterator;
using FoundDroneIterator_const = std::list<UnitIterator_const>::const_iterator;


class RechercheUniteParNomVisitor : public AbsUnitVisitor
{

public:
	RechercheUniteParNomVisitor(std::string nom);
	virtual ~RechercheUniteParNomVisitor() = default;

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

	virtual int getNumberFound() const { return m_unitsFound.size(); }
	virtual FoundDroneIterator begin();
	virtual FoundDroneIterator_const cbegin() const;
	virtual FoundDroneIterator_const cend() const;
	virtual FoundDroneIterator end();
	virtual void reset();

private:
	template<typename T>
	void defaultVisitAdminUnit(const T& unit);

	std::string m_searchedName;
	UnitIterator_const* m_currentIterator;
	std::list<UnitIterator_const> m_unitsFound;
};
#endif // !defined(RECHERCHE_UNITE_PAR_NOM_VISITOR__INCLUDED_)
