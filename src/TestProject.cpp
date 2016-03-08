#include "TestProject.h"

TestProject::TestProject()
{
}

TestProject::TestProject(std::string title):
	mTitle(title)
{
}

TestProject::~TestProject()
{
}

std::string TestProject::getTitle()
{
	return mTitle;
}
