#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> func(vector<ll> &arr){
    int n = arr.size();

    vector<ll> resto;

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ll a = abs(arr[i] - arr[j]);

            resto.push_back(a);
        }
    }    

    return resto;
}

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }

    if (k >= 3){
        cout << 0 << "\n";
        return;
    }

    vector<ll> resto = func(arr);

    if (k == 1){
        cout << min(*min_element(arr.begin(), arr.end()), *min_element(resto.begin(), resto.end())) << "\n";
    }
    else {  
        sort(resto.begin(), resto.end());

        resto.resize(unique(resto.begin(), resto.end()) - resto.begin());

        ll v = LINF;
        for (int i = 0; i < n; i++){
            ll menor = LINF;

            int l = 0, r = resto.size()-1;
            while (l < r){
                int mid = l + (r-l+1)/2;

                if (resto[mid] <= arr[i]) l = mid;
                else r = mid - 1;
            }
            if (resto[l] <= arr[i]) menor = resto[l];

            v = min(v, abs(arr[i] - menor));

            auto maior = lower_bound(resto.begin(), resto.end(), arr[i]);
            if (maior != resto.end()) v = min(v, abs(arr[i] - *maior));
        }


        cout << min({v, *min_element(arr.begin(), arr.end()), *min_element(resto.begin(), resto.end())}) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}