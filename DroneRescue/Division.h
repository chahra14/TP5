///////////////////////////////////////////////////////////
//  Division.h
//  Interface of the Class Division
//  Created on:      2023-10-30
//  Original author: Eric Germain bas� sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(DIVISION__INCLUDED_)
#define DIVISION__INCLUDED_

#include "AdminUnit.h"

class Division : public AdminUnit
{

public:
	Division(std::string name, AbsUnit * parent = nullptr);
	Division(const Division& rhs);
	virtual ~Division();
	virtual Division* clone() const;
	virtual std::string getUnitType(void) const { return DIVISION_TYPE; }

	//TODO : was virtual but I changed it
	virtual void accept(class AbsUnitVisitor& v);
	virtual void accept(class AbsUnitVisitor& v) const;
};

#endif // !defined(DIVISION__INCLUDED_)
