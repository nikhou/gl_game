cmake_minimum_required(VERSION 3.26)
project(gl_game)

cmake_policy(SET CMP0077 NEW)

include(FetchContent)

find_package(OpenGL)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

FetchContent_Declare(cJSON
	GIT_REPOSITORY https://github.com/DaveGamble/cJSON.git
	GIT_TAG master)

#prevent building libraries tests
set(ENABLE_CJSON_TEST OFF)
FetchContent_MakeAvailable(cJSON)

#I had some problems with headers file, so I included it manualny
include_directories(${cJSON_SOURCE_DIR})  

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME}
	OpenGL::GL
	glfw
	GLEW::GLEW
	cjson)

enable_testing()
add_subdirectory(test)
