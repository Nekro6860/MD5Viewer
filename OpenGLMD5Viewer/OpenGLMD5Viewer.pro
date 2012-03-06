TEMPLATE = app
TARGET = OpenGLMD5Viewer
QT += core \
    gui \
    opengl
HEADERS += src/rendering/TestCubeRenderer.h \
    src/core/Light.h \
    src/core/Camera.h \
    src/core/MD5/MD5Mesh.h \
    src/core/MD5/MD5Skeleton.h \
    src/core/MD5/MD5Object.h \
    src/rendering/TestCubeRenderer.h \
    src/core/Camera.h \
    src/core/Light.h \
    src/core/MD5/MD5Mesh.h \
    src/core/MD5/MD5Object.h \
    src/core/MD5/MD5Skeleton.h \
    src/RenderCanvas.h \
    src/rendering/Renderer.h \
    openglmd5viewer.h
SOURCES += src/rendering/TestCubeRenderer.cpp \
    src/core/Light.cpp \
    src/core/Camera.cpp \
    src/core/MD5/MD5Mesh.cpp \
    src/core/MD5/MD5Skeleton.cpp \
    src/core/MD5/MD5Object.cpp \
    src/rendering/TestCubeRenderer.cpp \
    src/core/Camera.cpp \
    src/core/Light.cpp \
    src/core/MD5/MD5Mesh.cpp \
    src/core/MD5/MD5Object.cpp \
    src/core/MD5/MD5Skeleton.cpp \
    src/RenderCanvas.cpp \
    src/rendering/Renderer.cpp \
    main.cpp \
    openglmd5viewer.cpp
FORMS += openglmd5viewer.ui
RESOURCES += 
