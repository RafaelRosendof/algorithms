//It's done the linear search
import java.util.Random;
public class Linear {
    
    public static boolean lsearch(int[] arr , int target ){
        for(int i = 0 ; i < arr.length ; i++){
            if(arr[i] == target){
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
       // System.out.println("figas");

       int [] arr = new int[100];

       Random random = new Random();
        //Create a array and fill with random numbers 
       for(int i = 0 ; i < arr.length ; i++){
        arr[i] = random.nextInt(101);
       }


       boolean res1 = lsearch(arr, 12);
       boolean res2 =  lsearch(arr, 10);
       boolean res3 =  lsearch(arr, -58); 

       assert res1 == true : "test 1 faliled";
       System.out.println("Teste 1 = Passou");

       assert res2 == true : "test 2 failed";
       System.out.println("Teste 2 = Passou");

       assert res3 == true : "test 3 failed";
       System.out.println("Teste 3 = Passou");


    }
}