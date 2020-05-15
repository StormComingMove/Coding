#include <iostream>
#include <vector>
using namespace std;

void moding(int& x, int y, int n){
	x += y;
	while(x >= n){
		x -= n;
	}
	while(x < 0){
		x += n;
	}
	return;
}

bool hasSingleCycle(vector<int> array){
	int n = array.size();
	vector<bool> visited(n);
	int curr = 0;
	while(visited[curr] == false){
		visited[curr] = true;
		moding(curr, array[curr], n);
	}
	if(curr != 0)
		return false;
	for(int i = 0;i < n;i++){
		if(visited[i] == false)
			return false;
	}
	return true;
}

int main(void){
	int arr[] = {2, 2, -1}; // {2, 3, 1, -4, -4, 2};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << (hasSingleCycle(v) ? "true" : "false") << endl;
	return 0;
}
