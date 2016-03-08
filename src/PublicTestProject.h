#ifndef PUBLICTESTPROJECT_H
#define PUBLICTESTPROJECT_H

#include "TestProject.h" // Base class: Main
#include "multithreading/producerConsumer/ProducerConsumerProject.h"

#include <algorithm>
#include <vector>

class PublicTestProject: public ::TestProject
{
public:
	PublicTestProject();
	virtual ~PublicTestProject();

	virtual int main(int argc, char** argv);

private:
	std::vector<::TestProject *> mTestProjects;
};

#endif // PUBLICTESTPROJECT_H
