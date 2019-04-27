CFLAGS = -Wall -O2 $(shell pkg-config --cflags libssl libcrypto)
CXXLIBS = $(shell pkg-config --libs libssl libcrypto)
SRCS = main.cpp sha256sum.cpp utils.cpp
INCLUDES =

OBJS = $(SRCS:.c=.o)

MAIN = compare

.PHONY: depend clean

all: $(MAIN)
	@echo Project has been compiled

debug: CXXLIBS += -D DEBUG -g
debug: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(CXXLIBS)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
