/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package devoir422;

/**
 *
 * @author Michel
 */
public class minimum extends Thread{
    
    int bon;
    int nombre; 
    int[] tab;
    int min;
    
    public int minimum(int nombre, int[] tab)
    {
        this.nombre=nombre;
        this.tab=tab;
        
        return min;
    }
    
    public void run()
    {
        System.out.println("Thread Minimum start");
        //tab= new int[nombre];
       try
       {
           
            min= tab[0];
            //System.out.println(tab[0]);
        
	for(int i=1;i<nombre;i++)
		{
			if(min>tab[i])
			{
			min=tab[i];
			}
		}
           
       }
       catch(Exception e)
       {
           System.out.println("Erreur");
       }
               
       
    }
    
}
