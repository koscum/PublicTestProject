#ifndef TESTPROJECT_H
#define TESTPROJECT_H

#include <string>

class TestProject
{
public:
	TestProject();
	virtual ~TestProject();

	virtual int main(int argc, char **argv) =0;

	std::string getTitle();

protected:
	TestProject(std::string title);

	std::string mTitle;
};

#endif // TESTPROJECT_H
