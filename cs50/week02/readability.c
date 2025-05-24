#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void cntWord(string text);
int gradeIdentifier(void);

// array's first element is count of words, second one count of sentences, third the count of
// letters

int cnt[] = {1, 0, 0};

int main(void)
{
    string text = get_string("Text: ");

    cntWord(text);

    int grade = gradeIdentifier();

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    // printf("%i - words, %i - sentences, %i - letters\n", cnt[0], cnt[1], cnt[2]); // debugging
}

void cntWord(string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            cnt[0]++;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?') )
        {
            cnt[1]++;
        }
        else if (isalpha(text[i]))
        {
            cnt[2]++;
        }
    }
}

int gradeIdentifier(void)
{
    float index;
    // trying to be precise as possible.
    float l = (100 * cnt[2])/ ((float) cnt[0]);
    float s;
    if (cnt[1] == 0)
    {
        s = 0;
    }
    else
    {
        s = (100 * cnt[1]) / ((float) cnt[0]);
    }

    index = 0.0588 * l - 0.296 * s - 15.8;
    index = (int) round(index);
    return index;
}

