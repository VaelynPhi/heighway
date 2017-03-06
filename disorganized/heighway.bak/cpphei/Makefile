CXXFLAGS = -g -Wall -DGL_GLEXT_PROTOTYPES

TARGET = sdv

OBJS = main.o

LIBS = -lGL -lglut -lGLU

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

