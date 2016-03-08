#ifndef MULTITHREADING_PRODUCERCONSUMER_PRODUCER_H
#define MULTITHREADING_PRODUCERCONSUMER_PRODUCER_H

#include "../Buffer.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace multithreading
{
	namespace producerConsumer
	{

		class Producer
		{
		public:
			Producer(std::string identifier, char product, unsigned long timeout, multithreading::Buffer& buffer);
			~Producer();

			void start();
			void stop();

			void waitToFinish() const;

		private:
			Producer(Producer& producer);

			void run() const;

			std::string mIdentifier;
			char mProduct;
			unsigned long mTimeout;
			multithreading::Buffer &mBuffer;

			bool mRun;
			std::thread *mThread;
		};

	}
}

#endif // MULTITHREADING_PRODUCERCONSUMER_PRODUCER_H
