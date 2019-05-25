#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
	/*if (l1 == nullptr && l2 == nullptr) return nullptr;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* pHead;
	if (p1 == nullptr || p2 == nullptr) {
		if (p1 == nullptr) {
			pHead = new ListNode(p2->val);
			p2 = p2->next;
		}
		else {
			pHead = new ListNode(p1->val);
			p1 = p1->next;
		}
	}
	else {
		if (p1->val <= p2->val) {
			pHead = new ListNode(p1->val);
			p1 = p1->next;
		}
		else {
			pHead = new ListNode(p2->val);
			p2 = p2->next;
		}
	}
	
	ListNode* p = pHead;
	while (p1 != nullptr || p2 != nullptr) {
		if (p1 == nullptr) {
			ListNode* tmp = new ListNode(p2->val);
			p2 = p2->next;
			p->next = tmp;
			p = p->next;
			continue;
		}
		if (p2 == nullptr) {
			ListNode* tmp = new ListNode(p1->val);
			p1 = p1->next;
			p->next = tmp;
			p = p->next;
			continue;
		}
		if (p2->val >= p1->val) {
			ListNode* tmp = new ListNode(p1->val);
			p1 = p1->next;
			p->next = tmp;
			p = p->next;
		}
		else {
			ListNode* tmp = new ListNode(p2->val);
			p2 = p2->next;
			p->next = tmp;
			p = p->next;
		}
	}
	return pHead;*/
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;
	if (l1->val > l2->val) {
		ListNode* tmp = l1;
		l1 = l2;
		l2 = tmp;
	}
	ListNode* p = l1;
	while (p != nullptr) {
		while (l2 != nullptr && (p->next->val > l2->val || p->next == nullptr)) {
			ListNode* tmp = l2;
			l2 = l2->next;
			tmp->next = p->next;
			p->next = tmp;
			p = p->next;
		}
		p = p->next;
	}
	return l1;

}

int main() {
	ListNode* l1 = nullptr;
	ListNode* l2 = new ListNode(0);
	ListNode* res = mergeTwoList(l1, l2);
	while (res != nullptr) {
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}