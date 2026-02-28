#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string a, b; cin >> a >> b;

    int n = a.size();
    int m = b.size();

    map<char, int> freq1, freq2;
    for (int i = 0; i < n; i++){
        freq1[a[i]]++;
    }
    for (int i = 0; i < m; i++){
        freq2[b[i]]++;
    }

    for (auto [x, y] : freq1){
        if (x == 'A') continue;
        if (freq2[x] != y){
            cout << -1 << "\n";
            return;
        }
    }
    for (auto [x, y] : freq2){
        if (x == 'A') continue;
        if (freq1[x] != y){
            cout << -1 << "\n";
            return;
        }
    }

    string d, e;
    for (int i = 0; i < n; i++){
        if (a[i] != 'A') d.push_back(a[i]);
    }
    for (int i = 0; i < m; i++){
        if (b[i] != 'A') e.push_back(b[i]);
    }

    if (d != e){
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    int i = 0, j = 0;
    int last_i = 0, last_j = 0;
    while (i < n && j < m){
        while(i < n && a[i] == 'A'){
            i++;
        }
        while(j < m && b[j] == 'A'){
            j++;
        }

        ans += abs(i - j + last_j - last_i);

        last_i = i;
        last_j = j;

        i++, j++;
    }

    if (i >= n && j >= m) {}
    else if (j < m) ans += (m - j);
    else ans += (n - i);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}