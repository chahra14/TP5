///////////////////////////////////////////////////////////
//  RechercheUniteParNomVisitor.h
//  Implementation of the Class RechercheUniteParNomVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
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
	// � COMPL�TER: rediriger vers la m�thode similaire pour param�tre constant
}

void RechercheUniteParNomVisitor::visitDrone(const Drone& unit)
{
	// � COMPL�TER: si les noms sont les m�mes, ajouter l'unit� � la structure de donn�es
	// contenant les �l�ments trouv�s.
}

void RechercheUniteParNomVisitor::visitDivision(Division& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitDivision(const Division& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitEscadron(Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitEscadron(const Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitQG(QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheUniteParNomVisitor::visitQG(const QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

template<typename T>
void RechercheUniteParNomVisitor::defaultVisitAdminUnit(const T& unit)
{
	// � COMPL�TER: it�rer sur le contenu de l'unit�
	// et appliquer le visiteur sur chaque �l�ment
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


