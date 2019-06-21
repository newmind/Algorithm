package net.acmicpc.p2504_stack_calc;

/*
https://www.acmicpc.net/problem/2504
괄호의 값

*/

import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    Stack<Tuple<Integer, Long>> stack = new Stack<>();

    String s = br.readLine();
    for (int i = 0; i < s.length(); i++) {
      int x = (int)s.charAt(i);
      if (x == ')') {
        if (stack.empty()) {
          stack.clear();
          break;
        }
        Tuple<Integer,Long> t = stack.pop();
        if (t._1 == '(') {
          long a = 2;
          if (!stack.empty()) {
            Tuple<Integer,Long> t2 = stack.peek();
            if (t2._1 == 0) {
              stack.pop();
              a = t2._2 + a;
              if (!stack.empty()) {
                Tuple<Integer,Long> t3 = stack.peek();
                if (t3._1 == 0) {
                  stack.pop();
                  a = t3._2 + a;
                }
              }
            }
          }
          stack.push(new Tuple<Integer,Long>(0, a));
        } else if (t._1 == 0) {
          if (stack.empty()) {
            stack.clear();
            break;
          }
          
          if (stack.peek()._1 != '(') {
            stack.clear();
            break;
          }
          stack.pop();

          long a = t._2 * 2;
          if (!stack.empty()) {
            Tuple<Integer,Long> t2 = stack.peek();
            if (t2._1 == 0) {
              stack.pop();
              a = t2._2 + a;
            }
          }

          stack.push(new Tuple<Integer,Long>(0, a));
        } else {
          stack.clear();
          break;
        }

      } else if (x == ']') {
        if (stack.empty()) {
          stack.clear();
          break;
        }

        Tuple<Integer,Long> t = stack.pop();
        if (t._1 == '[') {
          long a = 3;
          if (!stack.empty()) {
            Tuple<Integer,Long> t2 = stack.peek();
            if (t2._1 == 0) {
              stack.pop();
              a = t2._2 + a;
              if (!stack.empty()) {
                Tuple<Integer,Long> t3 = stack.peek();
                if (t3._1 == 0) {
                  stack.pop();
                  a = t3._2 + a;
                }
              }
            }
          }
          stack.push(new Tuple<Integer,Long>(0, a));
        } else if (t._1 == 0) {
          if (stack.empty()) {
            stack.clear();
            break;
          }

          if (stack.peek()._1 != '[') {
            stack.clear();
            break;
          }
          stack.pop();
          
          long a = t._2 * 3;
          if (!stack.empty()) {
            Tuple<Integer,Long> t2 = stack.peek();
            if (t2._1 == 0) {
              stack.pop();
              a = t2._2 + a;
            }
          }
          stack.push(new Tuple<Integer,Long>(0, a));
        } else {
          stack.clear();
          break;
        }

      } else  {
        stack.push(new Tuple<Integer,Long>(x, 0L));
      }
    }
    
    if (stack.size() == 1 && stack.peek()._1 == 0) {
      System.out.println(stack.peek()._2);
    } else 
      System.out.println(0);
    return;
  }
}

class Tuple<T1, T2> {
  public final T1 _1;
  public final T2 _2;
  public Tuple (T1 a, T2 b) {
      this._1 = a;
      this._2 = b;
  }
}