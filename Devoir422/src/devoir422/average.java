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
public class average extends Thread {
    
    float average;
    int nombre;
    int tab[];
    public float average(int nombre, int tab[])
    {

        this.nombre=nombre;
        this.tab=tab;
        return average;
    }
    
    public void run()
    {
        int sum=0;
        System.out.println("Thread Average Start");

	for(int i=0;i<nombre;i++)
		{
			sum=sum+tab[i];
		}
	try
        {
            average= sum/nombre;
        }
        catch(Exception e)
        {
            System.out.println("Erreur");
        }
    }
    
}
