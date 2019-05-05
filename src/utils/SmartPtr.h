//
//  ObjectRef.hpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#ifndef SmartPtr_h
#define SmartPtr_h

#include <stdio.h>

template <class T>
class SmartPtr
{
private:
    T       *ptr;
    bool    released;
    
public:
    SmartPtr(T *p = NULL);
    SmartPtr();
    
    void release();
    
    bool isReleased() const;
    
    T & operator * ();
    
    T * operator -> ();
};

#endif /* ObjectRef_hpp */
