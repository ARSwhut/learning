#include <iostream>
#include "onlyHeapOrStack.h"
int main() {
	//HeapA a;
	HeapA* a = new HeapA();
	HeapApro* A1 = HeapApro::create();
	HeapApro* A2 = HeapApro::create();
	/*while (true) {
		HeapApro* A = HeapApro::create();
		A->destroy();
	}*/

	//StackA b = new StackA();
	StackA b;
	return 0;
}