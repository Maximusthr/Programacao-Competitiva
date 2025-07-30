// Errinchto idea - upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int brute(int a, int b){
    int count = 0;
    for (int i = a; i <= b; i++){
        if (i % 2 && i % 3 && i % 5 && i % 7) count++;
    }

    return count;
}

ll count(ll num){
    const int FIXED = brute(0, 209);
    ll answer = FIXED * (num/210);
    answer += brute(0, num % 210);
    return answer;
}

void solve(){
    ll l, r; cin >> l >> r;

    cout << count(r) - count(l-1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}