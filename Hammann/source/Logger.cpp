/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 			  Logger Class     														      */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Logger.h"

std::mutex multithreadMutex;
static Util::Logger * instancePointer;

Util::Logger * Util::Logger::getInstance(void)
{
	if (instancePointer == nullptr)
	{
		multithreadMutex.lock();
		instancePointer = new Logger();
		multithreadMutex.unlock();
	}
	return instancePointer;
}

void Util::Logger::Start(Priority _priorityThreshold = WARNING, const std::string& _logFile = "")
{
	instancePointer->activated = true;
	instancePointer->priorityThreshold = _priorityThreshold;
	if (_logFile != "")
		instancePointer->logFileStream.open(_logFile.c_str());
}

void Util::Logger::Stop(void)
{
	instancePointer->activated = false;
	if (instancePointer->logFileStream.is_open())
		instancePointer->logFileStream.close();
}

void Util::Logger::Write(Priority _priority = DEBUG, const std::string& _message = "Default Message")
{
	if (instancePointer->activated && _priority >= instancePointer->priorityThreshold)
	{
		std::ostream & stream = instancePointer->logFileStream.is_open() ? instancePointer->logFileStream : std::cout;
		stream << instancePointer->priorityNames[_priority] << " : " << _message << std::endl;
	}
}
