include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(example main.cpp)

TARGET_LINK_LIBRARIES (example PRIVATE opencas)
