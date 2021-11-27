import java.util.Scanner;

public class binary_search_recursive {

    public int bSearch(int arr[], int lo, int hi, int ele) 
    {
        if (hi > lo)
        {
            int mid = (hi + lo)/2;
            if(arr[mid] == ele)
                return mid;
            
            if(arr[mid] > ele)
                return bSearch(arr, lo, mid-1, ele);
            
            return bSearch(arr, mid+1, hi, ele);
        }

        return -1;
        
    }

    public static void main(String[] args) {
        binary_search_recursive bs = new binary_search_recursive();
        int arr[] = new int[10];
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter 10 values for array");
        for (int i = 0; i < 10; i++) {
            arr[i] = ob.nextInt();
        }
        System.out.println("Enter value to search");
        int ele = ob.nextInt();
        int c = bs.bSearch(arr, 0, 10, ele);
        if(c==-1)
            System.out.println("Not found");
        else
             System.out.println("Found");
        ob.close();
    }
    
}
