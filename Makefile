EXEC=biblio

SRC = main.cc cd.cc book.cc vhs.cc tools.cc media.cc
OBJS= $(SRC:.cc=.o)

CXXFLAGS = -std=c++11
CXX = g++

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.c
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

clean:
	$(RM) $(EXEC) *.o
