#include <OMLogger/Logger.hpp>

#include "DataStructure/DataStructure.hpp"
#include "Tree/Tree.hpp"
#include "Algo/Algo.hpp"
#include "Pathfinding/Pathfinding.hpp"

int main()
{
	OM::Logger::Logger::GetInstance()->SetDisplaySettings(OM::Logger::DisplayVerbosity);

	// Comment this for display debug
	OM::Logger::Logger::GetInstance()->SetVerbosity(
		OM::Logger::VerbosityInfo | OM::Logger::VerbosityWarning | OM::Logger::VerbosityError);

	// OM_LOG_INFO("----------------");
	// OM_LOG_INFO(" Data Structure ");
	// OM_LOG_INFO("----------------");
	// DataStructure::Exercice();
	
	// OM_LOG_INFO("----------------");
	// OM_LOG_INFO("      Tree      ");
	// OM_LOG_INFO("----------------");
	// Tree::Exercice();

	// OM_LOG_INFO("----------------");
	// OM_LOG_INFO("      Algo      ");
	// OM_LOG_INFO("----------------");
	// Algo::Exercice();

	OM_LOG_INFO("----------------");
	OM_LOG_INFO("   Pathfinding  ");
	OM_LOG_INFO("----------------");
	Pathfinding::Exercice();
}