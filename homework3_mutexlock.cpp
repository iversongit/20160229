 ///
 /// @file    homework3_mutexlock.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-29 03:41:29
 ///
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;
class MutexLock{
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
	private:
	   pthread_mutex_t _mutex;
};

MutexLock::MutexLock(){
	cout<<"MutexLock()"<<endl;
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock(){
	cout<<"~MutexLock()"<<endl;
    pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock(){
	cout<<"lock()"<<endl;
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock(){
	cout<<"unlock()"<<endl;
	pthread_mutex_unlock(&_mutex);
}
MutexLock mutex;               //全程一把锁即可
void * pthread_func(void* p){
	cout<<"child lock()"<<endl;
	mutex.lock();
	pthread_exit(NULL);
}

int main(void){

	mutex.lock();
//	sleep(2);
	pthread_t phid;
	pthread_create(&phid,NULL,pthread_func,NULL);    //创建子进程，以实现锁的互斥机制
	sleep(2);
	pthread_join(phid,NULL);	//少此句将不会看到互斥锁的效果
	return 0;
}
