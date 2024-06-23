TOP_DIR = $(PWD)
INCLUDE_DIR = $(PWD)/backends

GLFW_DIR = /Users/shikhershah/Projects/GameEngine/Bell/External/glfw/include
GLFW_BIN = /Users/shikhershah/Projects/GameEngine/Bell/bin/lib

#-framework Cocoa -framework OpenGL -framework IOKit

all:
	g++ *.cpp $(INCLUDE_DIR)/imgui_impl_glfw.cpp $(INCLUDE_DIR)/imgui_impl_opengl3.cpp $(GLFW_BIN)/libglfw3.a  -std=c++11 -I$(INCLUDE_DIR) -I$(TOP_DIR) -I$(GLFW_DIR) -framework Cocoa -framework OpenGL -framework IOKit -shared -o libimgui.a

