#include <bits/stdc++.h>

using namespace std;

const int N = 40;

vector< pair< int, int > > e[N];
long long a[N];
int dp[1 << 10], n;

void dfs(int v, int used, long long vis) {
	int cnt = __builtin_popcountll(vis);
	if (cnt + (n - v) <= dp[used])
		return;
	if (v == n) {
		dp[used] = max(dp[used], cnt);
		return;
	}
	dfs(v+1, used, vis);
	if ((vis & a[v]) != vis) return;
	for (auto it : e[v]) if (vis & (1LL<<it.first)) {
		used |= 1<<it.second;
	}
	dfs(v+1, used, vis | (1LL<<v));
}

class Clicounting {
public:
	int count(vector <string> g) {
		n = g.size();
		int id = 0;
		for (int i = 0; i < n; i++) {
			a[i] = 1LL<<i;
			for (int j = 0; j < n; j++) {
				if (g[i][j] != '0')
					a[i] |= (1LL<<j);
				if (g[i][j] == '?' && i < j) {
					e[j].emplace_back(i, id);
					id++;
				}
			}
		}
		memset(dp, 0, sizeof dp);
		dfs(0, 0, 0);
		int tot = 0;
		for (int i = 0; i < (1<<id); i++) {
			for (int j = 0; j < id; j++) if (i & (1<<j))
				dp[i] = max(dp[i], dp[i ^ (1<<j)]);
			tot += dp[i];
		}
		return tot;
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
		cout << "Testing Clicounting (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487345008;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Clicounting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string g[] = {"011","101","110"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 1:
			{
				string g[] = {"01?","101","?10"};
				_expected = 5;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 2:
			{
				string g[] = {"0?","?0"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 3:
			{
				string g[] = {"0??","?0?","??0"};
				_expected = 16;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 4:
			{
				string g[] = {"0???","?0??","??0?","???0"};
				_expected = 151;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 5:
			{
				string g[] = {"00110011011101011110101111011111101111", "001111111110111100111010011111001?1100", "11011110101101101110100111110111110011", "11100101011010101110111111111100100111", "01100001111111111111110111111111111100", "01110010011111101111100001101011011101", "11100101111101101100111001011101111010", "11011010111111101001111101010001111110", "01101011010111111111110101110111101101", "11011111101111001111111111101110101101", "11111111010101101110110010111110011011", "10101111111011010101111110010001110111", "01011101110101011111001010110100011011", "11101111111110111101101011110110111011", "01111111101001011110101001111010111111", "11001000100111100001100011110101110001", "10111111111011100110101111110111101101", "10111110111111101011101101100001111110", "11111100111010101101011100111101110111", "01001101110111010110111110101111101100", "11111111111101111101000010110001110001", "00011011111100000011000101110111011000", "11010011010111101111000010011111111101", "10111001110100001111010011000011111100", "10111000011111011001101100111010010101", "11111111110001111100010100011011111011", "01111100111011111111110010001101111110", "11111011101111111010111011000110101111", "11011110011000100011001011100111101110", "11111010111011011011011000111011110111", "10101100111001101001011111011101101111", "10101111100100011111111101101110111110", "11111011110101111111101101111111011110", "0?101111001111110110111111100101101110", "11001111111011101101011101111011110000", "11011101110100101111001110111111110010", "10110011001111100110000001111111110100", "10110100111111111010101011010110000000"};
				_expected = 20;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			/*case 6:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
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
