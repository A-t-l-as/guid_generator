cmake_minimum_required(VERSION 3.16)

project(GuidGenerator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GuidGenerator main.cpp
)

target_include_directories(GuidGenerator PRIVATE
    ../KsUtils
    ../KsUtils/src
)

target_link_libraries(GuidGenerator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../KsUtils/build/Desktop_Qt_6_9_3_MinGW_64_bit-Release/libKsUtils.a
)

include(GNUInstallDirs)
install(TARGETS GuidGenerator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
