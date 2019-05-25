#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;
mutex mtx;
condition_variable condv;
int count_val = 0;
void func(int val) {
	while (true) {
		this_thread::sleep_for(chrono::seconds(2));
		unique_lock<mutex> lck(mtx);
		if (count_val != val) {
			condv.wait(lck);
		}
		cout << static_cast<char>('A' + val) << endl;
		count_val = (count_val + 1) % 3;
		condv.notify_all();
	}

}

int main() {
	thread t1(func, 0);
	thread t2(func, 1);
	thread t3(func, 2);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}