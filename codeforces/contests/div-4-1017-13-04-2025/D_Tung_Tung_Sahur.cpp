// I found this idea, but I implemented another one which got WA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        string p;
        cin >> p;
    
        string s;
        cin >> s;
    
        vector<pair<int, char>> arr;

        int sum_aux = 0;
        for (int i = 0; i < (int)p.size(); i++){
            if (p[i] == 'R') {
                if (sum_aux > 0 && p[i-1] == 'L' && i-1 >= 0) {
                    arr.push_back({sum_aux, 'L'});
                    sum_aux = 0;
                }
                sum_aux++;
                if (i+1 == (int)p.size()) arr.push_back({sum_aux, 'R'});
            }
            else if (p[i] == 'L'){
                if (sum_aux > 0 && p[i-1] == 'R' && i-1 >= 0) {
                    arr.push_back({sum_aux, 'R'});
                    sum_aux = 0;
                }
                sum_aux++;
                if (i+1 == (int)p.size()) arr.push_back({sum_aux, 'L'});
            }
        }
    
        vector<pair<int, int>> aux;

        int elem = 0;
        for (int i = 0; i < (int)s.size(); i++){
            if (s[i] == 'R'){
                if (elem > 0 && s[i-1] == 'L' && i-1 >= 0){
                    aux.push_back({elem, 'L'});
                    elem = 0;
                }
                elem++;
                if (i+1 == (int)s.size()) aux.push_back({elem, 'R'});
            }
            else if (s[i] == 'L'){
                if (elem > 0 && s[i-1] == 'R' && i-1 >= 0){
                    aux.push_back({elem, 'R'});
                    elem = 0;
                }
                elem++;
                if (i+1 == (int)s.size()) aux.push_back({elem, 'L'});
            }
        }
        
        if ((int)arr.size() != (int)aux.size()) cout << "NO" << "\n";
        else {
            bool ok = true;
            for (int i = 0; i < (int)arr.size(); i++){
                if (aux[i].first < arr[i].first || aux[i].first > arr[i].first*2 || aux[i].second != arr[i].second){
                    ok = false;
                    break;
                }
            }
            
            if (!ok) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
    }
}   
