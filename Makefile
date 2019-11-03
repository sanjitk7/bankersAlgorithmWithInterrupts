
CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = bankers_interrupt_main.c bankers_process.c interrupt_create.c  queue.c 
OBJ = $(SRC:.cc=.o)
EXEC = bankerswithinterrupt

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf *.o $(EXEC)