#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> freq(MAX);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    auto ok = [&](int mid) -> bool {
        int qtd = 0;
        for (int i = 0; i < MAX; i++){
            qtd += freq[i]/mid;
        }
        return (qtd >= k);
    };

    // ideia da bb -> fatiar os elementos
    int l = 0, r = n;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }

    vector<int> ans;
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < freq[i]/l; j++){
            ans.push_back(i);
        }
    }

    for (int i = 0; i < k; i++){
        cout << ans[i] << " \n"[i == k-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}