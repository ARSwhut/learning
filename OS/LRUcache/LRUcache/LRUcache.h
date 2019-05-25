#pragma once
#ifndef LRUCACHE_H_
#define LRUCACHE_H_
#include <map>
#include <list>
struct Node {
	int key;
	int value;
};

class LRUCache {
private:
	std::map<int, std::list<Node>::iterator> mymap;
	std::list<Node> mylist;
	int maxSize;
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void set(int key, int value);
};

#endif