import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt();
        BitSet[] B = new BitSet[2];
        B[0] = new BitSet(n);
        B[1] = new BitSet(n);
        while(m-- >= 0) {
            String op = in.next();
            int opd1 = in.nextInt();
            int opd2 = in.nextInt();
            opd1--; opd2--;
            if(op.equals("AND"))
                B[opd1].and(B[opd2]);
            else if(op.equals("OR"))
                B[opd1].or(B[opd2]);
            else if(op.equals("XOR"))
                B[opd1].xor(B[opd2]);
            else {
                opd2++;
                if(op.equals("FLIP"))
                    B[opd1].flip(opd2);
                else
                    B[opd1].set(opd2);
            }
            System.out.println(B[0].cardinality() + " " + B[1].cardinality());
        }
    }
}