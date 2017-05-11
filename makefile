.PHONY:clean
	CC=g++
	CFLAGS += -O3
	CFLAGS += -std=c++0x
	CFLAGS += -lncurses
	CFLAGS += -pg -D_DEBUG -g -c -Wall

TARGET=./main
SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)
	chmod a+x $(TARGET)
clean:
	rm -rf *.o $(TARGET)

