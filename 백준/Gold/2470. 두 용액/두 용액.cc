#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, zero, yongak[111111];
long long mini = 99999999999999;
pair<int, int> srch, minpos, mp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &yongak[i]);
        if (yongak[i] < 0)
            mp.first++;
        else if (yongak[i] > 0)
            mp.second++;
        else if (++zero >= 2)
        {
            printf("0 0");
            return 0;
        }
    }
    sort(yongak, yongak + n);
    if (!mp.first)
    {
        printf("%d %d", yongak[0], yongak[1]);
        return 0;
    }
    else if (!mp.second)
    {
        printf("%d %d", yongak[n - 2], yongak[n - 1]);
        return 0;
    }
    srch.first = mp.first - 1;
    srch.second = mp.first;
    /*
    for (int i = 0; i < n; i++)
    {
        printf("%d ", yongak[i]);
    }
    printf("\n\n");
    */
    if (mp.first >= 2)
    {
        mini = -(yongak[mp.first - 2] + yongak[mp.first - 1]);
        minpos.first = mp.first - 2;
        minpos.second = mp.first - 1;
    }
    if (mp.second >= 2)
    {
        mini = min(mini, (long long)yongak[mp.first] + yongak[mp.first + 1]);
        minpos.first = mp.first;
        minpos.second = mp.first + 1;
    }
    while (1)
    {
        int yonghap = yongak[srch.first] + yongak[srch.second];
        // printf("%d %d = %d\n", srch.first, srch.second, yonghap);
        if (yonghap == 0)
        {
            printf("%d %d", yongak[srch.first], yongak[srch.second]);
            return 0;
        }
        else if (abs(yonghap) < mini)
        {
            mini = abs(yonghap);
            minpos.first = srch.first;
            minpos.second = srch.second;
        }
        if (yonghap < 0 && srch.second < n - 1)
        {
            srch.second++;
            continue;
        }
        else if (yonghap > 0 && srch.first > 0)
        {
            srch.first--;
            continue;
        }
        break;
    }
    printf("%d %d", yongak[minpos.first], yongak[minpos.second]);
}