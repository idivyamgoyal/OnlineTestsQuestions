#include<iostream>
#include<vector>
using namespace std;

int bitScore(int num) {
    int big = -1e8, small = 1e8;
    
    for(int i = 0; i < 3; i++) {
        big = max(big, num % 10);
        small = min(small, num % 10);
        num /= 10;
    }

    return (big * 11) + (small * 7);
}

void solve() {
    int N;
    cin >> N;
    vector<int> bitScores;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        bitScores.push_back(bitScore(num) % 100);
    }

    // index, count
    vector<pair<int, int>> count(10, {-1, 0});

    for(int i = 0; i < bitScores.size(); i++) {
        int val = bitScores[i];
        pair<int, int> &mp = count[val / 10];

        if(mp.first == -1) {
            mp.first = (val / 10) % 2 == 0 ? 0 : 1;
            mp.second++;
        }
        else {
            if(mp.first == (val / 10) % 2) {
                mp.second++;
            }
        }
    }

    int myCount = 0;
    for(pair<int, int> &mp : count) {
        if(mp.second >= 2) {
            myCount += mp.second == 2 ? 1 : 2;
        }
    }

    cout << myCount;
}

int main() {
    solve();
    return 0;
}