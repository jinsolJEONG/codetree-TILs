#include <bits/stdc++.h>
using namespace std;

int n, m;
int s_y, s_x, d_v;
int arr[54][54];
bool used[54][54];
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
    while(1){
        bool ismove = 0;
        //좌 턴부터 쭈욱
        for(int i = 0; i < 4; i ++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            dir = turn_left(dir);
            if(arr[ny][nx]==0 && used[ny][nx]==0){
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
    ret = 1;
    //i
    cin >> n >> m >> s_x >> s_y >> d_v;
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