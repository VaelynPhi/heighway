CXXFLAGS = -g -Wall -DGL_GLEXT_PROTOTYPES

TARGET = heighway

OBJS = heighway.o

LIBS = -lGL -lglut -lGLU

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

