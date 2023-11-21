///////////////////////////////////////////////////////////
//  DronesRescue.cpp
//  Implementation of the main function
//  Created on:      2023-10-30
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include <iostream>

#include "QG.h"
#include "Division.h"
#include "Escadron.h"
#include "EscadronMandataire.h"
#include "Drone.h"
#include "PlanMissions.h"
#include "Mission.h"
#include "ExtractionProprietesVisitor.h"
#include "RechercheDroneParIdVisitor.h"
#include "RechercheUniteParNomVisitor.h"
#include "LoggingDecorator.h"

AbsUnit& addDivision(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(std::shared_ptr<Division>(new Division(name, &unit))));
}

AbsUnit& addEscadron(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(std::shared_ptr<Escadron>(new Escadron(name, &unit))));
}

AbsUnit& addDrone(AbsUnit& unit, std::string name)
{
	return unit.addUnit(*(std::shared_ptr<Drone>(new Drone(name, &unit))));
}

AbsUnit& addDecoratedEscadron(AbsUnit& unit, std::string escadronName, std::string logFileName)
{
	std::shared_ptr<Escadron> escadronPtr(new Escadron(escadronName, &unit));
	std::shared_ptr<LoggingDecorator> ld(new LoggingDecorator(*escadronPtr, logFileName, unit.getName()));
	return unit.addUnit(*ld);
}

int main(int argc, char** argv)
{
	srand((unsigned)time(NULL));

	// PARTIE A - Creation d'une organisation avec deux divisions ayant deux escadrons chacune
	QG theQG("PolyDrones International inc.");
	AbsUnit& div1 = addDivision(theQG, "Division Lassonde"); 
	AbsUnit& escadronGIGL = addEscadron(div1, "Escadron GIGL"); 
	addDrone(escadronGIGL, "Drone LOG2990");
	addDrone(escadronGIGL, "Drone LOG2990"); // Doublon place volontairement
	addDrone(escadronGIGL, "Drone INF3995");
	addDrone(escadronGIGL, "Drone INF8970");
	addDrone(escadronGIGL, "Drone LOG3900");
	addDrone(escadronGIGL, "Drone LOG8970");
	AbsUnit& escadronELE = addEscadron(div1, "Escadron ELE");
	addDrone(escadronELE, "Drone ELE1001");
	addDrone(escadronELE, "Drone ELE2003");
	addDrone(escadronELE, "Drone ELE3000");
	addDrone(escadronELE, "Drone ELE8080");

	AbsUnit& div2 = addDivision(theQG, "Division principale");
	AbsUnit& escadronGBM = addEscadron(div2, "Escadron GBM"); // REMPLACER CETTE LIGNE PAR LA SUIVANTE POUR TESTER LE DECORATEUR
//	AbsUnit& escadronGBM = addDecoratedEscadron(div2, "EscadronGBM", "LogEscadronGBM.txt"); // UTILISER CETTE LIGNE A LA PLACE DE LA PRECEDENTE POUR TESTER LE DECORATEUR
	addDrone(escadronGBM, "Drone GBM1100");
	addDrone(escadronGBM, "Drone GBM2100");
	addDrone(escadronGBM, "Drone GBM3100");
	addDrone(escadronGBM, "Drone GBM8970");
	AbsUnit& escadronIND = addEscadron(div2, "Escadron IND");
	addDrone(escadronIND, "Drone IND1901");
	addDrone(escadronIND, "Drone IND2902");
	addDrone(escadronIND, "Drone IND3903");
	addDrone(escadronIND, "Drone IND8974");

	// PARTIE B - Affichage de l'organisation
	std::cout << "Affichage de la structure de PolyDrones International: " << std::endl << std::endl;
	std::cout << theQG << std::endl << std::endl;

	// PARTIE C - Creation d'un plan de mission

	PlanMissions pm1("Plan mission 1", &(dynamic_cast<Division&>(div1)));
	EscadronMandataire escadronMandataireGIGL(dynamic_cast<Escadron&>(escadronGIGL));
	pm1.addMission(*(new Mission("Mission vegetale", "Sauvetage de mes tulipes.", "Demain.", &escadronMandataireGIGL)));
	pm1.addMission(*(new Mission("Mission animale", "Sauvetage de mes poissons rouges.", "Maintenant.", &escadronMandataireGIGL)));

	// PARTIE D - Affichage du plan de mission
	std::cout << "Affichage des plans de missions: " << std::endl << std::endl;
	std::cout << pm1 << std::endl;
	
	// PARTIE E - Test du premier visiteur - ExtractionProprietesVisitor
	std::cout << std::endl << "Test du premier visiteur..." << std::endl;
	std::unique_ptr<ExtractionProprietesVisitor> v1(new ExtractionProprietesVisitor());
	theQG.accept(*v1);
	
	// PARTIE F - Test du second visiteur - RechercheDroneParIdVisitor
	std::string tampon;
	int idRecherche;
	std::cout << std::endl << "Test du second visiteur..." << std::endl;
	while (true) {
		std::cout << "Entrez l'identifiant du drone recherche: ";
		std::cin >> tampon;

		try {
			idRecherche = std::stoi(tampon);
			break;
		}
		catch (...) {
			std::cout << "Entree invalide." << std::endl;
		}
	}

	std::cout << "Resultats de la recherche pour id = " << idRecherche << "..." << std::endl;
	std::unique_ptr<RechercheDroneParIdVisitor> v2 (new RechercheDroneParIdVisitor(idRecherche));
	theQG.accept(*v2);
	if (v2->queryIsDroneFound()) {
		std::unique_ptr<AbsUnitVisitor> v1b (new ExtractionProprietesVisitor());
		(v2->getDroneFound())->accept(*v1b);
	}
	else {
		std::cout << "Recherche infructueuse." << std::endl;
	}
	
	// PARTIE F - Test du troisième visiteur - RechercheUniteParNomVisitor

	std::string nomRecherche;
	std::cout << std::endl << "Test du troisieme visiteur..." << std::endl;
	std::cout << "Entrez le nom de l'unite recherchee: ";
	std::cin.ignore();
	std::getline(std::cin, nomRecherche);

	std::cout << "Resultats de la recherche pour nom = " << nomRecherche << "..." << std::endl;
	std::unique_ptr<RechercheUniteParNomVisitor> v3 (new RechercheUniteParNomVisitor(nomRecherche));
	theQG.accept(*v3);
	int compteur = 0;
	for (FoundDroneIterator it = v3->begin(); it != v3->end(); it++) {
		std::unique_ptr<AbsUnitVisitor> v1c (new ExtractionProprietesVisitor());
		std::cout << ++compteur << ": ";
		(*it)->accept(*v1c);
	}
	if (compteur == 0) {
		std::cout << "Recherche infructueuse." << std::endl;
	}

	// PARTIE G - Test du décorateur - Cette partie devrait quand meme fonctionner si le decorateur n'est pas encore implemente.
	std::cout << std::endl << "Test du decorateur..." << std::endl;
	std::cout << escadronGBM << std::endl;

	return 0;
 }
