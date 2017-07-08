#include <bits/stdc++.h>

using namespace std;

vector< int > g[1000];
int vi[1000], vu[1000];

set< pair< int, int> > din, dout;

int b[1024];
void dfs(int v) {
	if (b[v]) return;
    b[v] = 1;
    for (int u : g[v]) {
    	dfs(u);
    }
}
int used[1024];

class ScoresSequence {
public:
	int count(vector <int> s) {
		memset(vi, 0, sizeof vi);
		memset(vu, 0, sizeof vu);
		int n = s.size();
		din.clear();
		dout.clear();
		for (int i = 0; i < n; ++i)
		{
			vu[i] = s[i];
			vi[i] = n-1-s[i];
		}
		for (int i = 0; i < n; i++) {
			vector<pair< int, int> > ve, vk;
     		for (int j = 0; j < n; j++) {
                if (!used[j]) {
                	ve.emplace_back(-vu[j], j);
                    vk.emplace_back(-vi[j], j);
                }
     		}
     		sort(ve.begin(), ve.end());
     		sort(vk.begin(), vk.end());
     		if (ve[0].first < vk[0].first) {
     		    int v = ve[0].second;
         		used[v] = 1;
         		for (int j = 0; j < vk.size(); j++) {
                    int u = vk[j].second;
                    if (u == v) continue;
                    if (vu[v] > 0) {
	                	assert(vu[v] > 0);
	                  	assert(vi[u] > 0);                    
	                	vu[v]--;
	                    vi[u]--;
	                    g[v].push_back(u);
	                }
	                else {
	                	assert(vu[u] > 0);
	                	assert(vi[v] > 0);
	                    vi[v]--;
	                    vu[u]--;
	                    g[u].push_back(v);
	                }
         		}
     		}
     		else {
     		    int u = vk[0].second;
         		used[u] = 1;
         		for (int j = 0; j < ve.size(); j++) {
                    int v = ve[j].second;
                    if (u == v) continue;
                    if (vi[u] > 0) {
	                	assert(vu[v] > 0);
	                  	assert(vi[u] > 0);                    
	                	vu[v]--;
	                    vi[u]--;
	                    g[v].push_back(u);
	                }
	                else {
	                	assert(vu[u] > 0);
	                	assert(vi[v] > 0);
	                    vi[v]--;
	                    vu[u]--;
	                    g[u].push_back(v);
	                }
         		}
     		}
		}

       int ans = 0;
       for (int i = 0; i < n; i++) {
           memset(b, 0, sizeof b);
           dfs(i);
           for (int j = 0; j < n; ++j) {
           	   ans += b[j];
           }
       }
       return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing ScoresSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1498820411;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ScoresSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {2, 0, 1};
				_expected = 6;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int s[] = {1, 0, 2};
				_expected = 6;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int s[] = {1, 1, 1};
				_expected = 9;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int s[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
				_expected = 55;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int s[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
				_expected = 1422;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 5:
			{
				int s[] = {0};
				_expected = 1;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 6:
			{
				int s[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int s[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
