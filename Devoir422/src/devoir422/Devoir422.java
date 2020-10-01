/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package devoir422;

import java.util.Scanner;





/**
 *
 * @author Michel
 */
public class Devoir422 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        // TODO code application logic here
        init entre = new init();
        entre.initial();
        average Moy = new average();
        minimum Min = new minimum ();
        maximum Max = new maximum();
        
        
        Moy.average(entre.qtNmbr, entre.tab);
        Min.minimum(entre.qtNmbr, entre.tab);
        Max.maximum(entre.qtNmbr, entre.tab);
        
        
        
       // Moy.
       System.out.println("Threads start");
        Moy.start();
        Min.start();
        Max.start();
        
        while((Moy.isAlive() || Max.isAlive() || Min.isAlive()))
        {
            //System.out.println("Wait");
        }
        
        System.out.println("La moyenne est " + Moy.average(entre.qtNmbr, entre.tab));
         System.out.println("Le maximum est " + Max.maximum(entre.qtNmbr, entre.tab));
          System.out.println("La minimum est " + Min.minimum(entre.qtNmbr, entre.tab));
        
        
        

             

        
        
       
      
       
       
       
       
       
        
        
        
        
        
        
    }
    
    
    
    
}
