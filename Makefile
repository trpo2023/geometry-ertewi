CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

.PHONY: clean

bin/main: bin/main.o bin/geometrylib.a
	$(CC) $(CFLAGS) -o $@ $^

bin/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src
	
bin/geometrylib.a: bin/geometrylib.o
	ar rsc $@ $^

bin/geometrylib.o: src/libgeometry/geometrylib.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf main bin/*.o
	rm -rf main bin/*.d
	rm -rf main bin/*.a
	
-include bin/main.d bin/geometrylib.d