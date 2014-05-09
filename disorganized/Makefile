CXXFLAGS = -g -Wall -DGL_GLEXT_PROTOTYPES

TARGET = heighway

OBJS = obj/compute.o obj/draw.o obj/heighway.o

LIBS = -lGL -lglut -lGLU

.PHONY: clean try

$(TARGET): $(OBJS)
#	# [MAKE] $@
	@$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

obj/%.o: %.cpp
#	# [COMPILE]  $< --> $@
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
#	# [REMOVE] $(OBJS) $(TARGET)
	@-rm $(OBJS) $(TARGET) 2>/dev/null

try: $(TARGET)
	@./$(TARGET)

