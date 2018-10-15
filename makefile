# Written by Matthew Marinets
# Oct 2018

CFLAGS=-g -Wall -Werror -Iinclude
CC=g++
EXECUTABLE_NAME=LinkedStack

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
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE_NAME)
	if [ -d $(OBJDIR) ]; then rmdir $(OBJDIR); fi  # Remove OBJDIR only if it exists
