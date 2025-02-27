/* required header files */
#include <stdio.h>
#include <stdint.h>

/* decleration of structure */
struct tcp_header
{
	uint16_t chksum;
	uint16_t window;
	uint16_t source;
	uint16_t destination;
};

/* start of main */
uint32_t main()
{
	/*struct tcp_header s1 = {43,65,45,76};
	printf("ckhsum : %d\nwindow : %d\nsource : %d\ndestination : %d\n",s1.chksum,s1.window,s1.source,s1.destination);
*/
	printf("Enter the fields accordingly..\n");
	uint16_t a,b,c,d;
	scanf("%hx %hx %hx %hx",&a,&b,&c,&d);
	struct tcp_header s1 = {a,b,c,d};
	printf("ckhsum : %d\nwindow : %d\nsource : %d\ndestination : %d\n",s1.chksum,s1.window,s1.source,s1.destination);
	return 0;
}
