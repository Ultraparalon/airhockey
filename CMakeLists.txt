project(airhockey)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(PROJECT_SRC)
file(GLOB PROJECT_SRC sources/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})
include_directories(includes)
include_directories(${SDL2_INCLUDE_DIRS}
					${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}	${SDL2_LIBRARIES}
										${SDL2_IMAGE_LIBRARIES})
