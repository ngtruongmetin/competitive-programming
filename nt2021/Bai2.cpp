#include <bits/stdc++.h>
using namespace std;
const long long avc = -9999999;
int main() {
	int m,n;
	cin >> m >> n;
    long long a[m+1][n+1], dp[m+1][n+1], trace[m+1][n+1];
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			dp[i][j]=avc;
		}
	}
	for(int i=1;i<=m;++i) {
		for(int j=1;j<=n;++j) {
			trace[i][j]=-1;
		}
	}	
	for(int i=1;i<=m;++i) {
        dp[i][1] = a[i][1];
    }
    for (int j=2;j<=n;j++){
        for (int i=1;i<=m;i++){
            for (int di=-1;di<=1;di++) {
                int pr=i+di;
                if (pr<1 || pr>m) continue;
                long long tmp = dp[pr][j - 1] + a[i][j];
                if (tmp > dp[i][j]) {
                    dp[i][j] = tmp;
                    trace[i][j] = pr;
                }
            }
        }
    }
    long long ans=avc,lr=-1;
    for (int i=1;i<=m;i++) {
        if (dp[i][n] > ans) {
            ans=dp[i][n];
            lr=i;
        }
    }
    int path[n+1];
    int row=lr;
    for (int j=n;j>=1;--j) {
        path[j] = row;
        row = trace[row][j];
    }
	for (int j = 1; j <= n; j++) {
        if (j>1)
            cout<<"->";
        cout<<path[j];
    }
    cout << endl;
    cout << ans;

    return 0;
}
