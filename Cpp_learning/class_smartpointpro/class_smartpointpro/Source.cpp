#include "smartpoint.h"

int main() {
	SmartPointPro p(new Object());
	p->a = 10;
	p->b = 20;
	int a_val = (*p).a;
	int b_val = (*p).b;

	int a1 = p.GetObject().a;
	int b1 = p.GetPtr()->b;
	std::cout << a_val << "," <<b_val << std::endl;
	std::cout << a1 << "," << b1 << std::endl;
	return 0;
}