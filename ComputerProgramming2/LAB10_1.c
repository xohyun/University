struct customer {
	char name[40];
	int age;
};

#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;

	struct customer aCustomer = {"�ڼ���", 36};
	struct customer cArray[2] = {{"�嵿��", 38}, {"��ҿ�", 38}};
	struct customer * cp;
	cp = &aCustomer;
	printf("��)\n");
	printf("Name = %s, Age = %d\n", cp -> name, cp -> age);
	
	cp = cArray;
	printf("��)\n");	
	for (i = 0; i < 2; i++)
	{
		printf("Name = %s, Age = %d\n", cp->name, cp->age);
		cp++;
	}

}
