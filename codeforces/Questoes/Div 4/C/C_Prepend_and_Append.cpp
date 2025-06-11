#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;
        deque<char> binary;
        string aux; cin >> aux;
        for (auto &i : aux) binary.push_back(i);
        
        while ((int)binary.size() > 0){
            if (binary.front() == '1' && binary.back() == '0' || binary.front() == '0' && binary.back() == '1'){
                binary.pop_front();
                binary.pop_back();
            }
            else break;
        }

        cout << (int)binary.size() << "\n";
    }
}
