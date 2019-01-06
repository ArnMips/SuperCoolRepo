include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    ../arto-converter/artoConverter.h \
    tst_arabictoroman.h \
    tst_romantoarabic.h \
    tst.h \
    tst_asciitoint.h

SOURCES += \
        main.cpp \
    ../arto-converter/artoConverter.cpp
