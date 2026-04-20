#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    int x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;

    vector<int> ans;

    int a = query(1, 2);
    int b = query(2, 3);
    int c = query(1, 3);

    int y = a + b - c;
    int x = abs(a - y);
    int z = abs(b - y);
    ans.push_back(x);
    ans.push_back(y);
    ans.push_back(z);

    for (int i = 2; i < n-1; i++){
        int v = query(i+1, i+2);
        ans.push_back(abs(v - ans.back()));
    }

    cout << "! ";
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}