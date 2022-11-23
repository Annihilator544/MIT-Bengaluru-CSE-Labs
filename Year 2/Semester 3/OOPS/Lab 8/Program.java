import java.lang.Thread;
class Producer extends Thread {
    StringBuffer buffer;
    boolean dp = false;
    Producer()
    {
        buffer = new StringBuffer(4);
    }
    public void run()
    {
        synchronized (buffer)
        {
            for (int i = 0; i < 4; i++) {
                try {
                    buffer.append(i);
                    System.out.println("Produced " + i);
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
            System.out.println("Buffer is FUll");
            buffer.notify();
        }
    }
}
class Consumer extends Thread {
    Producer p;
    Consumer(Producer temp)
    {
        p = temp;
    }
    public void run()
    {
        synchronized (p.buffer)
        {
            try {
                p.buffer.wait();
            }
            catch (Exception e) {
                e.printStackTrace();
            }
            for (int i = 0; i < 4; i++) {
                System.out.print(p.buffer.charAt(i) + " ");
            }
            System.out.println("\nBuffer is Empty");
        }
    }
}
class GFG {
    public static void main(String args[]){
        Producer p = new Producer();
        Consumer c = new Consumer(p);
        Thread t1 = new Thread(p);
        Thread t2 = new Thread(c);
        t2.start();
        t1.start();
    }
}