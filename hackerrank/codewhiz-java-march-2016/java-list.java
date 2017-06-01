import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List list = new ArrayList();
        for(int i = 0; i<n; i++) {
            list.add(in.nextInt());
        }
        int q = in.nextInt();
        while(q-- > 0) {
            String op = in.next();
            if(op.equals("Insert")) {
                int x = in.nextInt(), y = in.nextInt();
                list.add(x, y);
            }
            else {
                int x = in.nextInt();
                list.remove(x);
            }
        }
        for(int i = 0; i<list.size(); i++)
            System.out.print(list.get(i) + " ");
    }
}