#include <iostream>
#include <queue>
#include <iomanip>
#include <map>

using namespace std;

int mapp[1000][1000], n, m, group[1000][1000], g;

void color(int, int);
int getnear(int, int);

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			mapp[i][j] = c - '0';
			if (mapp[i][j]) mapp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!mapp[i][j]) {
				g++;
				color(j, i);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << mapp[i][j];
		}
		cout << '\n';
	}
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mapp[i][j] == -1) {
				cout << (getnear(j,i)+1)%10;
			}
			else cout << 0;
		}
		cout << '\n';
	}
}

int getnear(int x, int y) {
	map<int,int> gchk;
	int near = 0,
		xx[4] = { -1,1,0,0 },
		yy[4] = { 0,0,-1,1 };
	for (int k = 0; k < 4; k++) {
		if (xx[k] + x >= 0 && xx[k] + x < m && yy[k] + y >= 0 && yy[k] + y < n) {
			map<int, int>::iterator fn = gchk.find(group[y + yy[k]][x + xx[k]]);
			if (mapp[y + yy[k]][x + xx[k]] != -1 && fn==gchk.end()) {
				near += mapp[y + yy[k]][x + xx[k]];
				gchk.insert(make_pair(group[y + yy[k]][x + xx[k]], 0));
			}
		}
	}
	return near;
}

void color(int x, int y) {
	queue<pair<int, int>> all, scan;
	scan.push(make_pair(x, y));
	mapp[y][x] = -1;
	while (!scan.empty()) {
		x = scan.front().first;
		y = scan.front().second;
		all.push(scan.front());
		scan.pop();
		int xx[4] = { -1,1,0,0 },
			yy[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			if (xx[i] + x >= 0 && xx[i] + x < m && yy[i] + y >= 0 && yy[i] + y < n) {
				if (mapp[y + yy[i]][x + xx[i]] == 0) {
					scan.push(make_pair(x + xx[i], y + yy[i]));
					mapp[y + yy[i]][x + xx[i]] = -1;
				}
			}
		}
	}
	int cn = all.size();
	while (!all.empty()) {
		//cout << all.front().first << "," << all.front().second << "\n";
		mapp[all.front().second][all.front().first] = cn;
		group[all.front().second][all.front().first] = g;
		all.pop();
	}
}