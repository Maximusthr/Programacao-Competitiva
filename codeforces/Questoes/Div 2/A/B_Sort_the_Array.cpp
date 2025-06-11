#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i: arr) cin >> i;
    
    vector<int> order = arr;
    sort(order.begin(), order.end());

    int pos_s = 0;
    int pos_f = 0;
    int aux = 0;
    bool ok = false;

    vector<int> new_sequence;

    for (int i = 0; i < qtd; i++){
        if (arr[i] != order[i] && !ok){
            pos_s = i;
            ok = true;
        }
        if (ok){
            new_sequence.push_back(arr[i]);
            if (arr[pos_s] == order[i]) {
                pos_f = i;
                break;
            }
        }
    }

    for (int i = pos_f; i < qtd-1; i++){ // special case when two subsequences aren't sorted.
        if (arr[i] > arr[i+1]) {
            cout << "no" << "\n";
            return 0;
        }
    }

    vector<int> new_sorted = new_sequence;
    sort(new_sorted.rbegin(), new_sorted.rend());
    bool seg = true;
    int new_pos = pos_s;
    for (int i = 0; i < (int)new_sorted.size(); i++){
        if (new_sorted[i] != arr[new_pos]) seg = false;
        new_pos++;
        if (pos_s > pos_f) break;
    }

    if (seg) {
        cout << "yes" << "\n";
        cout << pos_s + 1 << " " << pos_f + 1<< "\n";
    }
    else cout << "no" << "\n";
}
