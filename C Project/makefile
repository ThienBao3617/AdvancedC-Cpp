CC = gcc

CFLAGS = -I./header file

SOURCES = source file/main.c source file/data.c source file/UI.c

TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES)
    $(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
    rm -f $(TARGET)
