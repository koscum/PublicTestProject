#ifndef MULTITHREADING_PRODUCERCONSUMER_PRODUCERCONSUMERPROJECT_H
#define MULTITHREADING_PRODUCERCONSUMER_PRODUCERCONSUMERPROJECT_H

#include "../../TestProject.h" // Base class: Main
#include "../Buffer.h"
#include "Consumer.h"
#include "Producer.h"

#include <iostream>

namespace multithreading
{
	namespace producerConsumer
	{

		class ProducerConsumerProject: public ::TestProject
		{
		public:
			ProducerConsumerProject();
			virtual ~ProducerConsumerProject();

			virtual int main(int argc, char **argv);
		};

	}
}

#endif // MULTITHREADING_PRODUCERCONSUMER_PRODUCERCONSUMERPROJECT_H
