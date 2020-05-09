// given (x,y) points - how many rectangles present

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

struct Point {
  int x;
  int y;
};

int rectangleMania(vector<Point> coords);

int main(void){
	int npoints;
	cin >> npoints;
	vector<Point> coords;
	for(int i = 0;i < n;i++){
		Point temp;
		cin >> temp.x >> temp.y;
		coords.push_back(temp);
	}
	cout << rectangleMania(coords) << endl;
	return 0;
}

int rectangleMania(vector<Point> coords) {
  
  return -1;
}

