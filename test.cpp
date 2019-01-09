#include <iostream>
using namespace std;

const double PI=3.14159;
// 静态连篇
class Point {
    private:
        double x,y;
    public:
        Point(double i,double j) {x=i;y=j;}
        double area() {return 0;}
};

class Circle:public Point {
    private:
        double radius;
    public:
        Circle(double a,double b,double r):Point(a,b){radius=r;}
        double area(){return PI*radius*radius;}
};

int main(){
    Point a(1.5,6.7);
    Circle c(1.5,6.7,2.5);
    cout<<"点面积为"<<a.area()<<endl; //输出"点面积为0"
    cout<<"圆面积为"<<c.area()<<endl; //输出"圆面积为19.6349"
    Point * p=&c; //派生类对象的地址赋给指向基类的指针
    cout<<"圆面积为"<<p->area()<<endl; //调用基类的area函数, 输出"圆面积为0"
    Point &rc=c; //派生类对象初始化基类的引用
    cout<<"圆面积为"<<rc.area()<<endl; //调用基类的area函数, 输出"圆面积为0"
    Circle * p1=&c; //派生类对象的地址赋给指向派生类的指针
    cout<<"圆面积为"<<p1->area()<<endl; //调用派生类area函数, 输出"圆面积为19.6349"
    Circle &rc1=c; //派生类对象初始化派生类的引用
    cout<<"圆面积为"<<rc1.area()<<endl; //调用派生类area函数, 输出"圆面积为19.6349“
}