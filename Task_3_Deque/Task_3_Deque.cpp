// Task_3_Deque.cpp : Defines the entry point for the console application.
//

#include <vector>

#include "MyDeque.h"

int main()
{
	MyDeque<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);

	std::cout << "---------------------------\n";

	std::cout << a.pop_front();

	/*a.push_front(7);
	a.push_back(8);

	a.size();
	a.empty();
	std::cout << "\n\n";
	
	a.front();
	a.back();*/



	std::vector<int> a1;
	//a1.insert();

	system("pause");
	return 0;
}

