project3: main.o hexoutput.o sampler.o
	g++ -o project3 main.cc hexoutput.cpp sampler.cpp

main.o: main.cc DisjointSet.h hexpathfinder.h stack.h
	g++ -c main.cc

hexoutput.o: hexoutput.cpp hexpathfinder.h
	g++ -c hexoutput.cc

sampler.o: sampler.cpp sampler.h
	g++ -c sampler.cpp

