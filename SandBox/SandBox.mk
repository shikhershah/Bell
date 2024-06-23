SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp, $(SANDBOX_BIN)/%.o, $(SRCS))



#$(BIN_DIR)/Application.o:
#		g++ Application.cpp $(CFLAGS) -c -o $@ $^

#all:
#	echo $(BELL_DIR)
#	echo $(OBJS)



#$(BIN_DIR)/$(OBJS):
#	g++ Application.cpp $(CFLAGS) -c -o $@ $^


.PHONY: build

build: $(OBJS)

$(SANDBOX_BIN)/%.o: src/%.cpp
	 g++ $(CFLAGS) -c $< -o $@





