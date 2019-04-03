#include <Wrap.h>

template<class T, class Pref, class Suf>
void Wrap<T, Pref, Suf>::incr_owned() { 
    if (owned) {
        ++*owned; 
    }
}

template<class T, class Pref, class Suf>
void Wrap<T, Pref, Suf>::decr_owned() { 
    if (owned && --*owned == 0) { 
        delete p; 
        delete owned; 
    } 
} 

template<class T, class Pref, class Suf>
Wrap<T, Pref, Suf>::Wrap(T& x, Pref pr, Suf su)
:p(&x), owned(0), prefix(pr), suffix(su) { 
} 

template<class T, class Pref, class Suf>
Wrap<T, Pref, Suf>::Wrap(T* pp, Pref pr, Suf su)
:p(pp), owned(new int(1)), prefix(pr), suffix(su) {
} 

template<class T, class Pref, class Suf>
Wrap<T, Pref, Suf>::Wrap(const Wrap<T, Pref, Suf>& a)
:p(a.p), owned(a.owned), prefix(a.prefix), suffix(a.suffix) { 
    incr_owned();
}

template<class T, class Pref, class Suf>
Wrap<T, Pref, Suf>& Wrap<T, Pref, Suf>::operator=(const Wrap<T, Pref, Suf>& a) {
    a.incr_owned();
    decr_owned();
    p = a.p;
    owned = a.owned;
    prefix = a.prefix;;
    suffix = a.suffix;
}

template<class T, class Pref, class Suf>
Wrap<T, Pref, Suf>::~Wrap() {
    decr_owned();
}

template<class T, class Pref, class Suf>
Call_proxy<T,Suf> Wrap<T, Pref, Suf>::operator->() const {
    prefix();
    return Call_proxy<T,Suf>(p,suffix);
}

// extract pointer to wrapped object
template<class T, class Pref, class Suf>
T* Wrap<T, Pref, Suf>::direct() const { 
    return p; 
}


