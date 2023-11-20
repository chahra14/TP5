///////////////////////////////////////////////////////////
//  RechercheDroneParIdVisitor.h
//  Implementation of the Class RechercheDroneParIdVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "RechercheDroneParIdVisitor.h"
#include "Division.h"
#include "Drone.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "QG.h"

RechercheDroneParIdVisitor::RechercheDroneParIdVisitor(int id)
	: m_searchedId(id), m_droneFound(nullptr), m_isDroneFound(false), m_currentIterator(nullptr)
{
}

void RechercheDroneParIdVisitor::visitDrone(Drone& unit)
{
	// À COMPLÉTER: rediriger vers la méthode similaire pour paramètre constant
}

void RechercheDroneParIdVisitor::visitDrone(const Drone& unit)
{

	// À COMPLÉTER: si les identifiants sont les mêmes:
	// 1. Assigner le drone à l'attribut chargé de le stocker; et
	// 2. Assigner 'true' à l'attribut chargé de déterminer si on a trouvé.
}

void RechercheDroneParIdVisitor::visitDivision(Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitDivision(const Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadron(Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadron(const Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitQG(QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

void RechercheDroneParIdVisitor::visitQG(const QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
}

template<typename T>
void RechercheDroneParIdVisitor::defaultVisitAdminUnit(const T& unit)
{
	// À COMPLÉTER: itérer sur le contenu de l'unité et appliquer
	// le visiteur sur chaque élément.
	// NOTE: vous devez stopper la recherche dès qu'un drone a été trouvé.
}



