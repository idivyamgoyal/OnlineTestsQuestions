#include<iostream>
#include<vector>

using namespace std;

void rotationByK(vector<vector<int>> &matrix, int k, int i, int n, int m, vector<vector<int>> &ans) {


    int elements = 2 * ((n - 2 * i) + (m - 2 * i)) - 4;
    int row = i, col = i, r = i, c = i;
    k = k % elements;
    
    if(i % 2 == 0) { //odd layers
        k = elements - k;
    }

    while(k-- > 0) {
        if(row == i && col < m - 1 - i) {
            col++;
        }
        else if(row < n - 1 - i && col == m - 1 - i) {
            row++;
        }
        else if(col > i && row == n - 1 - i) {
            col--;
        }
        else {
            row--;
        }
    }

    while(elements-- > 0) {
        ans[row][col] = matrix[r][c];

        if(row == i && col < m - 1 - i) {
            col++;
        }
        else if(row < n - 1 - i && col == m - 1 - i) {
            row++;
        }
        else if(col > i && row == n - 1 - i) {
            col--;
        }
        else if(row > i && col == i){
            row--;
        }

        if(r == i && c < m - 1 - i) {
            c++;
        }
        else if(c == m - 1 - i && r < n - 1 - i) {
            r++;
        }
        else if(r == n - 1 - i && c > i) {
            c--;
        }
        else if(c == i && r > i){
            r--;
        }
    }
}


void solve() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    int num = n / 2;
    vector<int> rotation(num, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < num; i++) {
        cin >> rotation[i];
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));


    for(int i = 0; i < rotation.size(); i++) {
        rotationByK(matrix, rotation[i], i, n, m, ans);
    }
        
    for(vector<int> p: ans) {
        for(int i: p) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {

    solve();
    return 0;
}