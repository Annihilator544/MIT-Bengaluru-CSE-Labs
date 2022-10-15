class Maximum {
    void max(int i,int j,int k){
        if(i>j&&i>k)
            System.out.println(i+" is the greatest number");
        else if(j>i&&j>k)
            System.out.println(j+" is the greatest number");
        else if(k>j&&k>i)
            System.out.println(k+" is the greatest number");
    }
    void max(float i,float j,float k){
        if(i>j&&i>k)
            System.out.println(i+" is the greatest number");
        else if(j>i&&j>k)
            System.out.println(j+" is the greatest number");
        else if(k>j&&k>i)
            System.out.println(k+" is the greatest number");
    }
    void max(int arr[]){
        Array.stream(arr).max().getasInt();
    }
    void max(int arr[][]){
        int m=arr[0][0];
        for (int i =0;i<arr.length;i++){
            for (int j =0;i<arr.length;j++){
                if(arr[i][j]>max)
                max=arr[i][j];
            }

        }
        System.out.println(max);
    }
}