//{ Driver Code Starts
//Initial template code for JAVA

import java.util.*;

class Node
{
    int data;
    Node next;
    
    Node(int x)
    {
        data = x;
        next = null;
    }
}

class Program046
{
    public static void makeLoop(Node head, Node tail, int x){
        if (x == 0) return;
        
        Node curr = head;
        for(int i=1; i<x; i++)
            curr = curr.next;
        
        tail.next = curr;
    }
    
    public static void main (String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            
            while(t--> 0)
            {
                int n = sc.nextInt();
                
                int num = sc.nextInt();
                Node head = new Node(num);
                Node tail = head;
                
                for(int i=0; i<n-1; i++)
                {
                    num = sc.nextInt();
                    tail.next = new Node(num);
                    tail = tail.next;
                }
                
                int pos = sc.nextInt();
                makeLoop(head, tail, pos);
                
                Solution x = new Solution();
                if( x.detectLoop(head) )
                    System.out.println("True");
                else
                    System.out.println("False");
            }
        }
    }
}

// } Driver Code Ends


//User function template for JAVA

/* Node is defined as

class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}

*/


class Solution {
    //Function to check if the linked list has a loop.
    public boolean detectLoop(Node head){
        // Add code here
        //using floyd's cycle finding algorithm
        //time complexity O(n)
        //space complexity O(1)
        Node slow = head;
        Node fast = head;
        while(fast!=null && fast.next!=null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
}