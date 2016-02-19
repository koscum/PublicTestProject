#ifndef CONSUMER_H
#define CONSUMER_H

#include "../Buffer.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

namespace multithreading
{
	namespace producerConsumer
	{

		class Consumer
		{
		public:
			Consumer(std::string identifier, unsigned long timeout, multithreading::Buffer& buffer);
			~Consumer();

			void start();
			void stop();

			void waitToFinish() const;

		private:
			Consumer(Consumer& consumer);

			void run() const;

			std::string mIdentifier;
			unsigned long mTimeout;
			multithreading::Buffer &mBuffer;

			bool mRun;
			std::thread *mThread;
		};

	}
}

#endif // CONSUMER_H
