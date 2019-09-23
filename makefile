T=Planet
Q=Parser
R=program2
P=Scanner
FLAGS=g++ -Wall -Wextra -std=c++14 -g -DDEBUG

all: $(R)

$(R): $(R).o $(P).o $(T).o $(Q).o
	$(FLAGS) $(P).o $(T).o $(Q).o $(R).o -o $(R)
$(R).o: $(R).cpp
	$(FLAGS) -c -D TEST5 -D TEST6 -D TEST7 -D TEST8 -D TEST9 -D TEST10 -D TEST11 $(R).cpp -o $(R).o
$(Q).o: $(Q).cpp $(Q).h
	$(FLAGS) -c $(Q).cpp
$(T).o: $(T).cpp $(T).h
	$(FLAGS) -c $(T).cpp
$(P).o: $(P).cpp $(P).h
	$(FLAGS) -c $(P).cpp
run: all
	./$(R)
memcheck: all
	valgrind --track-origins=yes --leak-check=full ./$(R)
clean:
	rm -rf $(R) *.o
