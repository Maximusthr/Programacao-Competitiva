/**
* @file C_Company_Layoffs.cpp
* @author GabrielCampelo
* Created on 2026-03-27 at 08:36:13
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(all(vec));
    vector<pair<int, int>> cnt; //{val, qtd}

    int curr = vec[0];
    int aux = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i] > curr) {
            cnt.pb({curr, aux});
            curr = vec[i];
            aux = 1;
        } else {
            aux++;
        }
    }
    cnt.pb({curr, aux});

    int og_n = n;
    n = cnt.size();

    // // DEBUGG
    // for (int i = 0; i < n; i++) {
    //     cout << "{" << cnt[i].first << ", " << cnt[i].second << "} ";
    // }
    // cout << endl;

    vector<int> prefix_qtd(n);
    vector<ll> prefix_sum(n);
    prefix_qtd[0] = cnt[0].second;
    prefix_sum[0] = 1ll * cnt[0].first * cnt[0].second;

    for (int i = 1; i < n; i++) {
        prefix_qtd[i] = prefix_qtd[i - 1] + cnt[i].second;
        prefix_sum[i] = prefix_sum[i - 1] + 1ll * cnt[i].first * cnt[i].second;
    }
    
    // // DEBUGG
    // for (int i = 0; i < n; i++) {
    //     cout << prefix_qtd[i] << " ";
    // }
    // cout << endl;

    while (m--) {
        int q;
        cin >> q;

        int l = 0, r = n;
        int m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (cnt[m].first >= q) r = m;
            else l = m + 1;
        }

        if (l == n) {
            cout << prefix_sum[n - 1] << endl;
        } else if (l > 0){
            int new_val = q;
            int new_qtd = prefix_qtd[n - 1] - prefix_qtd[l - 1];

            cnt[l] = {new_val, new_qtd};
            prefix_qtd[l] = prefix_qtd[l - 1] + new_qtd;
            prefix_sum[l] = prefix_sum[l - 1] + 1ll * new_val * new_qtd;
            
            n = l + 1;

            cout << prefix_sum[n - 1] << endl;
        } else {
            cout << 1ll * q * og_n << endl;
        }
    }

    return 0;
}