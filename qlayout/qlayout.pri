# This was needed to work around "number of sections exceeded object file format limit" linker error
win32:QMAKE_CXXFLAGS += /bigobj

SOURCES += \
	$$PWD/qlayoutwireitem.cpp \
	$$PWD/qlayoutmacroitem.cpp \
	$$PWD/qlayoutrectitem.cpp \
	$$PWD/qlayoutscene.cpp

HEADERS += \
	$$PWD/qlayoutwireitem.h \
	$$PWD/qlayoutmacroitem.h \
	$$PWD/qlayoutrectitem.h \
	$$PWD/qlayoutscene.h
