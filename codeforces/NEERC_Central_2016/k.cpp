#include <bits/stdc++.h>

using namespace std;

struct commandd {
  commandd(string cmd = "", string p1 = "", string p2 = "") : cmd(cmd), p1(p1), p2(p2) {}
  string cmd, p1, p2;
  bool operator==(commandd c) {
    return cmd == c.cmd && p1 == c.p1 && p2 == c.p2;
  }
  bool operator!=(commandd c) {
    return !(*this == c);
  }
  void print() {
    cout << cmd << " " << p1;
    if (p2.size())
      cout << ", " << p2;
    cout << "\n";
  }
};

bool isHex(char c) {
  return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F');
}
bool isConst(string s) {
  if (s.size() != 2) return 0;
  return isHex(s[0]) && isHex(s[1]);
}

bool isRegister(string s) {
  if (s.size() != 2) return 0;
  return s[0] == 'R' && s[1] >= '1' && s[1] <= '8';
}

bool shortenMov1(vector<commandd> & vc) {
  int sz = 2;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - 2;
  string rx = vc[i+1].p1, ry = vc[i].p1;
  if (!isRegister(rx) || !isRegister(ry)) return 0;
  if (vc[i] != commandd("PUSH", ry)) return 0; 
  if (vc[i+1] != commandd("POP", rx)) return 0; 
  commandd c("MOV", rx, ry);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}


bool shortenMov2(vector<commandd> & vc) {
  int sz = 2;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i].p1, co = vc[i+1].p2;
  if (!isRegister(rx) || !isConst(co)) return 0;
  if (vc[i] != commandd("XOR", rx, rx)) return 0;
  if (vc[i+1] != commandd("ADD", rx, co)) return 0;
  commandd c("MOV", rx, co);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenAdd1(vector<commandd> & vc) {
  int sz = 4;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i+2].p1, ry = vc[i+1].p2, rz = vc[i].p1;
  if (!isRegister(rx) || !isRegister(ry) || !isRegister(rz)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("PUSH", rz)) return 0; 
  if (vc[i+1] != commandd("MOV", rz, ry)) return 0;
  if (vc[i+2] != commandd("ADD", rx, rz)) return 0;
  if (vc[i+3] != commandd("POP", rz)) return 0;
  commandd c("ADD", rx, ry);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenAdd2(vector<commandd> & vc) {
  int sz = 5;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i+2].p2, co = vc[i+1].p2, rz = vc[i].p1;
  if (!isRegister(rx) || !isConst(co) || !isRegister(rz)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("PUSH", rz)) return 0; 
  if (vc[i+1] != commandd("MOV", rz, co)) return 0;
  if (vc[i+2] != commandd("ADD", rz, rx)) return 0;
  if (vc[i+3] != commandd("MOV", rx, rz)) return 0;
  if (vc[i+4] != commandd("POP", rz)) return 0;
  commandd c("ADD", rx, co);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenXor1(vector<commandd> & vc) {
  int sz = 7;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i+3].p1, ry = vc[i+1].p2, rz = vc[i].p1, co = vc[i+2].p2;
  if (!isRegister(rx) || !isConst(co) || !isRegister(rz) || !isRegister(ry)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("PUSH", rz)) return 0; 
  if (vc[i+1] != commandd("MOV", rz, ry)) return 0;
  if (vc[i+2] != commandd("XOR", rz, co)) return 0;
  if (vc[i+3] != commandd("XOR", rx, rz)) return 0;
  if (vc[i+4] != commandd("MOV", rz, co)) return 0;
  if (vc[i+5] != commandd("XOR", rx, rz)) return 0;
  if (vc[i+6] != commandd("POP", rz)) return 0;
  commandd c("XOR", rx, ry);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenXor2(vector<commandd> & vc) {
  int sz = 5;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i+2].p1, rz = vc[i].p1, co = vc[i+1].p2;
  if (!isRegister(rx) || !isConst(co) || !isRegister(rz)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("PUSH", rz)) return 0; 
  if (vc[i+1] != commandd("XOR", rz, co)) return 0;
  if (vc[i+2] != commandd("XOR", rx, rz)) return 0;
  if (vc[i+3] != commandd("POP", rz)) return 0;
  if (vc[i+4] != commandd("XOR", rx, rz)) return 0;
  commandd c("XOR", rx, co);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenPush(vector<commandd> & vc) {
  int sz = 7;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i].p1, rz = vc[i+1].p2;
  if (!isRegister(rx) || !isRegister(rz)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("PUSH", rx)) return 0; 
  if (vc[i+1] != commandd("MOV", rx, rz)) return 0;
  if (vc[i+2] != commandd("POP", rz)) return 0;
  if (vc[i+3] != commandd("PUSH", rz)) return 0;
  if (vc[i+4] != commandd("XOR", rx, rz)) return 0;
  if (vc[i+5] != commandd("XOR", rz, rx)) return 0;
  if (vc[i+6] != commandd("XOR", rx, rz)) return 0;
  commandd c("PUSH", rx);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}

bool shortenPop(vector<commandd> & vc) {
  int sz = 5;
  if (vc.size() < sz) return 0;
  int i = (int)vc.size() - sz;
  string rx = vc[i].p1, rz = vc[i].p2;
  if (!isRegister(rx) || !isRegister(rz)) return 0;
  if (rx == rz) return 0;
  if (vc[i] != commandd("MOV", rx, rz)) return 0; 
  if (vc[i+1] != commandd("POP", rz)) return 0;
  if (vc[i+2] != commandd("XOR", rx, rz)) return 0;
  if (vc[i+3] != commandd("XOR", rz, rx)) return 0;
  if (vc[i+4] != commandd("XOR", rx, rz)) return 0;
  commandd c("POP", rx);
  for (int i = 0; i < sz; i++) vc.pop_back();
  vc.push_back(c);
  return true;
}


int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d ", &n);
  vector<commandd> vc;
  for (int t = 0; t < n; t++) {
    commandd c;
    cin >> c.cmd >> c.p1;
    if (c.cmd == "XOR" || c.cmd == "ADD" || c.cmd == "MOV") {
      c.p1.pop_back();
      cin >> c.p2;
      if (c.p2.size() == 1)
        c.p2 = "0" + c.p2;
    }
    vc.push_back(c);
    bool ok = 1;
    while (ok) {
      ok = 0;
      ok |= shortenMov1(vc);
      ok |= shortenMov2(vc);
      ok |= shortenAdd1(vc);
      ok |= shortenAdd2(vc);
      ok |= shortenXor1(vc);
      ok |= shortenXor2(vc);
      ok |= shortenPush(vc);
      ok |= shortenPop(vc);
    }
  }
  cout << vc.size() << "\n";
  for (commandd c : vc)
    c.print();
  return 0;
}