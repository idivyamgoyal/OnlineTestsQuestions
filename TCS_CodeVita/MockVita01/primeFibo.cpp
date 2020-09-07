#include<iostream>
#include<vector>
#include<string>
#include <bits/stdc++.h> 
using namespace std;

long lastFibNum(vector<int> &primeCombinations) {
    long ans = 0;
    int size = primeCombinations.size();
    long num1 = primeCombinations[0];
    long num2 = primeCombinations[size - 1];
    
    while(size > 2) {
        ans = num1 + num2;
        num1 = num2;
        num2 = ans;
        size--;
    }

    return ans;
}

int convertToNum(string num) {
    int size = num.size();
    int ans = 0;
    for(int i = 0; i < size; i++) {
        ans = (ans * 10) + (num.at(i) - '0');
    }
    return ans;
}

bool notPresent(vector<int> &combinations, string num) {
    int ans = convertToNum(num);
    for(int val : combinations) {
        if(val == ans) {
            return false;
        }
    }
    return true;
}

void makeCombinations(vector<int> &combinations, vector<int> &prime) {
    int size = prime.size();
    for(int idx = 0; idx < size; idx++) {
        string ans = to_string(prime[idx]);
        for(int i = 0; i < size; i++) {
            if(i != idx && notPresent(combinations, ans + to_string(prime[i]))) {
                combinations.push_back(convertToNum(ans + to_string(prime[i])));
            }
        }
    }
}

bool isPrime(int num) {
    if(num == 2) {
        return true;
    }
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrime(int n1, int n2, vector<int> &prime) {
    for(int i = n1; i <= n2; i++) {
        if(isPrime(i)) {
            prime.push_back(i);
        }
    }
}

void findPrimeCombi(vector<int> &combinations, vector<int> &primeCombinations) {
    int size = combinations.size();
    for(int i = 0; i < size; i++) {
        if(isPrime(combinations[i])) {
            primeCombinations.push_back(combinations[i]);
        }
    }
}

void solve() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> prime;
    vector<int> combinations;
    findPrime(n1, n2, prime);
    makeCombinations(combinations, prime);
    vector<int> primeCombinations;
    findPrimeCombi(combinations, primeCombinations);
    sort(primeCombinations.begin(), primeCombinations.end());
    cout << lastFibNum(primeCombinations) << endl;
}

int main() {
    solve();
    return 0;
}