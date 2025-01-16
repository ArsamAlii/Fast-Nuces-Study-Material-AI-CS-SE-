#include<stdio.h>

int input_number();
int is_palindrome(int num);

int main()
{	
	int num = input_number();
	
	return 0;
	}

int input_number()
{
	int num;
	printf("Enter a 3 digit number");
	scanf("%d",& num);
	
	is_palindrome(num);
	
	return num;
	}

int is_palindrome(int num)
{
	int first_digit = num/100;
	int last_digit = num%10;
	
	if(first_digit == last_digit){
	printf("It is palindrome");
	}
	
	else {
		printf("It is not a palindrome");
	}
		
	}
