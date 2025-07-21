#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    struct coord {
        ll l, r;
    };

    vector<ll> val;
    vector<coord> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].l >> arr[i].r;
        val.push_back(arr[i].l);
        val.push_back(arr[i].r + 1);
    }

    sort(val.begin(), val.end());
    // deixo unico
    val.resize(unique(val.begin(), val.end()) - val.begin());

    vector<int> freq(val.size() + 2);
    for (int i = 0; i < n; i++){
        int posl = lower_bound(val.begin(), val.end(), arr[i].l) - val.begin();
        int posr = lower_bound(val.begin(), val.end(), arr[i].r + 1) - val.begin();

        freq[posl]++;
        freq[posr]--;
    }

    for (int i = 1; i < val.size() + 2; i++){
        freq[i] += freq[i-1];
    }

    vector<ll> ans(n + 1);
    for (int i = 1; i < val.size() + 2; i++){
        ans[freq[i - 1]] += val[i] - val[i-1];
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }  
}