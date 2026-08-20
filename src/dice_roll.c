/* File: src/dice_roll.c */
#include "../include/dice_roll.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/random.h>
#include <time.h>

#define drD_MIN_SIDES 1
#define drD_MAX_SIDES 255

/* Internal state for Xorshift64 */
static uint64_t dg_state = 0;

void DR_Init(void) {
    if (getrandom(&dg_state, sizeof(dg_state), 0) != sizeof(dg_state)) {
        fprintf(stderr, "Warning: getrandom failed; falling back to time(NULL)\n");
        dg_state = (uint64_t)time(NULL);
    }
    
    /* Xorshift requirement: state must not be zero */
    if (dg_state == 0) {
        dg_state = 0xACE1;
    }
}

/**
 * @brief Internal Xorshift64 implementation.
 */
static uint64_t DR_Xorshift64(void) {
    uint64_t x = dg_state;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    dg_state = x;
    return dg_state;
}

int DR_RollDice(int num_dice, int sides, int* results) {
    /* Standard validation */
    if (sides < drD_MIN_SIDES || sides > drD_MAX_SIDES) {
        fprintf(stderr, "Error: sides out of valid range\n");
        return -1;
    }
    if (num_dice <= 0) {
        fprintf(stderr, "Error: Number of dice must be positive\n");
        return -1;
    }
    if (results == NULL) {
        fprintf(stderr, "Error: results pointer is NULL\n");
        return -1;
    }

    int sum = 0;
    /* Rejection threshold to eliminate modulo bias */
    uint64_t limit = UINT64_MAX - (UINT64_MAX % (uint64_t)sides);

    for (int i = 0; i < num_dice; i++) {
        uint64_t val;
        /* Spin until we get a value within the fair range */
        while ((val = DR_Xorshift64()) >= limit);

        int roll = (int)(val % (uint64_t)sides) + 1;
        results[i] = roll;
        sum += roll;
    }

    return sum;
}

