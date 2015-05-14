# cs335 lab4
# to compile your project, type make and press enter

all: lab42

lab42: lab42.cpp
	g++ lab42.cpp -o lab42

clean:
	rm -f lab42
	rm -f *.o

