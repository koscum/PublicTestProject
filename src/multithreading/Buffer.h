#ifndef BUFFER_H
#define BUFFER_H

#include <queue>
#include <mutex>
#include <condition_variable>

namespace multithreading
{

	class Buffer
	{
	public:
		Buffer(unsigned int size = Buffer::DEFAULT_SIZE);
		~Buffer();

		void put(char c);
		char get();

		static const unsigned int DEFAULT_SIZE = 32;

	private:
		Buffer(Buffer& buffer);

		unsigned int mSize;
		std::queue<char> mQueue;
		std::mutex mMutex;
		std::condition_variable mConditionVariable;
	};

}

#endif // BUFFER_H
