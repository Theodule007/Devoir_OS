
#include <stdio.h>

// H
void intro();
void computeCollatz(unsigned long n);
// Header declaration for class-wide variables
unsigned int counter = 0;

int main(int argc, char** argv) {
  //
 Initialization
  intro();
  unsigned long number;
  // New implementation
  // NOTE: This program uses arguments in order to get the number required, instead of through scaning user input
  //if (argc >1){ //check if there is more than one argument (the first argument is the initial command)
    // Further user input sanitization

        if (sscanf(argv[1], "%ld", &number) != 0) { // converting from char array to int, !=0 means sscanf is sucessful

      if (number >= 1) {
        printf("The number for analysis is: %ld\n", number);
      } else {
        printf("Please enter a valid positive integer; program terminated abnormally!\n");
        return 1;
      }
    }
 // }
  else { //catch error for lack of arguments
    printf("Please enter a valid positive integer by passing a single argument; program terminated abnormally!\n");
    return 1;
  }

  // Begin computation
  printf("Beginning output of numbers...\n");
  computeCollatz(number);

  return 0;
}

/*
  Function implementations
*/

// intro function
void intro() {
  printf("\nCollatz Conjecture Computation (C variant) v0.1\nThis is a demonstration of the Collatz Conjecture problem\n\n");
}

// primary computation algorithm
void computeCollatz(unsigned long n) {
  unsigned long r; // Initialize r (result)
  // Odd/Even checking
  if (n%2==0) { //Even
    r = n/2;
  } else { //Odd
    r = (3*n)+1;
  }
  printf("%lu\n", r);
  counter++; //Adding to counter
  // Recursive checking
  if (r<=1) { // "just in case" boundary checking for code safety
    printf("The number reached 1, counter=%i\n", counter);
  } else {
    computeCollatz(r); // Recursion!
  }
}
