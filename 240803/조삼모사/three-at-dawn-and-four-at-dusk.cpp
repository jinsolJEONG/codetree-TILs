#include <bits/stdc++.h>
using namespace std;

int n, arr[24][24];
int mn = 1e9;

void cal(vector<int>& m, vector<int>& e){
    int mSum = 0;
    int eSum = 0;
    for(int i = 0; i < m.size(); i++)
        for(int j = 0; j < m.size(); j++)
            if(i != j) mSum += arr[m[i]][m[j]];
    for(int i = 0; i < e.size(); i++)
        for(int j = 0; j < e.size(); j++)
            if(i != j) eSum += arr[e[i]][e[j]];
    int cha = abs(mSum - eSum);
    mn = min(mn, cha);
}

void btck(int lev, vector<int>& m, vector<int>&e){
    if(lev == n){
        if(m.size()==n/2 && e.size()==n/2)cal(m, e);
        return;
    }
    if(m.size() < n/2){
        m.push_back(lev);
        btck(lev + 1, m, e);
        m.pop_back();
    }
    if(e.size() < n/2){
        e.push_back(lev);
        btck(lev + 1, m, e);
        e.pop_back();
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    //s
    vector<int> m;
    vector<int> e;
    btck(0, m, e);

    cout << mn << '\n';

    return 0;
}