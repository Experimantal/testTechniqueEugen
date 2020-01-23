#include <iostream>

int main(int argc, char** argv)
{
	for (int it = 1; it != argc; ++it)
		std::cout << argv[it];
	return (0);
}