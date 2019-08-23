#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

struct node {
	long long val, cnt;
	node(long long val = -1, long long cnt = 0) : val(val), cnt(cnt) {}
	node operator+(node other) {
		if (val == other.val)
			return node(val, (cnt + other.cnt) % mod);
		if (val < other.val)
			return other;
		return *this;
	}
	node operator*(node other) {
		if (val == -1 || other.val == -1) return node();
		return node(val + other.val, cnt * other.cnt % mod);
	}
};

struct matrix {
	int n, m;
	node a[103][103];
	matrix(int n = 0, int m = 0) : n(n), m(m) {}
	node* operator[](int id) { return a[id]; }
	const node* operator[](int id) const { return a[id]; }
  matrix operator*(matrix other) {
  	matrix ret(n, other.m);
  	for (int i = 0; i < n; i++) {
  		for (int j = 0; j < other.m; j++) {
  			for (int k = 0; k < m; ++k) {
         ret[i][j] = ret[i][j] + a[i][k] * other[k][j];
       }
  		}
  	}
  	return ret;
  }
};
int ma[103], cnt[103];

class CoinsQuery {
public:
	vector<long long> query(vector <int> w, vector <int> v, vector <int> query) {
		int n = w.size();
	  matrix b(100, 100);
    memset(ma, 0, sizeof ma);
    for (int i = 0; i < n; ++i) {
    	b[0][w[i]-1] = b[0][w[i]-1] + node(v[i], 1);
    }
    for (int i = 1; i < 100; ++i) {
    	b[i][i-1] = node(0, 1);
    }
    vector< matrix > m;
    m.push_back(b);
    int ma = 0;
    for (int v : query)
    	ma = max(v, ma);
    while ((1LL << m.size()) <= ma) m.push_back(m.back() * m.back());
    vector< long long > ans;
    for (int i = 0; i < query.size(); i++) {
      matrix v(100, 1);
      v[0][0] = node(0, 1);
      for (int j = 0; j < m.size(); j++)
      	if (query[i] & (1<<j))
	      	v = m[j] * v;
	     node res = v[0][0];
	     if (res.val == -1) res.cnt = -1;
	     ans.push_back(res.val);
	     ans.push_back(res.cnt);
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
		cout << "Testing CoinsQuery (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1493263277;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CoinsQuery _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int w[] = {2,3,5};
				int v[] = {20,30,50};
				int query[] = {1,2,3,4,5,6};
				long long __expected[] = {-1, -1, 20, 1, 30, 1, 40, 1, 50, 3, 60, 2 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 1:
			{
				int w[] = {7,4,3,8};
				int v[] = {10,20,17,13};
				int query[] = {10,100,1000,100000};
				long long __expected[] = {54, 3, 564, 33, 5664, 333, 566664, 33333 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 2:
			{
				int w[] = {2,3,5};
				int v[] = {1,10,100};
				int query[] = {1,2,3,4,5,6};
				long long __expected[] = {-1, -1, 1, 1, 10, 1, 2, 1, 100, 1, 20, 1 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 3:
			{
				int w[] = {1,1};
				int v[] = {1,1};
				int query[] = {10,20,30,40,50};
				long long __expected[] = {10, 1024, 20, 1048576, 30, 73741817, 40, 511620083, 50, 898961331 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 4:
			{
				int w[] = {1};
				int v[] = {1000000000};
				int query[] = {1,1000000000};
				long long __expected[] = {1000000000, 1, 1000000000000000000, 1 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			/*case 5:
			{
				int w[] = ;
				int v[] = ;
				int query[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int w[] = ;
				int v[] = ;
				int query[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int w[] = ;
				int v[] = ;
				int query[] = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.query(vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), vector <int>(query, query+sizeof(query)/sizeof(int))); break;
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
