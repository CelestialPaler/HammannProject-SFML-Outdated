/***************************************************************************************************/
/*								        		 		  Hammann Project  														      */
/*								        		 			  Logger Class     														      */
/*                                                    www.tianshicangxie.com                                                       */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once

// Header file
#include <string>
#include <mutex>
#include <fstream>
#include <iostream>
#include <chrono>

#include "Config.hpp"
#include "ConsoleColor.h"

/***************************************************************************************************/
// Namespace : Util
// Basic utilities for all kinds of uses.
namespace Util 
{
	/***************************************************************************************************/
	// Class : Logger
	// Implemented in a style of singleton with multithread security.
	// Do the logging thingy ... 
	class Logger
	{
	public:
		/***************************************************************************************************/
		// Enum : Logger priority
		enum Priority
		{
			DEBUG,
			INFO,
			WARNING,
			FATAL
		};

	public:
		// Get the pointer of the instance
		/// Singleton
		static Logger * GetInstance(void);

	public:
		// Start the logger
		/// - _priorityThreshold : Logger only log the message with priority above the threshold.
		/// - _logFile : The path to logfile. ("" for logging into std::cout)
		static void Start(Priority _priorityThreshold = WARNING,const std::string& _logFile = "");
		// Stop the logger
		static void Stop(void);
		// Write messages to the logger
		static void Write(Priority _priority = DEBUG, const std::string& _message = "Default Message");

	private:
		Logger(void) {}
		// Refused
		Logger(const Logger & _logger) = delete;
		// Refused
		Logger & operator = (const Logger & _logger) = delete;

		const std::string GetCurrentSystemTime() const;

	private:
		bool activated;
		std::ofstream logFileStream;
		Priority priorityThreshold;

	private:
		const std::string priorityNames[4] =
		{
			"DEBUG",
			"INFO",
			"WARNING",
			"FATAL"
		};
	};
}


