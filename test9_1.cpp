#include <iostream>
#include <string>
using namespace std;
class str{
    private:
        char *st;
    public:
        str( char *s ); //使用字符指针的构造函数
        str( str& s); //使用对象引用的构造函数
        str& operator=( str& a ); //重载使用对象引用的赋值运算符
        str& operator=( char *s ); //重载使用指针的赋值运算符
        void print( ) {cout<<st<<endl;} //输出字符串
        ~str( ) {delete st;}
};

str::str(char *s)
{
    st=new char[strlen(s)+1]; //为st申请内存
    strcpy(st,s); //将字符串s复制到内存区st
}


str::str(str& a)
{
    st=new char[strlen(a.st)+1]; //为st申请内存
    strcpy(st,a.st); //将对象a的字符串复制到内存区st
}
str& str::operator=(str& a)
{
    if (this==&a) //防止出现a＝a这样的赋值
        return *this; //a＝a，退出
    delete st; //不是自身，先释放内存空间
    st=new char[strlen(a.st)+1]; //重新申请内存
    strcpy(st,a.st); //将对象a的字符串复制到申请的内存区
    return *this; //返回this指针指向的对象
}
str& str::operator=(char *s)
{
    delete st; //是字符串直接赋值，先释放内存空间
    st=new char[strlen(s)+1]; //重新申请内存
    strcpy(st,s); //将字符串s复制到内存区st
    return *this;
}

int main() {
    str s1("We"),s2("They"),s3(s1); //调用构造函数和复制构造函数
    s1.print();s2.print();s3.print(); //显示We They We
    s2=s1=s3; //调用赋值操作符
    s3="Go home!"; //调用字符串赋值操作符
    s3=s3; //调用赋值操作符但不进行赋值操作
    s1.print();s2.print();s3.print(); //显示We We Go home！
}