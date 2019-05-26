#include "TwoStackQueue.h"

void TwoStackQueue::push(int val)
{
	while (!stackPop.empty()) {
		int tmp = stackPop.top();
		stackPop.pop();
		stackPush.push(tmp);
	}
	stackPush.push(val);
}

int TwoStackQueue::pop()
{
	while (!stackPush.empty()) {
		int tmp = stackPush.top();
		stackPush.pop();
		stackPop.push(tmp);
	}
	int pop_val = stackPop.top();
	stackPop.pop();
	return pop_val;
}
