#include <Call_proxy.h>

template<class T, class Suf>
Call_proxy<T,Suf>::Call_proxy(T* pp, Suf su) :p(pp), own(true), suffix(su) {
}

template<class T, class Suf>
Call_proxy<T,Suf>::Call_proxy(const Call_proxy& a) : p(a.p), own(true), suffix(a.suffix) { 
    a.own=false;
}

template<class T, class Suf>
Call_proxy<T,Suf>::~Call_proxy() { 
    if (own) { 
        suffix(); 
    }
}

template<class T, class Suf>
T* Call_proxy<T,Suf>::operator->() const { 
    return p; 
}

