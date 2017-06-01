import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {    

    public static void print(int A[],int i){
        try {
            System.out.println(A[i]);
        }
        catch(Exception e) {
            throw e;            
        }
        finally {
            int ma = A[0], mi = A[0];
            for(int j = 0; j<A.length; j++) {
                if(A[j] < mi)
                    mi = A[j];
                if(A[j] > ma)
                    ma = A[j];
            }
            System.out.println(ma + " " + mi);
        }
    }
    public static void main(String[] args) {
        int N;
        Scanner st = new Scanner(System.in);
        N = st.nextInt();
        int A[] = new int[N];
        for(int i = 0; i < N; i++) {
           A[i] = st.nextInt();
        }
        int i = st.nextInt();
        try {
            print(A, i);

        }
        catch(Exception e) {
            System.out.println(e.getClass().getName());
        }
   }// end of main
}// end of Solution