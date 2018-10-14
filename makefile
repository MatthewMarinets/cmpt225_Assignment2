
CFLAGS=-g -Wall -Werror -Iinclude
CC=g++
EXECUTABLE_NAME=linked_stack.exe

SOURCES:=$(wildcard *.cpp)
HEADERS:=$(wildcard include/*.h)
OBJDIR:=obj
OBJECTS:=$(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(CFLAGS) $(OBJECTS)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CC) -o $@ $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE_NAME)
	rmdir $(OBJDIR)
