#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//int tornado[10005][10005];
int smallTornado[55][8];
int xx1, yy1, xx2, yy2;

void wind(int m=25050025);

void outout(int big) {
	if (big / 10 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if(big/100==0){
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%2d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if(big/1000==0){
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%3d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if(big/10000==0){
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%4d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if (big / 100000 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%5d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if (big / 1000000 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%6d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if (big / 10000000 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%7d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if (big / 100000000 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%8d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else if (big / 1000000000 == 0) {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%9d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = yy1; i <= yy2; i++) {
			for (int j = xx1; j <= xx2; j++) {
				printf("%10d ", smallTornado[i - yy1+1][j - xx1+1]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int  big = 0, sizecalc;
	cin >> yy1 >> xx1 >> yy2 >> xx2;
	if (yy1 > yy2) swap(yy1, yy2);
	if (xx1 > xx2) swap(xx1, xx2);
	sizecalc = max((max(xx1<0?-xx1:xx1, xx2<0?-xx2:xx2)*2+1),(max(yy1<0?-yy1:yy1, yy2<0?-yy2:yy2)*2+1));
	wind(sizecalc * sizecalc);
	for (int i = yy1; i <= yy2; i++) {
		for (int j = xx1; j <= xx2; j++) {
			//printf("%3dvs%3d\t", big,smallTornado[i-yy1+1][j-xx1+1]);
			big = max(big, smallTornado[i - yy1+1][j - xx1+1]);
			//printf("%3d ", tornado[i + 5000][j + 5000]);
		}
		//printf("\n");
	}
	outout(big);
}

void wind(int maxi) {
	int x=0, y=0, move=1;
	//tornado[y][x] = 1;
	if (x >= xx1 && x <= xx2 && y >= yy1 && y <= yy2) {
		smallTornado[y - yy1+1][x - xx1+1] = 1;
	}
	for (int i = 1; i < maxi;) {
		for (int j = 0; j < move; j++) {
			i++;
			if (move % 2 == 0) {
				x--;
				//tornado[y][x] = i;
			}
			else {
				x++;
				//tornado[y][x] = i;
			}
			if (x >= xx1 && x <= xx2 && y >= yy1 && y <= yy2) {
				smallTornado[y - yy1+1][x - xx1+1] = i;
			}
		}
		for (int j = 0; j < move; j++) {
			i++;
			if (move % 2 == 0) {
				y++;
				//tornado[y][x] = i;
			}
			else {
				y--;
				//tornado[y][x] = i;
			}
			if (x >= xx1 && x <= xx2 && y >= yy1 && y <= yy2) {
				smallTornado[y - yy1+1][x - xx1+1] = i;
			}
		}
		move++;
	}
}