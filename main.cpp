#define CATCH_CONFIG_RUNNER
#define TEST 1 // Always change to 1 before your final submission to Github Classroom.

#include "tests/catch.hpp"
#include "main.hpp"
#include <stdlib.h>

// DO NOT CHANGE THIS METHOD
int runCatchTests(int argc, char *const argv[]) {
    return Catch::Session().run(argc, argv);
}

// =====================
// Exercise 1 - "Sieb des Eratosthenes"
// ---------------------
void eratosthenes(int n, int *sieve) {   // nimmt n und pointer zum sieb-array
    //TODO
    for (int i = 0; i < n; i++) {    //array wird mit 1 gefüllt
        sieve[i] = 1;
    }
    sieve[0] = sieve[1] = 0; //0 und 1 sind keine Primzahlen -> 0
    for (int i = 2; i < n; i++) {    //für jeden index ab 2 wird deren vielfaches gebildet und dort 0 gespeichert
        if (*(sieve + i) == 1)
            for (int j = 2; j * i < n; ++j) {
                sieve[j * i] = 0;
            }
    }
}
//Lösung von Michael Strommer:
void eratosthenes2(int n, int *sieve) {
    //TODO
    for (int i = 0; i < n; i++) {
        sieve[i] = 1;
    }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i < sqrt(n); i++) {
        if (*(sieve + i) == 1)
            for (int j = pow(i,2); j < n; j+=i) {
                sieve[j] = 0;
            }
    }
}

// =====================
// Exercise 2 - InversionCount
// ---------------------
int inversionCount(int size, int *numbers, int *inversions) {
    //TODO

    return 0;
}

// =====================
// Exercise 3 - MemSwap
// ---------------------
void memswap(char *mem1, char *mem2, int size) {
    // TODO
    
}



/*
 Test your C knowledge in the main function, but leave the very last lines of code unchanged. 
 */
int main(int argc, char *const argv[]) {
    // TODO Call your functions and experiment with C

    // =====================
    // Exercise 1
    // ---------------------
   // read some int n from the console
    // scanf("%i", &n);
    // or simply set a variable
    // create an dynamic array with the help of malloc (also free up the memory after usage again)
    //int sieve[n+1];    // or some static array
    // call function eratosthenes...
    // print all prime numbers up to n - 1
       


    // =====================
    // Exercise 2
    // ---------------------
    // Define two arrays of equal size n
    // Initialize one array with random ints
    // call inversionCount and pass the parameters
    // print all inversions and the total

    // =====================
    // Exercise 3
    // ---------------------
    // Define two arrays of equal size n
    // The type can be any simple type
    // fill array1
    // fill array2
    // Print the two arrays before memswap
    // Call memswap
    // Print the two arrays after memswap
    

    // DO NOT CHANGE CODE AFTER THIS LINE
    // This is where automatic testing starts, when the define macro constant is set to 1.
    // For local development you can set the constant to 0 until you finished your implementation.
    // Don't just program against the test cases. Also "play" with your source code and experiment with C.
    if (TEST) {
        return runCatchTests(argc, argv);
    }
    return 0;
}






