 /***************\
 *  CPU-Toaster  *
 *  0.2          *
 *  by bison     *
 *  GPL v2       *
 \***************/
 
#include<iostream>
#include<string>
#include<pthread.h> //sleep(int)
#include<time.h> //guess ^^

// Check windows
#if _WIN32 || _WIN64
	#if _WIN64
		#define ENVIRONMENT 64
	#else
		#define ENVIRONMENT 32
	#endif
#endif

// Check GCC
#if __GNUC__
	#if __x86_64__ || __ppc64__
		#define ENVIRONMENT 64
	#else
		#define ENVIRONMENT 32
	#endif
#endif

using namespace std;

int main(int argc, char* argv[])
{
	int runtime = 0;
	if (argc > 1)
	{
		runtime = atoi(argv[1]);
	}

	int sleepTime = 0;
	if (argc > 2)
	{
		sleepTime = atoi(argv[2]);
	}
	
	bool makeOutput = false;
	if (argc > 3)
	{
		makeOutput = true;
	}
				
	if (runtime == 0)
	{
		while(true)
		{ sleep(sleepTime); }
	}
	else
	{
		int outputTimer = time(NULL);
		int runtimeWithSeconds = time(NULL) + runtime;
		while(runtimeWithSeconds > time(NULL))
		{
			if (makeOutput && outputTimer <= time(NULL))
			{
				std::cout << "rest: " << (runtimeWithSeconds - time(NULL))  << "\n";
				outputTimer = time(NULL) + 1;
			}
			if (sleepTime > 0)
			{ usleep(sleepTime * 1000); }
			//{ sleep(sleepTime); }
		}
	}
	
	if (makeOutput)
	{
		std::cout << "fin: " << time(NULL) << "\n";
	}	
}
