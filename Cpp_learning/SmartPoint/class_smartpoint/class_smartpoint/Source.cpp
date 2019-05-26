class Object {
public:
	int a;
	int b;
};

class SmartPoint {
public:
	SmartPoint(Object* p) {
		ptr = p;
	}
	~SmartPoint() {
		delete ptr;
	}
private:
	Object* ptr;
};

/*引用传递，没有问题*/
void Process(SmartPoint& p) {

}

/*有问题，smartpoint p释放两次*/
//void Process(SmartPoint p) {
//
//}

int main() {
	while (true) {
		SmartPoint p(new Object());
		Process(p);
	}
	return 0;
}