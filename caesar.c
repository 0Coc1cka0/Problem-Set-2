#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void)
{
    int key;
    char text[MAX_LENGTH];

    do
    {
        printf("Key: ");
        scanf("%d", &key);
    }
    while (key < 0);


    while (getchar() != '\n')
        ;

    printf("Text: ");
    fgets(text, MAX_LENGTH, stdin);

    printf("Ciphertext: ");

    for (int i = 0; text[i] != '\0' && text[i] != '\n'; i++)
    {
        char c = text[i];

        if (isupper((unsigned char) c))
        {
            int position = c - 'A';
            int new_position = (position + key) % 26;
            printf("%c", new_position + 'A');
        }
        else if (islower((unsigned char) c))
        {
            int position = c - 'a';
            int new_position = (position + key) % 26;
            printf("%c", new_position + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");

    return 0;
}

