CPPFLAGS=--std=c++98 -g -Wall -pedantic -Iinclude/
LDFLAGS=-g 

all: libWrapCpp.so

testLib: main.o libWrapCpp.so
	g++ $(LDFLAGS) -L. -lWrapCpp $< -o $@

main.o: test/main.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

test/test.cpp:

libWrapCpp.so: Call_proxy.o Wrap.o
	g++ $(LDFLAGS) -shared -o $@ $<

Call_proxy.o: src/Call_proxy.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

Wrap.o: src/Wrap.cpp
	g++ $(CPPFLAGS) -o $@ -c $^

src/Wrap.cpp: include/Wrap.h include/Call_proxy.h

src/Call_proxy.cpp: include/Call_proxy.h

include/Call_proxy.h: include/Pref.h include/Suf.h

clean: 
	rm -rf *.o
	rm -rf testLib
