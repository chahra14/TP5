///////////////////////////////////////////////////////////
//  LoggingDecorator.cpp
//  Implementation of the Class LoggingDecorator
//  Created on:      2023-11-11
//  Original author: Eric Germain basé sur les travaux de Francois Guibault
///////////////////////////////////////////////////////////

#include "LoggingDecorator.h"


LoggingDecorator::LoggingDecorator(const AbsUnit& component, std::string logFileName, std::string division)
	: AbsUnit(component.getName(), component.getFullPath()), m_component(component.clone()), m_logFileName(logFileName)
{
	m_properties.insert(std::pair<std::string, std::string>("division", division));
	outf.open(m_logFileName, std::ios::out | std::ios::trunc);
	outf.flush();
	outf.close();
}

LoggingDecorator::LoggingDecorator(const AbsUnit& component, std::string logFileName, std::string division, std::string escadron)
	: AbsUnit(component.getName()), m_component(component.clone()), m_logFileName(logFileName)
{
	m_properties.insert(std::pair<std::string, std::string>("division", division));
	m_properties.insert(std::pair<std::string, std::string>("escadron", escadron));
	outf.open(m_logFileName, std::ios::out | std::ios::trunc);
	outf.flush();
	outf.close();
}

LoggingDecorator::LoggingDecorator(const LoggingDecorator& mdd)
	: AbsUnit(mdd.getName(), mdd.getFullPath()), m_component(UnitPtr(mdd.m_component->clone()))
{
	m_properties = mdd.getProperties();
	m_logFileName = mdd.m_logFileName;
}

LoggingDecorator::~LoggingDecorator()
{
	outf.flush();
	outf.close();
}

LoggingDecorator* LoggingDecorator::clone(void) const
{
	// À COMPLÉTER
}

std::string LoggingDecorator::getUnitType(void) const
{
	return m_component->getUnitType();
}

void LoggingDecorator::accept(class AbsUnitVisitor& v)
{
	// À COMPLÉTER
}

void LoggingDecorator::accept(class AbsUnitVisitor& v) const
{
	// À COMPLÉTER
}

AbsUnit& LoggingDecorator::addUnit(const AbsUnit& member)
{
	return m_component->addUnit(member);
}

UnitIterator LoggingDecorator::begin()
{
	return m_component->begin();
}

UnitIterator_const LoggingDecorator::cbegin() const
{
	return m_component->cbegin();
}

UnitIterator_const LoggingDecorator::cend() const
{
	return m_component->cend();
}

UnitIterator LoggingDecorator::end()
{
	return m_component->end();
}

void LoggingDecorator::deleteUnit(UnitIterator_const child)
{
	m_component->deleteUnit(child);
}

void LoggingDecorator::outputTime(std::ofstream& o) const
{ // Adaptation de l'exemple au https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170
	struct tm newtime;
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// On obtient le temps sous forme d'entier 64-bit.
	_time64(&long_time);

	// Conversion au temps local
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Argument invalide dans _localtime64_s.");
		exit(1);
	}

	// Conversion en representation ASCII
	err = asctime_s(timebuf, 26, &newtime);
	if (err)
	{
		printf("Argument invalide dans asctime_s.");
		exit(1);
	}
	o << std::endl;
	o << "##########" << std::endl;
	o << timebuf;
	o << "##########" << std::endl;
}

std::ostream& LoggingDecorator::printToStream(std::ostream& o) const
{
	outf.open(m_logFileName, std::ios::out | std::ios::app);
	outputTime(outf);
	outf << *m_component << std::endl;
	outf.flush();
	outf.close();
	return o << *m_component;
}


