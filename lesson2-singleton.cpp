#include <iostream>

class A {
private:
	A() { std::cout << "construct a\n"; }
	A(const A& a) = delete;
	A& operator=(const A& a) = delete;

public:
	static A& get() {
		static A a;
		return a;
	}
};

class B {
public:
	B() { std::cout << "construct b\n"; }
};

static B b;

int main() {
	std::cout << "go in main\n";
	A& a1 = A::get();
	std::cout << "addr of a1 = " << &a1 << '\n';
	A& a2 = A::get();
	std::cout << "addr of a2 = " << &a2 << '\n';

	return 0;
}
