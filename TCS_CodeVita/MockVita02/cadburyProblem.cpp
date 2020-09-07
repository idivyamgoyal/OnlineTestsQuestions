#include<iostream>
using namespace std;

int noOfCadbury(int h, int w) {
    if(h < 1 || w < 1) {
        return 0;
    }
    if(h == 1 && w == 1) {
        return 1;
    }

    int hw = min(h, w);
    return 1 + noOfCadbury(max(h, w) - hw, hw);
}

void solve() {
    int minH, maxH, minW, maxW;
    cin >> minH >> maxH >> minW >> maxW;

    int count = 0;

    for(int i = 0; i <= maxH - minH; i++) {
        for(int j = 0; j <= maxW - minW; j++) {
            count += noOfCadbury(minH + i, minW + j);
        }
    }

    cout << count;
}

int main() {
    solve();
    return 0;
}