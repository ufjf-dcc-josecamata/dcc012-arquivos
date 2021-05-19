
###############################################################################
# File management.  This is where the source, header, and object files are
# defined

#
# source files
srcfiles 	:= $(wildcard *.c) $(wildcard src/*.c)

#
# object files
objects		:= $(patsubst %.c, %.o, $(srcfiles))

################################################################################3

# Compiler and linker
CC=gcc
 
# Flags for compiler
CC_FLAGS= -I./include  
 
# Command used at clean target
RM = rm -rf

target     := ./arq.exe 
 
#
# Compilation and linking
#
all: $(target)

# Production rules:  how to make the target - depends on library configuration
$(notdir $(target)): $(objects)
	@echo "Linking "$@"..."
	@$(CC) $(objects) -o $@
 
%.o: %.c
	@echo "Compiling C "$<"..."
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(objects) $(target) *~


.PHONY: all clean
