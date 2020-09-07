#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;

int transfigure (string A, string B) {
    if(A.size() != B.size()) {
        return -1;
    }

    int n = A.size();

    unordered_map<char, int> map;

    for(int i = 0; i < n; i++) {
        map[A[i]]++;
    }

    for(int j = 0; j < n; j++) {
        map[B[j]]--;
    }

    for(auto val : map) {
        if(val.second != 0) {
            return -1;
        }
    }

    int count = 0;
    int idxA = n - 1;
    int idxB = idxA;
    while(idxA >= 0) {
        if(A[idxA] != B[idxB]) {
            count++;
            idxA--;
            continue;
        }
        idxA--;
        idxB--;
    }
    
    return count;
}

int main() {
    cout << transfigure("geeksforgeeks", "fogkgeeksrees") << endl;
    return 0;
}