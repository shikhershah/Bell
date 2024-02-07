SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, $(BELL_BIN)/%.o, $(SRCS))



#$(BIN_DIR)/Application.o:
#		g++ Application.cpp $(CFLAGS) -c -o $@ $^

#all:
#	echo $(BELL_DIR)
#	echo $(OBJS)



#$(BIN_DIR)/$(OBJS):
#	g++ Application.cpp $(CFLAGS) -c -o $@ $^




build: $(OBJS)

$(BELL_BIN)/%.o: %.cpp
	 g++ $(CFLAGS) -std=c++14   -c $< -o $@




.PHONY: build 
