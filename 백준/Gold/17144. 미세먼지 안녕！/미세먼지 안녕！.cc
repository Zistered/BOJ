#include <iostream>
#include <iomanip>

using namespace std;

int 세로, 가로, 반복, 방[50][50];
int 공기청정기_위, 공기청정기_아래, 공기청정기_가로;

void 확산();
void 순환();
void 방출력();

int main()
{
	cin >> 세로 >> 가로 >> 반복;
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			cin >> 방[i][j];
			if (방[i][j] == -1) {
				if (!공기청정기_위) {
					공기청정기_가로 = j;
					공기청정기_위 = i;
				}
				else {
					공기청정기_아래 = i;
				}
			}
		}
	}
	//방출력();
	while (반복--) {
		확산();
		//방출력();
		순환();
		//방출력();
	}
	int 먼지 = 0;
	방[공기청정기_위][공기청정기_가로] = 0;		//계속 -1인지 비교하는거보다 -1을 없애고
	방[공기청정기_아래][공기청정기_가로] = 0;	//비교없이 전부 더하는게 나을거같다는 판단
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			먼지 += 방[i][j];
		}
	}
	cout << 먼지;
}

void 확산() {
	int 새방[50][50] = { 0 };
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			int 날아갈먼지 = 방[i][j] / 5;
			if (j > 0 && 방[i][j - 1] != -1) {
				새방[i][j - 1] += 날아갈먼지;
				방[i][j] -= 날아갈먼지;
			}
			if (i > 0 && 방[i - 1][j] != -1) {
				새방[i - 1][j] += 날아갈먼지;
				방[i][j] -= 날아갈먼지;
			}
			if (j < 가로 - 1 && 방[i][j + 1] != -1) {
				새방[i][j + 1] += 날아갈먼지;
				방[i][j] -= 날아갈먼지;
			}
			if (i < 세로 - 1 && 방[i + 1][j] != -1) {
				새방[i + 1][j] += 날아갈먼지;
				방[i][j] -= 날아갈먼지;
			}
		}
	}
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			방[i][j] += 새방[i][j];
		}
	}
}

void 순환_위() {
	int y = 공기청정기_위 - 1, x = 공기청정기_가로;
	for (; y > 0; y--) {
		//방[y][x] = 10;
		방[y][x] = 방[y - 1][x];
	}
	for (; x < 가로 - 1; x++) {
		//방[y][x] = 20;
		방[y][x] = 방[y][x + 1];
	}
	for (; y < 공기청정기_위; y++) {
		//방[y][x] = 30;
		방[y][x] = 방[y + 1][x];
	}
	for (; x > 공기청정기_가로 + 1; x--) {
		//방[y][x] = 40;
		방[y][x] = 방[y][x - 1];
	}
	방[y][x] = 0;
}

void 순환_아래() {
	int y = 공기청정기_아래 + 1, x = 공기청정기_가로;
	for (; y < 세로-1; y++) {
		//방[y][x] = 10;
		방[y][x] = 방[y + 1][x];
	}
	for (; x < 가로 - 1; x++) {
		//방[y][x] = 20;
		방[y][x] = 방[y][x + 1];
	}
	for (; y > 공기청정기_아래; y--) {
		//방[y][x] = 30;
		방[y][x] = 방[y - 1][x];
	}
	for (; x > 공기청정기_가로 + 1; x--) {
		//방[y][x] = 40;
		방[y][x] = 방[y][x - 1];
	}
	방[y][x] = 0;
}

void 순환() {
	순환_위();
	순환_아래();
}
void 방출력() {
	cout << "================================\n";
	for (int i = 0; i < 세로; i++) {
		for (int j = 0; j < 가로; j++) {
			cout <<setw(2)<< 방[i][j] << " ";
		}
		cout << "\n";
	}
}