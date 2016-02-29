 ///
 /// @file    object_arr.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-28 23:41:11
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class Point{
	public:
		Point();
		Point(int x,int y);
		~Point();
		void print();
	private:
		int _x;
		int _y;
};

#if 1
Point::Point()
:_x(0)
,_y(0)
{
	cout<<"Point()"<<endl;
}
#endif

Point::Point(int x,int y)
:_x(x)
,_y(y)
{
	static int _iCount = 0;
	++_iCount;//前置自加比后置自加的效率要更高
	cout<<"Point(int,int) iCount:"<<_iCount<<endl;
}

Point::~Point(){
	cout<<"~Point()"<<endl;
}

void Point::print(){
	cout<<"("<<_x<<" , "<<_y<<")"<<endl;
}

int main(void){
	Point p[2]; //调用默认构造函数初始化数组
	/*类名（参数）--> 构造匿名对象*/
	Point p1[] = {Point(1,1),Point(2,2)};
	/*5个对象中其余的3个对象
	 *将调用默认构造函数进行
	  初始化工作
	 * */
	Point p2[5] = {Point(3,3),Point(4,4)};
	return 0;
}
