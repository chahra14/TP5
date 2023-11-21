///////////////////////////////////////////////////////////
//  EscadronMandataire.cpp
//  Implementation of the Class EscadronMandataire
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "EscadronMandataire.h"

#define MOT_DE_PASSE "MotDePasse"

EscadronMandataire::EscadronMandataire(Escadron& escadron)
	: EscadronAbs(escadron.getName(), escadron.getDivision()),
	  m_escadronReel(&escadron), m_motDePasseEnClair(MOT_DE_PASSE), m_jeton_ptr(new JetonSecurite())
{
}

EscadronMandataire::EscadronMandataire(const EscadronMandataire& rhs)
	: EscadronAbs(rhs), m_jeton_ptr(new JetonSecurite()), m_escadronReel(rhs.m_escadronReel) {}

EscadronMandataire::~EscadronMandataire()
{
}

EscadronMandataire* EscadronMandataire::clone() const
{
	// À compléter
	return new EscadronMandataire(*this);
}

std::string EscadronMandataire::getUnitType(void) const
{
	// À compléter
	return (*m_escadronReel).getUnitType();
}

std::string EscadronMandataire::getDivision(void) const
{
	// À compléter
	return (*m_escadronReel).getDivision();
}
unsigned int EscadronMandataire::getId(void) const
{
	// À compléter
	return (*m_escadronReel).getId();
}

//TODO : not sure if it call verifierSecurite
void EscadronMandataire::donnerAcces() const
{
	// À compléter
	m_jeton_ptr->donnerAcces();
}

void EscadronMandataire::enleverAcces() const
{
	// À compléter
	m_jeton_ptr->enleverAcces();
}

bool EscadronMandataire::getAccesStatut() const
{
	return m_jeton_ptr->getAccesStatut();
}

std::ostream& EscadronMandataire::printToStream(std::ostream& o) const
{
	verifierSecurite();
	if (getAccesStatut()) {
		o << "\t\t" << getName() << " (div: " << getDivision() << ")" << std::endl;

		++m_indent;
		//À compléter
		for (auto it = m_escadronReel->cbegin(); it != m_escadronReel->cend(); ++it) {
			std::cout << "\t\t";
			indent(o);
			o << *it;
		}
		--m_indent;
		std::cout << std::endl;
	}
	else
		o << "\t\tACCES REFUSE A " << getName() << std::endl;
	return o;
}

bool EscadronMandataire::verifierSecurite() const
{
	std::string tampon;
	if (getAccesStatut())
		return true;
	std::cout << std::endl
		<< "#########################" << std::endl
		<< "#### Acces demande a l'escadron XXXX" << getId() % 10 << "..." << std::endl
		<< "#### Entrez le mot de passe: ";
	std::cin >> tampon;
	if (tampon == m_motDePasseEnClair) {
		donnerAcces();
		std::cout << "#### Mot de passe accepte, merci."
			<< std::endl << "#########################" << std::endl << std::endl;
		return true;
	} 
	std::cout << "!!!! Mot de passe refuse, desole."
		<< std::endl << "#########################" << std::endl << std::endl;
	return false;

}

void EscadronMandataire::accept(class AbsUnitVisitor& v)
{
	v.visitEscadronMandataire(*this);
}

void EscadronMandataire::accept(class AbsUnitVisitor& v) const
{
	v.visitEscadronMandataire(const_cast<const EscadronMandataire&>(*this)); 
}
