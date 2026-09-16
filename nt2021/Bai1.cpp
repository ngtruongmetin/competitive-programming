#include <bits/stdc++.h>
using namespace std;
string s = "123456789";
long long m;

void solve(int pos, long long sum, long long num, string expr) {
    if (pos == 9) {
        if (sum+num == m) cout << expr << endl;
        return;
    }
    int digit = s[pos]-'0';
    solve(pos+1, sum, num*10+(num >= 0 ? digit:-digit), expr+s[pos]);
    solve(pos+1, sum+num, digit, expr+"+"+s[pos]);
    solve(pos+1, sum+num, -digit, expr+"-"+s[pos]);
}
int main() {
    cin >> m;
    solve(1,0,1,"1");
    solve(1,0,-1,"-1");
    return 0;
}
