#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void scan_word(int occurrences[26]);
bool is_anagram(int occurrences1[26], int occurrences2[26]);
int i, same = 1, *ptr1, *ptr2,
    letters1[26] = {0},
    letters2[26] = {0};
char c;
int main(void)
{
    ptr1 = letters1;
    ptr2 = letters2;
    printf("Enter first word: ");
    scan_word(ptr1);

    printf("Enter second word: ");
    scan_word(ptr2);
    if (is_anagram(ptr1, ptr2)) {
        printf("The words are anagrams. \n");
        return 0;
    }
    printf("The words are not anagrams. \n");
    return 0;
}

void scan_word(int *occurrences)
{
    while ((c = getchar()) != '\n') 
    {
        if (isalpha(c))
        {
            occurrences[toupper(c) - 'A']++;
        }
    }
}

bool is_anagram(int *occurrences1, int *occurrences2)
{
    for (i = 0; i < 26; i++) 
    {
        if (occurrences1[i] != occurrences2[i])
        {
            return false;
        }
    }
    return true;
}