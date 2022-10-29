class Maximum {
    static void max(int i,int j,int k){
        if(i>j&&i>k)
            System.out.println(i+" is the greatest number");
        else if(j>i&&j>k)
            System.out.println(j+" is the greatest number");
        else if(k>j&&k>i)
            System.out.println(k+" is the greatest number");
    }
    static void max(float i,float j,float k){
        if(i>j&&i>k)
            System.out.println(i+" is the greatest number");
        else if(j>i&&j>k)
            System.out.println(j+" is the greatest number");
        else if(k>j&&k>i)
            System.out.println(k+" is the greatest number");
    }
   static void max(int arr[]){
        Array.stream(arr).max().getasInt();
    }
    static void max(int arr[][]){
        int m=arr[0][0];
        for (int i =0;i<arr.length;i++){
            for (int j =0;i<arr.length;j++){
                if(arr[i][j]>max)
                max=arr[i][j];
            }

        }
        System.out.println(max);
    }
    public static void main(String args[]){
        max((float)2.3,(float)4.5,(float)6.7);
        max(2,6,8);

    }
}