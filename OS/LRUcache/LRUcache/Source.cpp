#include "LRUcache.h"

int main() {
	LRUCache cache(3);
	cache.set(1, 1);
	cache.set(2, 2);
	cache.set(3, 3);
	cache.set(4, 4);
	printf("%d\n", cache.get(4));
	printf("%d\n", cache.get(3));
	printf("%d\n", cache.get(2));
	printf("%d\n", cache.get(1));
	cache.set(5, 5);
	printf("%d\n", cache.get(4));
	printf("%d\n", cache.get(3));
	printf("%d\n", cache.get(2));
	printf("%d\n", cache.get(1));
	printf("%d\n", cache.get(5));
	return 0;
}