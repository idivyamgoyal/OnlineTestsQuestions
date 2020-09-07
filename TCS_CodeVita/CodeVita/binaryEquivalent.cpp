#include<iostream>
#include<vector>

using namespace std;

int combinations(vector<int> &binary_1, int size, int idx, vector<int> &idxs) {

    if(idx == (int)binary_1.size()) {
        int zeros = 0, ones = 0;
        for(int i = 0; i < (int)idxs.size(); i++) {
            ones += binary_1[idxs[i]];
            zeros += size - binary_1[idxs[i]];
        }
        if(zeros > 0 && ones > 0 && zeros == ones) {
            return 1;
        }
        return 0;
    }

    int count = 0;
    idxs.push_back(idx);
    count += combinations(binary_1, size, idx + 1, idxs);
    idxs.pop_back();
    count += combinations(binary_1, size, idx + 1, idxs);

    return count;
}

pair<int, pair<int, long>> getMeBinary(long num) {

    int count = 0, size = 0;
    long ans = 0, pow = 1;
    while(num > 0) {
        long rem = num % 2;
        if(rem == 1) {
            count++;
        }
        rem *= pow;
        ans += rem;
        pow *= 10;
        size++;
        num /= 2;
    }

    return {size, {count, ans}};
}

void solve() {

    int n;
    cin >> n;
    vector<int> binary_1;

    int size = -1e8;
    for(long i = 0; i < n; i++) {
        long num;
        cin >> num;

        pair<int, pair<int, long>> mp = getMeBinary(num);
        binary_1.push_back(mp.second.first);
        size = max(size, mp.first);
    }

    vector<int> idxs;
    int count = combinations(binary_1, size, 0, idxs);
    if(count == 0) {
        for (int i = 0; i < size; i++) {
            cout << 0;
        }
        return;
    }

    pair<int, pair<int, long>> mp = getMeBinary(count);

    size = size - mp.first;
    for(int i = 0; i < size; i++) {
        cout << 0;
    }
    cout << mp.second.second;

}

int main() {

    solve();
    return 0;
}