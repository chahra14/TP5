///////////////////////////////////////////////////////////
//  LoggingDecorator.h
//  Interface of the Class LoggingDecorator
//  Created on:      2023-11-11
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#if !defined(LOGGING_DECORATOR__INCLUDED_)
#define LOGGING_DECORATOR__INCLUDED_

#include <fstream>
#include "AbsUnit.h"

class LoggingDecorator : public AbsUnit
{
public:
	LoggingDecorator(const AbsUnit& component, std::string logFileName, std::string division);
	LoggingDecorator(const AbsUnit& component, std::string logFileName, std::string division, std::string escadron);
	LoggingDecorator(const LoggingDecorator& mdd);
	~LoggingDecorator();

	const AbsUnit& getComponent() const { return *m_component; }
	AbsUnit& getComponent() { return *m_component; }

	virtual LoggingDecorator* clone(void) const;
	virtual std::string getUnitType(void) const;

	virtual void accept(class AbsUnitVisitor& v);
	virtual void accept(class AbsUnitVisitor& v) const;

	virtual AbsUnit& addUnit(const AbsUnit& member);
	virtual UnitIterator begin();
	virtual UnitIterator_const cbegin() const;
	virtual UnitIterator_const cend() const;
	virtual UnitIterator end();
	virtual void deleteUnit(UnitIterator_const child);

	virtual std::ostream& printToStream(std::ostream& o) const;


protected:
	UnitPtr m_component;
	std::string m_logFileName;
	mutable std::ofstream outf;
	void outputTime(std::ofstream& o) const;
};

#endif // !defined(LOGGING_DECORATOR__INCLUDED_)
