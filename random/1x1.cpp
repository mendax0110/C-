/*include the libraries*/
#include <iostream>

/*main part of the program*/
int main()
{
	for(int i = 1; i <= 10; i++)
	{
		for(int i2 = 1; i2 <= 10; i2++)
		{
			std::cout << i << "x" << i2 << " = " << i*i2 << " ";
		}
		std::cout << std::endl << std::endl;
	}
}
