#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    set<int> a;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
        a.insert(arr[i].first);
    }

    sort(arr.begin(), arr.end());
    
    bool um = false;
    for (int i = 0; i < n; i++){
        if (arr[i].first == 1) um = true;
        else if (arr[i].first != 1 && um){
            cout << -1 << "\n";
            return;
        }
    }

    if (a.size() == 1){
        cout << 0 << "\n";
        return;
    }

    vector<pair<int, int>> ans;
    if (arr[0].first == 2){
        for (int i = 1; i < n; i++){
            while(arr[i].first > 2){
                arr[i].first = (arr[i].first + 1)/2;
                ans.push_back({arr[i].second, arr[0].second});
            }
        }
    }
    else {
        int achou = 0;
        int ref = arr[0].first;

        for (int j = 0; j < 10*n; j++){
            bool dif = false;
            for (int i = 1; i < n; i++){
                dif |= (arr[i] != arr[i-1]);
            }
            if (!dif) break;

            for (int i = 0; i < n; i++){
                if (arr[i].first > ref){
                    while(arr[i].first > ref){
                        arr[i].first = (arr[i].first + ref - 1)/ref;
                        ans.push_back({arr[i].second, arr[achou].second});
                    }
                    if (arr[i].first < ref){
                        ref = arr[i].first;
                        achou = i;
                    }
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}