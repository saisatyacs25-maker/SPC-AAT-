#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to scramble a word
void scrambleWord(char word[])
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}

// Function to check if a word index is already used
int isUsed(int used[], int usedCount, int index)
{
    for (int i = 0; i < usedCount; i++)
    {
        if (used[i] == index)
            return 1;
    }
    return 0;
}

int main()
{
    char words[][15] =
    {
        "ARRAY", "POINTER", "FUNCTION",
        "VARIABLE", "COMPILER", "STRUCTURE"
    };

    int totalWords = 6;
    int rounds = 5;
    int score;
    char guess[20];
    char choice;

    // Seed random number generator
    srand(time(NULL));

    do
    {
        score = 0;

        int used[10];
        int usedCount = 0;

        printf("=====================================\n");
        printf("        WORD SCRAMBLE GAME\n");
        printf("=====================================\n");
        printf("Unscramble the words\n");
        printf("Rounds : %d\n", rounds);
        printf("=====================================\n");

        for (int i = 0; i < rounds; i++)
        {
            int index;

            do
            {
                index = rand() % totalWords;
            }
            while (isUsed(used, usedCount, index));

            used[usedCount] = index;
            usedCount++;

            char scrambled[15];
            strcpy(scrambled, words[index]);
            scrambleWord(scrambled);

            printf("\n---------- ROUND %d ----------\n", i + 1);
            printf("Scrambled Word : %s\n", scrambled);
            printf("Your Answer    : ");
            scanf("%s", guess);

            if (strcmp(guess, words[index]) == 0)
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Wrong! Correct word: %s\n", words[index]);
            }
        }

        printf("\n=====================================\n");
        printf(" GAME OVER\n");
        printf(" Final Score : %d / %d\n", score, rounds);
        printf("=====================================\n");

        printf("Play again? (Y/N): ");
        scanf(" %c", &choice);

    }
    while (choice == 'Y' || choice == 'y');

    printf("\nThank you for playing!\n");
    return 0;
}
