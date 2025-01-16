#include <stdio.h>

int div_pizza(int n);
int div_drinks(int n);
float div_amount(float n);

int main() {
    int n;
    printf("Enter the number of guests: ");
    scanf("%d", &n); 
	
    if (n>15){
    	printf("only 15 guests allowed max");
    	return 0;
	}
	
	if (n < 0) {
        printf("Pizza for one person: -1\n");
        printf("Drink for one person: -1\n");
        printf("Amount for one person: -1\n");
}
  
	else{	
	int p_one = div_pizza(n);
    int d_one = div_drinks(n);
    float d_amount = div_amount(n);

    printf("Pizza for one person: %d\n", p_one);
    printf("Drink for one person: %d\n", d_one);
    printf("Amount for one person: %.1f\n", d_amount);
	}

  
    return 0;
}


int div_pizza(int n) {
    int piece_one = 24 / (n+1);
    return piece_one;
}

int div_drinks(int n) {
    int drink_one = 15 / (n+1);
    return drink_one;
}

float div_amount(float n) {
    float rem_amount = (5000.0 * 50.0) / (100.0 * n);
    return rem_amount;
}


