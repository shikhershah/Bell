#-framework Cocoa -framework OpenGL -framework IOKit

all:
	 @$(MAKE) -C $(BELL_CORE) -f Core.mk
	 @$(MAKE) -C $(BELL_PLATFORM) -f Platform.mk
	 @$(MAKE) -C $(BELL_RENDER) -f Render.mk 
	 g++ $(BELL_BIN)/*.o $(BELL_LIB)/libglfw3.a $(BELL_LIB)/libglad.a $(EXT_RENDER_DIR)/*.cpp $(EXT_RENDER_DIR)/backends/imgui_impl_glfw.cpp $(EXT_RENDER_DIR)/backends/imgui_impl_opengl3.cpp$(CFLAGS) $(LIBS) -shared -o $(BELL_BIN)/Bell.so
.PHONY: all

	
