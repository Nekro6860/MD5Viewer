TEMPLATE = app
TARGET = OpenGLMD5Viewer
QT += core \
    gui \
    opengl
HEADERS += src/core/utils/shaderLoader.h \
    openglmd5viewer.h \
    src/core/MD5/Md5iReader.h \
    src/rendering/Md5TexturedRenderer.h \
    src/rendering/Md5WireframeRenderer.h \
    src/rendering/Md5SolidRenderer.h \
    src/core/MD5/Md5Animation.h \
    src/core/MD5/Md5Mesh.h \
    src/core/MD5/Md5Model.h \
    src/core/MD5/Md5Object.h \
    src/core/MD5/Md5Skeleton.h \
    src/core/MD5/common.h \
    src/core/utils/Mathlib.h \
    src/RenderCanvasAbs.h \
    src/core/Camera.h \
    src/core/Light.h \
    src/RenderCanvas.h \
    src/rendering/Renderer.h
SOURCES += src/core/utils/shaderLoader.c \
    openglmd5viewer.cpp \
    src/core/MD5/Md5iReader.cpp \
    src/rendering/Md5TexturedRenderer.cpp \
    src/rendering/Md5WireframeRenderer.cpp \
    src/rendering/Md5SolidRenderer.cpp \
    src/core/MD5/Md5Animation.cpp \
    src/core/MD5/Md5Mesh.cpp \
    src/core/MD5/Md5Model.cpp \
    src/core/MD5/Md5Object.cpp \
    src/core/MD5/Md5Skeleton.cpp \
    src/RenderCanvasAbs.cpp \
    src/core/Camera.cpp \
    src/core/Light.cpp \
    src/RenderCanvas.cpp \
    src/rendering/Renderer.cpp \
    main.cpp
FORMS += openglmd5viewer.ui
RESOURCES += 
INCLUDEPATH += lib/Devil/include/IL \
    C:/devtools/MinGW/include/GL \
    C:/utils/Devil/include/IL
LIBS += "C:/utils/Devil/lib/DevIL.lib" \
    "C:/utils/glew/glew-1.7.0/bin/glew32.dll"
