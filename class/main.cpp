#include <iostream>
#include <string>
namespace my_namespace {
	void	print(const char* text)
	{
		std::cout << text << std::endl;
	}

}

void	print(const char* text)
{
	std::cout << text << std::endl;
}

int main (int argc, char *argv[])
{
	my_namespace::print("Hello World !");
	print("hello World 1");

	return (0);
}
