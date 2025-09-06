#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> boys(n);
    for (auto &i : boys) cin >> i;

    int m; cin >> m;
    vector<int> girls(m);
    for (auto &i : girls) cin >> i;

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        if (abs(boys[i]-girls[j]) <= 1){
            ans++;
            i++;
            j++;
        }
        else if (boys[i] < girls[j]){
            i++;
        }
        else j++;
    }
    cout << ans << "\n";
}