#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CheckBingo(int * arr);

int main(void)
{
	int i, num[9], result[9] = { 0, };
	
	printf("9���� ���� �Է��� �������� ä�켼��\n");
	
	for (i = 0; i < 9; i++)
		scanf("%d", num + i);
	
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	printf("���� ���߱� ���� ���� �Է��ϼ���\n");
	
	int input, cnt = 1;

	while (1)
	{
		scanf("%d", &input);

		for (i = 0; i < 9; i++)
		{
			if (num[i] == input)
			{
				result[i] = 1;
				break;
			}
		}

		if (cnt >= 5)
		{
			if (CheckBingo(result) == 2)
			{
				printf("����!");
				break;
			}
		}

		cnt++;
	}


	return 0;
}

int CheckBingo(int * r)
{
	int i, result = 0, rslt[8] = { 0, };

	if (r[0] && r[1] && r[2])
		rslt[0] = 1;

	if (r[3] && r[4] && r[5])
		rslt[1] = 1;

	if (r[6] && r[7] && r[8])
		rslt[2] = 1;

	if (r[0] && r[3] && r[6])
		rslt[3] = 1;

	if (r[1] && r[4] && r[7])
		rslt[4] = 1;

	if (r[2] && r[5] && r[8])
		rslt[5] = 1;

	if (r[0] && r[4] && r[8])
		rslt[6] = 1;

	if (r[2] && r[4] && r[6])
		rslt[7] = 1;

	for (i = 0; i < 8; i++)
	{
		if (rslt[i] == 1)
			result++;
	}

	return result;
}
