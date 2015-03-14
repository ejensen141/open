C_FLAGS = -static
SOURCES = read_map.c open.c main.c
OUTPUT = open
all:

	g++  $(SOURCES) $(C_FLAGS) -o $(OUTPUT)
	

install:all

	sudo cp open /bin
	cp extension_map.setting $(HOME)/.extension_map.setting

clean:

	rm open
	rm *.o
	


