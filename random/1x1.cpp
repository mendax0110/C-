// include the header file
#include <iostream>

// main function
int main()
{
	for(int i = 1; i <= 10; i++)
	{
		for(int i2 = 1; i2 <= 10; i2++)
		{
			// print the number
			std::cout << i << "x" << i2 << "=" << i*i2 << " ";
		}
		// print a new line
		std::cout << std::endl << std::endl;
	}
}