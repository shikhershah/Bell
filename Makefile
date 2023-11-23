TOP_DIR = $(PWD)
CORE_DIR = $(TOP_DIR)/src/Bell/Core
BIN_DIR = $(TOP_DIR)/bin


EXT_LOG_DIR = $(TOP_DIR)/External/spdlog/include 

INCLUDE_PATH :=
INCLUDE_PATH += -I$(CORE_DIR)
INCLUDE_PATH += -I$(EXT_LOG_DIR) 

#/Users/shikhershah/Projects/GameEngine/Bell/bin

CFLAGS :=
CFLAGS += $(INCLUDE_PATH)
CFLAGS += -std=c++11


export CFLAGS BIN_DIR


$(BIN_DIR)/main.o:
	 g++ main.cpp  $(CFLAGS) -c -o $@ $^
	 @$(MAKE) -C $(CORE_DIR) -f Core.mk
	 g++ bin/main.o bin/Logging.o  $(CFLAGS)  -o output





clean:
	rm $(BIN_DIR)/*.o
	
