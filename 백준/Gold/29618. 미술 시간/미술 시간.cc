#include <iostream>
#include <vector>
using namespace std;

int paper[100002], portal[100002];
int n, q;

void Paint(int, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < 100002; i++) {
		portal[i] = i;
	}
	int a, b, x;
	while (q--) {
		cin >> a >> b >> x;
		Paint(a, b, x);
	}
	for (int i = 1; i <= n; i++) {
		cout << paper[i] << ' ';
	}
}

void Paint(int go, int stop, int color) {
	int next = stop;
	vector<int> footprint;
	for (int i = go; i <= stop; i++) {
		if (paper[i]) {
			footprint.push_back(i);
			i = portal[i];
			next = max(next, i);
		}
		else {
			footprint.push_back(i);
			paper[i] = color;
		}
	}
	for (auto i : footprint) {
		portal[i] = next;
	}
}