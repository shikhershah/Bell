TOP_DIR = $(PWD)
BELL_DIR = $(TOP_DIR)/Bell
BELL_SRC = $(TOP_DIR)/Bell/src
BELL_CORE = $(TOP_DIR)/Bell/src/Bell/Core
BELL_EVENTS = $(TOP_DIR)/Bell/src/Bell/Events
BELL_IMGUI = $(TOP_DIR)/Bell/src/Bell/ImGui
BELL_PLATFORM = $(TOP_DIR)/Bell/src/Bell/Platform
BELL_BIN = $(TOP_DIR)/Bell/bin
BELL_LIB = $(TOP_DIR)/Bell/bin/lib

EXT_LOG_DIR = $(TOP_DIR)/Bell/External/spdlog/include/ 
EXT_GLAD_DIR = $(TOP_DIR)/Bell/External/glad/include/
EXT_GLFW_DIR = $(TOP_DIR)/Bell/External/glfw/include/
EXT_IMGUI_DIR = $(TOP_DIR)/Bell/External/imgui/
EXT_RENDER_DIR = $(TOP_DIR)/Bell/External/glm/

SANDBOX_DIR = $(TOP_DIR)/SandBox
SANDBOX_BIN = $(TOP_DIR)/SandBox/bin


INCLUDE_PATH :=
INCLUDE_PATH += -I$(BELL_SRC)
#INCLUDE_PATH += -I$(BELL_CORE)
#INCLUDE_PATH += -I$(BELL_EVENTS)
#INCLUDE_PATH += -I$(BELL_RENDER)
#INCLUDE_PATH += -I$(BELL_PLATFORM)
#INCLUDE_PATH += -I$(BELL_BIN)
INCLUDE_PATH += -I$(BELL_LIB)
INCLUDE_PATH += -I$(EXT_LOG_DIR) 
INCLUDE_PATH += -I$(EXT_GLAD_DIR)
INCLUDE_PATH += -I$(EXT_GLFW_DIR)
INCLUDE_PATH += -I$(EXT_IMGUI_DIR)
INCLUDE_PATH += -I$(EXT_IMGUI_DIR)/backends
INCLUDE_PATH += -I$(EXT_RENDER_DIR)
INCLUDE_PATH += -I$(SANDBOX_DIR)
INCLUDE_PATH += -I$(SANDBOX_BIN)
#INCLUDE_PATH += -I/opt/homebrew/include

#/Users/shikhershah/Projects/GameEngine/Bell/bin
LIBS :=
LIBS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
#LIBS += -L/opt/homebrew/lib
#LIBS += -lglfw3
#LIBS += -lglfw

CFLAGS :=
CFLAGS += $(INCLUDE_PATH)
CFLAGS += -std=c++11




export CFLAGS LIBS BELL_CORE BELL_EVENTS BELL_IMGUI BELL_PLATFORM BELL_BIN BELL_LIB EXT_LOG_DIR EXT_GLAD_DIR EXT_GLFW_DIR EXT_DIR EXT_IMGUI_DIR SANDBOX_DIR SANDBOX_BIN 

.PHONY: all clean

all:
	 @$(MAKE) -C $(BELL_DIR) -f Bell.mk
	 @$(MAKE) -C $(SANDBOX_DIR) -f SandBox.mk
	 g++ $(BELL_BIN)/Bell.so $(SANDBOX_BIN)/*.o $(CFLAGS) $(LIBS) -o output




clean:
	rm $(BELL_BIN)/*.o
	
