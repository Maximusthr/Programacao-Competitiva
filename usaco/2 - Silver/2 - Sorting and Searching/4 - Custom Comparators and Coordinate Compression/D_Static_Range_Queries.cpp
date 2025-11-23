#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5 + 10;

vector<ll> indices;

int getCompressedValue(int a){
    return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

void solve(){
    int n, q; cin >> n >> q;

    vector<pair<pair<int, int>, int>> arr;
    for (int i = 0; i < n; i++){
        int x, y, v; cin >> x >> y >> v;

        arr.push_back({{x, y}, v});
        indices.push_back(x);
        indices.push_back(y);
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++){
        cin >> queries[i].first >> queries[i].second;
        indices.push_back(queries[i].first);
        indices.push_back(queries[i].second);
    }

    // compressao
    sort(indices.begin(), indices.end());
    indices.resize(unique(indices.begin(), indices.end()) - indices.begin());

    vector<ll> diff(MAX);
    for (int i = 0; i < n; i++){
        diff[getCompressedValue(arr[i].first.first) + 1] += arr[i].second;
        diff[getCompressedValue(arr[i].first.second) + 1] -= arr[i].second;
    }

    vector<int> length(MAX);
    for (int i = 1; i < indices.size(); i++){
        length[i] = indices[i] - indices[i-1];
    }

    for (int i = 1; i < indices.size(); i++){
        diff[i] += diff[i-1];
    }

    vector<ll> prefix(MAX);
    for (int i = 1; i < indices.size(); i++){
        prefix[i] += prefix[i-1] + (diff[i] * length[i]);
    }

    for (int i = 0; i < q; i++){
        ll right = prefix[getCompressedValue(queries[i].second)];
        ll left = prefix[getCompressedValue(queries[i].first)];

        cout << right - left << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}