#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int> >& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		long long ans = 0;
		for(int i = 0;i < rows;i++){
			for(int j = 0;j < cols;j++){
				if(matrix[i][j] == 0)
					continue;
				if(i == 0 || j == 0){
					ans++;
					continue;
				}
				int minn = min(matrix[i][j-1], matrix[i-1][j]);
				minn = min(matrix[i-1][j-1], minn);
				matrix[i][j] = minn+1;
				ans += matrix[i][j];
			}
		}
		return ans;
    }
};

int main(void){
	int rows, cols;
	cin >> rows >> cols;
	vector<vector<int> > input(rows, vector<int>(cols));
	for(int i = 0;i < rows;i++)
		for(int j = 0;j < cols;j++)
			cin >> input[i][j];
	Solution* s = new Solution();
	cout << s->countSquares(input) << endl;
	return 0;
}

/*
class Solution {
public:
    int countSquares(vector<vector<int> >& matrix) { // with all ones
        if(matrix.size() == 0 || matrix[0].size() == 0)
			return 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int> > sum_matrix(rows, vector<int>(cols));
		// creating sum_matrix
		for(int i = 0;i < rows;i++){
			for(int j = 0;j < cols;j++){
				if(j == 0){
					sum_matrix[i][j] = matrix[i][j];
					continue;
				}
				sum_matrix[i][j] = matrix[i][j] + sum_matrix[i][j-1];
			}
		}
		for(int i = 0;i < cols;i++){
			for(int j = 0;j < rows;j++){
				if(j == 0)
					continue;
				sum_matrix[j][i] += sum_matrix[j-1][i];
			}
		}
		long long ans = 0;
		for(int i = 0;i < rows;i++){
			for(int j = i;j < rows;j++){
				int side = j-i+1;
				for(int k = side-1;k < cols;k++){
					if(k == side-1){
						if(sum_matrix[j][k] == side*side)
							ans++;
						continue;
					}
					if(sum_matrix[j][k] - sum_matrix[j][k-side] == side*side){
						ans++;
					}
				}
			}
			for(int j = i+1;j < rows;j++){
				for(int k = 0;k < cols;k++){
					sum_matrix[j][k] -= sum_matrix[i][k];
				}
			}
		}
		return ans;
    }
};

*/
