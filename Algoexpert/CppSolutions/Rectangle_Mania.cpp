// given (x,y) points - how many rectangles present

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

struct Point {
  int x;
  int y;
};

bool compare(Point a, Point b){
	if(a.x < b.x)
		return true;
	else if(a.x == b.x)
		return a.y < b.y;
	return false;
}

int rectangleMania(vector<Point> coords);

int main(void){
	int n;
	cin >> n;
	vector<Point> coords;
	for(int i = 0;i < n;i++){
		Point temp;
		cin >> temp.x >> temp.y;
		coords.push_back(temp);
	}
	cout << rectangleMania(coords) << endl;
	return 0;
}

// rectangle mania function
int rectangleMania(vector<Point> coords) {
	int npoints = coords.size();
	sort(coords.begin(), coords.end(), compare);
	map<pii, int> vertical_lines;
	int rectangles = 0;
	for(int i = 0;i < npoints;i++){
		for(int j = i+1;j < npoints;j++){
			if(coords[i].x == coords[j].x){
				pii temp = mp(coords[i].y, coords[j].y);
				auto it = vertical_lines.find(temp);
				if(it == vertical_lines.end())
					vertical_lines[temp] = 0;
				rectangles += vertical_lines[temp]++;
			}
			else
				break;
		}
	}
	return rectangles;
}
