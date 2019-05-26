#include <iostream>
#include "TwoStackQueue.h"

int main() {
	TwoStackQueue* test = new TwoStackQueue();
	test->push(1);
	test->push(2);
	test->push(3);
	test->pop();
	test->push(4);
	test->push(5);
	test->pop();
	test->pop();
	test->pop();
	delete test;
	return 0;
}