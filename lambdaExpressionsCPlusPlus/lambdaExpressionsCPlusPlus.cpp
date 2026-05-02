#include <iostream>

using namespace std;

//auto keyword is used generally when a library used without knowing its methods' return type. It arranges return type automatically.

auto automaticReturn2011(int x, float y) -> float	//C++ 2011 and beyond versions (It is needed to specify return type :) )
{
	return x + y;
}

auto automaticReturn2014(int x, float y)		//C++ 2014 and beyond versions
{
	return x + y;
}

int main()
{
	//auto 2011: 
	cout << "auto method 2011 usage: " << automaticReturn2011(2, 3.54) << endl;

	//auto 2014:
	cout << "auto method 2014 usage: " << automaticReturn2014(2, 3.54) << endl;
	
	
	//lambda capture usage and template:
	auto sum = [](auto x, auto y)
		{
			return x + y;
		};

	auto x = 2;			//usage of variables with auto keyword
	auto y = 3.54;

	cout << "Sum with lambda capture: " << sum(x, y) << endl;

	int count = 0;

	//lambda expression usage and template:
	auto autoCount = [&]()
		{
			return ++count;
		};


	//lambda expression uses all of the elements of above of it inside of used function/method with [&] reference specifier.
	//and with "[&]" expression, method processes the variables itself.
	cout << "Count with lambda expression [&]: " << autoCount() << endl;
	cout << "Count with lambda expression [&]: " << autoCount() << endl;
	cout << "Count with lambda expression [&]: " << autoCount() << endl;


	count = 0;

	// uses the variables above of it and make them local inside of it. Makes processes locally 
	//with "[=]" expression and the keyword "mutable".
	auto autoCount2 = [=]() mutable
		{
			++count;

			cout << "Count inside of the lambda [=]: " << count << endl;
		};
	
	//count increases locally.
	autoCount2();
	autoCount2();
	autoCount2();

	//make sure no change in "count".
	cout << "Count with lambda expression [=]: " << count << endl;

}