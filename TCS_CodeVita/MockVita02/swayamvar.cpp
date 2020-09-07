#include<iostream>
#include<queue>
#include<string>
using namespace std;

int swayamvar() {
    int N;
    cin >> N;
    queue<char> brides_que, grooms_que;
    string brides = "", grooms = "";
    cin >> brides >> grooms;

    for(int i = 0; i < N; i++) {
        brides_que.push((char)(brides[i]));
        grooms_que.push((char)(grooms[i]));
    }

    while(brides_que.size() > 0) {
        bool match = false;
        int size = grooms_que.size();
        char bride = brides_que.front();

        while(size-- > 0) {
            char groom = grooms_que.front();
            if(groom != bride) {
                grooms_que.pop();
                grooms_que.push(groom);
            }
            else {
                grooms_que.pop();
                brides_que.pop();
                match = true;
                break;
            }
        }

        if(!match) {
            break;
        }
    }

    return brides_que.size();
}

int main() {
    int result = swayamvar();
    cout << result << endl;
    return 0;
}