#include <iostream>
#include "log.h"

class Log
{
public:
	enum Level
	{
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if(m_LogLevel >= LevelError){
			NLOG("[ERROR]: ");
			LOG(message);
		}
	}

	void Warning(const char* message)
	{
		if(m_LogLevel >= LevelWarning){
			NLOG("[WARN]: ");
			LOG(message);
		}
	}

	void Info(const char* message)
	{
		if(m_LogLevel >= LevelInfo){
			NLOG("[INFO]: ");
			LOG(message);
		}
	}

	// constructor
	// Log() = delete; - this will deletes the default constructor
	// if u keep constructor in private - then u cant call outside the class - so this will make u that u cant create any instance of that class
	// usually we will do this above scenario at the time of constant classes
	Log()
	{
		m_LogLevel = LevelInfo;
	}

	Log(Level level)
	{
		SetLevel(level);
	}
};

int main(void)
{
	Log log;
	log.SetLevel(Log::LevelError);
	log.Error("Ganesh");
	log.Warning("Ganesh");
	log.Info("Ganesh");
}