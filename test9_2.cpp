#include <iostream>

using namespace std;

int swap(int *p,int *q)
{
    int e = 3;
    p = &e;
    cout<<*p<<endl;
}

int main()
{
    int x = 1;
    int y = 2;
    int *p = &x;
    int *q = &y;

    string xx = "HELLO WORLD";
    // cout<<&xx<<endl;
    // string *p = "HELLO WORLD";
    // cout<<*p<<endl;
    // int *p = &x;
    // p = x;
    // cout<<*p<<endl;
    // cout<<&x;
    swap(p,q);
    cout<<*p;
}

