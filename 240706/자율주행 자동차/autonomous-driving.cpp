#include <bits/stdc++.h>
using namespace std;

int n, m;
int s_y, s_x, d_v;
int arr[50][50];
bool used[50][50];
int ret;

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int turn_left(int dir) {
    return (dir + 3) % 4;
}

int go_back(int dir) {
    return (dir + 2) % 4;
}

void simul(int x, int y, int dir){
    used[y][x] = 1;
    ret++;

    while(1){
        bool ismove = 0;
        //좌 턴부터 쭈욱
        for(int i = 0; i < 4; i ++){
            dir = turn_left(dir);
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(arr[ny][nx]==0 && !used[ny][nx]){
                y = ny;
                x = nx;
                used[ny][nx] = 1; ismove = 1;
                ret++;
                break;
            }
        }
        //만약 턴했는데 갈 곳이 없다면?
        if(ismove == 0){
            int orai = go_back(dir);
            int by = y + dy[orai];
            int bx = x + dx[orai];
            if(arr[by][bx]==1) break;
            y = by;
            x = bx;
        }
    }
}



int main() {
    //r

    //i
    cin >> n >> m >> s_y >> s_x >> d_v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    //s
    simul(s_x, s_y, d_v);
    //o
    cout << ret;

    return 0;
}