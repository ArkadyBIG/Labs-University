#include <iostream>
#include "ListToSort.h"
#include <ctime>
#include "Lab3a.h"

//Выбранное задание со списка 1 : 11(координаты точек)
//со списка 2 : 3(SelectionSort)
//co списка 3 : 5
//co списка 4 : 2 



void DemonstrationMode();
void BenchmarkMode();
int main()
{
    std::cout << "Chose mode:   1 - Demonstration , 2 - Benchmark          0 - to exit\n>>";
    int mode;
    std::cin >> mode;
    switch (mode)
    {
        case 1:
            DemonstrationMode();
            break;
        case 2:
            BenchmarkMode();
            break;
        case 0:
            return 0;
            break;
        default:
            system("cls");
            std::cout << "Try again";   
    }
    main();
}

void DemonstrationMode()
{
    std::cout << "Choose type of sorting:  "
                    "1 - Selection Sort, 2 - Quick Sort, 3 - Bilt in Sort, 4 - Combination Sort\n>>";
    int sort_type;
    std::cin >> sort_type;
    std::cout << "Enter number of elements:\n>>";
    int number_of_elements;
    std::cin >> number_of_elements;
    std::cout << "Do you want to print this array?:  1 - yes, 2 - no\n>>";
    int user_input;
    std::cin >> user_input;       
    ListToSort List(number_of_elements);
    if (user_input == 1)
        List.print();
    unsigned start_time = clock();
    switch (sort_type)
    {
    case 1:
        List.SelectionSort();
        break;
    case 2:
        List.QuickSort();
        break;
    case 3:
        List.BiltInSort();
        break;
    case 4:
        std::cout << "Enter from wich number of elements swith to simpler sort:\n>>";
        int theshold;
        std::cin >> theshold;
        if (theshold < number_of_elements)
        {
            start_time = clock();
            List.CombinedAlgorithm(theshold);
            break;
        }
    default:
        std::cout << "Try again";
        main();
    }
    std::cout << "It took " << clock() - start_time << "miliseconds\n";
    std::cout << "Do you want to print sorted list?   1 - yes, 2 - no\n>>";
    std::cin >> user_input;
    if (user_input == 1)
        List.print();
}


void MesureTimeTest(void (ListToSort::*TypeOfSort)(), std::string sort_name)
{
    std::cout << sort_name << ":" << std::endl;
    unsigned time_passed = 0;
    for (unsigned number_of_elements = 10, start_of_round = clock();
        time_passed < 5000;
        time_passed = clock() - start_of_round, start_of_round = clock(), number_of_elements *= 2)
    {
        if (number_of_elements != 10)
            std::cout << "  (" << time_passed << " miliseconds)." << std::endl;
        std::cout << "Number of elements = " << number_of_elements ;
        ListToSort List(number_of_elements);
        (List.*TypeOfSort)();
    }
    std::cout << "  (" << time_passed << " miliseconds)." << std::endl;
}
void MesureTimeTestInCombineAlgorihtm(int threshold)
{
    std::cout << "Combine Algorihtm with threshold = "<< threshold << ":" << std::endl;
    unsigned time_passed = 0;
    for (unsigned number_of_elements = 10, start_of_round = clock();
        time_passed < 5000;
        time_passed = clock() - start_of_round, start_of_round = clock(), number_of_elements *= 2)
    {
        if (number_of_elements != 10)
            std::cout << "  (" << time_passed << " miliseconds)." << std::endl;
        std::cout << "Number of elements = " << number_of_elements ;
        ListToSort List(number_of_elements);
        List.CombinedAlgorithm(threshold);
    }
    std::cout << "  (" << time_passed << " miliseconds)." << std::endl;
}
void BenchmarkMode()
{
    MesureTimeTest(&ListToSort::BiltInSort, "Bilt in sort");
    MesureTimeTest(&ListToSort::QuickSort, "Quick sort");
    MesureTimeTest(&ListToSort::SelectionSort, "Selection sort");
    for (int t = 10; t < 100; t *= 2)
        MesureTimeTestInCombineAlgorihtm(t);
}
