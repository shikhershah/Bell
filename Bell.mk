

all:
	 @$(MAKE) -C $(BELL_CORE) -f Core.mk
	 @$(MAKE) -C $(BELL_PLATFORM) -f Platform.mk
	 g++ $(BELL_BIN)/*.o $(BELL_BIN)/*.a  -framework Cocoa -framework OpenGL -framework IOKit -shared -o $(BELL_BIN)/test.so

.PHONY: all

	
