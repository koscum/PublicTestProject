#include "Main.h"

multithreading::producerConsumer::Main::Main()
{
}

multithreading::producerConsumer::Main::~Main()
{
}

int multithreading::producerConsumer::Main::main(int argc, char **argv)
{
	std::cout << "ProducerConsumer" << '\n';

	Buffer buffer;

	Producer producerA("Producer A", 'A', 1240, buffer);
	Producer producerB("Producer B", 'B', 3290, buffer);
	Producer producerC("Producer C", 'C', 370, buffer);

	Consumer consumerA("Consumer A", 1270, buffer);
	Consumer consumerB("Consumer B", 5380, buffer);

	producerA.start();
	producerB.start();
	producerC.start();

	consumerA.start();
	consumerB.start();

	producerA.waitToFinish();
	producerB.waitToFinish();
	producerC.waitToFinish();

	consumerA.waitToFinish();
	consumerB.waitToFinish();

	return 0;
}
