#include <stdio.h>
#include <string.h>

int main()
{
	char inp[100][100];
	int n, i, j, len;
	int reg = 1;
	printf("Enter the no of statements: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", &inp[i]);
	for (i = 0; i < n; i++)
	{
		len = strlen(inp[i]);
		for (j = 2; j < len; j++)
		{
			if (inp[i][j] >= 97 && inp[i][j] <= 122)
			{
				printf("LOAD R%d %c \n", reg++, inp[i][j]);
			}

			if (j == len - 1 && inp[i][len - j] == '=')
			{
				j = 3;
				if (inp[i][j] == '+')
				{
					printf("ADD R%d R%d\n", reg - 2, reg - 1);
					printf("STORE %c R%d\n", inp[i][0], reg - 2);
				}
				else if (inp[i][j] == '-')
				{
					printf("SUB R%d R%d\n", reg - 2, reg - 1);
					printf("STORE %c R%d\n", inp[i][0], reg - 2);
				}
				else if (inp[i][j] == '*')
				{
					printf("MUL R%d R%d\n", reg - 2, reg - 1);
					printf("STORE %c R%d\n", inp[i][0], reg - 2);
				}
				else if (inp[i][j] == '/')
				{
					printf("DIV R%d R%d\n", reg - 2, reg - 1);
					printf("STORE %c R%d\n", inp[i][0], reg - 2);
				}

				break;
			}
		}
	}

	return 0;
}