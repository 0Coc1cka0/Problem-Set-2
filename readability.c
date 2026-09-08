#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];

    printf("Text: ");
    fgets(text, MAX_LENGTH, stdin);

    int letters = 0, words = 0, sentences = 0;

    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++)
    {
        char c = text[i];

        if (isalpha((unsigned char) c))
        {
            letters++;
        }

        if (c == ' ')
        {
            words++;
        }

        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    
    words++;

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int) (index + 0.5); 

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

