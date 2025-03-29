#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;

    vector<int> arr(x);
    for (auto &i: arr) cin >> i;

    vector<int> copy = arr;
    sort(copy.rbegin(), copy.rend());

    vector<pair<int, int>> pos;
    int r = 1;
    int aux = 0;
    int aux2 = 0;

    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            if (arr[j] == copy[i]) {
                if (aux == arr[j]) pos.push_back({arr[j], aux2});
                else pos.push_back({arr[j], r});
                aux = copy[i];
                aux2 = r;
                r++;
                break;
            }
        }
    }

    vector<int> correto;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            if (pos[j].first == arr[i]) {
                correto.push_back(pos[j].second);
                break;
            }
        }
    }


    for (int i = 0; i < (int)pos.size(); i++){
        cout << correto[i] << "\n";
    }

}