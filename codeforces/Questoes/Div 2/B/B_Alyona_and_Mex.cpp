#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    map<ll, ll> freq;   
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = 1; i < 1e5+5; i++){
        if (freq[i] == 0){
            auto it = freq.lower_bound(i+1);

            if (it != freq.end()){
                if (it->second >= 1){
                    it->second--;
                    freq[i] = 1;
                    if(it->second == 0){
                        freq.erase(it);
                    }
                }
                else {
                    cout << i << "\n";
                    return;
                }
            }
            else {
                cout << i << "\n";
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}