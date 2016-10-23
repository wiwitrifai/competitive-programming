/**
 *  IEEExtreme Programming Contest 10
 *  Problem : Goldbach's Second Conjecture
 *  Solver  : Wiwit Rifa'i
 *  Status  : Accepted
 */


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

public class Solution {
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
    boolean isprim[] = new boolean[10000];
    for (int i = 2; i < 10000; i++)
      isprim[i] = true;
    isprim[0] = isprim[1] = false;
    for (int i = 2; i < 10000; i++) if (isprim[i]) {
      for (int j = i * i; j < 10000; j += i)
        isprim[j] = false;
    }
    long n = in.nextLong();
    long a = 0, bb = 0, c = 0;
    for (int i = 4; i < 10000 && a <= 0; i++) {
      BigInteger b = BigInteger.valueOf(n - i);
      if (b.isProbablePrime(5)) {
        for (int j = 2; j < i && a <= 0; j++) if (isprim[j] && isprim[i-j]) {
          a = n-i;
          bb = j;
          c = i-j;
          break;
        }
      }
    }
    out.println(a + " " + bb + " " + c);

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