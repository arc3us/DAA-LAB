import java.util.Scanner;

public class binary_search_iterative {

    public static void main(String[] args) {
        int arr[] = new int[10];
        Scanner ob = new Scanner(System.in);
        System.out.println("Enter 10 values for array");
        for (int i = 0; i < 10; i++) {
            arr[i] = ob.nextInt();
        }
        System.out.println("Enter value to search");
        int ele = ob.nextInt();
        int lo, hi, mid;
        lo=0;
        hi=10;
        mid=5;
        boolean flag = false;
        while(lo<hi)
        {
            if(arr[mid] == ele)
            {
                flag = true;
                break;
            }
            else if(ele<arr[mid])
                {
                    hi = mid;
                    mid = (lo + hi) /2;
                }
            else{
                lo = mid;
                mid = (lo+hi)/2;
            }
        }
        ob.close();
        if(flag)
            System.out.println("found");
        else
            System.out.println("Not found");

    }
}
