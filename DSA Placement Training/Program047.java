import java.util.*;

class Node
{
    int data;
    Node next;
}

class Program047
{
    public static Node newNode(int data){
        Node temp = new Node();
        temp.data = data;
        temp.next = null;
        return temp;
    }
    
    public static void makeLoop(Node head, int x){
        if (x == 0)
            return;
        Node curr = head;
        Node last = head;

        int currentPosition = 1;
        while (currentPosition < x)
        {
            curr = curr.next;
            currentPosition++;
        }
        
        while (last.next != null)
            last = last.next;
        last.next = curr;
    }
    
    public static boolean detectLoop(Node head){
        Node hare = head.next;
        Node tortoise = head;
        while( hare != tortoise )
        {
            if(hare==null || hare.next==null) return false;
            hare = hare.next.next;
            tortoise = tortoise.next;
        }
        return true;
    }
    
    public static int length(Node head){
        int ret=0;
        while(head!=null)
        {
            ret += 1;
            head = head.next;
        }
        return ret;
    }
    
    public static void main (String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            int t = sc.nextInt();
            
            while(t--> 0)
            {
                int n = sc.nextInt();
                
                int num = sc.nextInt();
                Node head = newNode(num);
                Node tail = head;
                
                for(int i=0; i<n-1; i++)
                {
                    num = sc.nextInt();
                    tail.next = newNode(num);
                    tail = tail.next;
                }
                
                int pos = sc.nextInt();
                makeLoop(head, pos);
                
                Solution x = new Solution();
                x.removeLoop(head);
                
                if( detectLoop(head) || length(head)!=n )
                    System.out.println("0");
                else
                    System.out.println("1");
            }
        }
    }
}

// } Driver Code Ends


/*
class Node
{
    int data;
    Node next;
}
*/

class Solution
{
    //Function to remove a loop in the linked list.
    public void removeLoop(Node head){
        // code here
        // remove the loop without losing any nodes
        //we use floyd's cycle detection algorithm
        //we find the meeting point of slow and fast pointers
        //then we move slow pointer to head and move both slow and fast pointers by one step
        //the point where they meet is the starting point of the loop
        //we make the next of the previous node of the starting point of the loop as null
        //time complexity O(n)
        //space complexity O(1)
        //alternate method
        //we use hashing
        //we store the addresses of the nodes in a hashset
        //if we find a node whose address is already present in the hashset
        //then we make the next of the previous node of the current node as null
        //time complexity O(n)
        //space complexity O(n)
        Node fast = head;
        Node slow = head;
        Node temp = head;
        int ab = 0;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
            
            if(fast==slow){
                 ab = 1;
                break;
            }
        }
        
        if(ab==1){
        while(slow!=temp){
                    slow= slow.next;
                    temp = temp.next;
                }
        }        
                
        while(fast!=null){
            if(fast.next == slow){
                fast.next = null;
                
                return;
            }
            fast = fast.next;
        }
    }
}