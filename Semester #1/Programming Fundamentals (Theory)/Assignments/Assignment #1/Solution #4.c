#include <stdio.h>
#include <math.h>

float squareroot(float num);
float division(float added);
float addition(float a, float b);
float result(float final);

int main()
{
    float a, b;
    printf("Enter the values of a and b: ");
    scanf("%f %f", &a, &b);

    float final = result(squareroot(division(addition(a, b))));

    return 0;
}

float squareroot(float num)
{
    return sqrt(num);
}

float division(float added)
{
    float divided = added / 2;
    return divided;
}

float addition(float a, float b)
{
    float added = a + b;
    return added;
}

float result(float final)
{
    printf("The solution is: %f\n", final);
    return final;
}

