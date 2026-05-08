cmake_minimum_required(VERSION 3.16)
project(zombies)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SFML_USE_SYSTEM_DEPS ON)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

add_executable(zombies MACOSX_BUNDLE src/main.cpp)

target_link_libraries(zombies PRIVATE
  SFML::Graphics
  SFML::Window
  SFML::System
  "-framework Cocoa"
)

set_target_properties(zombies PROPERTIES
    MACOSX_BUNDLE TRUE
    BUILD_RPATH "${CMAKE_BINARY_DIR}/_deps/sfml-build/lib"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

