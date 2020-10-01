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
public class init {
    
    
        public int[] tab = null;
        public int qtNmbr;
        Scanner sc = null;
        
        public void initial()
        {
            
            System.out.println("Entrer le nombre");
        
        
       try
       {
           sc = new Scanner(System.in);
           
           qtNmbr= sc.nextInt();
           
           if(qtNmbr==0||qtNmbr<0)
           {
               System.out.println("Continuer de jouer aux imbeciles!!! Au revoir");
               System.exit(0);
           }
           tab = new int[qtNmbr];
           
           
           
           
           System.out.println(qtNmbr);
           for(int i=0; i<qtNmbr; i++)
           {
               System.out.println("Entrer le nombre #"+(i+1));
               tab[i]=sc.nextInt();
              // System.out.println(i);
               
               
           }
        
       } catch(Exception e)
       {
           System.out.println("Erreur ");
           sc.close();
             
       }
       
      
            
        }
        public int getValueNombre()
      {
          return qtNmbr;
      }
        
        public int[] getValueTab()
      {
          return tab;
      }
        
        
    
}
