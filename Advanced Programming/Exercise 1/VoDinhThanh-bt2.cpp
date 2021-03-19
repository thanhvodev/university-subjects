#include <iostream>
using namespace std;

void printNumberDiv3a5(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void sumOfDivBy3or5(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        if ((i % 5 == 0) || (i % 3 == 0))
        {
            sum += i;
        }
    }
    cout << sum << endl;
}

void printCount(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if ((i % 5 != 0) || (i % 3 != 0))
        {
            count += 1;
        }
    }
    cout << count << endl;
}

int main()
{
    int limit;
    cout << "Input the limit: ";
    cin >> limit;
    if (limit < 10 || limit > 150)
    {
        cout << "Out of range";
        exit(1);
    }
    cout << "Numbers are divisible by both 3 and 5: ";
    printNumberDiv3a5(limit);
    cout << "Sum of numbes being divisible by either 3 or 5: ";
    sumOfDivBy3or5(limit);
    cout << "Count of numbers not being divisible by 3 or 5: ";
    printCount(limit);
    return 0;
}