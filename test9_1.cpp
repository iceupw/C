#include <iostream>
#include <string>
using namespace std;

string &string::operator=(string &a)
{
    if(this==&a) //防止a=a这样的赋值
        return *this; //a=a,退出
    delete st;
    st=new char [strlen (a.st) +1]; //申请内存
    strcpy(st, a.st); //将对象a的数据复制一份到申请的内存区
    return *this; 
} //返回this指针指向的对象

int main()
{
    string s1("HELLO"),s2("WORLD");
    s1 = s2;
}