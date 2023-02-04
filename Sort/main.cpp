#include <iostream>

using namespace std;

#include "mergeSort.h"
#include "quickSort.h"
#include <iostream>


int main() {
    const int size = 10;
    int array[] = {7,3,6,1,9,1,5,0,22,3};
    for (int i=0;i<size;i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Merge Sort Test" << std::endl;
    Merge mergeSort;
    mergeSort.sort(array,size);

    for (int i=0;i<size;i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Quick Sort Test" << std::endl;
    int array2[] = {7,3,6,1,9,1,5,0,22,3};
    QSort qSort;
    qSort.sort(array2,size);
    for (int i=0;i<size;i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
