
add_executable(sample1
  sample1.cpp sample1.h
)
target_include_directories(sample1 PUBLIC
    PRIVATE
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>"
    "$<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
target_link_libraries(sample1
  PUBLIC chartwx
  ${wxWidgets_LIBRARIES}
)

