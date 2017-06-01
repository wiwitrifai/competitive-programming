import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Student{
   private int token;
   private String fname;
   private double cgpa;
   public Student(int id, String fname, double cgpa) {
      super();
      this.token = id;
      this.fname = fname;
      this.cgpa = cgpa;
   }
   public int getToken() {
      return token;
   }
   public String getFname() {
      return fname;
   }
   public double getCgpa() {
      return cgpa;
   }
}

class comp implements Comparator<Student> {
    @Override
    public int compare(Student a, Student b) {
        if(a.getCgpa() == b.getCgpa()) {
            if(a.getFname().equals(b.getFname())) {
                return a.getToken()-b.getToken();
            }
            else
                return a.getFname().compareTo(b.getFname());
        }
        else
            return (a.getCgpa() > b.getCgpa()) ? -1 : 1;
    }
}
public class Solution {

    public static void main(String[] args) {
      Scanner in = new Scanner(System.in);
      int totalEvents = Integer.parseInt(in.nextLine());
      Comparator<Student> comparator = new comp();
      PriorityQueue<Student> pq = new PriorityQueue<Student>(totalEvents, comparator);
      while(totalEvents>0){
         String event = in.next();
         if(event.equals("SERVED")) {
            if(pq.size() > 0)
                pq.remove();
         }
         else {
            String name = in.next();
            double cgpa = in.nextDouble();
            int token = in.nextInt();
            Student student = new Student(token, name, cgpa);
            pq.add(student);
         }
         totalEvents--;
      }
      if(pq.size() == 0)
          System.out.println("EMPTY");
       else {
           while(pq.size() > 0) {
               Student student = pq.remove();
               System.out.println(student.getFname());
           }
       }
    }
}
