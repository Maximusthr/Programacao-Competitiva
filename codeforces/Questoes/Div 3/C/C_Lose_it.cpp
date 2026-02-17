#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> elem(43);
    vector<int> v = {4, 8, 15, 16, 23, 42};

    int ans = n;
    for (int i = 0; i < n; i++){
        if (arr[i] == 4){
            elem[arr[i]]++;
        }
        else {
            for (int j = 0; j < v.size(); j++){
                if (arr[i] == v[j]) {
                    if (elem[v[j-1]] > 0){
                        elem[v[j-1]]--;
                        elem[arr[i]]++;
                        break;
                    }
                }
            }
        }
    }
    
    ans -= (elem[42]*6);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}