// WriteAndReadLock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
//#include <stdio.h>
//#include <pthread.h>
//#include <windows.h>
//
//pthread_mutex_t count_mutex;
//pthread_mutex_t write_mutex;
//int count = 0;
//
//void read_lock() {
//	pthread_mutex_lock(&count_mutex);
//	count++;
//	if (count == 1) {
//		pthread_mutex_lock(&write_mutex);
//	}
//	pthread_mutex_unlock(&count_mutex);
//}
//
//void read_unlock() {
//	pthread_mutex_lock(&count_mutex);
//	count--;
//	if (count == 0) {
//		pthread_mutex_unlock(&write_mutex);
//	}
//}
//
//
//void write_lock() {
//	pthread_mutex_lock(&write_mutex);
//}
//
//void write_unlock() {
//	pthread_mutex_unlock(&write_mutex);
//}
//
//void* func1(void* v) {
//	read_lock();
//	int i; 
//	for (i = 0; i < 10; ++i) {
//		printf("thread 1\n");
//		Sleep(1);
//	}
//	read_unlock();
//	return NULL;
//}
//
//void* func2(void* v) {
//	read_lock();
//	int i;
//	for (i = 0; i < 10; ++i) {
//		printf("thread 2\n");
//		Sleep(1);
//	}
//	read_unlock();
//	return NULL;
//}
//
//void* func3(void* v) {
//	Sleep(1);
//	write_lock();
//	printf("thread 3\n");
//	write_unlock();
//	return NULL;
//}
//
//int main()
//{
//	pthread_mutex_init(&count_mutex, NULL);
//	pthread_mutex_init(&write_mutex, NULL);
//	pthread_t p1, p2, p3;
//	pthread_create(&p1, NULL, func1, NULL);
//	pthread_create(&p2, NULL, func2, NULL);
//	pthread_create(&p3, NULL, func3, NULL);
//	pthread_join(p1, NULL);
//	pthread_join(p2, NULL);
//	pthread_join(p3, NULL);
//	pthread_mutex_destroy(&count_mutex);
//	pthread_mutex_destroy(&write_mutex);
//    return 0;
//}

#include <thread>
#include <iostream>
#include <mutex>
#include <windows.h>
std::mutex count_mutex;
std::mutex write_mutex;
int count = 0;

void read_lock() {
	count_mutex.lock();
	count++;
	if (count == 1) {
		write_mutex.lock();
	}
	count_mutex.unlock();
}
void read_unlock() {
	count_mutex.lock();
	count--;
	if (count == 0) {
		write_mutex.unlock();
	}
	count_mutex.unlock();
}

void write_lock() {
	write_mutex.lock();
}

void write_unlock() {
	write_mutex.unlock();
}

void func1() {
	read_lock();
	for (int i = 0; i < 10; ++i) {
		printf("thread 1\n");
		Sleep(1);
	}
	read_unlock();
}

void func2() {
	read_lock();
	for (int i = 0; i < 10; ++i) {
		printf("thread 2\n");
		Sleep(1);
	}
	read_unlock();
}

void func3() {
	Sleep(1);
	write_lock();
	for (int i = 0; i < 10; ++i) {
		printf("thread 3\n");
	}
	write_unlock();
}

int main() {
	std::thread t1(func1);
	std::thread t2(func2);
	std::thread t3(func3);
	t1.join();
	t2.join();
	t3.join();
	return 0;

}
