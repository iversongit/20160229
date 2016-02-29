 ///
 /// @file    const_object.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-28 21:09:30
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point{
	public:
		Point();
		Point(int x, int y);
		void setX(int x);
		void setY(int y);
		void print();
		void print() const;
		~Point();
	private:
		int _x;
		int _y;
};

Point::Point()
:_x(0)
,_y(0)
{
	cout<<"Point()"<<endl;
}

Point::Point(int x, int y)
:_x(x)
,_y(y)
{
	cout<<"Point(int x,int y)"<<endl;
}

void Point::setX(int x){
	_x = x;
}

void Point::setY(int y){
	_y = y;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_x<<" , "
		<<_y<<")"<<endl;
}

/* const成员函数print,不能修改_x,_y*/
void Point::print() const{
	cout<<"const->("<<_x<<" , "
		<<_y<<")"<<endl;
}

int main(void){
	Point p1;
	p1.print();
	cout<<"----------------"<<endl;

	/*
	 *声明一个普通类变量p2，则p2即可调用非
	 *const成员函数，也可调用const成员函数,
	  若出现重载成员函数（如本程序的print函数），
	  则只能调用隶属于非const成员函数的那一个
	*/ 
	Point p2(6,6);
	p2.print();
	p2.setX(8);
	p2.setY(8);
	p2.print();
	cout<<"****************"<<endl;

	/*
	 *声明一个const对象（类变量）
	  p3只能调用const成员函数，但是const对象也能
	  调用非const类型的析构函数
	 *
	*/
	const Point p3(3,3);
	p3.print();
//	p3.setX(1);
//	p3.setY(1);
//	p3.print();

	return 0;
}
