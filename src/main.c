/* File: src/main.c */
#include "../include/dice_roll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Main entry point for the dice application.
 */
int main(void) {
    printf("Dice Application Started.\n");

    /* Initialize entropy */
    DR_Init();

    char input[100];
    while (1) {
        printf("Enter dice notation (e.g., 3d6) or 'q' to quit: ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0 || strcmp(input, "quit") == 0) {
            printf("Exiting application.\n");
            break;
        }

        char *d_pos = strchr(input, 'd');
        if (d_pos == NULL) {
            fprintf(stderr, "Invalid format. Use n(d)n.\n");
            continue;
        }

        *d_pos = '\0';
        int num_dice = atoi(input);
        int sides = atoi(d_pos + 1);

        if (num_dice <= 0 || sides <= 0) {
            fprintf(stderr, "Invalid numbers provided.\n");
            continue;
        }

        /* Standard allocation */
        int* results = (int*)calloc(num_dice, sizeof(int));
        if (results == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        int sum = DR_RollDice(num_dice, sides, results);

        if (sum != -1) {
            printf("Results: ");
            for (int i = 0; i < num_dice; i++) {
                printf("%d ", results[i]);
            }
            printf("| Sum: %d\n\n", sum);
        }

        free(results);
    }

    return 0;
}

