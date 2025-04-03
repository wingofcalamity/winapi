CC = cl
CFLAGS = /EHsc /DUNICODE
SRC = src
BIN = bin

all: HelloWorld.exe

HelloWorld.exe:
	$(CC) $(CFLAGS) $(SRC)\HelloWorld.c /Fe:$(BIN)\HelloWorld.exe  

clean:
	del /Q $(BIN_DIR)\*.exe
	del /Q *.obj

.PHONY: all clean
