#include <Pref.h>
#include <Suf.h>

template<class T, class Pref, class Suf> class Wrap;

template<class T, class Suf>
class Call_proxy {
	T* p;
	mutable bool own;
	Suf suffix;

    // restrict creation
	Call_proxy(T* pp, Suf su);

    // prevent assignment
	Call_proxy& operator=(const Call_proxy&);

public:
	template<class U, class P, class S> friend class Wrap;

	Call_proxy(const Call_proxy& a);

	~Call_proxy();

	T* operator->() const;
};

