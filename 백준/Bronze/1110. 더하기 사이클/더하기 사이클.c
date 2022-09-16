#include <stdio.h>


int main(void) {
	int number, random;//number=입력받을 수, random=계속 바뀔 수
	int time = 1;
	scanf("%d", &number);
	random = (number / 10 + number % 10) % 10 + (number % 10) * 10;
	while (1)//random이 number와 일치할때까지 무한반복
	{

		if (random == number) {
			printf("%d\n", time);
			break;
		}
		else
		{
			random = (random / 10 + random % 10) % 10 + (random % 10) * 10;
			time += 1;

		}


	}

}