#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> copia;
map<int, int> freq;

const int MAX = 2e7;

int find_mex(){
    for (int i = 0; i < MAX; i++){
        if (freq[i] == 0) {
            return i;
        }
    }
}

ll transf_mex(vector<int> &arr, int v){
    int n = arr.size();
    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (freq[arr[i]] == 1 && arr[i] < v){

        }
        else {
            copia[i] = v;
        }
        ans += copia[i];
    }

    return ans;
}

void solve(){
    freq.clear();
    copia.clear();

    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    copia = arr;

    int v = find_mex();
    ll ans = transf_mex(arr, v);

    for (int i = 0; i < n; i++){
        if (arr[i] != copia[i]){
            freq[arr[i]]--;
            freq[copia[i]]++;
        }
    }

    arr = copia;

    if (k == 1){
        cout << ans << "\n";
    }
    else {
        v = find_mex();
        ans = transf_mex(arr, v);

        if (k % 2 == 0){
            cout << ans << "\n";
            return;
        }

        for (int i = 0; i < n; i++){
            if (arr[i] != copia[i]){
                freq[arr[i]]--;
                freq[copia[i]]++;
            }
        }

        arr = copia;
        v = find_mex();
        ans = transf_mex(arr, v);

        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}