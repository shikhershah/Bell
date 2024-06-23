

all:
	 @$(MAKE) -C $(BELL_CORE) -f Core.mk
	 @$(MAKE) -C $(BELL_PLATFORM) -f Platform.mk
	 @$(MAKE) -C $(BELL_RENDER) -f Render.mk 
	 g++ $(BELL_BIN)/*.o $(BELL_LIB)/*.a  -framework Cocoa -framework OpenGL -framework IOKit -shared -o $(BELL_BIN)/Bell.so

.PHONY: all

	
