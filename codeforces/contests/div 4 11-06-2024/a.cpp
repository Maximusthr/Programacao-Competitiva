#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int i = 0;

    string word1;
    string word2;

    for (int j = 0; j < n; j++){
        cin >> word1;
        cin >> word2;

        char temp = word1[0];

        word1[0] = word2[0];
        word2[0] = temp;

        cout << word1 << " " << word2 << "\n";
        i++;
    }
}
