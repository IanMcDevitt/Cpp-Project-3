// Author: <Ian McDevitt>
// Email: <mcdeviti@email.sc.edu>
// Section #: <002>
// Copyright 2021 <Ian McDevitt>
// Modified from template code @coleca24 GitHub
#include "./ArrayList.h"

template <class U>
ostream& operator<<(ostream & os, ArrayList<U> a) {
    os << "[";
    for (int i = 0; i < a.getSize(); i++) {
        os << a.getData(i) << " ";
    }
    os << "]";
    return os;
}

template <class T>
ArrayList<T>::ArrayList() {
    size = 0;
    data = new T[size];
}

template <class T>
ArrayList<T>::ArrayList(int size, T val) {
    this->size = size;
    data = new T[size];
    for (int i = 0; i <size; i++) {
        data[i] = val;
    }
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & copy) {
    setSize(copy.getSize());
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = copy[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete [] data;
}

template <class T>
void ArrayList<T>::setSize(int size) {
    if (size >= 0) {
        this->size = size;
    } else {
        std::cout << "Incorrect size\n";
        exit(1);
    }
}

template <class T>
int ArrayList<T>::getSize() const {
    return size;
}

template <class T>
T ArrayList<T>::getData(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T ArrayList<T>::operator[](int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    } else {
        std::cout << "Invalid Index\n";
        exit(0);
    }
}

template <class T>
T& ArrayList<T>::operator[](int index) {
    return data[index];
}

template <class T>
const ArrayList<T> & ArrayList<T>::operator=(const ArrayList<T> rhs) {
    size = rhs.getSize();
    delete [] data;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
    return *this;
}

template <class T>
void ArrayList<T>::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

// Start of new functions

template <class T>
bool ArrayList<T>::operator!=(const ArrayList<T> & rhs) const {
    if (size == rhs.getSize()) {
        for (int i = 0; i < size; i++) {
            if (data[i] != rhs[i]) {
                return true;
            }
        }
    } else {
        return true;
    }
        return false;
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(T val) const {
    ArrayList<T> ret(*this);
    for (int i = 0; i <ret.getSize(); i++) {
        ret[i] += val;
    }
    return ret;
}
template <class T>
ArrayList<T> ArrayList<T>::operator+(const ArrayList<T> & rhs) const {
    ArrayList<T> ret(*this);
    if (size == rhs.getSize()) {
        for (int i = 0; i <ret.getSize(); i++) {
               ret[i] += rhs[i];
        }
    }
    return ret;
}

template <class T>
ArrayList<T> & ArrayList<T>::operator--() {
    T *temp = data;
    data = new int[size -1];
    for (int i = 0; i < size-1; i++) {
        data[i] = temp[i];
    }
    size--;
    delete [] temp;
    return *this;
}

template <class T>
ArrayList<T> ArrayList<T>::operator--(int val) {
    ArrayList<T> ret(*this);
    T *temp = data;
    data = new T[size -1];
    for (int i = 0; i < size-1; i++) {
        data[i] = temp[i];
    }
        size--;
        delete [] temp;
    return ret;
}
template <class T>
void ArrayList<T>::operator+=(T val) {
     ArrayList<T> ret(*this);
     T *temp = data;
     data = new T[size +1];
     for (int i = 0; i < size; i++) {
        data[i] = temp[i];
     }
     data[size] = val;
     delete [] temp;
     size++;
    // return ret;
}
template <class T>
void ArrayList<T>::operator+=(const ArrayList<T> & rhs) {
    T *temp = data;
    data = new T[size + rhs.getSize()];
    for (int i = 0; i < size; i++) {
        data[i] = temp[i];
    }
    for (int i = 0; i < rhs.getSize(); i++) {
        data[size + i] = rhs[i];
    }
    size += rhs.getSize();
    delete [] temp;
    // return ret;
}

template <class T>
ArrayList<T> ArrayList<T>::operator*(int val) const {
    ArrayList<T> ret(val *size);
    // ret.data = new T[val*size];
    int j = 0;
    std::cout << val << std::endl;
    while (val > 0) {
        for (int i = 0; i < size; i++) {
            ret.data[j] = data[i];
            j++;
        }
        val--;
    }
    return ret;
}
template <class T>
ArrayList<T> ArrayList<T>::operator/(int val) const {
    ArrayList<T> ret(val);
    // ret.data = new T[val];
    for (int i = 0; i < val; i++) {
        ret.data[i] = data[i];
    }
    return ret;
}
