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
    } 

	//s
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
        if (i + t[i] <= n) 
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        else dp[i + 1] = max(dp[i + 1], dp[i]);
    }

	//o
    cout << dp[n] << '\n';
    return 0;
}