#include <stdio.h>
#include <conio.h>
int main(void)
{
	char ch;
	while(1)
	{
		//scanf("%c", &ch); // �� 1)
		//ch = getchar(); // �� 2)
		//ch = fgetc(stdin); // �� 3)
		ch = getch(); // �� 4)
		//ch = getche(); // �� 5)
		if( ch == 'q' ) break;
		putch(ch); // printf("%c", ch), putchar(ch), fputc(ch, stdout)�� ��� ���� ���
	}
}