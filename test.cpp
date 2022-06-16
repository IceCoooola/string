#include"string.h"
using namespace IceCola;

void test1()
{
	string a("hello world");
	string b(a);
	string c = b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	//string的三种遍历方法
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	string::iterator e = a.begin();
	while (e != a.end())
	{
		std::cout << *e << " ";
		e++;
	}
	std::cout << std::endl;
	for (auto e : a)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}


void test2()
{
	string a("hello world");
	a.insert(0, '1');
	a.insert(0, "hi ");
	std::cout << a << std::endl;
	a.erase(0, 1);
	std::cout << a << std::endl;
	a.erase(6, 100);
	std::cout << a << std::endl;
	std::cout << a.find('i') << std::endl;
	std::cout << a.find('x') << std::endl;
	a += 'x';
	std::cout << a << std::endl;
	a += "hello";
	std::cout << a << std::endl;

}

int main()
{
	//test1();
	test2();
	return 0;
}