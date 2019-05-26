#pragma once
#ifndef SMARTPOINT_H_
#define SMARTPOINT_H_
#include <iostream>
class Object;
class Counter {
	friend class SmartPointPro;
public:
	Counter() {
		ptr = nullptr;
		cnt = 0;
	}
	Counter(Object* p) {
		ptr = p;
		cnt++;
	}
	~Counter() {
		delete ptr;
	}
private:
	Object* ptr;
	int cnt;
};

class SmartPointPro {
public:
	SmartPointPro(Object* p) {
		ptr_couter = new Counter(p);
	}
	SmartPointPro(const SmartPointPro& sp) {
		ptr_couter = sp.ptr_couter;
		++ptr_couter->cnt;
	}
	SmartPointPro& operator=(const SmartPointPro& sp) {
		++sp.ptr_couter->cnt;
		--ptr_couter->cnt;
		if (ptr_couter->cnt == 0) {
			delete ptr_couter;
		}
		ptr_couter = sp.ptr_couter;

	}
	~SmartPointPro() {
		--ptr_couter->cnt;
		if (ptr_couter->cnt == 0) {
			delete ptr_couter;
		}
	}

	Object* GetPtr() {
		return ptr_couter->ptr;
	}
	Object& GetObject() {
		return *(ptr_couter->ptr);
	}

	//ÖØÔØ²Ù×÷·û
	Object* operator->() {
		return ptr_couter->ptr;
	}
	Object& operator*() {
		return *(ptr_couter->ptr);
	}
private:
	Counter* ptr_couter;
};

class Object {
public:
	int a;
	int b;
};
#endif