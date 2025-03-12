parser:expr.cpp interp.cpp main.cpp scanner.cpp tree.cpp
		g++ -o parser -g expr.cpp interp.cpp main.cpp scanner.cpp tree.cpp

clean:
		rm -f parser *.o