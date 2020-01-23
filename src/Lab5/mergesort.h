#include <iostream>

template<typename T>
void mergesort(T f, T l) {
	
    int size = l - f;
    if (size == 0 || size == 1)
        return;

    T center = f + (size / 2);

    mergesort(f, center);
	
    mergesort(center, l);


    T n1 = f;
    T n2 = center;

    auto list = new typename std::iterator_traits<T>::value_type[size];

    size = 0;
    while(n1 != center || n2 != l)
        if(n1 == center)
            while(n2 != l) {
                list[size] = *n2;
                n2++;
                size++;
            }
        else if(n2 == l)
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
    while(f != l){
        *f = list[size];
        size++;
        f++;
    }
    delete[] list;
}