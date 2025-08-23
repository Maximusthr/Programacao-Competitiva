#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];

    ll ans = 0;
    int qtd_1 = 0, qtd_0 = 0, q1 = 0, q2 = 0;
    for (int i = n-1; i >= 0; i--) {
        if (v[i] == 0) {
            qtd_0++;
            ans += (qtd_1%2 ? q1 : q2);
        }
        else {
            qtd_1++;
            if (qtd_1%2)
                q1 += qtd_0+1;
            else
                q2 += qtd_0+1;
            qtd_0 = 0;
            ans += (qtd_1%2 ? q1 : q2);
        }
    }
    cout << ans << endl;
}