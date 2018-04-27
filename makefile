CXX = g++
CXXFLAGS = -Wall
EXE = xc2

SRCDIR = src
SRCS = main.cpp PFAString.cpp
OBJS = $(SRCS:%.cpp=%.o)
OBJS := $(addprefix $(SRCDIR)/, $(OBJS))

.PHONY : all clean

all : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

$(SRCDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) core $(EXE)
