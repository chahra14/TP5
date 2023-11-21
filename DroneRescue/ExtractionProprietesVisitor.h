///////////////////////////////////////////////////////////
//  ExtractionProprietesVisitor.h
//  Interface of the Class ExtractionProprietesVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(EXTRACTION_PROPRIETES_VISITOR__INCLUDED_)
#define EXTRACTION_PROPRIETES_VISITOR__INCLUDED_

#include <iostream>
#include <fstream>
#include <string>

#include "AbsUnitVisitor.h"

class ExtractionProprietesVisitor : public AbsUnitVisitor
{

public:
	ExtractionProprietesVisitor();
	ExtractionProprietesVisitor(std::ostream& stream);
	virtual ~ExtractionProprietesVisitor() = default;

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

	virtual std::ostream& getStream() const { return m_stream; }
private:
	static int m_indent;
	void indent(std::ostream& o) const;
	
	template<typename T>
	void defaultVisitAdminUnit(const T& unit);

	std::ofstream m_file;
	std::ostream& m_stream;
};
#endif // !defined(EXTRACTION_PROPRIETES_VISITOR__INCLUDED_)
