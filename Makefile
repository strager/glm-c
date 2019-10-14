CFLAGS += -I.
test.exe: test/main.o
	$(CC) -o $(@) $(<)
