#include <iostream>
#include <cstring>

class MyString {
private:
	char* data;
public:
	MyString(char* pData = nullptr) {
		data = new char[strlen(pData) + 1];
		strcpy(data, pData);
	}
	MyString(const MyString& ms) {
		data = new char[strlen(ms.data) + 1];
		strcpy(data, ms.data);
	}
	MyString& operator=(const MyString& ms) {
		if (this == &ms) {
			return *this;
		}
		MyString tmp(ms);
		char* t = tmp.data;
		tmp.data = data;
		data = t;
		return *this;
	}
	~MyString(void) {
		delete []data;
		data = nullptr;
	}
	void print() {
		std::cout << data << '\n';
	}
};

int main() {
	MyString m1("hello\n");
	MyString m2 = m1;
	m2.print();
	return 0;
}
