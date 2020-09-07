#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
using namespace std;

int findDistance(int x, int y) {
    int dist = pow(x, 2) + pow(y, 2);
    dist = (int)sqrt(dist);
    return dist;
}
int findCollisions(vector<vector<int>> &car) {
    int size = car.size();
    // vector<int> time(size, 0);
    int collisions = 0;
    unordered_map<int, int> map;

    for(int i = 0; i < size; i++) {
        // time[i] = findDistance(car[i][0], car[i][1]) / car[i][2];
        map[findDistance(car[i][0], car[i][1]) / car[i][2]]++;
    }

    for(auto t : map) {
        collisions += (t.second * (t.second - 1)) / 2;
    }

    // for(int i = 0; i < size; i++) {
    //     for(int j = i + 1; j < size; j++) {
    //         if(time[i] == time[j]) {
    //             collisions++;
    //         }
    //     }
    // }

    return collisions;
}

void solve() {
    int cars;
    cin >> cars;
    vector<vector<int>> car(cars, vector<int>(3, 0));
    for(int i = 0; i < cars; i++) {
        cin >> car[i][0] >> car[i][1] >> car[i][2];
    }
    cout << findCollisions(car) << endl;
}

int main() {
    solve();
    return 0;
}