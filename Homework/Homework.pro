QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_POST_LINK = rm -f "*.gcda"
#LIBS += -lgcov

SOURCES +=  tst_formalverification.cpp \
    HW1/linecoverage.cpp \
    HW2/edgecoverage.cpp \
    HW2/edgepaircoverage.cpp \
    HW3/stresstesting.cpp \
    HW4/logicalexpression.cpp \
    HW5/inputdomain.cpp

HEADERS += \
    HW1/linecoverage.h \
    HW2/edgecoverage.h \
    HW3/stresstesting.h \
    HW4/logicalexpression.h \
    HW5/inputdomain.h
