 ///
 /// @file    sizeof_object.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-28 21:46:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Object{
	public:
		Object();
		~Object();
		void print();
	private:           //64位操作系统下
		int _a;        //int型，在一般系统上占据4个内存字节
		char _b;       //char型，占一个内存字节，与int合并后浪费3个字节
		float _c;      //float型（单精度浮点型），占4个内存字节，浪费4个内存字节
		double _d;     //double型（双精度浮点型），占8个内存字节，无浪费情况
		short _e[5];   //short型数组，每个元素占2个内存字节，共占10个内存字节，
		               //浪费6个内存字节
		char & _f;     //引用，当成指针维护，占用8个内存字节，无浪费
		double & _g;   //引用，当成指针维护，占用8个内存字节，无浪费
		static int _h; //static成员，位于全局静态区（公共内存），不影响
		               //单个对象的大小，占0个内存字节
};

int Object::_h = 0;

Object::Object()
:_a(0)
,_b('b')
,_c(0.0)
,_d(1.1)
//,_e(1,2,3,4,5)
,_f(_b)
,_g(_d)
{
//	int i;
//	for(i=0; i<5; i++) _e[i] = 0;
//	for(i=0; i<5; i++) cout<<_e[i]<<endl;
	cout<<"Object()"<<endl;
}

Object::~Object(){
	cout<<"~Object()"<<endl;
}

void Object::print()
{
	cout<<"this is just a test"<<endl;
}

int main(){
	/*
	 *即使类中没有一个成员变量，创建出来的对象也
	  占一个字节的空间，目的是让其能够在栈上依附，
	  以此来区分不同的对象
	 *
	 */
	Object obj;
	obj.print();
	cout<<"sizeof(Object->obj)"<<sizeof(obj)<<endl;
	cout<<"sizeof(Object)"<<sizeof(Object)<<endl;
	return 0;
}
