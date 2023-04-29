CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

all: bin/geometry/main bin/geometry-test/test_main

.PHONY: clean test play

bin/geometry/main: obj/src/geometry/main.o bin/libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

bin/geometry-test/test_main: obj/test/main.o obj/test/tests.o bin/libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src -lm

obj/test/main.o: test/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I thirdparty

obj/test/tests.o: test/tests.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src -I thirdparty
	
bin/libgeometry.a: obj/src/libgeometry/geometrylib.o obj/src/libgeometry/parser.o
	ar rsc $@ $^

obj/src/libgeometry/geometrylib.o: src/libgeometry/geometrylib.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/libgeometry/parser.o: src/libgeometry/parser.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf obj/src/libgeometry/*.o
	rm -rf obj/src/geometry/*.o
	rm -rf obj/test/*.o
	rm -rf obj/src/libgeometry/*.d
	rm -rf obj/src/geometry/*.d
	rm -rf obj/test/*.d
	rm -rf bin/*.a

test:
	./bin/geometry-test/test_main

play:
	./bin/geometry/main input

-include bin/main.d bin/geometrylib.d bin/parser.d
