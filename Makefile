CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

bin/main: bin/main.o
	$(CC) $(CFLAGS) -o $@ $^

bin/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src
	
clean:
	rm -rf main bin/*.o
	rm -rf main bin/*.d
	
-include bin/main.d
