// given points - check whether it is a strainght line

#include <iostream>
#include <vector>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates);

int main(void){
	int n;
	cin >> n;
	vector<vector<int>> coords(n, vector<int>(2));
	for(int i = 0;i < n;i++)
		cin >> coords[i][0] >> coords[i][1];
	cout << (checkStraightLine(coords) ? "true" : "false") << endl;
	return 0;
}

bool checkStraightLine(vector<vector<int>>& coordinates){
	int n = coordinates.size();
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	int slopey = coordinates[1][1] - coordinates[0][1];
	int slopex = coordinates[1][0] - coordinates[0][0];
	for(int i = 2;i < n;i++){
		int tempy = coordinates[i][1] - coordinates[0][1];
		int tempx = coordinates[i][0] - coordinates[0][0];
		if(slopey*tempx != slopex*tempy)
			return false;
	}
	return true;
}
