 ///
 /// @file    singleton.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-29 00:37:24
 ///
#include <stdio.h> 
#include <iostream>

using std::endl;
using std::cout;

class Singleton{
	public:
		static Singleton * gInstance();
		void destroy();
	private:
		Singleton();
		static Singleton * _instance;
};

Singleton * Singleton::_instance = NULL;

Singleton::Singleton(){
	cout<<"Singleton()"<<endl;
}

Singleton * Singleton::gInstance(){
	cout<<"gInstance()"<<endl;
	if(_instance == NULL){
		_instance = new Singleton;
	}
		return _instance;
}

void Singleton::destroy(){
	if(_instance != NULL){
		delete _instance;
		_instance = NULL;
	}
}

int main(void){
	Singleton *p1 = Singleton::gInstance();
	Singleton *p2 = Singleton::gInstance();
	Singleton *p3 = Singleton::gInstance();

	printf("*p1: %p\n",p1);
	printf("*p2: %p\n",p2);
	printf("*p3: %p\n",p3);	
	
	p3->destroy();

	char *p = new char[1];    //将上下两部分明显区分开来
	

	Singleton *p4 = Singleton::gInstance();
	Singleton *p5 = Singleton::gInstance();
	printf("*p4: %p\n",p4);
	printf("*p5: %p\n",p5);
	delete[] p;
	return 0;
}
