#include <stdio.h>
#include <stdlib.h>
void intro();
void computeCollatz(unsigned long n);
// Header declaration for class-wide variables
unsigned int counter = 0;

int main(int argc, char** argv)
{
    //Initialization
    intro();

    unsigned long number;
    if (sscanf(argv[1],"%ld", &number) != 0)   // conversion de la valeur envoyee par le parent de caractere a entier, !=0 means scanf is sucessful
    {
        printf("Le nombre a analyser est: %ld\n", number);
    }

    // Begin computation
    printf("Commnecons a executer...\n");
    computeCollatz(number);
    return 0;
}

// intro function
void intro()
{
    printf("Demonstration de la conjecture de Collatz\n\n");
}

// primary computation algorithm
void computeCollatz(unsigned long n)
{
    unsigned long r; // Initialize r (result)
    // Odd/Even checking
    if (n%2==0)   //Even
    {
        r = n/2;
    }
    else     //Odd
    {
        r = (3*n)+1;
    }
    printf("%lu\n", r);
    counter++; //Adding to counter
    // Recursive checking
    if (r<=1)   // "just in case" boundary checking for code safety
    {
        printf("The number reached 1, counter=%i\n", counter);
    }
    else
    {
        computeCollatz(r); // Recursion!
    }
}
