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
    for (int i = 0; i < size; i++) {
        inversions[i] = 0;
        for (int j = i + 1; j < size; ++j) {
            if (numbers[i] > numbers[j]) {
                inversions[i] += 1;
            }
        }
    }
    int inversions_total = 0;
    for (int i = 0; i < size; i++) {
        inversions_total += inversions[i];
    }
    return inversions_total;
}

// =====================
// Exercise 3 - MemSwap
// ---------------------
void memswap(char *mem1, char *mem2, int size) {
    // TODO
    char temp;
    for (int i = 0; i < size; ++i) {
        temp = *(mem1+i);
        *(mem1+i) = *(mem2+i);
        *(mem2+i) = temp;
    }
}

// =====================
// Tools - please ignore
// ---------------------
void printIntArray(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%i", *(array+i));
    }
    printf("\n");
}
void printCharArray(char *array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%c", *(array+i));
    }
    printf("\n");
}

/*
 Test your C knowledge in the main function, but leave the very last lines of code unchanged. 
 */
int main(int argc, char *const argv[]) {
    // TODO Call your functions and experiment with C

    // =====================
    // Exercise 1
    // ---------------------
    int n = 500;
    printf("n = %i\n", n);    // read some int n from the console
    // scanf("%i", &n);
    // or simply set a variable
    // create an dynamic array with the help of malloc (also free up the memory after usage again)
    int *sieve = (int *) malloc(sizeof(int) * (n + 1));
    //int sieve[n+1];    // or some static array
    eratosthenes(n, sieve);    // call function eratosthenes...
    int counter = 0;
    for (int i = 0; i < n; ++i) {   // print all prime numbers up to n - 1
        if (*(sieve + i) == 1) {
            printf("%i ", i);
            counter++;
            if (counter % 10 == 0) {
                printf("\n");
            }
        }
    }
    free(sieve);
    printf("\n=============");

    // =====================
    // Exercise 2
    // ---------------------
    // Define two arrays of equal size n
    //printf("\nenter size:");
    int size = 7;
    //scanf("%i", &size);
    int *numbers = (int *) malloc(sizeof(int) * size);
    int *inversions = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {      // Initialize one array with random ints
        *(numbers+i) = rand() % 10;
    }
    //printf("random numbers in array:\n");
    /*
    for (int i = 0; i < size; i++) {
        scanf("%i", &numbers[i]);
    }
     */
    // call inversionCount and pass the parameters
    // print all inversions and the total
    printf("\n%i inversions.\n", inversionCount(size, numbers, inversions));
    printIntArray(numbers, size);
    printIntArray(inversions, size);
    free(numbers);
    free(inversions);
    printf("=============");

    // =====================
    // Exercise 3
    // ---------------------
    size = 8;
    char *array1 = (char *)malloc(sizeof(char) * size);    // Define two arrays of equal size n
    char *array2 = (char *)malloc(sizeof(char) * size);    // The type can be any simple type

    for (int i = 0; i < size; ++i) {    // fill array1
        *(array1+i) = 'a' + i;
    }
    for (int i = 0; i < size; ++i) {    // fill array2
        *(array2+i) = 'A' + i;
    }
    printf("\nBefore:");    // Print the two arrays before memswap
    printf("\nArray1: ");
    printCharArray(array1, size);
    printf("Array2: ");
    printCharArray(array2, size);

    memswap(array1, array2, size);  // Call memswap

    printf("After:");    // Print the two arrays after memswap
    printf("\nArray1: ");
    printCharArray(array1, size);
    printf("Array2: ");
    printCharArray(array2, size);

    // DO NOT CHANGE CODE AFTER THIS LINE
    // This is where automatic testing starts, when the define macro constant is set to 1.
    // For local development you can set the constant to 0 until you finished your implementation.
    // Don't just program against the test cases. Also "play" with your source code and experiment with C.
    if (TEST) {
        return runCatchTests(argc, argv);
    }
    return 0;
}






