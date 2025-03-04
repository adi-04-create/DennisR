#include <stdio.h>
#pragma pack(1)
struct example
{
	double a;
	int b;
	char c;
	char d;
	short e;
	char f;
	double g;
};
#pragma pack(0)

int main()
{
	printf("Size of structure (●'◡'●)→ %lu\n",sizeof(struct example));
	return 0;
}
