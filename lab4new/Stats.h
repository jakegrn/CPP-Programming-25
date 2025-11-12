// Creating new Stats.h header

// If STATS_H is not defined, define it (has to have endif)
#ifndef STATS_H

// Define STATS_H to prevent multiple inclusions
#define STATS_H

// No () needed since not a function lol
class Stats
{
public:
    static double average(const int a[], int count);
    static int largest(const int a[], int count);
    static int sum(const int a[], int count);
};

#endif