#include <bits/stdc++.h>
using namespace std;

map< string, set< int > > mp;

pair< string, int > parse(string s) {
    if (s.back() != ')')
        return make_pair(s, 0);
    int len = 0;
    while (s[len] != '(') len++;
    return make_pair(s.substr(0, len), stoi(s.substr(len+1, s.size()-len-2)));
}
string encode(string s, int v) {
    if (v == 0)
        return s;
    return s + "(" + to_string(v) + ")";
}

string add(string s) {
    if (!mp.count(s)) {
        set< int > st;
        st.insert(1);
        mp[s] = st;
        return s;
    }
    else {
        set< int > & st = mp[s];
        auto it = st.begin();
        int n = *it;
        st.erase(it);
        if (st.empty())
            st.insert(n+1);
        return encode(s, n);
    }
}
void del(string s) {
    auto it = parse(s);
    mp[it.first].insert(it.second);
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string cmd, s;
        cin >> cmd >> s;
        if (cmd == "crt") {
            cout << "+ " << add(s) << "\n";
        }
        else if (cmd == "del") {
            del(s);
            cout << "- " << s << "\n";
        }
        else {
            string ss;
            cin >> ss;
            del(s);
            cout << "r " << s << " -> " << add(ss) << "\n";
        }
    }
    return 0;
}
