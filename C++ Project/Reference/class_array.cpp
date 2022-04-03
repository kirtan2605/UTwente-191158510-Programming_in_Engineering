#include <iostream>
#define N 5
 
using namespace std;
 
class Test {
    // private variables
    int x, y;
 
public:
    // dummy constructor
    Test() {}
 
    // parameterised constructor
 
    Test(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
 
    // function to print
    void print() { cout << x << " " << y << endl; }
};
 
int main()
{
    // allocating dynamic array
    // of Size N using new keyword
    Test* arr = new Test[N];
 
    // calling constructor
    // for each index of array
    for (int i = 0; i < N; i++) {
        arr[i] = Test(i, i + 1);
    }
 
    // printing contents of array
    for (int i = 0; i < N; i++) {
        arr[i].print();
    }
 
    return 0;
}