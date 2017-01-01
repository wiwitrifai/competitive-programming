#include <bits/stdc++.h>

using namespace std;

const int N = 33;

class P8XMatrixRecovery {
public:
	int n, g[N][N];
	int match[N], mark[N];
	bool dfs(int v) {
		if (mark[v])
			return false;
		mark[v] = 1;
		for (int u = 0; u < n; u++) if (g[v][u])
			if (match[u] == -1 || dfs(match[u]))
				return match[u] = v, true;
		return false;
	}
	bool check() {
		memset(match, -1, sizeof match);
		for (int i = 0; i < n; i++) {
			memset(mark, 0, sizeof mark);
			if (!dfs(i))
				return false;
		}
		return true;
	}
	vector <string> solve(vector <string> rows, vector <string> columns) {
		int r = rows.size(), c = n = columns.size();
		memset(g, 0, sizeof g);
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				bool ok = true;
				for (int k = 0; k < r; k++) {
					if (rows[k][i] == '1' || columns[j][k] == '1') {
						if (rows[k][i] == '0' || columns[j][k] == '0') {
							ok = false;
							break;
						}
					}
				}
				g[i][j] = ok;
			}
		}
		assert(check());
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) if (rows[i][j] == '?') {
				bool bef[N];
				rows[i][j] = '0';
				for (int k = 0; k < c; k++) {
					bef[k] = g[j][k];
					if (columns[k][i] == '1')
						g[j][k] = 0;
				}
				if (!check()) {
					rows[i][j] = '1';
					for (int k = 0; k < c; k++) {
						g[j][k] = bef[k];
						if (columns[k][i] == '0')
							g[j][k] = 0;
					}
					assert(check());
				}
			}
		}
		return rows;
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
		cout << "Testing P8XMatrixRecovery (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483082555;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		P8XMatrixRecovery _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string rows[] = {"10?"
				                ,"?11"};
				string columns[] = {"01"
				                   ,"10"
				                   ,"1?"};
				string __expected[] = {"101", "011" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 1:
			{
				string rows[] = {"0"
				                ,"?"
				                ,"1"};
				string columns[] = {"0?1"};
				string __expected[] = {"0", "0", "1" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 2:
			{
				string rows[] = {"10"
				                ,"01"};
				string columns[] = {"10"
				                   ,"01"};
				string __expected[] = {"10", "01" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			case 3:
			{
				string rows[] = {"??0"
				                ,"11?"
				                ,"?01"
				                ,"1?1"};
				string columns[] = {"1???"
				                   ,"?111"
				                   ,"0?1?"};
				string __expected[] = {"010", "110", "101", "101" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}
			/*case 4:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string rows[] = ;
				string columns[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(rows, rows+sizeof(rows)/sizeof(string)), vector <string>(columns, columns+sizeof(columns)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
