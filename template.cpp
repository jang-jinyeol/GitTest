#include <iostream>
#pragma warning(disable:4996)
using namespace std;

template<class T, class U, int i>void test(T str) {

	U buffer[i];
	strcpy(buffer, str);
	cout << buffer << endl;
}


int main() {

	//const char* a = "asdad";
	
	test<const char*, char, 12>("C++");

}