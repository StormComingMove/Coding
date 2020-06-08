#include <iostream>
using namespace std;

class A{};
class B{};

int main(void){

	A* a = new A();
	B* b = new B();
	cout << a << ' ' << b << endl;
	A* ptr = reinterpret_cast <A*>(b);
	A* ptr1 = (A*)b;
	cout << ptr << ' ' << ptr1 << endl;
	/*
	int x = 8;
	void* ptr = &x;
	cout << ptr << endl;
	int* int_ptr;
	int_ptr = (int*)ptr;
	cout << int_ptr << endl;
	cout << *int_ptr << endl;
	int* ptr1 = reinterpret_cast <int*>(ptr);
	cout << *ptr1 << endl;
	*/
	return 0;
}
