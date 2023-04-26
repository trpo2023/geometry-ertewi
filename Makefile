CFLAGS = -Wall -Wextra -Werror -lm
CPPFLAGS = -MMD

.PHONY: clean

bin/main: obj/src/geometry/main.o bin/libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/geometry/main.o: src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< -I src
	
bin/libgeometry.a: obj/src/libgeometry/geometrylib.o obj/src/libgeometry/parser.o
	ar rsc $@ $^

obj/src/libgeometry/geometrylib.o: src/libgeometry/geometrylib.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/libgeometry/parser.o: src/libgeometry/parser.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf obj/src/libgeometry/*.o
	rm -rf obj/src/geometry/*.o
	rm -rf obj/src/libgeometry/*.d
	rm -rf obj/src/geometry/*.d
	rm -rf bin/*.a
	
-include bin/main.d bin/geometrylib.d bin/parser.d
