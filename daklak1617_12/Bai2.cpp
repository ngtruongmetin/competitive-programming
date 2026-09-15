#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], b[101], c[101][101];
int main() {
    int dem=0;
    bool tv=false;
    cin >> n;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;++i) {
	    int tong=0;
        int tich=1;
        bool cotong=false;
        for(int j=1;j<=n;++j) {
            if (i!=j) {
            	tong+=a[i][j];
			}
        }
        if (a[i][i]<tong) {
            cotong=true;
	        for(int j=1;j<=n;++j) {
	            if (i!=j) {
	            	tich*=a[j][i];
				}
	        }
        }
        if (cotong) {
            if (tich<a[i][i]) {
            	tv=true;
                dem++;
                b[dem]=i;
                c[dem][dem]=a[i][i];
            }
        }
    }

    if (tv) {
		cout << "YES" << endl;
		for (int j=1;j<=dem;++j) {
			cout << b[j] << " " << b[j] << " "<< c[j][j] << endl;
		}
    } 
    else {
        cout << "NO";
    }
    return 0;
}
