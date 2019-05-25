#include "LRUcache.h"

LRUCache::LRUCache(int capacity)
{
	maxSize = capacity;
}

LRUCache::~LRUCache()
{
}

int LRUCache::get(int key)
{
	std::map<int, std::list<Node>::iterator>::iterator iter = mymap.find(key);
	//没有命中
	if (iter == mymap.end()) {
		return -1;
	}
	//命中
	else {
		std::list<Node>::iterator listiter = mymap[key];
		Node* tmp = new Node();
		tmp->key = key;
		tmp->value = listiter->value;
		mylist.erase(listiter);
		mylist.push_front(*tmp);
		mymap[key] = mylist.begin();
		delete tmp;
	}
	return mylist.begin()->value;
}

void LRUCache::set(int key, int value)
{
	std::map<int, std::list<Node>::iterator>::iterator iter = mymap.find(key);
	//没有命中
	if (iter == mymap.end()) {
		if (mylist.size() == maxSize) {
			mymap.erase(mylist.back().key);
			mylist.pop_back();
		}
		Node* tmp = new Node();
		tmp->key = key;
		tmp->value = value;
		mylist.push_front(*tmp);
		mymap[key] = mylist.begin();
		delete tmp;
	}
	//命中
	else {
		std::list<Node>::iterator listiter= mymap[key];
		mylist.erase(listiter);
		Node* node = new Node();
		node->key = key;
		node->value = value;
		mylist.push_front(*node);
		mymap[key] = mylist.begin();
		delete node;
	}
}
