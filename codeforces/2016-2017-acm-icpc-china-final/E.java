import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

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
  int parse(String s) {
    int red = 0;
    int res = 0, mul = 3;
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (c == '.')
        red = 1;
      else {
        res *= 10;
        res += c - '0';
        mul -= red;
      }
    }
    while (mul > 0) {
      res *= 10;
      mul--;
    }
    return res;
  }
  int gcd(int a, int b) {
    return a > 0 ? gcd(b % a, a) : b;
  }
  public void solve(int testNumber, InputReader in,PrintWriter out) {
    int t = in.nextInt();
//    out.println(t);
    for (int tc = 1; tc <= t; tc++) {
      int n = in.nextInt();
      int[] a = new int[n];
      int[] b = new int[n];
      for (int i = 0; i < n; i++) {
        String s = in.next();
        String[] ss = s.split(":");
        a[i] = parse(ss[0]);
        b[i] = parse(ss[1]);
        int d = gcd(a[i], b[i]);
        a[i] /= d;
        b[i] /= d;
//        out.println(a[i] + " " + b[i] );
      }
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          if (1L * a[i] * (a[j] + b[j]) > 1L * a[j] * (a[i] + b[i])) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
          }
        }
      }
      BigInteger up = BigInteger.valueOf(a[0]);
      BigInteger down = BigInteger.valueOf(a[0] + b[0]);
      int ans = 1;
      while (ans < n) {
        BigInteger bigA = BigInteger.valueOf(a[ans]), bigB = BigInteger.valueOf(a[ans] + b[ans]);
        up = up.multiply(bigB).add(down.multiply(bigA));
        down = down.multiply(bigB);
        if (up.compareTo(down) >= 0)
          break;
        ans++;
      }
      out.println("Case #"+tc + ": " + ans);
    }
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