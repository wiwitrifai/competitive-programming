import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class E {
  public static void main(String[] args) {
  InputStream inputStream = System.in;
  OutputStream outputStream = System.out;
  InputReader in = new InputReader(inputStream);
  PrintWriter out = new PrintWriter(outputStream);
  Task solver = new Task();
  solver.solve(1, in, out);
  out.close();
  }
}

class Task {
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    String s = in.next();
    int m = in.nextInt(), n = s.length();
    long cur = 0, mul = 1;
    for (int i = 0; i < n; i++) {
      cur = (cur * 10 + s.charAt(i)-'0') % m;
      mul = (mul * 10) % m;
    }
    long ans = cur;
    for (int i = 0; i < n; i++) {
      if (s.charAt(i) != '0') {
        if (ans > cur) ans = cur;
      }
      cur = (cur * 10 + s.charAt(i)-'0') % m;
      cur = (cur - mul * (s.charAt(i)-'0')) % m;
      if (cur < 0) cur += m;
    }
    out.println(ans);
  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream stream) {
  reader = new BufferedReader(new InputStreamReader(stream), 32768);
  tokenizer = null;
  }

  public String next() {
  while (tokenizer == null || !tokenizer.hasMoreTokens()) {
    try {
      tokenizer = new StringTokenizer(reader.readLine());
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }
  return tokenizer.nextToken();
  }

  public int nextInt() {
  return Integer.parseInt(next());
  }

  public long nextLong() {
  return Long.parseLong(next());
  }
    
  public double nextDouble() {
  return Double.parseDouble(next());
  }
}
