#include "multithreading/Buffer.h"
#include "multithreading/producerConsumer/Main.h"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int selection = 0;

	while (true)
	{
		std::cout << std::string(128, '\n');

		std::cout << "Hello! Welcome to Public Test Project." << '\n'
		          << '\n'
		          << "Currently available test projects:" << '\n'
		          << '\t' << "1) Multithreading::ProducerConsumer" << '\n'
		          << '\t' << "0) Exit" << '\n'
		          << '\n'
		          << "Your choice: ";

		std::cin >> selection;
		switch(selection)
		{
			case 1:
			{
				multithreading::producerConsumer::Main producerConsumerMain;

				std::cout << "Multithreading::ProducerConsumer returned with exit code " << producerConsumerMain.main(argc, argv) << "." << '\n';
			}
			case 0:
			{
				return 0;
			}
			default:
			{
				continue;
			}
		}
	}
}
