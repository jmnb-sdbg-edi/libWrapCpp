#include <cstdarg>

template<class T> class Callback {
public:
    typedef void (T::* f0)();

    Callback(T& target, f0 operation);

    virtual void Execute();

private:
    Callback();
    Callback(const Callback<T>&);
    T& _target;
    f0 _op0;
};

template<class T, typename Return> class CallbackR {
public:
    typedef Return (T::* f0)();

    CallbackR(T& target, f0 operation);

    virtual Return Execute();

private:
    CallbackR();
    CallbackR(const CallbackR<T, Return>&);
    T& _target;
    f0 _op0;
};

template<class T, typename Arg> class CallbackA {
public:
    typedef void (T::* fn)(Arg arg1...);

    CallbackA(T& target, fn operation);

    void Execute(Arg arg1...);

private:
    CallbackA();
    CallbackA(const CallbackA<T, Arg>&);
    T& _target;
    fn _opn;
};

template<class T, typename Return, typename Arg> class CallbackRA {
public:
    typedef Return (T::* fn)(Arg arg1...);

    CallbackRA(T& target, fn operation);

    Return Execute(Arg arg1...);

private:
    CallbackRA();
    CallbackRA(const CallbackRA<T, Return, Arg>&);
    T& _target;
    fn _opn;
};

