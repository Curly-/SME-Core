CPPS= $(wildcard *.cpp)
OBJS= $(CPPS:.cpp=.o)
CFLAGS= -std=c++0x -Wall -g -fPIC
LFLAGS= -shared
INCLUDE=
LIBS=
OBJDIR=objects/
OUT=libSME_Core.so

all: mkdirs $(OBJS) libSME_Core.so

clean:
	rm -rf $(OBJDIR) &&\
        rm -f $(OUT) 

install:
	cp $(OUT) /lib

uninstall:
	rm -f /lib/$(OUT)
        
.PHONY: all clean install uninstall

mkdirs:
	mkdir objects

$(OUT):$(OBJS)
	$(CXX) $(LFLAGS) -o $(OUT) $(addprefix $(OBJDIR), $(OBJS))

%.o: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -c -o $(OBJDIR)$@ $<
