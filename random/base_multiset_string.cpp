/*include the libraries*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

/*main function*/
int main()
{
    int a[10] = {7, 22, 9, 1, 18, 30, 100, 22, 85, 13};
    int aSize = sizeof(a) / sizeof(int);

    std::multiset<int, std::less<int> > intMultiset(a, a + aSize);

    /*print the elements of the multiset*/
    cout << "Printing the elements of the multiset: ";
    multiset<int>::iterator it;

    for(it = intMultiset.begin(); it != intMultiset.end(); ++it)
        cout << " " << *it;
    cout << endl << endl;

    std::ostreambuf_iterator<int> output(cout, " ");

    /*print the elements of the multiset*/
    cout << "There are currently " << intMultiset.count(15) << " elements in the multiset\n\n";

    intMultiset.insert(15);
    intMultiset.insert(15);

    /*print the elements of the multiset*/
    cout << "After two inserts, there are currently " << intMultiset.count(15) << " elements of 15 in the multiset\n\n";

    /*print the elements of the multiset*/
    cout << "Printing the elements of the multiset: ";

    for(it = intMultiset.begin(); it != intMultiset.end(); ++it)
        cout << " " << *it;
    cout << endl << endl;

    return 0;
}