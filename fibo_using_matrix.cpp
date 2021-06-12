// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int multiply(int f[2][2], int m[2][2])
{
    int w = f[0][0]*m[0][0] + f[0][1]*m[1][0];
    int x = f[0][0]*m[0][1] + f[0][1]*m[1][1];
    int y = f[1][0]*m[0][0] + f[1][1]*m[1][0];
    int z = f[1][0]*m[0][1] + f[1][1]*m[1][1];
    
    f[0][0] = w;
    f[0][1] = x;
    f[1][0] = y;
    f[1][1] = z;
}

void power(int f[2][2], int n)
{
    int m[2][2] = {{1, 1}, {1, 0}};
    for(int i=2; i<=n;i++)
        multiply(f, m);
}

int fibo(int n)
{
    int f[2][2] = {{1, 1}, {1, 0}};
    
    if(n==0)
        return 0;
    power(f, n-1);
    
    return f[0][0];
}
int main() {
    // Write C++ code here
    int n = 9;
    cout << fibo(n);
    return 0;
}