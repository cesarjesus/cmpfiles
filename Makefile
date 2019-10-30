CFLAGS = -Wall -O2 $(shell pkg-config --cflags libssl libcrypto)
CXXLIBS = $(shell pkg-config --libs libssl libcrypto)
SRCS = main.cpp sha256sum.cpp utils.cpp
INCLUDES =

OBJS = $(SRCS:.c=.o)
DUPS_OBJS = checkdups.o utils.o walk_function.o walk_dups_function.o walk_directory.o

MAIN = compare

DUPS = checkdups

.PHONY: depend clean

all: $(MAIN) $(DUPS)
	@echo Project has been compiled

debug: CXXLIBS += -D DEBUG -g
debug: $(MAIN)

$(DUPS): $(DUPS_OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(DUPS) $(DUPS_OBJS) $(CXXLIBS)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(CXXLIBS)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN) $(DUPS)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
