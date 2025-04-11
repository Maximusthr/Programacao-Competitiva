#include <bits/stdc++.h>

using namespace std;

using ll = long long;

typedef struct{
    ll t;
    ll z;
    ll y;
} temp;

ll m, n;
ll t, z, y;
vector<temp> arr;
vector<ll> baloes;

bool ok (ll valor){
    // formula
    ll total = 0;
    for (int i = 0; i < n; i++){
        total += valor/(arr[i].t*arr[i].z + arr[i].y) + min((valor % (arr[i].t*arr[i].z+arr[i].y)/arr[i].t), arr[i].z);
    }

    return total >= m;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++){
        cin >> t >> z >> y;
        arr.push_back({t, z, y});
    }

    ll l = 0;
    ll r = 1e10+1;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)) r = mid;
        else l = mid+1;
    }

    cout << r << "\n";

    ll resto = m;
    for (int i = 0; i < n; i++){
        ll cap = r/(arr[i].t*arr[i].z + arr[i].y) + min((r % (arr[i].t*arr[i].z+arr[i].y)/arr[i].t), arr[i].z);
        ll uso = min(resto, cap);
        cout << uso << " ";
        resto -= uso;
    }
    cout << "\n";
}
