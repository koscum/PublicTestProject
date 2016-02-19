#ifndef MAIN_H
#define MAIN_H

#include "../Buffer.h"
#include "Consumer.h"
#include "Producer.h"

#include <iostream>

namespace multithreading
{
	namespace producerConsumer
	{

		class Main
		{
		public:
			Main();
			~Main();

			int main(int argc, char **argv);
		};

	}
}

#endif // MAIN_H
