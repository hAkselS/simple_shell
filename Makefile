TARGET = shell


all:  $(TARGET)


CC     = clang
#CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)


#debug: DEBUG_FLAGS = -g -DDEBUG
#debug: clean $(TARGET)


shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c


shell: shell.o
	$(CC) $(CFLAGS) -o $(TARGET) shell.o


test: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(TARGET) *.o

