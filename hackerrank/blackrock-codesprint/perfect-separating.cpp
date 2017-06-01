#include <bits/stdc++.h>
using namespace std;
const int N = 55;

char s[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int m = n/2;
    map< pair<int, int>, long long > mp;
    mp[{0, 0}] = 1;
    for(int i = 0; i<m; i++) {
        map< pair<int, int>, long long > nmp;
        nmp.clear();
        if(s[i] == 'a') {
            for(auto it = mp.begin(); it != mp.end(); it++) {
                int len = it->first.first, val = it->first.second;
                long long cnt = it->second;
                if(len == 0) {
                    nmp[{1, 1}] += cnt;
                    nmp[{-1, 1}] += cnt;
                    continue;
                }
                int sign = len / abs(len);
                len = abs(len);
                nmp[{sign * (len+1), (val << 1) | 1}] += cnt;
                if(len) {
                    len--;
                    if(val & (1<<len)) {
                        nmp[{sign * len, val^(1<<len)}] += cnt;
                    }
                }
            }
        }
        else {
            for(auto it = mp.begin(); it != mp.end(); it++) {
                int len = it->first.first, val = it->first.second;
                long long cnt = it->second;
                if(len == 0) {
                    nmp[{1, 0}] += cnt;
                    nmp[{-1, 0}] += cnt;
                    continue;
                }
                int sign = len / abs(len);
                len = abs(len);
                nmp[{sign * (len+1), (val << 1)}] += cnt;
                if(len) {
                    len--;
                    if((val & (1<<len)) == 0) {
                        nmp[{sign * len, val}] += cnt;
                    }
                }
            }
        }
        swap(mp, nmp);
    }
    map< pair<int, int>, long long > mq;
    mq[{0, 0}] = 1;
    for(int i = n-1; i>=m; i--) {
        map< pair<int, int>, long long > nmp;
        nmp.clear();
        if(s[i] == 'a') {
            for(auto it = mq.begin(); it != mq.end(); it++) {
                int len = it->first.first, val = it->first.second;
                long long cnt = it->second;
                if(len == 0) {
                    nmp[{1, 1}] += cnt;
                    nmp[{-1, 1}] += cnt;
                    continue;
                }
                int sign = len / abs(len);
                len = abs(len);
                nmp[{sign * (len+1), val | (1<<len)}] += cnt;
                if(len) {
                    len--;
                    if(val & 1) {
                        nmp[{sign * len, val>>1}] += cnt;
                    }
                }
            }
        }
        else {
            for(auto it = mq.begin(); it != mq.end(); it++) {
                int len = it->first.first, val = it->first.second;
                long long cnt = it->second;
                if(len == 0) {
                    nmp[{1, 0}] += cnt;
                    nmp[{-1, 0}] += cnt;
                    continue;
                }
                int sign = len / abs(len);
                len = abs(len);
                nmp[{sign * (len+1), val}] += cnt;
                if(len) {
                    len--;
                    if((val & 1) == 0) {
                        nmp[{sign * len, val>>1}] += cnt;
                    }
                }
            }
        }
        swap(mq, nmp);
    }
    long long ans = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        //if(mq.count(it->first))
        //    ans += it->second * mq[it->first];
        auto np = it->first;
        np.first *= -1;
        if(mq.count(np))
            ans += it->second * mq[np];
    }
    printf("%lld\n", ans);
    return 0;
}