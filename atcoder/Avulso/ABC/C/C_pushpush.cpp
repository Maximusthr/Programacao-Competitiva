#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    bool inv = true;
    deque<int> deq;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (inv) deq.push_front(x);
        else deq.push_back(x);
        inv ^= 1;
    }

    if (!inv){
        for (auto d : deq) cout << d << " ";
        cout << "\n";
    }
    else {
        for (int i = n-1; i >= 0; i--){
            cout << deq[i] << " \n"[i == 0];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}