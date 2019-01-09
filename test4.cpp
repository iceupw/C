// 多重继承使用虚函数

#include <iostream>
using namespace std;
class A {
    public:
        virtual void f() {cout<<"Call A"<<endl;} //必须使用virtual声明
};
class B {
    public:
        virtual void f() {cout<<"Call B"<<endl;} //必须使用virtual声明
};
class C:public A,public B {
    public:
        void f() {cout<<"Call C"<<endl;} //可省略关键字virtual
};

int main()
{
    A *pa;
    B *pb;
    C *pc,c;
    pa = &c;
    pb = &c;
    pc = &c;
    pa->f();
    pb->f();
    pc->f();
}
