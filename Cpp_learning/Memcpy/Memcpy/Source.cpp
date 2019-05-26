#include <iostream>
#include <assert.h>
void* Memcpy(void* dst, const void* src, size_t t) {
	if (dst == nullptr || src == nullptr)
		return nullptr;
	const char* s = (const char*)src;
	char* d = (char*)dst;
	while (t--) {
		*d = *s;
		d++;
		s++;
	}
	return dst;
}

void* Memmove(void* dst, const void* src, size_t t) {
	if (src == nullptr || dst == nullptr)
		return nullptr;
	char *s, *d;
	if (dst <= src) {
		s = (char*)src;
		d = (char*)dst;
		while (t--) {
			*d++ = *s++;
		}
	}
	else {
		s = (char*)src + t;
		d = (char*)dst + t;
		while (t--) {
			*--d = *--s;
		}
	}
	return dst;
}
//通过4个字节来拷贝提高效率

void* mymemcpy(void* dst, const void* src, size_t t) {
	assert((dst != nullptr) && (src != nullptr));
	int wordnum = t / 4;
	int slice = t % 4;
	if (dst <= src) {
		const int* pintsrc = (const int *)src;
		int* pintdst = (int*)dst;
		while (wordnum--) {
			*pintdst++ = *pintsrc++;
		}
		const char* pcharsrc = (const char*)pintsrc;
		char* pchardst = (char*)pintdst;
		while (slice--) {
			*pchardst++ = *pcharsrc++;
		}
	}
	else {
		//const int* pintsrc = (const int*);
		/*const char* s = (const char*)src + t;
		char* d = (char*)dst + t;
		const int* pintsrc = (const int*)s;
		int* pintdst = (int*)d;
		while (wordnum--) {

		}*/

	}
	return dst;
} 

int main() {
	char a[10] = "abcdkef";
	char b[10];
	int* a1 = new int();
	int* b1 = a1 + 1;
	//Memcpy(b, a, 5);
	Memmove(b, a, 5);
	printf("%s\n", b);
	return 0;
}