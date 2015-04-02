all: runprogram

runprogram : Project6.cpp slotmachine.o stringlibrary.o
	g++ Project6.cpp stringlibrary.o slotmachine.o -o runprogram

slotmachine.o : slotmachine.cpp
	g++ -c slotmachine.cpp

stringlibrary.o : stringlibrary.cpp
	g++ -c stringlibrary.cpp

clean:
	rm -rf *. o runprogram
