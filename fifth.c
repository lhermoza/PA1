#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char* argv[])
{
	int i;
	int j;		
	for(i = 1; i < argc; i++)
	{
		j = 0;
		while(argv[i][j] != '\0')
		{
			if(argv[i][j] == 'a'|| argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'o' || argv[i][j] == 'u' || argv[i][j] == 'A'|| 
			argv[i][j] == 'E' || argv[i][j] == 'I' || argv[i][j] == 'O' || argv[i][j] == 'U')					
			{
				printf("%c", argv[i][j]);
			}
				j++;
		}
	}
printf("\n");
return 0;
}
