/* 
 * Rewrite the routines day_of_year and month_day with pointers instead of indexing.
 *
 * Author  : Aditya Nathwani
 * Created : 15 March, 2025
 */
#include <stdio.h>

void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main() 
{
	int month, day;


	printf("Day of year: %d\n", day_of_year(2024, 3, 14));

	month_day(2024, 74, &month, &day);
	printf("Month: %d, Day: %d\n", month, day);
	return 0;
}

int day_of_year(int year, int month, int day) 
{
	static int daytab[2][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  
	};

	int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int *p = daytab[leap];

	while (--month)  // Decrement month until 0
		day += *p++; // Add days of previous months

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) 
{
	static int daytab[2][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int *p = daytab[leap]; // Pointer to the correct row for leap/non-leap year

	int month = 1;
	while (yearday > *p) {
		yearday -= *p++; // Subtract days of each month
		month++;
	}

	*pmonth = month;
	*pday = yearday;
}

