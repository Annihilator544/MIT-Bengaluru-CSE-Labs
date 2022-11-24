class GenericArray{
    public static <T> void swap(T[] array, int left, int right){
        T temp = array[right];
        array[right] = array[left];
        array[left] = temp;
    }
    public static void main (String[]args){
        Integer arr[]=new Integer[2];
        arr[1]=5;
        arr[0]=10;
        swap(arr,0,1);
        System.out.println("arr[0] = "+arr[0]+"\narr[1] = "+arr[1]);
        String arr2[]=new String[2];
        arr2[1]="Hello";
        arr2[0]="World";
        swap(arr2,0,1);
        System.out.println("arr2[0] = "+arr2[0]+"\narr2[1] = "+arr2[1]);
    }
}