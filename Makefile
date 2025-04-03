parser: main.cpp src/expr.cpp src/interp.cpp src/scanner.cpp src/tree.cpp
		 g++ -o parser -g main.cpp src/expr.cpp src/interp.cpp src/scanner.cpp src/tree.cpp

clean:
		rm -f parser