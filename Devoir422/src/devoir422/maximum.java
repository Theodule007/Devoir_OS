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
public class maximum extends Thread {
    
    
    int nombre;
    int[] tab;
    int max;
    
    public int maximum(int nombre, int[] tab)
    {
        
        this.nombre=nombre;
        this.tab=tab;
        
        return max;
    }
    
    public void run()
    {
        
        System.out.println("Thread maxim start");
        try
        {
            max= tab[0];
        
        for(int i=1;i<nombre;i++)
		{
			if(max<tab[i])
			{
			max=tab[i];
			}
		}
            
        }
        catch (Exception e)
        {
            System.out.println("Erreur");
            
        }
         
    }
    
}
