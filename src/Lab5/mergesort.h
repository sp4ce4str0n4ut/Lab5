#include <iostream>

template<typename T>
void mergesort(T first, T last) {
    int size = last - first;
    if (size == 0 || size == 1)
        return;

    T center = first + (size / 2);

    merge_sort(first, center);
    merge_sort(center, last);


    T n1 = first;
    T n2 = center;

    auto list = new typename std::iterator_traits<T>::value_type[size];

    size = 0;
    while(n1 != center || n2 != last)
        if(n1 == center)
            while(n2 != last) {
                list[size] = *n2;
                n2++;
                size++;
            }
        else if(n2 == last)
            while(n1 != center) {
                list[size] = *n1;
                n1++;
                size++;
            }
        else if(*n1 < *n2) {
            list[size] = *n1;
            n1++;
            size++;
        }
        else {
            list[size] = *n2;
            n2++;
            size++;
        }

    size = 0;
    while(first != last){
        *first = list[size];
        size++;
        first++;
    }
    delete[] list;
}