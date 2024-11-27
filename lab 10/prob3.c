#include <stdio.h>

#define Max_Temp 40

int checkTemperature(float temp)
{
    static int count = 0;
    if (temp > Max_Temp)
    {
        count++;
    }
    return count;
}

int main()
{
    float temp[100];
    int n, i, c;

    printf("Enter the number of temperatures you want to add:\n");
    scanf("%d", &n);

    printf("Enter temperatures:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &temp[i]);
    }

    c = 0;
    for (i = 0; i < n; i++)
    {
        c = checkTemperature(temp[i]);
    }

    printf("%d times the temperature exceeded the limit of %d degrees Celsius\n", c, Max_Temp);

    return 0;
}
