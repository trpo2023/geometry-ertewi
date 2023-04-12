CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

clean:
	rm -rf main bin/*.o
	rm -rf main bin/*.d
bin/main: bin/main.o
	$(CC) $(CFLAGS) -o $@ $^

bin/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src
	
-include bin/main.d
