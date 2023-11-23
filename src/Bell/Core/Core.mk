SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))


$(BIN_DIR)/Logging.o:
	g++ logging.cpp $(CFLAGS) -c -o $@ $^	

