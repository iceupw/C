#include <iostream>
using namespace std;
class A {
    public:
    A(){ }
        virtual void func() {cout<<"构造A"<<endl;}
    ~A(){ }
        virtual void fund() {cout<<"清除A"<<endl;}
};
class B:public A {
    public:
        B() {func();}
        void fun() {cout<<"开始…";func();}
        ~B() {fund();}
};
class C:public B {
    public:
        C() { }
        void func() {cout<<"类C"<<endl;}
        ~C() {fund();}
        void fund() {cout<<"清除C"<<endl;}
};

int main()
{
    C c;
    c.fun();
}