#pragma once
#ifndef ONLYHEAPORSTACK_H_
#define ONLYHEAPORSTACK_H_
//����İ汾 ȱ�㣺�޷�����̳е����⣬���HeapA��Ϊ������Ļ���ʱ��
//ͨ������Ҫ������������Ϊvirtual��Ȼ������������д��ʵ�ֶ�̬��
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

//ʹ��protected���ʿ��ƽ�������������
//���ʹ�ò����㣬new����delete��ʹ��public static���������죬
//�����캯������Ϊprotected

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

//����new��delete�����
class StackA {
public:
	StackA() {}
	~StackA() {}
private:
	void* operator new(size_t t) {}
	void operator delete(void* ptr) {}
};
#endif
