#include <iostream>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0;i < n;i++) cin >> v[i];
	bool ans = true;
	int reached = 0;
	for(int i = 0;i < n;i++){
		if(reached < i)
			return false;
		reached = max(reached, i + v[i]);
	}
	
}
