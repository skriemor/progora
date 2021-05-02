#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<class T, int N> struct array {

    typedef T value_type;
    typedef T* iterator;
    typedef T* const_iterator;
    typedef unsigned int size_type;

    T elems[N];

    iterator begin() { return elems; }
    const_iterator begin() const { return elems; }
    iterator end() { return elems + N; }
    const_iterator end() const { return elems + N; }

    size_type size() const;

    T& operator[](int n) { return elems[n]; }
    const T& operator[](int n) const { return elems[n]; }
    const T& at(int n) const;
    T& at(int n);

    T * data() { return elems; }
    const T * data() const { return elems; }
    
};


template<class it1,class it2>void copyem(it1* f1, it1* e1, it2* f2) {
    if (f1==e1) return;
    it1* kek = f1;
    while (kek != e1) {
        *f2++ = *kek++;
    }
}
int getIndexOfIntList(std::list<int> gg, int n) {
    std::list<int>::iterator i = gg.begin();
    int a=0;
    while (std::find(gg.begin(), gg.end(), n) != i) {
        i++; a++;
    }
    return a;
}
int main(){
    array<int, 10> ia  {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> iv = { 0,1,2,3,4,5,6,7,8,9 };
    std::list<int> il = { 0,1,2,3,4,5,6,7,8,9 };

    array<int, 10> ia2;
    copyem(ia.begin(), ia.end(), ia2.begin());
    std::vector<int> iv2 = iv;
    std::list<int> il2 = il;

    for (int i = 0; i < 10; i++) ia2[i] += 2;
    for (std::vector<int>::iterator i = iv2.begin(); i != iv2.end(); i++) *i += 3;
    for (std::list<int>::iterator i = il2.begin(); i != il2.end(); i++) *i += 5;

    for (auto i : ia2) std::cout << i << " "; std::cout << std::endl;
    for (auto i : iv2) std::cout << i << " "; std::cout << std::endl;
    for (auto i : il2) std::cout << i << " "; std::cout << std::endl;
    

    std::cout << std::endl;
    copyem(ia2.begin(), ia2.end(), &iv2[0]);
    
    copy(il2.begin(),il2.end(), ia2.begin() );
    std::cout << "modositott masodik array:"<<std::endl;
    for (auto i : ia2) std::cout << i << " "; std::cout << std::endl; 
    std::cout << "modositott masodik vector:" << std::endl;
    for (auto i : iv2) std::cout << i << " "; std::cout << std::endl;
    std::cout << "modositott masodik lista:" << std::endl;
    for (auto i : il2) std::cout << i << " "; std::cout << std::endl;
    
 
    if (std::find(iv2.begin(), iv2.end(), 3) == iv2.end()) {
        std::cout << "Nem volt a vektorban"<<std::endl;
    }
    else {
        std::cout<<std::find(iv2.begin(), iv2.end(), 3) - iv2.begin() +1 <<". helyen volt a "<< 3 <<" a vektorban" <<std::endl;
    }

    if (std::find(il2.begin(), il2.end(), 27) == il2.end()) {
        std::cout << "Nem volt a listaban"<<std::endl;
    }
    else {
        std::cout << getIndexOfIntList(il2,27) + 1<<". volt a listaban a 27";
    }
    
}

