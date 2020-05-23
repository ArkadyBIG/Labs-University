#pragma once

#include <random>
#define ll long long


using std::size_t;

struct Vector3f
{
    float _x;
    float _y;
    float _z;
    float lenght_sqr;
    bool operator<(const Vector3f& a)
    {
        if (this->lenght_sqr < a.lenght_sqr)
            return true;
        return false;
    }
    //random float from 0 to 10
    float _randomize()
    {
        return (float)(rand() % 1001) / 100.f;
    }
    Vector3f()
    {
        _x = _randomize();
        _y = _randomize();
        _z = _randomize();
        lenght_sqr = _lenght_squeared();
    }
    float _lenght_squeared()
    {
        return _x * _x + _y * _y + _z * _z;
    }
};


class ListToSort
{
private:
    Vector3f* list;
    size_t number_of_elements;

public:
    ListToSort(unsigned int, int rand_seed = 0);
    ~ListToSort();

    void print();
    bool is_sorted();

    void SelectionSort();
    void BiltInSort();
    void QuickSort();
    void CombinedAlgorithm(unsigned);
private:

    ll find_index_of_smallest(Vector3f* list, ll from, size_t number_of_elements);
    void selection_sort(Vector3f* list, int from, int to);
    ll LomutoPartition(Vector3f* list, ll from, ll to);
    void quicksort(Vector3f* list, ll from, ll to);
    void combined_algirithm(unsigned threshold, Vector3f* list, ll from, ll to);
};


