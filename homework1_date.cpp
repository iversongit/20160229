 ///
 /// @file    homework1_date.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-29 01:29:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

/*
 *定义一个满足如下要求的Date类
  1）用下面的格式输出日期
		年.月.日（2011.01.31）
  2）可以运行在日期上加一天操作
  3）设置日期操作
  4）年，月，日可以各用一个整数表示
 *
 */ 

/*2月暂定为28天*/
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
class Date{
	public:
		Date(int,int,int);
		~Date();
		void set(int year,int month,int day);
		void show();
		void isValuable();
		Date & operator ++ (int);
		Date & operator ++ ();
	private:
		int _year;
		int _month;
		int _day;
};

Date::Date(int year=1970,int month=1, int day=1){
	cout<<"Date(int,int,int)"<<endl;
	set(year,month,day);
}

Date::~Date(){
	cout<<"~Date()"<<endl;
}

void Date::set(int year,int month,int day){    //设置日期
	_year = year;
	_month = month;
	_day = day;
	if((year%4 == 0 && year%100 != 0) || year%400 == 0){  //对闰年进行处理
		days[1] = 29;
	}
	isValuable();
	days[1] = 28;
}

void Date::show(){     //显示日期
	cout<<_year<<"."<<_month<<"."<<_day<<endl;
}

void Date::isValuable(){    //判断日期是否合法
	if(_year<1970 || _year>9999 || _month<1 || _month> 12 || _day<1 || _day>days[_month-1]){
	   cout<<"wrong date,return the origin date"<<endl;
	   _year = 1970;
	   _month = 1;
	   _day = 1;
	}
}

Date & Date::operator ++ (){   //日期向后推一天
	++(_day);
	if(_day > days[_month-1])
	{
		++(_month);
		_day = 1;
	}

	if(_month > 12){
		++(_year);
		_month = 1;
		_day = 1;
	}

	if(_year > 9999){
		cout<<"wrong date,return the origin date"<<endl;
		_year = 1970;
		_month = 1;
		_day = 1;
	}

	return *this;
}

Date & Date::operator ++ (int rhs){
	Date *pOld = new Date(_year,_month,_day);
	return *pOld;
}

int main(void){
	Date d1;
	d1.show();
	cout<<"----------------"<<endl;
	d1.set(2016,2,25);       //正确
	d1.show();
	cout<<"----------------"<<endl;
	(++d1)++;				 //正确
	d1.show();
	cout<<"----------------"<<endl;
	d1.set(2015,2,29);       //报错
	d1.show();
	cout<<"----------------"<<endl;
	d1.set(2015,5,32);       //报错
	d1.show();
	return 0;
}
