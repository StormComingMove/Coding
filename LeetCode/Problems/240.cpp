#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define pb push_back

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main(void){
	int rows, cols, target;
	cin >> rows >> cols >> target;
	vector<vector<int>> matrix(rows, vector<int>(cols));
	for(int i = 0;i < rows;i++)
		for(int j = 0;j < cols;j++)
			cin >> matrix[i][j];
	cout << (searchMatrix(matrix, target) ? "true" : "false") << endl;
	return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int rows = matrix.size();
	int cols = matrix[0].size();
	int x = 0;
	int y = cols-1;
	while(x<rows && y >= 0){
		if(matrix[x][y] == target)
			return true;
		if(matrix[x][y] < target){
			x++;
		}
		else{
			y--;
		}
	}
	return false;
}
