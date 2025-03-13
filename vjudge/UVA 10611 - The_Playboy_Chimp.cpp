#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    vector<int> ladies(qtd);
    for (auto &i : ladies) cin >> i;

    int q; cin >> q;
    vector<int> queries(q);
    for (auto &i : queries) cin >> i;

    for (int i = 0; i < q; i++){
        int l = 0;
        int r = qtd-1;

        // find the lowest value
        int lower = -1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (ladies[mid] >= queries[i]){
                r = mid-1;
            }
            else {
                lower = ladies[mid];
                l = mid+1;
            }
        }

        //find the biggest value
        int big = -1;
        l = 0;
        r = qtd-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if (ladies[mid] > queries[i]){
                big = ladies[mid];
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        if (lower == -1) {
            cout << "X ";
        } else cout << lower << " ";
        if (big == -1){
            cout << "X\n";
        } else cout << big << "\n";
    }
}
