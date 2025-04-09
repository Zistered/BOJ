#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h=0;
string s;
    getline(cin, s);
    for(auto i:s){
        switch(i){
            case 'B':
                h++;
            case 'A':
            case 'a':
            case 'b':
            case 'D':
            case 'd':
            case 'e':
            case 'g':
            case 'O':
            case 'o':
            case 'P':
            case 'p':
            case 'Q':
            case 'q':
            case 'R':
            case '@':
                h++;
        }
    }
    cout<<h;

    return 0;
}