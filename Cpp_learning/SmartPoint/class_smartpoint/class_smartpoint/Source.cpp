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

/*���ô��ݣ�û������*/
void Process(SmartPoint& p) {

}

/*�����⣬smartpoint p�ͷ�����*/
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