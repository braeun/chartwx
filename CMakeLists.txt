cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(chartwx VERSION 0.1.0 LANGUAGES CXX)

# Forbid in-tree building
if(CMAKE_SOURCE_DIR MATCHES CMAKE_BINARY_DIR)
      message(STATUS "Please do an out-of-tree build:")
      message(STATUS "rm -f CMakeCache.txt && mkdir build && cd build; cmake .. && make")
      message(FATAL_ERROR "In-tree-build detected!")
endif()

include(CMakeDependentOption)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

# This setting is useful for providing JSON file used by CodeLite for code completion
#set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#-----------------------------------------------------------------------------
# BUILD SYSTEM
#-----------------------------------------------------------------------------

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)

include(CheckTypeSize)
check_type_size("int" SIZEOF_INT LANGUAGE CXX)
if (${SIZEOF_INT} LESS "4")
  message(FATAL_ERROR "int must be at least 32bit")
endif()


#-----------------------------------------------------------------------------
# DEPENDENCIES
#-----------------------------------------------------------------------------

# Specify search path for CMake modules to be loaded by include() and find_package()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# load the package to obtain information from pkgconfig
# ensure that packages etc. in /usr/local are found
# do NOT use CMAKE_PREFIX_PATH as it is used by qtcreator to select the Qt version
set(ENV{PKG_CONFIG_PATH} "${PKG_CONFIG_PATH}:/usr/local/lib/pkgconfig:/usr/local/lib64/pkgconfig")
find_package(PkgConfig REQUIRED)

find_package(wxWidgets COMPONENTS core base xrc xml REQUIRED)
if(wxWidgets_FOUND)
  include(${wxWidgets_USE_FILE})
endif()

# CMake config files
include(CMakePackageConfigHelpers)

find_package(Doxygen)

include(GNUInstallDirs)

#-----------------------------------------------------------------------------
# OPTIONS
#-----------------------------------------------------------------------------
# build options
#-----------------------------------------------------------------------------
CMAKE_DEPENDENT_OPTION(BUILD_DOCUMENTATION "build the documentation using doxygen" ON "DOXYGEN_FOUND" OFF)

#-----------------------------------------------------------------------------
# COMPILE DEFINITIONS
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# BUILD ALL COMPONENTS
#-----------------------------------------------------------------------------

add_subdirectory(src/chartwx)

add_subdirectory(src/samples)

#if (BUILD_DOCUMENTATION)
#  # doxygen settings can be set here, prefixed with "DOXYGEN_"
##  set(DOXYGEN_EXTRACT_PRIVATE YES)
#  set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/api-docs")
#  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
#  set(DOXYGEN_PROJECT_BRIEF "Charts for wxWidgets")

#  # this target will only be built if specifically asked to.
#  # run "make api-docs" to create the doxygen documentation
#  doxygen_add_docs(api-docs
#    src README.md
#    COMMENT "Generate API-documents for imca."
#  )
#endif()

#-----------------------------------------------------------------------------
# INSTALL
#-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------
# PACKAGE GENERATION
#-----------------------------------------------------------------------------

# generate a self-extracting archive using the modified template in the
# projects cmake directory

# first all variables must be set
set(CPACK_GENERATOR "STGZ")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT "Harald Braeuning")
set(CPACK_PACKAGE_VENDOR "GSI - Beam Instrumentation")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Charts for wxWidgets")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_PACKAGING_INSTALL_PREFIX "")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
#set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}.${CMAKE_SYSTEM_PROCESSOR}")

include(CPack)



