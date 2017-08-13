BINARY = test

OBJS = main.o unitests.o transaction.o account.o collections.o casts.o Person.o
CC=g++#clang++
CPP_FLAGS=-g -std=c++11 -Wall -pedantic -Werror
ARTIFACTS = $(OBJS) $(BINARY)
all:	$(BINARY)
	echo "All done"

$(BINARY): $(OBJS)
	$(CC) $(CPP_FLAGS) -o $@ $^ #$@ == rule target, $^ == rule dependency
	
%.o: %.cpp
	$(CC) $(CPP_FLAGS) -o $@ -c $< #==pattern matched dependency

main.o : unitests.hpp collections.hpp transaction.hpp account.hpp casts.hpp Person.hpp

unitests.o : collections.hpp transaction.hpp account.hpp casts.hpp Person.hpp

collections.o : collections.hpp

transaction.o : transaction.hpp

account.o : account.hpp

casts.o: casts.hpp

Person.o: Person.hpp
clean:
	rm -f $(ARTIFACTS)
	echo clean succeeded
