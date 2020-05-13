// check whether given number is valid perfect square

#include <iostream>
#include <vector>
using namespace std;

bool isPerfectSquare(int num);

int main(void){
	int x;
	cin >> x;
	cout << (isPerfectSquare(x) ? "true" : "false") << endl;
	return 0;
}

bool isPerfectSquare(int num){
	int l = 1, r = 100000;
	while(l <= r){
		int mid = l + (r-l)/2;
		long long square = (long long)mid*mid;
		if(square == (long long)num)
			return true;
		else if(square > (long long)num)
			r = mid-1;
		else
			l = mid+1;
	}
	return false;
}
