cmake_minimum_required(VERSION 3.8)
set(PROJECT_NAME nadaquote)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)

# Build Config
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-O2 -s -m64 -march=athlon64-sse3 -mtune=generic") # evtl. -fimplicit-constexpr -ffastmath
    add_subdirectory(libs)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Wpedantic")
else () # Debug build
    set(CMAKE_CXX_FLAGS "-g")
    add_subdirectory(libs)
    set(CMAKE_CXX_FLAGS "-g -Werror -Wall -Wextra -Wpedantic")
endif ()
add_subdirectory(libs/libnada)
add_subdirectory(libs/cpr) # requires libcurl / libssl-dev / libcurl4-openssl-dev
include_directories(libs/cpr/include)
find_package(SFML 2 REQUIRED graphics window system) # audio network
find_package(nlohmann_json REQUIRED)

if (UNIX)
    set(OS_BIBLIOTHEKEN OpenGL GL pthread stdc++fs)
elseif (WIN32)
    find_package(OpenGL REQUIRED)
    set(OS_BIBLIOTHEKEN ${OPENGL_LIBRARIES} stdc++fs ws2_32 winmm)
endif()
set(NADA_LINK_LIBRARIES nada bibliotheken cpr nlohmann_json::nlohmann_json sfml-graphics sfml-window sfml-system ${OS_BIBLIOTHEKEN})

message(STATUS "CMAKE_CXX_FLAGS=${CMAKE_CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/)
file(GLOB_RECURSE QUELLTEXT src/*.hpp src/*cpp)
#add_executable(${PROJECT_NAME} ${QUELLTEXT})
#target_link_libraries(${PROJECT_NAME} PRIVATE ${NADA_LINK_LIBRARIES})
#target_compile_options(${PROJECT_NAME} PRIVATE ${CMAKE_CXX_FLAGS})

file(GLOB_RECURSE TESTS test/*.cpp)
add_executable(${PROJECT_NAME}_test ${QUELLTEXT} ${TESTS})
target_compile_definitions(${PROJECT_NAME}_test PRIVATE UNITTEST=1)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${NADA_LINK_LIBRARIES} gcov)
target_compile_options(${PROJECT_NAME}_test PRIVATE -coverage)
