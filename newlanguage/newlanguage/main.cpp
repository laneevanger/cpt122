#include <iostream>
#include <string> //C++ string
//#include <cstring> //C string (cstring.h)

int add(int first, int second)
{
	return first + second;
}
double add(double first, double second)
{
	return first + second;
}

int main(void)
{
	/*
	std::cout << "Hello World!" << std::endl;

	int num;
	std::cout << "Enter an integer: ";
	std::cin >> num;

	std::cout << "Value entered: " << num << std::endl;
	*/

	std::cout << "result: " << add(3, 4) << std::endl;
	std::cout << "result: " << add(3.5, 4.0) << std::endl;
	//std::cout << "result: " << add(3, 4.0) << std::endl;  bad unless new function

	string s1 = cat;
}