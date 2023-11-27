///////////////////////////////////////////////////////////
//  RechercheUniteParNomVisitor.h
//  Implementation of the Class RechercheUniteParNomVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "RechercheUniteParNomVisitor.h"
#include "Division.h"
#include "Drone.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "QG.h"

RechercheUniteParNomVisitor::RechercheUniteParNomVisitor(std::string nom)
	: m_searchedName(nom), m_currentIterator(nullptr)
{
}

void RechercheUniteParNomVisitor::visitDrone(Drone& unit)
{
	// À COMPLÉTER: rediriger vers la méthode similaire pour paramètre constant
	visitDrone(const_cast<const Drone&>(unit));
}

void RechercheUniteParNomVisitor::visitDrone(const Drone& unit)
{
	// À COMPLÉTER: si les noms sont les mêmes, ajouter l'unité à la structure de données
	// contenant les éléments trouvés.

	if (m_searchedName == unit.getName()) {
		m_unitsFound.push_back(*m_currentIterator); 
	}
}

void RechercheUniteParNomVisitor::visitDivision(Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitDivision(const Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitEscadron(Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitEscadron(const Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitQG(QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void RechercheUniteParNomVisitor::visitQG(const QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

template<typename T>
void RechercheUniteParNomVisitor::defaultVisitAdminUnit(const T& unit)
{
	// À COMPLÉTER: itérer sur le contenu de l'unité
	// et appliquer le visiteur sur chaque élément

	for (auto it = unit.cbegin(); it != unit.cend(); it++) {
		m_currentIterator = new UnitIterator_const(it);
		it->accept(*this);
	}
}

FoundDroneIterator RechercheUniteParNomVisitor::begin()
{
	return m_unitsFound.begin();
}

FoundDroneIterator_const RechercheUniteParNomVisitor::cbegin() const
{
	return m_unitsFound.begin();
}

FoundDroneIterator_const RechercheUniteParNomVisitor::cend() const
{
	return m_unitsFound.cend();
}

FoundDroneIterator RechercheUniteParNomVisitor::end()
{
	return m_unitsFound.end();
}

void RechercheUniteParNomVisitor::reset()
{
	m_unitsFound.clear();
}
