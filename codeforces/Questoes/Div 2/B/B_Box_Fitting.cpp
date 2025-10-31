#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, w; cin >> n >> w;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    auto ok = [&](int mid) -> bool {

        multiset<int> teste;
        for (int i = 0; i < n; i++){
            teste.insert(arr[i]);
        }

        int h = 1;
        int aux = w;

        while(!teste.empty()){
            auto it = teste.upper_bound(aux);
            if (it != teste.begin()) it--;
            if (*it > aux){
                h++;
                aux = w;
                continue;
            }
            else {
                aux -= *it;
            }
            teste.erase(it);
        }

        return (h <= mid);
    };

    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }  
        else l = mid + 1;
    }

    cout << l << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}