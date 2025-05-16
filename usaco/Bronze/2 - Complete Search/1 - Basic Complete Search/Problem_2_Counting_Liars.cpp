#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<pair<char, int>> arr;

    int G = 0;
    int L = 0;

    vector<int> nums;

    for (int i = 0; i < n; i++){
        char c; int p; cin >> c >> p;
        arr.push_back({c, p});
        nums.push_back(p);
    }

    int ans = INF;

    for (int i = 0; i < n; i++){
        int x = nums[i];
        int liar = 0;
        for (int j = 0; j < n; j++){
            if (arr[j].first == 'G' && arr[j].second > x) liar++;
            if (arr[j].first == 'L' && arr[j].second < x) liar++;
        }
        ans = min(ans, liar);
    }

    cout << ans << "\n";
}
