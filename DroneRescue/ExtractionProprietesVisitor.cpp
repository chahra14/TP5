///////////////////////////////////////////////////////////
//  ExtractionProprietesVisitor.h
//  Implementation of the Class ExtractionProprietesVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "ExtractionProprietesVisitor.h"
#include "Division.h"
#include "Drone.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "QG.h"
#include <algorithm>

int ExtractionProprietesVisitor::m_indent = 0;

ExtractionProprietesVisitor::ExtractionProprietesVisitor()
	: m_stream(std::cout)
{
}

ExtractionProprietesVisitor::ExtractionProprietesVisitor(std::ostream& stream)
	: m_stream(stream)
{
}

//TODO : Don't understand
void ExtractionProprietesVisitor::visitDrone(Drone& unit) 
{
	// À COMPLÉTER: rediriger vers la méthode similaire pour paramètre constant
	visitDrone(const_cast<const Drone&>(unit)); 
}

void ExtractionProprietesVisitor::visitDrone(const Drone& unit)
{
	m_stream << unit.getName() << ": {";
	for (auto const& it : unit.getProperties())
		m_stream << "(" << it.first << ":" << it.second << ") ";
	m_stream << "}" << std::endl;
}

void ExtractionProprietesVisitor::visitDivision(Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitDivision(const Division& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitEscadron(Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitEscadron(const Escadron& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitQG(QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::visitQG(const QG& unit)
{
	// À COMPLÉTER: utiliser la méthode par défaut pour les classes dérivées de AdminUnit
	defaultVisitAdminUnit(unit);
}

void ExtractionProprietesVisitor::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
}

//TODO

template<typename T>
void ExtractionProprietesVisitor::defaultVisitAdminUnit(const T& unit)
{
	// À COMPLÉTER: ajouter les éléments suivants au flux de données
	//              de maniere à reproduire la sortie (similaire au cas du drone)
	//				- le nom de l'unité
	//	            - les paires clé-valeur pour chacune des propriétés


	m_stream << unit.getName() << ": {";

	std::for_each(unit.getProperties().begin(), unit.getProperties().end(), [this](const auto& pair) {
		m_stream << pair.first << " : " << pair.second << ", ";
		});
	m_stream << "}" << std::endl;

	// Dans un deuxieme temps: itérer sur le contenu de l'unité et visiter chaque élément

	indent(m_stream);
	for (auto it = unit.cbegin(); it != unit.cend(); ++it) {
		defaultVisitAdminUnit(*it);
	}

