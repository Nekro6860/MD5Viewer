TEMPLATE = app
TARGET = OpenGLMD5Viewer
QT += core \
    gui \
    opengl
HEADERS += src/RenderCanvas.h \
    src/rendering/Renderer.h \
    openglmd5viewer.h
SOURCES += src/RenderCanvas.cpp \
    src/rendering/Renderer.cpp \
    main.cpp \
    openglmd5viewer.cpp
FORMS += openglmd5viewer.ui
RESOURCES += 
