/*
 * Corso C++ - https://github.com/egalli64/corso-cpp/a7
 *
 * Mergesort
 */
#include <iostream>

void print(int data[], int left, int right)
{
    std::cout << "[ ";
    for (size_t i = left; i <= right; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << "]\n";
}

void merge(int values[], int left, int center, int right)
{
    int sz1 = center - left + 1;
    int first[sz1];
    for (int i = 0; i < sz1; ++i)
    {
        first[i] = values[left + i];
    }

    int sz2 = right - center;
    int second[sz2];
    for (int i = 0; i < sz2; ++i)
    {
        second[i] = values[center + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < sz1 && j < sz2)
    {
        if (first[i] < second[j])
        {
            values[k] = first[i];
            i += 1;
        }
        else
        {
            values[k] = second[j];
            j += 1;
        }
        k += 1;
    }
    while (i < sz1)
    {
        values[k] = first[i];
        i += 1;
        k += 1;
    }
    while (j < sz2)
    {
        values[k] = second[j];
        j += 1;
        k += 1;
    }
}

void sort(int values[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int center = left + (right - left) / 2;
    sort(values, left, center);
    sort(values, center + 1, right);
    merge(values, left, center, right);

    std::cout << "Merging " << left << ' ' << right << ": ";
    print(values, left, right);
}

int main()
{
    int values[]{6, 1, 3, 7, 4, 5, 2, 8};
    constexpr size_t sz = sizeof(values) / sizeof(int);

    std::cout << "Working on: ";
    print(values, 0, sz - 1);

    sort(values, 0, sz - 1);

    std::cout << "Sorted: ";
    print(values, 0, sz - 1);
}