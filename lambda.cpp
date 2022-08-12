/*code from:https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/cpp/lambda-expressions-in-cpp.md*/
/*include the libraries*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <typename C> void print(const string& s, const C& c)
{
    cout << s;
    
    for(const auto& e : c)
    {
        cout << e << " ";
    }

    cout << endl;

}

void fillVector(vector<int>& v)
{
    /*local static variable*/
    static int nextValue = 1;

    /*the lambda expression*/
    generate(v.begin(), v.end(), []() { return nextValue++; });
}

/*main function*/
int main()
{
    /*The number of elements in the vector*/
    const int elementCount = 9;

    /*Create a vector object with each element set to 1*/
    vector<int> v(elementCount, 1);

    /*These variables hold the previous two elements of the vector*/
    int x = 1;
    int y = 1;

    /*Sets each element in the vector to the sum of the
     *previous two elements
     */
     generate_n(v.begin() + 2, elementCount - 2, [=]() mutable throw() -> int
     {
         int n = x + y;
         x = y;
         y = n;
         return n;
     });
   
    /*Print the vector*/
    print("Vector v after call to generate_n() with lambda: ", v);

    /*print the local variables*/
    cout << "x: " << x << " y: " << y << endl;

    /*fill the vector after 1st call to fillVector()*/
    fillVector(v);
    print("Vector v after 1st call to fillVector(): ", v);
    /*fill the vector after 2nd call to fillVector()*/
    fillVector(v);
    print("Vector v after 2nd call to fillVector(): ", v);
}   