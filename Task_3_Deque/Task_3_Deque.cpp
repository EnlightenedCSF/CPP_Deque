#include <vector>
#include <string>

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

	std::cout << "---------------------------\n\n";
	
	std::cout << a.pop_front() << '\n';
	std::cout << a.pop_front() << '\n';
	std::cout << a.pop_back() << '\n';
	std::cout << a.pop_back() << '\n';
	std::cout << a.size();

	std::cout << "---------------------------\n\n";
	MyDeque<char*> b;
	b.push_back("The");
	b.push_back("quick");
	b.push_back("brown");
	b.push_back("fox");
	b.push_back("jumps");
	b.push_back("over");
	b.push_back("the");
	b.push_back("lazy");
	b.push_back("dog.");
	while (b.size() > 5)
	{
		std::cout << b.pop_back() << '\n';
	}
	std::cout << "---------------------------\n";
	for (int i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << '\n';
	}

	std::cout << (std::string)b;

	/*auto n = new MyDeque<double>();
	n->push_front(15);
	std::cout << "\n" << n;*/

	system("pause");
	return 0;
}

