#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, x, y; cin >> n >> x >> y;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> inter;
    for (int i = x; i < y; i++){
        inter.push_back(arr[i]);
    }

    vector<int> exter;
    for (int i = 0; i < x; i++){
        exter.push_back(arr[i]);
    }
    for (int i = y; i < n; i++){
        exter.push_back(arr[i]);
    }

    int menor = *min_element(inter.begin(), inter.end());
    vector<int> new_inter;

    int i = 0;
    while (inter[i] != menor){
        inter.push_back(inter[i]);
        i++;
    }
    for (; i < inter.size(); i++) new_inter.push_back(inter[i]);
    
    i = 0;
    vector<int> ans;
    while (i < exter.size() && exter[i] < menor){
        ans.push_back(exter[i]);
        i++;
    }
    for (int j = 0; j < new_inter.size(); j++){
        ans.push_back(new_inter[j]);
    }
    while(i < exter.size()){
        ans.push_back(exter[i]);
        i++;
    }

    for (auto ab : ans) cout << ab << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}