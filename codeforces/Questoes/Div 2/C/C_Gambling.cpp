#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> a(n), b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    bool vez = false;
    ll sc_a = 0, sc_b = 0;
    for (int i = 0, j = 0; ;){
        if (i == n && j == n) break;
        if (!vez){
            // a joga
            if (i < n && j < n){
                if (a[i] > b[j]){
                    sc_a += a[i];
                    i++;
                }
                else {
                    j++;
                }
            }
            else if (j == n){
                sc_a += a[i];
                i++;
            }
            else {
                j++;
            }

            vez ^= 1;
        }
        else {
            // b joga
            if (i < n && j < n){
                if (b[j] > a[i]){
                    sc_b += b[j];
                    j++;
                }
                else {
                    i++;
                }
            }
            else if (i == n){
                sc_b += b[j];
                j++;
            }
            else {
                i++;
            }

            vez ^= 1;
        }
    }

    cout << sc_a - sc_b << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}