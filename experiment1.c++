#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int operation = 0;
void complexRec(int n)
{
    operation++;
    if (n <= 2)
    {
        return;
    }
    int p = n;
    while (p > 0)
    {
        operation++;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            operation++;
            temp[i] = i ^ p;
        }
        p >>= 1;
    }
    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        operation++;
        small[i] = i * i;
    }
    if (n % 3 == 0)
    {
        operation++;
        reverse(small.begin(), small.end());
    }
    else
    {
        operation++;
        reverse(small.begin(), small.end());
    }
    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);
}

int main()
{
    complexRec(8);
    cout << operation;
    return 0;
}

// Recurrence Relation : T(n) = 3T(n/2) + n + nlogn
//
