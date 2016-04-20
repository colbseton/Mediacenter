EXEC=biblio

OBJS= main.o cd.o command.o book.o vhs.o tools.o media.o

all: $(EXEC)
$(EXEC): $(OBJS)
	$(CXX) -o $@ $^ 
clean:
	$(RM) $(EXEC) *.o
