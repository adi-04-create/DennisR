#include <stdio.h>
#include <stdlib.h>

uint32_t main()
{
	printf("Enter your choice\n");
	printf("t : triangle\ns : square\nc : circle\nq : exit\n");
	char c;
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%c",&c);

		switch(c)
		{
			case 't':
				printf("Enter dimensions of Triangle.\n");
				uint32_t a,b;
				scanf("%d %d",&a,&b);
				uint32_t area = (a*b)/2;
				printf("%d\n",area);
				printf("Area of Triangle\n");
				break;
			case 'c':
				printf("Enter radius of circle : ");
				uint32_t radius;
				scanf("%d\n",&radius);
				uint32_t area1 = 3.1415*radius*radius;
				printf("Area of Circle = %d\n",area1);
				printf("\n");
				break;
			default:
				printf("Invalid INPUT.\n");
				break;
			case 'q':
				printf("Exiting...\n");
				exit(0);
		}
	}
	return 0;
}
