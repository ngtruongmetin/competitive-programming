#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], b[101][101];
int main(){
	cin >> n;
	for (int i=1;i<=n;++i) {
		a[i][0]=0;
		a[0][i]=0;
		b[i][0]=0;
		b[0][i]=0;
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			b[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] + a[i+1][j] + a[i][j+1];
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cout<< b[i][j] << " ";
		}
		cout <<endl;
	}
}
