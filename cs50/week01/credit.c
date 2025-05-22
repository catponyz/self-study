#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool verify(long x);
int first2Digits(long n);
int numofDigits(long n);

int main(void)
{
    long cardNumber = get_long("What's your card number? ");

    int first2 = first2Digits(cardNumber);
    int numOfDigits = numofDigits(cardNumber);
    bool isValid = verify(cardNumber);

    if (((numOfDigits == 15) && ((first2 == 34) || (first2 == 37))) && isValid)
    {
        printf("AMEX\n");
    }
    else if (((numOfDigits == 16) && ((first2 >= 51) && (first2 <= 55))) && isValid)
    {
        printf("MASTERCARD\n");
    }
    else if ((((numOfDigits == 13) || (numOfDigits == 16)) && (first2 / 10 == 4)) && isValid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int first2Digits(long n)
{
    while (n > 99)
    {
        n /= 10;
    }
    return n;
}

int numofDigits(long n)
{
    int s = 0;
    while (n > 0)
    {
        s++;
        n /= 10;
    }
    return s;
}

bool verify(long x)
{
    int s = 0;
    while (x > 0)
    {
        int k = x % 10;
        x /= 10;
        s += k;

        int l = (x % 10) * 2;
        x /= 10;
        if (l / 10 == 0)
        {
            s += l;
        }
        else
        {
            s = s + (l % 10) + 1;
        }
    }

    if (s % 10 == 0)
    {
        return true;
    }
    return false;
}
