CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

main: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
	
-include main.d
