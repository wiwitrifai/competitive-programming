#include <bits/stdc++.h>

using namespace std;

class AlphabetOrderDiv2 {
public:
	string isOrdered(vector <string> words) {
		int g[30][30];
		memset(g, -1, sizeof g);
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++) {
				for (int k = j+1; k < words[i].size(); k++) {
					int a = words[i][j]-'a', b = words[i][k] - 'a';
					if (a == b) continue;
					if (g[a][b] != -1) {
						if (g[a][b] != 1)
							return "Impossible";
					}
					g[a][b] = 1;
					g[b][a] = 0;
				}
			}
		}
		int d[30];
		memset(d, 0, sizeof d);
		int cnt = 0;
		stack< int > st;
		for (int i = 0; i < 26; i++) {
			d[i] = 0;
			for (int j = 0; j < 26; j++) {
				if (g[j][i] == 1)
					d[i]++;
			}
			if (d[i] == 0)
				st.push(i);
		}
		while (!st.empty()) {
			cnt++;
			int now = st.top();
			st.pop();
			for (int i = 0; i < 26; i++) {
				if (g[now][i] == 1) {
					d[i]--;
					if (d[i] == 0)
						st.push(i);
				}
			}
		}
		return cnt == 26 ? "Possible" : "Impossible";
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
		cout << "Testing AlphabetOrderDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484992855;
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
		AlphabetOrderDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"single","round","match"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"topcoder","topcoder"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"algorithm", "contest"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"pink","floyd"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"gimnasia","y","esgrima","la","plata"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"hello","hello"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 6:
			{
				string words[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 7:
			{
				string words[] = {"abc","bca"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 8:
			{
				string words[] = {"aaaaa","eeeee","iiiii","ooooo","uuuuu"} ;
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 9:
			{
				string words[] = {"ab","bc","ca"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 10:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 11:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 12:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
