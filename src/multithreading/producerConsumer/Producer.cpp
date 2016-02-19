#include "Producer.h"

multithreading::producerConsumer::Producer::Producer(std::string identifier, char product, unsigned long timeout, multithreading::Buffer& buffer):
	mIdentifier(identifier),
	mProduct(product),
	mTimeout(timeout),
	mBuffer(buffer),
	mRun(false),
	mThread(NULL)
{
}

multithreading::producerConsumer::Producer::Producer(Producer& producer):
	mBuffer(producer.mBuffer)
{
}

multithreading::producerConsumer::Producer::~Producer()
{
	stop();
	waitToFinish();
}

void multithreading::producerConsumer::Producer::start()
{
	if (mThread == NULL)
	{
		mRun = true;
		mThread = new std::thread(&multithreading::producerConsumer::Producer::run, this);
	}
}

void multithreading::producerConsumer::Producer::stop()
{
	mRun = false;
}

void multithreading::producerConsumer::Producer::waitToFinish() const
{
	if ((mThread != NULL) && mThread->joinable())
	{
		mThread->join();
	}
}

void multithreading::producerConsumer::Producer::run() const
{
	while (mRun)
	{
		mBuffer.put(mProduct);
		std::cout << mIdentifier << " produced: " << mProduct << "." << '\n';

		std::this_thread::sleep_for(std::chrono::milliseconds(mTimeout));
	}
}
