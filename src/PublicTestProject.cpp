#include "PublicTestProject.h"

PublicTestProject::PublicTestProject()
{
	mTestProjects.insert(mTestProjects.end(), new multithreading::producerConsumer::ProducerConsumerProject());
	mTestProjects.insert(mTestProjects.end(), new gui::gtkmm3::Gtkmm3Project());
}

PublicTestProject::~PublicTestProject()
{
}

int PublicTestProject::main(int argc, char** argv)
{
	unsigned int selection;
	std::string clearScreen = std::string(128, '\n');

	while (true)
	{
		std::cout << clearScreen;

		std::cout << "Hello! Welcome to Public Test Project." << '\n'
		          << '\n'
		          << "Currently available test projects:" << '\n';

		unsigned int selectionId = 1;
		std::for_each(mTestProjects.begin(), mTestProjects.end(), [&selectionId] (::TestProject* testProject)
		{
			std::cout << '\t' << selectionId++ << ") " << testProject->getTitle() << '\n';
		});

		std::cout << '\t' << "0) Exit" << '\n'
		          << '\n'
		          << "Your choice: ";

		selection = 0;
		std::cin >> selection;
		if (selection == 0)
		{
			return 0;
		}
		else if (selection <= mTestProjects.size())
		{
			::TestProject *testProject = mTestProjects[selection - 1];

			std::cout << testProject->getTitle() << " returned with exit code " << testProject->main(argc, argv) << "." << '\n';
		}
	}
}
