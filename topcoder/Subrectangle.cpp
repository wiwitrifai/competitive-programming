#include <bits/stdc++.h>

using namespace std;

class Subrectangle {
public:
	int minMissed(string S) {
		vector<int> isi, kosong;
		char cur = '.';
		int cnt = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] != cur) {
				if (cur == '#')
					isi.push_back(cnt);
				else
					kosong.push_back(cnt);
				cnt = 0;
				cur = S[i];
			}
			cnt++;
		}
		if (cnt > 0) {
			if (cur == '.') {
				kosong.push_back(cnt);
			} else {
				isi.push_back(cnt);
				kosong.push_back(0);
			}
		}
		int tot = 0;
		for (int x : kosong)
			tot += x;
		if (isi.empty()) return 1;
		for (int add = 0; add <= S.size(); ++add) {
			int n = S.size() + add;
			for (int h = 1; h <= n; ++h) {
				if (n % h) continue;
				int w = n/h;
				for (int a = 1; a <= w; ++a) {
					if (a == w) {
						if (tot > 0)
							continue;
						return add;
					}
					int b = w - a;
					int z = 0;
					assert(kosong.size() > 1);
					int awal = kosong[0], akhir = kosong.back();
					while (awal >= w) z++, awal -= w;
					while (akhir >= w) z++, akhir -= w;
					awal += akhir;
					while (awal > b) awal -= b, z++;
					for (int x : isi)
						z += (x + a - 1) / a;
					for (int i = 1; i+1 < kosong.size(); ++i) {
						int x = kosong[i];
						z += (x + b - 1) / b - 1;
					}
					if (z <= h)
						return add;
				}
			}
		}
		return S.size();
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
		cout << "Testing Subrectangle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515638011;
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
		Subrectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "..###.##";
				_expected = 2;
				_received = _obj.minMissed(S); break;
			}
			case 1:
			{
				string S = "#.##.#.#..";
				_expected = 2;
				_received = _obj.minMissed(S); break;
			}
			case 2:
			{
				string S = "####";
				_expected = 0;
				_received = _obj.minMissed(S); break;
			}
			case 3:
			{
				string S = "";
				_expected = 1;
				_received = _obj.minMissed(S); break;
			}
			case 4:
			{
				string S = "........................................";
				_expected = 1;
				_received = _obj.minMissed(S); break;
			}
			case 5:
			{
				string S = "###...###";
				_expected = 3;
				_received = _obj.minMissed(S); break;
			}
			case 6:
			{
				string S = ".#.###.##...#.####.###...###.##";
				_expected = 15;
				_received = _obj.minMissed(S); break;
			}
			case 7:
			{
				string S = ".................................................##..##...##..............................";
				_expected = 5;
				_received = _obj.minMissed(S); break;
			}
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
			}*/
			/*case 9:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
			}*/
			/*case 10:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
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
