#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int testCases;
    cin >> testCases;
    vector<vector<int>> monkeys;
    for(int i = 0; i < testCases; i++) {
        int n;
        cin >> n;
        vector<int> mon;
        for(int i = 0; i < n; i++) {
            int d;
            cin >> d;
            mon.push_back(d);
        }
        monkeys.push_back(mon);
    }

    for(int i = 0; i < testCases; i++) {
        cout << monkeys[i].size() << endl;
    }
}

int  main() {
    solve();
    return 0;
}