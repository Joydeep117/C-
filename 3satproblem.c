#include <stdio.h>
#include <math.h>

#define VARS 3       // Number of variables
#define CLAUSES 2    // Number of clauses

// Function to evaluate the 3-SAT formula
int evaluate(int assignment[]) {

    // Example formula:
    // (x1 OR !x2 OR x3) AND (!x1 OR x2 OR x3)

    int c1 = assignment[0] || !assignment[1] || assignment[2];
    int c2 = !assignment[0] || assignment[1] || assignment[2];

    return c1 && c2;
}

int main() {
    int assignment[VARS];

    // Try all possible assignments
    for (int i = 0; i < (1 << VARS); i++) {
        for (int j = 0; j < VARS; j++) {
            assignment[j] = (i >> j) & 1;
        }

        if (evaluate(assignment)) {
            printf("Satisfying assignment found:\n");
            for (int k = 0; k < VARS; k++) {
                printf("x%d = %d  ", k + 1, assignment[k]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("No satisfying assignment exists.\n");
    return 0;
}
