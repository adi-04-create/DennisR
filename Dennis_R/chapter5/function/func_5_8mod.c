#include <stdio.h>
#include <string.h>
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday);

int main(void) 
{
	char mon[20] = {0};
	char ch;
	int i = 0;
	int day, year, month;
	printf("Enter a year  : ");
	scanf("%d",&year);
	printf("Enter a month : ");
//	scanf("%d",&month);
	while(( ch = getchar()) != '\n' )
	{
		mon[i++] = ch;
	}
	if(strcmp
	printf("Enter a day   : ");
	scanf("%d",&day);

	day = day_of_year(year, month, day);
	if (day != -1) {
		printf("Day of the year: %d\n", day);
	}

	month_day(year, day);
	month_day(year, day); // Example of invalid input

	return 0;
}

/* day_of_year: set day of year from month & day with error checking */
int day_of_year(int year, int month, int day) {
	int i, leap;

	if (month < 1 || month > 12) {
		printf("Error: Invalid month %d. It should be between 1 and 12.\n", month);
		return -1;
	}

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (day < 1 || day > daytab[leap][month]) {
		printf("Error: Invalid day %d for month %d in year %d.\n", day, month, year);
		return -1;
	}

	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}

/* month_day: set month, day from day of year with error checking */
void month_day(int year, int yearday) {
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int max_days = leap ? 366 : 365;

	if (yearday < 1 || yearday > max_days) {
		printf("Error: Invalid day of year %d. It should be between 1 and %d.\n", yearday, max_days);
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	printf("Month: %d, Day: %d\n", i, yearday);
}

