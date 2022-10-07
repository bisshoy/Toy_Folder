import java.util.*;

public class CoinFlip {
   public static void main(String args[]) {

      Scanner input = new Scanner(System.in); 
        
      System.out.print("Enter your number: "); 
      int num = input.nextInt(); 

      for (int i = 1; i <= num; i++) { // number of rows 
         for (int j = num; j >= i; j--) { // number of stars printed 
            System.out.print("*");

         } 

         System.out.println();

      }

      input.close();

   }

}

