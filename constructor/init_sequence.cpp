#include <iostream>

using namespace std;

class X
{
private:
    int i;
    int j;
public:
//    X(int val) : j(val), i(j) {};
    X(int n = 0) : j(n), i(n) {};
    X(istream& is = cin) {is >> i >> j;};

    void print(void) {cout << "i:"<< i << " j:" << j << endl;}
};

int main()
{
    X num;
    num.print();
    return 0;
}