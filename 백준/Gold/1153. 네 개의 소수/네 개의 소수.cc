#include <cstdio>

bool eratos[1000099];

int main() {
    int n, mn=-1, sum=0, l, r;
    eratos[1] = 1;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++) {
        if (eratos[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            eratos[j] = 1;
        }
    }
    if (n < 8) {
        printf("-1");
        return 0;
    }
    if (n % 2) {
        printf("2 3 ");
        n -= 5;
    }
    else {
        printf("2 2 ");
        n -= 4;
    }
    for (int i = 2; i < n; i++) {
        if (eratos[i]) continue;
        for (int j = n; j >= 2; j--) {
            if (eratos[j]) continue;
            if (i + j == n) {
                printf("%d %d\n", i, j);
                return 0;
            }
            else if (i + j < n) break;
        }
    }
}