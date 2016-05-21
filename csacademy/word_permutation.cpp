#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
pair<string, int> s[N];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s, s+n);
    for(int i = 0; i<n; i++) {
        cout << s[i].second + 1 << " ";
    }
    cout << endl;
    return 0;
}