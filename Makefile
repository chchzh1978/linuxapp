#.PHONE:all
all:usesharedlib uselib hello sayhello driverdemo

usesharedlib:usesharedlib.c hello.so
	gcc $^ -o $@ -Wall

uselib:uselib.c libhello.a
	gcc $^ -o $@ -Wall 

(%.o) : %.c
	gcc -c $< -o $@

hello.so:sharedfirst.c sharedsecond.c
	gcc -fpic -shared $^ -o $@ -Wall

libhello.a:firsthello.c secondhello.c
	gcc -c $^ -Wall
	ar -r $@ $(patsubst %.c,%.o,$^)

hello sayhello driverdemo:FORCE
hello:hello.c
	gcc $< -o $@ -Wall

sayhello:sayhello.c hellomain.c
	gcc $(filter-out FORCE, $^) -o $@ -Wall 

driverdemo:driverdemo.c
	gcc $< -o $@ -Wall

#.PHONE:clean
clean:
	rm -f usesharedlib hello.so hello sayhello uselib libhello.a firsthello.o secondhello.o

print: *.c
	lpr -p $?
	touch print

.PHONY: FORCE
FORCE:

