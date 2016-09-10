CPPS= $(wildcard *.cpp)
OBJDIR=build/
OBJS= $(patsubst %.cpp,$(OBJDIR)%.o,$(CPPS))
CFLAGS= -std=c++0x -Wall -g -fPIC
LFLAGS= -shared
DEPENDS=
INCLUDES=$(DEPENDS)
LIBS=
OUT=$(OBJDIR)libSME_Core.so
-include Makefile-conf

all: DEPENDS mkdirs $(OBJS) $(OUT)

clean: DEPENDS
	rm -f $(OUT) &&\
	rm -rf $(OBJDIR)

DEPENDS:
ifeq ($(CONF), Debug)
	$(foreach DIR,$(filter-out $(PAR), $(DEPENDS)),\
        cd $(DIR) && $(MAKE) PAR="$(join $(DEPENDS), $(PAR))" $(MAKECMDGOALS);)
endif

install:
	cp $(OUT) /lib

uninstall:
	rm -f /lib/$(OUT)

.PHONY: all clean install uninstall

mkdirs:
	mkdir -p $(OBJDIR)

$(OUT):$(OBJS)
	$(CXX) -o $(OUT) $(OBJS) $(LFLAGS)

$(OBJDIR)%.o: %.cpp
	$(CXX) $(CFLAGS) $(subst ../,-I../,$(INCLUDES)) -c -o $@ $<
