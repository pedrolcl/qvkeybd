# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(qvkeybd LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
if(QT_FEATURE_static)
    find_package(Qt6 REQUIRED COMPONENTS Svg)
endif()

qt_add_executable(${PROJECT_NAME}
    main.cpp
    mystyle/mystyle.qrc
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

# Resources:
set(demo_resource_files
    "Basic.qml"
    "basic-b2qt.qml"
    "content/AutoScroller.qml"
    "content/FloatingButton_Active.svg"
    "content/FloatingButton_Available.svg"
    "content/FloatingButton_Unavailable.svg"
    "content/HandwritingModeButton.qml"
    "content/TextArea.qml"
    "content/TextField.qml"
)

qt6_add_resources(${PROJECT_NAME} "demo"
    PREFIX
        "/"
    FILES
        ${demo_resource_files}
)

if(QT_FEATURE_static)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt::Svg
    )
    qt_import_plugins(${PROJECT_NAME}
        INCLUDE Qt::QVirtualKeyboardPlugin
    )
endif()

if(NOT QT_FEATURE_vkb_desktop)
    target_compile_definitions(${PROJECT_NAME} PUBLIC
        MAIN_QML="basic-b2qt.qml"
    )
endif()

if(QT_FEATURE_vkb_desktop)
    target_compile_definitions(${PROJECT_NAME} PUBLIC
        MAIN_QML="Basic.qml"
    )
endif()
