cmake_minimum_required(VERSION 3.0.2)
project(entt_example)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(thirdparty/godot-cpp/)

if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

set(SPACESHIP_SRC
    src/gdlibrary.cpp
    src/Entity.cpp
    src/EntityManager.cpp
)

set(BUILD_PATH ${CMAKE_SOURCE_DIR}/bin)

add_library(entt_example SHARED ${SPACESHIP_SRC})

target_link_libraries(entt_example ${GODOT_CPP_LIB} godot-cpp)

# create the library directly in the right folder
set_target_properties(entt_example PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
