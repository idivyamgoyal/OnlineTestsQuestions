#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int countCities(vector<vector<char>> &mat, vector<vector<bool>> &visited, int sr, int sc, vector<vector<int>> &dir) {
    visited[sr][sc] = true;
    int count = 1;
    for(int d = 0; d < 8; d++) {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if(r >= 0 && c >= 0 && r < mat.size() && c < mat[0].size() && mat[r][c] == '@' && !visited[r][c]) {
            count += countCities(mat, visited, r, c, dir);
        }
    }

    return count;
}

int maxCities(vector<vector<char>> &a, int n, int m) {
    
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '*') {
                for(int d = 0; d < 8; d++) {
                    int r = i + dir[d][0];
                    int c = j + dir[d][1];

                    if(r >= 0 && c >= 0 && r < n && c < m && a[r][c] == '.') {
                        a[r][c] = '@';
                    }
                }
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '@' && !visited[i][j]) {
                count = max(count, countCities(a, visited, i, j, dir));
            }
        }
    }

    // non-recursive approach
/*     queue<pair<int, int>> que;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '@' && !visited[i][j]) {
                int newCount = 0;    
                que.push({i, j});
                while(que.size() > 0) {
                    pair<int, int> mp = que.front();
                    que.pop();
                    if(visited[mp.first][mp.second]) {
                        continue;
                    }
                    visited[mp.first][mp.second] = true;
                    newCount++;
                    for(int k = 0; k < 8; k++) {
                        int r = mp.first + dir[k][0];
                        int c = mp.second + dir[k][1];

                        if(r >= 0 && c >= 0 && r < n && c < m && a[r][c] == '@' && !visited[r][c]) {
                            que.push({r, c});
                        }
                    }
                }
                count = max(count, newCount);
            }

        }
    } */

    return count;
}