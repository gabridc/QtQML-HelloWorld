cmake_minimum_required(VERSION 3.1.0)

if(LINUX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

if(WIN)
    set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
endif()

project(Broker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(LINUX)
    set(Qt5Core_VERSION "5.15")
    set(CMAKE_MODULE_PATH "~/Qt/5.15.2")
    set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
    set(Qt5_DIR "~/Qt/5.15.2/")
endif()

if(WIN)
    set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5")
    set(Qt5_DIR "D:/Qt/5.15.2/mingw81_64/bin")
    set(Qt5Core_VERSION "5.15")
    set(Qt5Qml_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Qml")
    set(Qt5Network_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Network")
    set(Qt5Core_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Core")
    set(Qt5Quick_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Quick")
    set(Qt5QmlModels_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5QmlModels")
    set(Qt5Gui_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Gui")
    set(Qt5Widgets_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Widgets")
    set(Qt5Sql_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Sql")
    set(Qt5NetworkAuth_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5NetworkAuth")    
endif()

if(ANDROID)
    set(ANDROID_ABIS "armeabi-v7a")
    #set(ANDROID_ABIS "arm64-v8a")
    set(ANDROID_ARM_NEON "ON")
    set(Qt5Core_VERSION "5.15")
    set(CMAKE_MODULE_PATH "~/Qt/5.15.2")
    set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/android/lib/cmake/Qt5")
    set(Qt5_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5")
    set(Qt5Qml_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Qml")
    set(Qt5Network_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Network")
    set(Qt5Core_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Core")
    set(Qt5Quick_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Quick")
    set(Qt5QmlModels_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5QmlModels")
    set(Qt5Gui_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Gui")
    set(Qt5Widgets_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Widgets")
    set(Qt5Sql_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Sql")
    set(Qt5NetworkAuth_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5NetworkAuth")
endif()

find_package(Qt5 REQUIRED COMPONENTS Qml Quick Widgets)

include_directories(D:/Qt/5.15.2/mingw81_64/include/)
include_directories(D:/Qt/5.15.2/mingw81_64/include/QtWidgets)
include_directories(.)

qt5_add_resources(RESOURCES qml.qrc)

if(ANDROID)
    add_library(Hello SHARED
            main.cpp
            Hello.cpp
            Hello.h
            ${RESOURCES})
else()
add_executable(Hello
        main.cpp
        Hello.cpp 
        Hello.h
        ${RESOURCES})
endif()

if(LINUX)
    target_link_libraries(Hello Qt5::Quick Qt5::Qml Qt5::Widgets)
endif()

if(ANDROID)
    target_link_libraries(Hello Qt5::Quick Qt5::Qml  Qt5::Widgets)
endif()


if(WIN)
target_link_libraries(Hello Qt5::Quick Qt5::Qml Qt5::Widgets)
endif()