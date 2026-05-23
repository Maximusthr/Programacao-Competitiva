#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int qtd(vector<int> arr, int ref, int ans){
    int sum = 0;

    int n = arr.size();
    for (int i = 0; i < n; i++){
        while(arr[i] != ref){
            if (arr[i] & 1) arr[i]++;
            else arr[i] /= 2;
            sum++;
            if (arr[i] < ref && arr[i] % 2 == 0) return INF;
            if (sum >= ans) return INF;
        }
    }

    return sum;
}

vector<int> possi;
void num(int v){
    while(v > 1){
        possi.push_back(v);
        if (v & 1) v++;
        else v /= 2;
    }
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = INF;

    set<int> val = {arr.begin(), arr.end()};
    vector<int> copy = {val.begin(), val.end()};

    possi.push_back(1);
    for (int i = 0; i < min((int)copy.size(), 5); i++){
        num(copy[i]);
    }

    sort(possi.begin(), possi.end());
    possi.resize(unique(possi.begin(), possi.end()) - possi.begin());

    int sz = possi.size();
    for (int i = 0; i < possi.size(); i++){
        ans = min(ans, qtd(arr, possi[i], ans));
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}