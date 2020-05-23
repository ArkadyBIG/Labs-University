#include "ListToSort.h"
#include <algorithm>
#include <iostream>

#define ll long long 
ListToSort::ListToSort(unsigned int  number_of_elements,int rand_seed)
    :number_of_elements(number_of_elements)
{
    srand(rand_seed);
    this->list = new Vector3f[number_of_elements];
}
ListToSort::~ListToSort()
{
    delete[] this->list;
}

void ListToSort::print()
{
    for (ll i = 0; i < number_of_elements; ++i)
        std::cout << list[i].lenght_sqr << ' ';
    std::cout << "\n\n\n";
}
bool ListToSort::is_sorted()
{
    for (ll i = 1; i < number_of_elements; ++i)
    {
        if (list[i].lenght_sqr < list[i - 1].lenght_sqr)
        {
            return false;
        }
    }
    return true;
}

ll ListToSort::find_index_of_smallest(Vector3f* list, ll from, size_t number_of_elements)
{
    ll index = from;
    float lenght_to_compare = list[from].lenght_sqr;
    for (ll i = from + 1; i < number_of_elements ; i++)
    {
        if (list[i] < list[index])
        {
            index = i;
        }
    }
    return index;
}
void ListToSort::selection_sort(Vector3f* list, int from, int to)
{
    for (ll i = from; i < to - 1; i++)
    {
        ll index_of_smallest = find_index_of_smallest(list, i, to);
        if (index_of_smallest != i)
        {
            Vector3f temp = list[index_of_smallest];
            list[index_of_smallest] = list[i];
            list[i] = temp;
        }
    }
}
void ListToSort::SelectionSort()
{
    selection_sort(list, 0, number_of_elements);
}

void ListToSort::BiltInSort()
{
    std::sort(list, list + number_of_elements);
}

ll ListToSort::LomutoPartition(Vector3f* list, ll from, ll to)
{
    Vector3f pivot = list[to];
    ll i = from;
    for (ll j = from; j < to; ++j)
    {
        if (list[j] < pivot)
        {
            std::swap(list[i], list[j]);
            i++;
        }
    }
    std::swap(list[i], list[to]);
    return i;
}
void ListToSort::quicksort(Vector3f* list, ll from, ll to)
{
    if (from < to)
    {
        ll pivot = LomutoPartition(list, from, to);
        if(pivot)
            quicksort(list, from, pivot - 1);
        quicksort(list, pivot + 1, to);
    }
}
void ListToSort::QuickSort()
{
    quicksort(list, 0, number_of_elements -1);
}

void ListToSort::combined_algirithm(unsigned threshold, Vector3f* list, ll from, ll to)
{
    if (from < to)
    {
        ll pivot = LomutoPartition(list, from, to);
        if (pivot - 1 - from > threshold)
            if(pivot - from - 1 < pivot)
                combined_algirithm(threshold, list, from, pivot - 1);
        else
            selection_sort(list, from, pivot);
        if (to - pivot - 1 > threshold)
            combined_algirithm(threshold, list, pivot + 1, to);
        else
            selection_sort(list, pivot + 1, to + 1);
    }
}
void ListToSort::CombinedAlgorithm(unsigned threshold)
{
    combined_algirithm(threshold, list, 0, number_of_elements - 1);
}

 
