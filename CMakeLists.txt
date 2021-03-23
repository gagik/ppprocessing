cmake_minimum_required(VERSION 3.7)

project("prosecco-project")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


# https://github.com/mrshpot/openframeworks-linux-cmake/
set(OF_DIR "${PROJECT_SOURCE_DIR}/libs/openFrameworks/")
set(OF_SRC_DIR "${PROJECT_SOURCE_DIR}/libs/openFrameworks/libs/openFrameworks")
message(STATUS ${OF_DIR})

add_library(openFrameworks STATIC
${OF_SRC_DIR}/graphics/ofTessellator.cpp
${OF_SRC_DIR}/utils/ofTimer.cpp
${OF_SRC_DIR}/utils/ofXml.cpp
${OF_SRC_DIR}/utils/ofThread.cpp
${OF_SRC_DIR}/utils/ofSystemUtils.cpp
${OF_SRC_DIR}/utils/ofFileUtils.cpp
${OF_SRC_DIR}/utils/ofUtils.cpp
${OF_SRC_DIR}/utils/ofMatrixStack.cpp
${OF_SRC_DIR}/utils/ofURLFileLoader.cpp
${OF_SRC_DIR}/utils/ofLog.cpp
${OF_SRC_DIR}/utils/ofFpsCounter.cpp
${OF_SRC_DIR}/graphics/ofTrueTypeFont.cpp
${OF_SRC_DIR}/graphics/ofImage.cpp
${OF_SRC_DIR}/graphics/ofCairoRenderer.cpp
${OF_SRC_DIR}/graphics/ofPath.cpp
${OF_SRC_DIR}/graphics/ofGraphics.cpp
${OF_SRC_DIR}/graphics/of3dGraphics.cpp
${OF_SRC_DIR}/graphics/ofBitmapFont.cpp
${OF_SRC_DIR}/graphics/ofPixels.cpp
${OF_SRC_DIR}/graphics/ofGraphicsBaseTypes.cpp
${OF_SRC_DIR}/graphics/ofRendererCollection.cpp
${OF_SRC_DIR}/video/ofVideoGrabber.cpp
${OF_SRC_DIR}/video/ofGstUtils.cpp
${OF_SRC_DIR}/video/ofVideoPlayer.cpp
${OF_SRC_DIR}/video/ofGstVideoGrabber.cpp
${OF_SRC_DIR}/video/ofGstVideoPlayer.cpp
${OF_SRC_DIR}/communication/ofSerial.cpp
${OF_SRC_DIR}/communication/ofArduino.cpp
${OF_SRC_DIR}/app/ofAppNoWindow.cpp
${OF_SRC_DIR}/app/ofMainLoop.cpp
${OF_SRC_DIR}/app/ofAppGLFWWindow.cpp
${OF_SRC_DIR}/app/ofAppGlutWindow.cpp
${OF_SRC_DIR}/app/ofAppRunner.cpp
${OF_SRC_DIR}/app/ofBaseApp.cpp
${OF_SRC_DIR}/events/ofEvents.cpp
${OF_SRC_DIR}/sound/ofSoundBaseTypes.cpp
${OF_SRC_DIR}/sound/ofSoundBuffer.cpp
${OF_SRC_DIR}/sound/ofOpenALSoundPlayer.cpp
${OF_SRC_DIR}/sound/ofSoundPlayer.cpp
${OF_SRC_DIR}/sound/ofFmodSoundPlayer.cpp
${OF_SRC_DIR}/sound/ofRtAudioSoundStream.cpp
${OF_SRC_DIR}/sound/ofSoundStream.cpp
${OF_SRC_DIR}/math/ofMath.cpp
${OF_SRC_DIR}/math/ofMatrix3x3.cpp
${OF_SRC_DIR}/math/ofMatrix4x4.cpp
${OF_SRC_DIR}/math/ofQuaternion.cpp
${OF_SRC_DIR}/math/ofVec4f.cpp
${OF_SRC_DIR}/math/ofVec2f.cpp
${OF_SRC_DIR}/gl/ofMaterial.cpp
${OF_SRC_DIR}/gl/ofShader.cpp
${OF_SRC_DIR}/gl/ofLight.cpp
${OF_SRC_DIR}/gl/ofFbo.cpp
${OF_SRC_DIR}/gl/ofGLUtils.cpp
${OF_SRC_DIR}/gl/ofGLRenderer.cpp
${OF_SRC_DIR}/gl/ofTexture.cpp
${OF_SRC_DIR}/gl/ofVboMesh.cpp
${OF_SRC_DIR}/gl/ofBufferObject.cpp
${OF_SRC_DIR}/gl/ofVbo.cpp
${OF_SRC_DIR}/gl/ofGLProgrammableRenderer.cpp
${OF_SRC_DIR}/types/ofColor.cpp
${OF_SRC_DIR}/types/ofParameter.cpp
${OF_SRC_DIR}/types/ofParameterGroup.cpp
${OF_SRC_DIR}/types/ofRectangle.cpp
${OF_SRC_DIR}/types/ofBaseTypes.cpp
${OF_SRC_DIR}/3d/of3dUtils.cpp
${OF_SRC_DIR}/3d/ofNode.cpp
${OF_SRC_DIR}/3d/of3dPrimitives.cpp
${OF_SRC_DIR}/3d/ofCamera.cpp
${OF_SRC_DIR}/3d/ofEasyCam.cpp
)


set_property(TARGET openFrameworks PROPERTY CXX_STANDARD 14)
target_include_directories(openFrameworks PUBLIC
  /usr/include/cairo
  /usr/include/glib-2.0
  /usr/lib/x86_64-linux-gnu/glib-2.0/include
  /usr/include/pixman-1
  /usr/include/freetype2
  /usr/include/libpng16
  /usr/include/harfbuzz
  /usr/include/gstreamer-1.0
  /usr/include/orc-0.4
  /usr/include/AL
  /usr/include/rtaudio
  /usr/include/gtk-3.0
  /usr/include/pango-1.0
  /usr/include/fribidi
  /usr/include/gdk-pixbuf-2.0
  /usr/include/libmount
  /usr/include/blkid
  /usr/include/gio-unix-2.0
  /usr/include/atk-1.0
  /usr/include/at-spi2-atk/2.0
  /usr/include/dbus-1.0
  /usr/lib/dbus-1.0/include
  /usr/include/at-spi-2.0
  )

target_include_directories(openFrameworks PUBLIC
  ${OF_DIR}/libs/fmodex/include
  ${OF_DIR}/libs/glm/include
  ${OF_DIR}/libs/glm/include/glm
  ${OF_DIR}/libs/glm/include/glm/simd
  ${OF_DIR}/libs/glm/include/glm/gtx
  ${OF_DIR}/libs/glm/include/glm/gtc
  ${OF_DIR}/libs/glm/include/glm/ext
  ${OF_DIR}/libs/glm/include/glm/detail
  # ${OF_DIR}/libs/json/include
  ${OF_DIR}/libs/kiss/include
  ${OF_DIR}/libs/pugixml/include
  ${OF_DIR}/libs/tess2/include
  ${OF_DIR}/libs/utf8/include
  ${OF_DIR}/libs/utf8/include/utf8
  ${OF_SRC_DIR}
  ${OF_SRC_DIR}/utils
  ${OF_SRC_DIR}/graphics
  ${OF_SRC_DIR}/video
  ${OF_SRC_DIR}/communication
  ${OF_SRC_DIR}/app
  ${OF_SRC_DIR}/events
  ${OF_SRC_DIR}/sound
  ${OF_SRC_DIR}/math
  ${OF_SRC_DIR}/gl
  ${OF_SRC_DIR}/types
  ${OF_SRC_DIR}/3d
  )

target_compile_definitions(openFrameworks PUBLIC
  __LINUX_ALSA__
  __LINUX_PULSE__
  __UNIX_JACK__
  )

target_compile_definitions(openFrameworks PUBLIC
  GCC_HAS_REGEX
  OF_USING_GTK
  OF_USING_MPG123
  )

target_compile_definitions(openFrameworks PUBLIC
  _REENTRANT
  )

target_compile_options(openFrameworks PUBLIC
  "-pthread"
  )

target_link_directories(openFrameworks INTERFACE
  ${OF_DIR}/libs/fmodex/lib/linux64/
  )

target_link_libraries(openFrameworks INTERFACE
  fmodex
  ${OF_DIR}/libs/kiss/lib/linux64/libkiss.a
  ${OF_DIR}/libs/tess2/lib/linux64/libtess2.a
  gstapp-1.0
  gstvideo-1.0
  gstbase-1.0
  gstreamer-1.0
  udev
  fontconfig
  freetype
  sndfile
  openal
  curl
  glfw
  rtaudio
  jack
  pulse-simple
  pulse
  asound
  GLEW
  X11
  GLU
  GL
  gtk-3
  gdk-3
  z
  pangocairo-1.0
  pango-1.0
  harfbuzz
  atk-1.0
  cairo-gobject
  cairo
  gdk_pixbuf-2.0
  gio-2.0
  gobject-2.0
  glib-2.0
  mpg123
  glut
  X11
  Xrandr
  Xxf86vm
  Xi
  Xcursor
  dl
  pthread
  freeimage
  boost_filesystem
  boost_system
  pugixml
  uriparser
  Xinerama
  )

target_link_options(openFrameworks INTERFACE
  -Wl,--as-needed
  -Wl,--gc-sections
  -fuse-ld=gold
  )
# end of openframeworks

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 11)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/tools/antlr-4.9.1-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# CMake commands copied by the CMake file for CImg

# To use PKG_CHECK_MODULES to find some optional packages
find_package(PkgConfig)

# ### CIMG related stuff
# Flags to enable fast image display, using the XSHM library.
SET(CIMG_XSHM_CCFLAGS  -Dcimg_use_xshm)

# Flags to enable screen mode switching, using the XRandr library.
SET(CIMG_XRANDR_CCFLAGS  -Dcimg_use_xrandr)

# Flags to enable native support for JPEG image files, using the JPEG library.
# ( http://www.ijg.org/ )
SET(CIMG_JPEG_CCFLAGS  -Dcimg_use_jpeg)

# Flags to enable native support for TIFF image files, using the TIFF library.
# ( http://www.libtiff.org/ )
SET(CIMG_TIFF_CCFLAGS  -Dcimg_use_tiff)

# Flags to enable native support for PNG image files, using the PNG library.
# ( http://www.libpng.org/ )
SET(CIMG_PNG_CCFLAGS  -Dcimg_use_png)

#Flags to enable OPENCV support (Camera)
# ( http://www.opencv.org/ )
SET(CIMG_OPENCV_CCFLAGS-Dcimg_use_opencv)

# Flags to enable native support for EXR image files, using the OpenEXR library.
# ( http://www.openexr.com/ )
SET(CIMG_OPENEXR_CCFLAGS  -Dcimg_use_openexr)

# Flags to enable native support for various video files, using the FFMPEG library.
# ( http://www.ffmpeg.org/ )
SET(CIMG_FFMPEG_CCFLAGS  -Dcimg_use_ffmpeg)

# Flags to enable native support of most classical image file formats, using the Magick++ library.
# ( http://www.imagemagick.org/Magick++/ )
SET(CIMG_MAGICK_CCFLAGS -Dcimg_use_magick)

# Flags to enable faster Discrete Fourier Transform computation, using the FFTW3 library
# ( http://www.fftw.org/ )
SET(CIMG_FFTW3_CCFLAGS  -Dcimg_use_fftw3)

# ### Search Additional Libraries ##########
FIND_PACKAGE(OpenCV)
FIND_PACKAGE(JPEG)
FIND_PACKAGE(TIFF)
FIND_PACKAGE(PNG)
FIND_PACKAGE(ZLIB)
FIND_PACKAGE(LAPACK)
FIND_PACKAGE(BLAS)

PKG_CHECK_MODULES(FFTW3 fftw3)
PKG_CHECK_MODULES(OPENEXR OpenEXR)
PKG_CHECK_MODULES(MAGICK Magick++)

if(NOT WIN32)
  FIND_PACKAGE(X11)
  FIND_PACKAGE(Threads REQUIRED)
endif()

# #### End of additional libraries search ##########


### Configure Paths according to detected packages
if(TIFF_FOUND)
  get_filename_component(TIFF_LIB_DIRS ${TIFF_LIBRARIES} PATH)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_TIFF_CCFLAGS}")
  link_directories(${TIFF_LIB_DIRS})
  include_directories(${TIFF_INCLUDE_DIR})
  SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${TIFF_LIBRARIES})
endif()

if(JPEG_FOUND)
  get_filename_component(JPEG_LIB_DIRS ${JPEG_LIBRARIES} PATH)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_JPEG_CCFLAGS}")
  link_directories(${JPEG_LIB_DIRS})
  include_directories(${JPEG_INCLUDE_DIR})
  SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${JPEG_LIBRARIES})
endif()

if (ZLIB_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_ZLIB_CCFLAGS}")
  link_directories(${ZLIB_LIB_DIRS})
  include_directories(${ZLIB_INCLUDE_DIR})
  SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${ZLIB_LIBRARIES})

  # PNG requires ZLIB
  if(PNG_FOUND)
    SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_PNG_CCFLAGS}")
    link_directories(${PNG_LIB_DIRS})
    include_directories(${PNG_INCLUDE_DIR} )
    SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${PNG_LIBRARIES} )
  endif()
endif()

if(FFTW3_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_FFTW3_CCFLAGS}")
  link_directories( ${FFTW3_LIBRARY_DIRS} )
  include_directories( ${FFTW3_INCLUDE_DIRS} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${FFTW3_LIBRARIES} )
endif()

if(OPENEXR_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_OPENEXR_CCFLAGS}")
  link_directories( ${OPENEXR_LIBRARY_DIRS} )
  include_directories( ${OPENEXR_INCLUDE_DIRS} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${OPENEXR_LIBRARIES} )
endif()

if(MAGICK_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_MAGICK_CCFLAGS}")
  link_directories( ${MAGICK_LIBRARY_DIRS} )
  include_directories( ${MAGICK_INCLUDE_DIRS} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${MAGICK_LIBRARIES} )
endif()

if( LIBAVCODEC_FOUND  AND LIBAVFORMAT_FOUND AND LIBSWSCALE_FOUND AND LIBAVUTIL_FOUND )
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_FFMPEG_CCFLAGS}")
  link_directories( ${LIBAVFORMAT_LIBRARY_DIRS} )
  link_directories( ${LIBAVCODEC_LIBRARY_DIRS} )
  link_directories( ${LIBSWSCALE_LIBRARY_DIRS} )
  link_directories( ${LIBAVUTIL_LIBRARY_DIRS} )
  include_directories( ${LIBAVFORMAT_INCLUDE_DIRS} ${LIBAVFORMAT_INCLUDE_DIRS}/libavformat)
  include_directories( ${LIBAVCODEC_INCLUDE_DIRS} ${LIBAVCODEC_INCLUDE_DIRS}/libavcodec )
  include_directories( ${LIBSWSCALE_INCLUDE_DIRS} ${LIBSWSCALE_INCLUDE_DIRS}/libswscale)
  include_directories( ${LIBAVUTIL_INCLUDE_DIRS} ${LIBAVUTIL_INCLUDE_DIRS}/libavutil )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVFORMAT_LIBRARIES} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVCODEC_LIBRARIES} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBSWSCALE_LIBRARIES} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVUTIL_LIBRARIES} )
endif()

if(NOT APPLE)
  if(NOT WIN32)
    if(X11_FOUND)
      SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_XSHM_CCFLAGS} ${CIMG_XRANDR_CCFLAGS}")
      SET(SYSTEM_LIBS ${SYSTEM_LIBS} Xext Xrandr)
    endif()
  endif(NOT WIN32)
endif(NOT APPLE)

if(X11_FOUND)
  link_directories(${X11_LIB_DIRS})
  include_directories(${X11_INCLUDE_DIR})
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${X11_LIBRARIES} )
endif()

if (NOT WIN32)
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${CMAKE_THREAD_LIBS_INIT} )
endif()

if( WIN32)
  SET( SYSTEM_LIBS  ${SYSTEM_LIBS}  gdi32 )
endif()

if (OpenCV_FOUND)
  message("OpenCV Found")
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_OPENCV_CCFLAGS}")
  include_directories(${OpenCV_INCLUDE_DIRS})
  link_directories(${OpenCV_LIB_DIRS})
  SET( SYSTEM_LIBS  ${SYSTEM_LIBS}  ${OpenCV_LIBS} )
endif()

if(LAPACK_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_LAPACK_CCFLAGS}")
  link_directories( ${LAPACK_LIBRARY_DIRS} )
  include_directories( ${LAPACK_INCLUDE_DIRS} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LAPACK_LIBRARIES} )
endif()

if(BLAS_FOUND)
  SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_BLAS_CCFLAGS}")
  link_directories( ${BLAS_LIBRARY_DIRS} )
  include_directories( ${BLAS_INCLUDE_DIRS} )
  SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${BLAS_LIBRARIES} )
endif()

# Add CIMG Flags to Compilation Flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CIMG_CFLAGS}")

# CMake commands for this specific project start here

# to disable some warnings for CImg
if (NOT WIN32)
  set(CMAKE_CXX_FLAGS "-Wdeprecated -Wno-attributes" )
endif()

if (APPLE)
  set(CMAKE_CXX_FLAGS "-Wdeprecated -std=c++11" )
endif()

if (MSVC)
  set(CMAKE_CXX_FLAGS "/EHsc /wd4127 /wd4311 /wd4312 /wd4512 /wd4571 /wd4640 /wd4706 /wd4710 /wd4800 /wd4804 /wd4820 /wd4996")
endif()


# Call macro to add lexer and grammar to your build dependencies.
antlr_target(ProcessingGrammarLexer ProcessingLexer.g4 LEXER
            OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/)
antlr_target(ProcessingGrammarParser  ProcessingParser.g4 PARSER
             DEPENDS_ANTLR ProcessingGrammarLexer 
             COMPILE_FLAGS -lib ${PROJECT_SOURCE_DIR}/libs/
             OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/)
             
# add our project source directories
include_directories(${PROJECT_SOURCE_DIR}
					 ${PROJECT_SOURCE_DIR}/libs/
           /usr/include/libfswatch/c++
           /usr/include/libfswatch/c
  )
  

add_executable(prosecco antlr.cpp Scene.cpp ImageVisitor.cpp ofApp.cpp           
               ${ANTLR_ProcessingGrammarParser_CXX_OUTPUTS} ${ANTLR_ProcessingGrammarLexer_CXX_OUTPUTS})

#add_executable(prosecco antlr.cpp Scene.cpp ImageVisitor.cpp               
#               ${ANTLR_SceneGrammarParser_CXX_OUTPUTS})

# link required libraries
target_link_libraries(prosecco openFrameworks antlr4_static ${SYSTEM_LIBS})

# copy the input file next to the generated executable
add_custom_command(TARGET prosecco POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/*.pde"
  $<TARGET_FILE_DIR:prosecco>)

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally
if (WIN32)
add_custom_command(TARGET prosecco POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/*.pde"
  $<TARGET_FILE_DIR:prosecco>/../)
endif()

