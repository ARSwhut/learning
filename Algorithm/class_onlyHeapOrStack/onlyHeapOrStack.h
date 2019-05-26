#pragma once
#ifndef ONLYHEAPORSTACK_H_
#define ONLYHEAPORSTACK_H_
//最初的版本 缺点：无法解决继承的问题，如果HeapA作为其他类的基类时，
//通常是需要将析构函数设为virtual，然后在子类中重写，实现多态。
//
class HeapA {
public:
	HeapA() {}
	void destroy() {
		delete this;
	}
private:
	~HeapA() {}

};

//使用protected访问控制解决子类访问问题
//类的使用不方便，new不能delete，使用public static函数来构造，
//将构造函数设置为protected

class HeapApro {
protected:
	HeapApro() {}
	~HeapApro() {}
public:
	static HeapApro* create() {
		return new HeapApro();
	}
	void destroy() {
		delete this;
	}
};

//禁用new和delete运算符
class StackA {
public:
	StackA() {}
	~StackA() {}
private:
	void* operator new(size_t t) {}
	void operator delete(void* ptr) {}
};
#endif
