#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ASCII_OFFSET = 65;
// adding the scoresTable array additional 0 value at the last element, that will be the score of non-letter chars.
const int scoresTable[] = {1, 3, 3,  2, 1, 4, 2, 4, 1, 8, 5, 1,  3, 1,
                         1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10, 0};

int score(string givenWord);
void toUpper(string word);

int main(void)
{
    string player1Word = get_string("Player 1: ");
    string player2Word = get_string("Player 2: ");

    toUpper(player1Word);
    toUpper(player2Word);

    int player1Score = score(player1Word);
    int player2Score = score(player2Word);

    if (player1Score > player2Score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string givenWord)
{
    int score = 0;

    for (int i = 0, len = strlen(givenWord); i < len; i++)
    {
        score += scoresTable[givenWord[i] - ASCII_OFFSET];
    }
    return score;
}

void toUpper(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char letter = word[i];
        if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
        {
            // for handling case issues, changing them all to uppercase.
            word[i] = toupper(letter);
        }
        else
        {
            // handling the non-letter chars by changing them into char that comes right after 'Z' in ASCII.
            word[i] = '[';
        }
    }
}
