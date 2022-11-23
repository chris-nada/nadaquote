# CMake Datei zur Erzeugung von ImGui als Library mit SFML im Backend.
cmake_minimum_required(VERSION 3.7)

project(bibliotheken)

# COPY imconfig-SFML.h zu imconfig.h
include_directories(imgui)
include_directories(implot)
include_directories(imgui-sfml)
include_directories(${SFML_DIR}/include)

add_library(bibliotheken STATIC
        imgui/imgui.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/misc/cpp/imgui_stdlib.cpp
        imgui-sfml/imgui-SFML.cpp
        implot/implot.cpp
        implot/implot_items.cpp
        )

        
target_include_directories(bibliotheken SYSTEM PUBLIC
    ${SFML_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/imgui
    ${CMAKE_CURRENT_LIST_DIR}/imgui-sfml
    ${CMAKE_CURRENT_LIST_DIR}/implot
    ${CMAKE_CURRENT_LIST_DIR}/doctest/doctest
    ${CMAKE_CURRENT_LIST_DIR}/cereal/include
    )

# Ueber Build Modus informieren
add_custom_command(TARGET bibliotheken PRE_BUILD COMMAND echo CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
