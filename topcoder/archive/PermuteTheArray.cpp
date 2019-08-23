#include <bits/stdc++.h>

using namespace std;

const int N = 255;

int p[N];
int col[N];
vector<int> e[N];

int find(int x) {
	if (p[x] < 0)
		return x;
	int root = find(p[x]);
	col[x] ^= col[p[x]];
	p[x] = root;
	return root;
}

bool merge(int u, int v, int d) {
	int ru = find(u), rv = find(v);
	if (ru == rv) {
		if ((col[u] ^ col[v]) != d)
			return false;
		return true;
	}
	if (ru > rv)
		swap(ru, rv);
	p[rv] = ru;
	col[rv] = d;
	for (int x : e[rv])
		e[ru].push_back(x);
	return true;
}
int cnt[N][2];
int dp[N][N];

class PermuteTheArray {
public:
	vector <int> getPermutation(vector <int> A, vector <int> x, vector <int> y, vector <int> d) {
		memset(p, -1, sizeof p);
		memset(col, 0, sizeof col);
		int n = A.size();
		for (int i = 0; i < n; ++i) {
			e[i].clear();
			e[i].push_back(i);
		}
		int m = x.size();
		for (int i = 0; i < m; ++i) {
			bool res = merge(x[i], y[i], d[i]);
			if (!res)
				return vector<int>();
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i) {
			if (p[i] < 0) {
				for (int x : e[i]) {
					find(x);
					++cnt[i][col[x]];
				}
			}
		}
		dp[n][0] = 1;
		for (int i = n-1; i >= 0; --i) {
			for (int j = 0; j <= n; ++j) {
				dp[i][j] = 0;
				for (int k = 0; k < 2; ++k)
					if (j >= cnt[i][k])
						dp[i][j] |= dp[i+1][j-cnt[i][k]];
			}
		}
		multiset<int> ganjil, genap;
		for (int i = 0; i < n; ++i)
			if (A[i] & 1)
				ganjil.insert(A[i]);
			else
				genap.insert(A[i]);
		if (!dp[0][ganjil.size()] && !dp[0][genap.size()])
			return vector<int>();
		vector<int> ans(n, -1);
		
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
		cout << "Testing PermuteTheArray (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1544376887;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PermuteTheArray _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1, 3, 5, 2};
				int x[] = {0};
				int y[] = {1};
				int d[] = {0};
				int __expected[] = {1, 3, 2, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1, 3, 5, 2};
				int x[] = {0, 1, 0, 1, 2};
				int y[] = {1, 2, 3, 3, 3};
				int d[] = {0, 0, 1, 1, 0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1, 3, 2, 5};
				int x[] = {0, 1, 0, 1, 2};
				int y[] = {1, 2, 3, 3, 3};
				int d[] = {0, 0, 1, 1, 1};
				int __expected[] = {1, 3, 5, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
				int x[] = {0, 0, 1, 5, 6};
				int y[] = {1, 2, 2, 6, 7};
				int d[] = {0, 0, 0, 0, 1};
				int __expected[] = {1, 3, 5, 2, 4, 6, 8, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {20, 546, 23, 20, 4, 573, 1, 3, 665, 32, 329, 54, 23, 9};
				int x[] = {};
				int y[] = {};
				int d[] = {};
				int __expected[] = {1, 3, 4, 9, 20, 20, 23, 23, 32, 54, 329, 546, 573, 665 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				int x[] = ;
				int y[] = ;
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int x[] = ;
				int y[] = ;
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int x[] = ;
				int y[] = ;
				int d[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
