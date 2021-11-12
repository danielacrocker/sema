#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

class MyData
{
	int i;
	string s;

public:
	void doTask(int ii, string ss)
	{
		i = ii;
		s = ss;
		cout << " i = " << i << " s = " << s << endl;
	};
};

class DataWrapper
{
private:
	MyData data;
	std::mutex m;

public:
	template<typename Function>
	void processData(Function userFunc)
	{
		std::lock_guard<std::mutex> lock(m);

		// passing protected data to user-supplied function
		userFunc(data);
	}
};

void goodFunction(MyData& protectedData)
{
	protectedData.doTask(1, "my String");
}

MyData* unprotected;

void badFunction(MyData& protectedData)
{
	unprotected = &protectedData;
}

DataWrapper w;

void foo()
{
	w.processData(goodFunction);

	// passing in a bad function
	w.processData(badFunction);

	// unprotected access to protected data
	unprotected->doTask(99, "hacked string");
}


// M A I N

int main()
{
	std::thread t(foo);
	t.join();
	return 0;
}

	
	
