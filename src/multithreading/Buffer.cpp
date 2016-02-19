#include "Buffer.h"

multithreading::Buffer::Buffer(unsigned int size) :
	mSize(size)
{
}

multithreading::Buffer::Buffer(Buffer& buffer)
{
}

multithreading::Buffer::~Buffer()
{
}

void multithreading::Buffer::put(char c)
{
	std::unique_lock<std::mutex> lock(mMutex);
	mConditionVariable.wait(lock, [this]
	{
		return (mQueue.size() < mSize);
	});

	mQueue.push(c);

	lock.unlock();
	mConditionVariable.notify_all();
}

char multithreading::Buffer::get()
{
	char c = 0;

	std::unique_lock<std::mutex> lock(mMutex);
	mConditionVariable.wait(lock, [this]
	{
		return (!mQueue.empty());
	});

	c = mQueue.front();
	mQueue.pop();

	lock.unlock();
	mConditionVariable.notify_all();

	return c;
}
