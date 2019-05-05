//
//  ObjectRef.cpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#include "SmartPtr.h"

template <class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p), released(false) {}

template <class T>
SmartPtr<T>::SmartPtr() {
    release();
}

template <class T>
void SmartPtr<T>::release() {
    if (!released) {
        delete(ptr);
        released = true;
    }
}

template <class T>
bool SmartPtr<T>::isReleased() const {
    return released;
}

template <class T>
T & SmartPtr<T>::operator * () {
    return *ptr;
}

template <class T>
T * SmartPtr<T>::operator -> () {
    return ptr;
}
