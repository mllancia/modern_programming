## Makefile
## author:  Holger Arndt
## version: 15.09.2025

CXX = g++
MAKEDEP = $(CXX) -MM -fPIC
QTCXX = $(CXX)
QTCXXFLAGS = -Wall -std=c++17 -fPIC
QT6INCBASE := /usr/include/qt6
QT6INC := -I$(QT6INCBASE)/QtCore -I$(QT6INCBASE)/QtGui \
	-I$(QT6INCBASE)/QtWidgets -I$(QT6INCBASE)
QT6LIB := -lQt6Core -lQt6Gui -lQt6Widgets

CCEXE = shapetst
CCSRC := $(CCEXE).cc shapes.cc shapewin.cc
CCOBJ := $(patsubst %.cc,%.o,$(CCSRC))
CCDEP := $(patsubst %.cc,%.dep,$(CCSRC))

all: $(CCEXE)

.SUFFIXES:
.SECONDARY:

%: %.o $(CCOBJ)
	$(QTCXX) $(CCOBJ) -o $@ $(QT6LIB)

%.o: %.cc
	$(QTCXX) $(QT6INC) $(QTCXXFLAGS) -c $<

%.dep: %.cc
	$(MAKEDEP) $< $(QT6INC) | sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' > $@

clean:
	rm -f $(CCOBJ) $(CCDEP) $(CCEXE)

-include $(CCDEP)
