#pragma once
#ifndef TWOSTACKQUEUE_H_
#define TWOSTACKQUEUE_H_
#include<stack>
class TwoStackQueue {
private:
	std::stack<int> stackPush, stackPop;
public:
	TwoStackQueue() {}
	~TwoStackQueue() {}
public:
	void push(int val);
	int pop();
};
#endif
