#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n+1);
    multiset<int> v;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        v.insert(x);
        arr[i] = x;
    }

    while(q--){
        int x; cin >> x;

        vector<int> tirei;
        for (int i = 0; i < x; i++){
            int y; cin >> y;

            tirei.push_back(arr[y]);
            v.erase(v.find(arr[y]));
        }

        cout << *v.begin() << "\n";

        for (auto &i : tirei) v.insert(i);
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}