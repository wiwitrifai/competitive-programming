#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<string> rotate(vector<string> s) {
	int n = s.size(), m = s[0].size();
	vector<string> res;
	for (int i = 0; i < m; i++)
		res.push_back(string(n, '.'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			res[j][n-1-i] = s[i][j];
		}
	}
	return res;
}

bool cek(vector<string> s) {
	int n = s.size(), m = s[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (s[i][j] == '.') continue;
			if (s[i][j-1] == '.') return false;
		}
	}
	return true;
}

const int N = 1024;

long long powmod(long long b, long long p) {
	long long r= 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

long long C[N][N];

long long calc(vector<int> h, int n, int m) {
	long long ans = 1;
	for (int i = 0; i < n; i++)
		ans = (ans * C[m][h[i]]) % mod;
	return ans;
}

class GravityPuzzle {
public:
	int count(vector <string> board) {
		for (int i = 0; i < N; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++)
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
		for (int _i = 0; _i < 4; _i++) {
			board = rotate(board);
			if (!cek(board)) continue;
			int n = board.size(), m = board[0].size();
			vector<int> h;
			for (int i = 0; i < n; i++) {
				int j = 0;
				while (j < m && board[i][j] == '#') j++;
				h.push_back(j);
			}
			bool dua = 1;
			if (h[0] < h.back())
				reverse(h.begin(), h.end());
			for (int i = 1; i < n; i++)
				dua &= h[i-1] >= h[i];
			if (dua) {
				long long ans = 0;
				vector<int> v(m);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < h[i]; j++)
						v[j]++;
				}
				long long mula = C[n][v[0]], mulb = C[m][h[0]];
				for (int i = 1; i < m; i++)
					mula = (mula * C[v[i-1]][v[i]]) % mod;
				for (int i = 1; i < n; i++)
					mulb = (mulb * C[h[i-1]][h[i]]) % mod;
				ans = mula * calc(h, n, m) + mulb * calc(v, m, n) - mula * mulb;
				ans %= mod;
				if (ans < 0) ans += mod;
				return ans;
			}
			else {
				long long ans = 1;
				for (int i = 0; i < n; i++)
					ans = (ans * C[m][h[i]]) % mod;
				return (int) ans;
			}
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
		cout << "Testing GravityPuzzle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1511887663;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GravityPuzzle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"#...",
				                  "....",
				                  "...."};
				_expected = 12;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {".#."};
				_expected = 1;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"#.",
				                  "##"};
				_expected = 4;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {".##",
				                  "..#",
				                  "..."};
				_expected = 72;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".##########.",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............",
				                  "............"};
				_expected = 999999937;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"."};
				_expected = 1;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"##........", "###.......", "####......", "######....", "######....", "########..", "########..", "##########", "##########"};
				_expected = 767661144;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 7:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
