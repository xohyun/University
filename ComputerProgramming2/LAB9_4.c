#include <stdio.h>
#include <string.h>
int main(void)
{
	char fullName[50];
	char lastName[50] = "Suehee";
	char firstName[50] = "Pak";

	char id[15] = "630826-2020222"; // 14 ���� ���� + '\0'
	char idFront[7];

	// fullName �� ���� ��, �� �׸��� �̸��� �ִ´�.
	strcat(firstName, ", ");
	strcat(firstName, lastName);
	strcpy(fullName, firstName);

	printf("����� fullname �� %s\n", fullName);
	// idFront �� �ֹε�� ��ȣ�� �� 6 �ڸ��� �ִ´�.
	strncpy(idFront, id, 6);
	idFront[6] = '\0';

	printf("�ֹε�Ϲ�ȣ ���ڸ��� %s\n", idFront);
}