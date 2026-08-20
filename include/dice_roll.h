#ifndef DICE_ROLL_H
#define DICE_ROLL_H

/**
 * @brief Initializes the internal pseudo-random number generator.
 * 
 * Uses kernel entropy via getrandom() to seed the Xorshift64+ state.
 */
void DR_Init(void);

/**
 * @brief Rolls a specified number of dice with sides.
 * 
 * Employs rejection sampling to eliminate modulo bias, ensuring perfect fairness.
 * 
 * @param num_dice Number of dice to roll.
 * @param sides Number of sides per die.
 * @param results Pointer to an array where individual roll results will be stored.
 * @return The sum of all rolled dice, or -1 on invalid input.
 */
int DR_RollDice(int num_dice, int sides, int* results);

#endif /* DICE_ROLL_H */

