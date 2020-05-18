#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
template <class T>
inline T square(T x){
	return x*x;
}

template <>
string square(string ss){
	return (ss+ss);}

int main(){
int i = 4;
string s = "ganesh";
cout << square(i) << endl;
cout << square(s) << endl;
}
