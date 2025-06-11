#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    string word; cin >> word;

    int keys = 0;
    map<char, int> rooms;

    for (int i = 0; i < (int)word.size(); i++){
        if (word[i] >= 97 && word[i] <= 122) rooms[word[i]]++;
        else {
            if (rooms[word[i]+32] >= 1) rooms[word[i]+32]--;
            else keys++;
        }
    }

    cout << keys << "\n";
}
