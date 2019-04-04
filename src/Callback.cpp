#include <Callback.h>

template<class T> 
Callback<T>::Callback(T& target, f0 operation) 
: _target(target),_op0(operation) {}

template<class T> 
void Callback<T>::Execute() {
    (_target.*_op0)();
}

template<class T, typename Return> 
CallbackR<T, Return>::CallbackR(T& target, f0 operation) 
: _target(target),_op0(operation) {}

template<class T, typename Return> 
Return CallbackR<T, Return>::Execute() {
    Return result = (_target.*_op0)();
    return result;
}

template<class T, typename Arg> 
CallbackA<T, Arg>::CallbackA(T& target, fn operation) 
: _target(target),_opn(operation) {}

template<class T, typename Arg> 
void CallbackA<T, Arg>::Execute(Arg arg1...) {
    va_list args;
    va_start(args, arg1);
    (_target.*_opn)(arg1);
    va_end(args);
}

template<class T, typename Return, typename Arg> 
CallbackRA<T, Return, Arg>::CallbackRA(T& target, fn operation) 
: _target(target),_opn(operation) {}

template<class T, typename Return, typename Arg> 
Return CallbackRA<T, Return, Arg>::Execute(Arg arg1...) {
    va_list args;
    va_start(args, arg1);
    Return result = (_target.*_opn)(arg1);
    va_end(args);
    return result;
}

