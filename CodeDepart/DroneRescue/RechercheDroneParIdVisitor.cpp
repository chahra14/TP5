///////////////////////////////////////////////////////////
//  RechercheDroneParIdVisitor.h
//  Implementation of the Class RechercheDroneParIdVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
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
	// � COMPL�TER: rediriger vers la m�thode similaire pour param�tre constant
}

void RechercheDroneParIdVisitor::visitDrone(const Drone& unit)
{

	// � COMPL�TER: si les identifiants sont les m�mes:
	// 1. Assigner le drone � l'attribut charg� de le stocker; et
	// 2. Assigner 'true' � l'attribut charg� de d�terminer si on a trouv�.
}

void RechercheDroneParIdVisitor::visitDivision(Division& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitDivision(const Division& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadron(Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadron(const Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitQG(QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void RechercheDroneParIdVisitor::visitQG(const QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

template<typename T>
void RechercheDroneParIdVisitor::defaultVisitAdminUnit(const T& unit)
{
	// � COMPL�TER: it�rer sur le contenu de l'unit� et appliquer
	// le visiteur sur chaque �l�ment.
	// NOTE: vous devez stopper la recherche d�s qu'un drone a �t� trouv�.
}



