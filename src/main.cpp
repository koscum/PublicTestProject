#include "multithreading/Buffer.h"
#include "multithreading/producerConsumer/Main.h"

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "Hello world!" << '\n';

	multithreading::producerConsumer::Main producerConsumerMain;

	return producerConsumerMain.main(argc, argv);
}
