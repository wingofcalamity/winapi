CC = cl
CFLAGS = /EHsc /DUNICODE
SRC = src
BIN = bin

all: 

HelloWorld.exe:
	$(CC) $(CFLAGS) $(SRC)\HelloWorld.c /Fe:$(BIN)\HelloWorld.exe  

HelloINI.exe:
	$(CC) $(CFLAGS) $(SRC)\HelloINI.c /Fe:$(BIN)\HelloINI.exe  

HelloWindow.exe:
	$(CC) $(CFLAGS) $(SRC)\HelloWindow.c /Fe:$(BIN)\HelloWindow.exe  

clean:
	del /Q $(BIN_DIR)\*.exe
	del /Q *.obj

.PHONY: all clean
