#include <bits/stdc++.h>
using namespace std;

int n, ret, maxT; 

int main() {
	//r

	//i
    cin >> n;
    vector<int> t(n), p(n);
    for (int i = 0; i < n; i++){
        cin >> t[i] >> p[i];
        maxT = max(maxT, t[i]);
    } 

	//s
	vector<int> dp(maxT + 1, 0);
    for (int i = 0; i < n; i++) 
        for (int j = maxT; j >= t[i]; j--) 
            dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
    for (int i = 0; i <= maxT; i++) ret = max(ret, dp[i]);

	//o
    cout << ret << '\n';
    return 0;
}