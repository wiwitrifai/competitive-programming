#include <bits/stdc++.h>

using namespace std;

const int N = 32;
int match[N], matched[N];
bool mark[N];
vector<int> adj[N];

bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

class MaximizingGCD {
public:
	int maximumGCDPairing(vector <int> A) {
		set<int> all;
		int n = A.size();
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				all.insert(A[i] + A[j]);
		set<int> fact;
		for (int x : all) {
			vector<int> fnow;
			fnow.push_back(1);
			for (long long i = 2; i * i <= x; ++i) {
				if (x % i) continue;
				int sz = fnow.size();
				int mul = 1;
				while ((x % i) == 0) {
					x /= i;
					mul *= i;
					for (int j = 0; j < sz; ++j)
						fnow.push_back(fnow[j] * mul);
				}
			}
			if (x > 1) {
				int sz = fnow.size();
				for (int j = 0; j < sz; ++j)
					fnow.push_back(fnow[j] * x);
			}
			for (int x : fnow)
				fact.insert(x);
		}
		for (auto it = fact.rbegin(); it != fact.rend(); ++it) {
			int x = *it;
			vector<int> lo, hi;
			int zero = 0, half = 0;
			for (int i = 0; i < n; ++i) {
				int r = A[i] % x;
				if (r == 0)
					++zero;
				else if (r * 2 < x)
					lo.push_back(r);
				else if (r * 2 == x)
					++half;
				else
					hi.push_back(r);
			}
			if (zero & 1)
				continue;
			if (half & 1)
				continue;
			if (lo.size() != hi.size())
				continue;
			int m = lo.size();
			fill(matched, matched + m, -1);
			fill(match, match + m, -1);
			for (int i = 0; i < m; ++i)
				adj[i].clear();
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < m; ++j) {
					if ((lo[i] + hi[j]) == x)
						adj[i].push_back(j);
				}
		  while(true){
		    memset(mark, false, sizeof mark);
		    bool fnd = false;
		    for(int i = 0; i < lo.size(); i++) if(matched[i] == -1 && !mark[i])
		      fnd |= dfs(i);
		    if(!fnd)
		      break;
		  }
		  bool ok = 1;
		  for (int i = 0; i < m; ++i)
		  	if (matched[i] == -1) {
		  		ok = 0;
		  		break;
		  	}
		  if (ok)
		  	return x;
		}
		return 1;
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
		cout << "Testing MaximizingGCD (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1544374805;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MaximizingGCD _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {5, 4, 13, 2};
				_expected = 6;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {26, 23};
				_expected = 49;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {100, 200, 300, 500, 1100, 700};
				_expected = 100;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {46, 78, 133, 92, 1, 23, 29, 67, 43, 111, 3908, 276, 13, 359, 20, 21};
				_expected = 4;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
				          65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608};
				_expected = 16400;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.maximumGCDPairing(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
