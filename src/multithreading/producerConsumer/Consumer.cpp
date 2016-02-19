#include "Consumer.h"

multithreading::producerConsumer::Consumer::Consumer(std::string identifier, unsigned long timeout, multithreading::Buffer& buffer):
	mIdentifier(identifier),
	mTimeout(timeout),
	mBuffer(buffer),
	mRun(false),
	mThread(NULL)
{
}

multithreading::producerConsumer::Consumer::Consumer(Consumer& consumer):
	mBuffer(consumer.mBuffer)
{
}

multithreading::producerConsumer::Consumer::~Consumer()
{
	stop();
	waitToFinish();
}

void multithreading::producerConsumer::Consumer::start()
{
	if (mThread == NULL)
	{
		mRun = true;
		mThread = new std::thread(&multithreading::producerConsumer::Consumer::run, this);
	}
}

void multithreading::producerConsumer::Consumer::stop()
{
	mRun = false;
}

void multithreading::producerConsumer::Consumer::waitToFinish() const
{
	if ((mThread != NULL) && mThread->joinable())
	{
		mThread->join();
	}
}

void multithreading::producerConsumer::Consumer::run() const
{
	while (mRun)
	{
		char product = mBuffer.get();
		std::cout << mIdentifier << " consumed: " << product << "." << '\n';

		std::this_thread::sleep_for(std::chrono::milliseconds(mTimeout));
	}
}
