#include <stdio.h>

int checkspell(char * chr, int spell);

int main(void)
{
	char str[100];
	
	gets(str);
	for (int i = 'a'; i <= 'z'; i++)
	{
		printf("%d ", checkspell(str, i));
	}
	return 0;
}

int checkspell(char * chr, int spell)
{
	int result = -1;

	for (int i = 0; *(chr + i) != '\0'; i++)
	{
		if (*(chr + i) == spell)
		{
			result = i;
			break;
		}
	}

	return result;	
}