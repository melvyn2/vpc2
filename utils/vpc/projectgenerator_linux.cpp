/**
 * 
 * Adapter for "project" generators on Linux
 * 
 */ 
#include "projectgenerator_linux.h"

struct linux_project_generator_t
{
	const char* name;
	CLinuxProjectGenerator* generator;
};

CUtlVector<linux_project_generator_t> g_Generators;

CLinuxProjectGenerator::CLinuxProjectGenerator(const char* name)
{
	g_Generators.AddToTail(linux_project_generator_t {name, this});
}

CLinuxProjectGenerator* CLinuxProjectGenerator::GetGenerator(const char* name)
{
	for(int i = 0; i < g_Generators.Count(); i++)
	{
		auto gen = g_Generators[i];
		if(strcmp(gen.name, name) == 0) return gen.generator;
	}
	return nullptr;
}