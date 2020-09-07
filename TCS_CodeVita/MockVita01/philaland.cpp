#include<iostream>
#include<vector>
using namespace std;

int numOfCoins(int target, vector<int> &coins) {
    if(coins[target / 2] != 0) {
        return 1 + coins[target / 2];
    }

    coins[target / 2] = numOfCoins(target / 2, coins);
    return coins[target / 2] + 1;
}

void solve() {
    int testCases;
    cin >> testCases;
    vector<int> nums(testCases, 0);
    for(int i = 0; i < testCases; i++) {
        cin >> nums[i];
    }
    vector<int> coins(5001, 0);
    coins[1] = 1;
    coins[2] = 2;
    coins[3] = 2;
    for(int target : nums) {
        cout << numOfCoins(target, coins) << endl;
    }
}

int main() {
    solve();
    return 0;
}