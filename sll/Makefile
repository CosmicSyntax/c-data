# Setting some variables...
	# Locations
OBJ_LOC = ./obj/
LIB_LOC = ./lib/
	# List
OB_ = list.o main.o
OBJ = $(patsubst %, $(OBJ_LOC)%, $(OB_))
HDR = $(wildcard $(LIB_LOC)*.h)
LIB = $(wildcard $(LIB_LOC)*.c)
BIN = LINKED

default: $(OBJ) $(HDR) $(BIN)

# Compile lib
$(OBJ_LOC)%.o: $(LIB_LOC)%.c
	mkdir -p obj
	cc -c $^ -o $@

# Compile main
$(OBJ_LOC)%.o: %.c
	cc -c $^ -o $@

# Link
$(BIN): $(OBJ)
	cc $^ -o $@

# Clean up
.PHONY: clean destory
	
# Remove just objects
clean:
	rm -f ./obj/*.o

# Remove everything
destroy:
	rm -f ./obj/*.o
	rm -f ./LINKED
