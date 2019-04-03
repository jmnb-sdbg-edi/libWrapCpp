#include <Call_proxy.h>

template<class T, class Pref, class Suf>
class Wrap {
	T* p;
	int* owned;
	void incr_owned();
	void decr_owned();

    Pref prefix;
    Suf suffix;

public:
	Wrap(T& x, Pref pr, Suf su);

	Wrap(T* pp, Pref pr, Suf su);

	Wrap(const Wrap& a);

	Wrap& operator=(const Wrap& a);

	~Wrap();

	Call_proxy<T,Suf> operator->() const;

    // extract pointer to wrapped object
	T* direct() const;
};

