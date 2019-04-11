CPPFLAGS=--std=c++98 -g -Wall -pedantic -fPIC -Iinclude/
LDFLAGS=-g -fPIC

all: libWrapCpp.so

testLib: main.o libWrapCpp.so
	g++ $(LDFLAGS) $< -L. -lWrapCpp -o $@

main.o: test/main.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

test/main.cpp:

libWrapCpp.so: Call_proxy.o Wrap.o Callback.o Timespan_us.o
	g++ $(LDFLAGS) -shared -o $@ $^

Call_proxy.o: src/Call_proxy.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

Callback.o: src/Callback.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

Wrap.o: src/Wrap.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

Timespan_us.o: src/Timespan_us.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

src/Wrap.cpp: include/Wrap.h include/Call_proxy.h

src/Call_proxy.cpp: include/Call_proxy.h

src/Callback.cpp: include/Callback.h

src/Timespan_us.cpp: include/Timespan_us.h

include/Call_proxy.h: include/Pref.h include/Suf.h

clean: 
	rm -rf *.o
	rm -rf testLib

