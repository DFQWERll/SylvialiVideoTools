cmake_minimum_required(VERSION 3.5)

#set(CMAKE_OSX_DEPLOYMENT_TARGET "11.3")

project(SylvialiVideoTools LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE ON  )


find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(SylvialiVideoTools SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(SylvialiVideoTools
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
endif()

##设置ffmpeg头文件和库路径
set(FFMPEG_PREFIX_PATH ./External/FFMPEG/x86_64)
include_directories(
       ${FFMPEG_PREFIX_PATH}/include/
)
FIND_LIBRARY(AVUTIL_LIBRARY1 avutil  ${FFMPEG_PREFIX_PATH}/lib)
target_link_libraries(SylvialiVideoTools PRIVATE  Qt5::Widgets
    ${AVUTIL_LIBRARY1})


##直接引入需要将pc文件中的-framewoek删除掉
#set(PKG_CONFIG_EXECUTABLE "/opt/homebrew/bin/pkg-config")
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(ffmpeg REQUIRED IMPORTED_TARGET  libavutil)

#target_link_libraries(SylvialiVideoTools PRIVATE  Qt5::Widgets
#   PkgConfig::ffmpeg)

#message("lhg --- ${PKG_CONFIG_PATH}")

