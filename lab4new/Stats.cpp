#include "Stats.h"

int Stats::largest(const int a[], int count)
{
    int biggest = 0;
    for (int i = 0; i < count; i++)
    {
        if (a[i] > biggest)
        {
            biggest = a[i];
        }
    }
    return biggest;
}

int Stats::sum(const int a[], int count)
{
    int sumTotal = 0;
    for (int i = 0; i < count; i++)
    {
        sumTotal += a[i];
    }
    return sumTotal;
}

double Stats::average(const int a[], int count)
{
    int total = Stats::sum(a, count);
    return (total / count);
}
