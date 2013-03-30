CXXFLAGS = -g -Wall -DGL_GLEXT_PROTOTYPES

TARGET = heighway

OBJS = compute.o draw.o heighway.o

LIBS = -lGL -lglut -lGLU

.PHONY: clean

$(TARGET): $(OBJS)
	@$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.c
	# %.c --> $@
	$(CXX) $(CXXFLAGS) -c %.c

clean:
	rm $(OBJS) $(TARGET)

#g++ -g -Wall -DGL_GLEXT_PROTOTYPES   -c -o compute.o compute.cpp
