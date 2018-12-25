CFLAGS = -Wall -Wextra -ggdb3 -std=c++11 -fno-exceptions -fno-rtti -fvisibility=hidden -march=native -pipe
main: main.cpp
	clang++ $(CFLAGS) -lboost_asio -o $@ $^
server:
	clang++ $(CFLAGS) -lboost_asio -o $@ $^
clean:
	rm -f main server
