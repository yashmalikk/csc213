#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
  // Make sure the user provided an N parameter on the command line
  if(argc != 2){
    fprintf(stderr, "Usage: %s N (N must be >=1)\n", argv[0]);
    exit(1);
  }

  // Convert the N parameter to an integer
  int N = atoi(argv[1]);

  // Make sure N is >= 1
  if (N < 1){
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }
  
  // TODO: read from standard input and print out ngrams until you reach the end of the input
  // Allocate memory for the n-gram array
  char *ngram = (char *)malloc(N * sizeof(char));
    if (ngram == NULL) {
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
  }
  // Read the first N characters to form the first n-gram
  int i;
  for (i = 0; i < N; i++) {
    char ch = getchar();
    if (ch == '\n' || ch == EOF) {
      exit(0);  // End the program if the input ends early
    }
    ngram[i] = ch;
  }

  // Print the first n-gram
  for (i = 0; i < N; i++) {
    printf("%c", ngram[i]);
  }
  printf("\n");

  // Continue reading input one character at a time and form new n-grams
  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
  // Shift the n-gram left by one position
    for (i = 0; i < N - 1; i++) {
      ngram[i] = ngram[i + 1];
    }
    ngram[N - 1] = ch;  // Add the new character to the end of the n-gram

    // Print the updated n-gram
    for (i = 0; i < N; i++) {
      printf("%c", ngram[i]);
    }

    printf("\n");
  }

  // Free the allocated memory
  free(ngram);
  return 0;
} 