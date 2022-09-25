/*include the header file*/
#include <iostream>

/*using namespace std*/
using namespace std;

void function(int* num2)
{
	cout << "address of num2 in function: " << num2 << endl;
	*num2 *= 10;
}

/*main function*/
int main()
{
	int num1 = 5;
	/*print the address of num1*/
	cout << "address of the function: " << num1 << endl;
	cout << "address: " << &num1 << endl;
	function(&num1);
	cout << "Number after the function: " << num1 << endl;
}