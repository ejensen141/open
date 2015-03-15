C_FLAGS = -static
SOURCES = read_map.c open.c main.c
S_OPEN_SOURCES = read_map.c sopen.c smain.c
OUTPUT = open
OUTPUT_S = sopen

all:

	g++  $(SOURCES) $(C_FLAGS) -o $(OUTPUT)
	g++  $(S_OPEN_SOURCES) $(C_FLAGS) -o $(OUTPUT_S)

install:all

	sudo cp open /bin
	sudo cp sopen /bin
	cp extension_map.setting $(HOME)/.extension_map.setting

clean:

	rm open
	rm sopen



