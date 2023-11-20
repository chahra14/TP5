///////////////////////////////////////////////////////////
//  ExtractionProprietesVisitor.h
//  Implementation of the Class ExtractionProprietesVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "ExtractionProprietesVisitor.h"
#include "Division.h"
#include "Drone.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "QG.h"

int ExtractionProprietesVisitor::m_indent = 0;

ExtractionProprietesVisitor::ExtractionProprietesVisitor()
	: m_stream(std::cout)
{
}

ExtractionProprietesVisitor::ExtractionProprietesVisitor(std::ostream& stream)
	: m_stream(stream)
{
}

void ExtractionProprietesVisitor::visitDrone(Drone& unit)
{
	// � COMPL�TER: rediriger vers la m�thode similaire pour param�tre constant
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
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitDivision(const Division& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitEscadron(Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitEscadron(const Escadron& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitEscadronMandataire(EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitEscadronMandataire(const EscadronMandataire& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitQG(QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::visitQG(const QG& unit)
{
	// � COMPL�TER: utiliser la m�thode par d�faut pour les classes d�riv�es de AdminUnit
}

void ExtractionProprietesVisitor::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
}

template<typename T>
void ExtractionProprietesVisitor::defaultVisitAdminUnit(const T& unit)
{
	// � COMPL�TER: ajouter les �l�ments suivants au flux de donn�es
	//              de maniere � reproduire la sortie (similaire au cas du drone)
	//				- le nom de l'unit�
	//	            - les paires cl�-valeur pour chacune des propri�t�s

	// Dans un deuxieme temps: it�rer sur le contenu de l'unit� et visiter chaque �l�ment
}

