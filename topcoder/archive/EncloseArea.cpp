#include <bits/stdc++.h>

using namespace std;

const int N = 50;

bool used[N+5][N+5];

class EncloseArea {
public:
	vector <string> enclose(int A) {
		if (A & 1) {
			return vector<string>();
		}
		vector<string> ans(N, string(N, '.'));
		memset(used, false, sizeof used);
		A /= 2;
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < N; ++j) {
				int r = j, c = j+i;
				if (((r + c) & 1)) continue;
				if (min(r, c) <= 0 || max(r, c) >= N) continue;
				if (used[r][c]) continue;
				if (A <= 0) continue;
				--A;
				used[r][c] = 1;
			}
			for (int j = 1; j < N; ++j) {
				int r = j, c = j-i;
				if (((r + c) & 1)) continue;
				if (min(r, c) <= 0 || max(r, c) >= N) continue;
				if (used[r][c]) continue;
				if (A <= 0) continue;
				--A;
				used[r][c] = 1;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if ((i + j) & 1) {
					if (used[i][j+1] != used[i+1][j])
						ans[i][j] = '\\';
				}
				else {
					if (used[i][j] != used[i+1][j+1])
						ans[i][j] = '/';
				}
			}
		}
		if (A != 0)
			return vector<string>();
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
		cout << "Testing EncloseArea (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1579954000;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EncloseArea _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 12;
				string __expected[] = {"........", "../\\....", "./..\\...", ".\\...\\..", "..\\../..", "...\\/...", "........", "........" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 1:
			{
				int A = 7;
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 2:
			{
				int A = 2498;
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 3:
			{
				int A = 10;
				string __expected[] = {"./\\..", "/./..", "\\.\\/\\", ".\\../", "..\\/." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 4:
			{
				int A = 26;
				string __expected[] = {"/\\/\\/\\", "\\..../", "/....\\", "\\..../", "/....\\", "\\/\\/\\/" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 5:
			{
				int A = 196;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			case 6:
			{
				int A = 2402;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
			}
			/*case 7:
			{
				int A = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.enclose(A); break;
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
