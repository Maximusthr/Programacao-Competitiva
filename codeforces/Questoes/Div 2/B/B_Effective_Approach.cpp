#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    vector<pair<int, int>> arr;
    for (int i = 0; i < qtd; i++){
        int n; cin >> n;
        arr.push_back({n, i});
    }

    sort(arr.begin(), arr.end(), [&](pair<int, int> &x, pair<int, int> &y){
        return x.first < y.first;
    });

    int q; cin >> q;
    long long a = 0, b = 0;

    while(q--){
        int x; cin >> x;
        int pos_a = 0, pos_b = 0;


        //BS first try (lowerbound)
        int l = 0;
        int r = qtd-1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if (arr[mid].first == x){
                pos_a = arr[mid].second;
                r = mid-1;
            }
            else if (arr[mid].first > x){
                r = mid - 1;
            }
            else l = mid+1;
        }

        // BS second try (upperbound)
        l = 0;
        r = qtd-1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if (arr[mid].first == x){
                pos_b = arr[mid].second;
                l = mid+1;
            }
            else if (arr[mid].first > x){
                r = mid - 1;
            }
            else l = mid+1;
        }

        a += pos_a + 1;
        b += qtd-pos_b;
    }

    cout << a << " " << b << "\n";
}
