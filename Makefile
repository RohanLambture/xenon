scanner: main.cpp scanner.cpp 
		g++ -o scanner -g main.cpp scanner.cpp

clean:
		rm -f scanner *.o