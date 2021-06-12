#include <iostream>
using namespace std;

int fibo(int n)
{
    if(n <= 1)
        return n;
    return fibo(n-1) + fibo(n-2);
}
int main() {
    // Write C++ code here
    int n = 2;
    cout << fibo(n);
    return 0;
}