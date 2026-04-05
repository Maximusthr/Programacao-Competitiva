#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    deque<int> deq;
    deq.push_back(n);
    for (int i = n-1; i >= 0; i--){
        if (s[i] == 'R') deq.push_front(i);
        else deq.push_back(i);
    }

    for (int i = 0; i < deq.size(); i++){
        cout << deq[i] << " \n"[i == deq.size()-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}