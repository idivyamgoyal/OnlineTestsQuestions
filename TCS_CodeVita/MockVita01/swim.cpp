#include<iostream>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;

float distance(float x1, float y1, float x2, float y2) {
    float dist = pow((x1 - x2), 2) + pow((y1 - y2), 2);
    dist = (float)sqrt(dist);
    return dist;
}

float time(float dist, float factor) {
    return dist / factor;
}

void solve() {
    cout << setprecision(6);
    float xl, yl, xm, ym, factor;
    cin >> xl >> yl >> xm >> ym >> factor;
    float xx = (xl + xm) / 2;
    float dist1 = distance(xl, yl, xl, 0);
    float dist2 = distance(xl, 0, xm, ym);
    float dist3 = distance(xl, yl, xm, 0);
    float dist4 = distance(xm, 0, xm, ym);
    float dist5 = distance(xl, yl, xx, 0);
    float dist6 = distance(xx, 0, xm, ym);
    float t1 = time(dist5, factor) + time(dist6, 1);
    float t2 = time(dist1, factor) + time(dist2, 1);
    float t3 = time(dist3, factor) + time(dist4, 1);
    if(t2 > t1 && t2 > t3) {
        xx = (xx + xm) / 2;
    }
    else if(t3 > t1 && t3 > t2) {
        xx = (xl + xx) / 2;
    }
    float prev = xx;
    while(1) {
        if(t2 > t1 && t2 > t3) {
            xx = (xx + xm) / 2;
        }
        else if(t3 > t1 && t3 > t2) {
            xx = (xl + xx) / 2;
        }
        if(prev == xx) {
            break;
        }
    }
}

int main() {
    solve();
    return 0;
}