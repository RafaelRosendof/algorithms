import java.util.Arrays;
import java.util.Random;

public class Binary{
    //binary funcition

    //create a array and fill with random numbers 
    //sort 
    // create the asserts

    public boolean binary(int[] arr , int target){
        //create mid 
        //create first and last
        int first = 0;
        int last = arr.length - 1;

        while(first < last){
            int mid = first + (last - first) / 2;

            //if meio == target 
            if(mid == target){return true;}

            if(mid < target){
                first = mid;
            }
            else if(mid > target){
                last = mid;
            }
        }
        return false;
    }

    public static void main(String[] args) {
       // System.out.println("figas");

       int [] arr = new int[300];

       Random random = new Random();
        //Create a array and fill with random numbers 
       for(int i = 0 ; i < arr.length ; i++){
        arr[i] = random.nextInt(101);
       }
       Binary binario = new Binary();

       //first we gonna need to sort our array

       Arrays.sort(arr);

       boolean res1 = binario.binary(arr, 12);
       boolean res2 =  binario.binary(arr, 10);
       boolean res3 =  binario.binary(arr, 58); 

       assert res1 == true : "test 1 faliled";
       System.out.println("Teste 1 = Passou");

       assert res2 == true : "test 2 failed";
       System.out.println("Teste 2 = Passou");

       assert res3 == true : "test 3 failed";
       System.out.println("Teste 3 = Passou");


    }
}