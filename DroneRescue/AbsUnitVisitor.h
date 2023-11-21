///////////////////////////////////////////////////////////
//  AbsUnitVisitor.h
//  Interface of the Class AbsUnitVisitor
//  Created on:      2023-11-06
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(ABS_UNIT_VISITOR__INCLUDED_)
#define ABS_UNIT_VISITOR__INCLUDED_


class AbsUnitVisitor
{

public:
	AbsUnitVisitor() = default;
	virtual ~AbsUnitVisitor() = default;

	virtual void visitDivision(class Division& unit) = 0;
	virtual void visitDrone(class Drone& unit) = 0;
	virtual void visitEscadron(class Escadron& unit) = 0;
	virtual void visitEscadronMandataire(class EscadronMandataire& unit) = 0;
	virtual void visitQG(class QG& unit) = 0;

	virtual void visitDivision(const class Division& unit) = 0;
	virtual void visitDrone(const class Drone& unit) = 0;
	virtual void visitEscadron(const class Escadron& unit) = 0;
	virtual void visitEscadronMandataire(const class EscadronMandataire& unit) = 0;
	virtual void visitQG(const class QG& unit) = 0;

};
#endif // !defined(ABS_UNIT_VISITOR__INCLUDED_)
