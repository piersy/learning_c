# This cmake lists is used to configure and build
# the third party project defined in CMakeLists.txt.in
# during the normal cmake configure stage. This makes the 
# build stage quicker, avoids accessing the internet when
# building and allows us to depend on the third party 
# project (google test) as if it was a local project.
project(googletest-inst NONE)
message(bindir_${CMAKE_BINARY_DIR}/googletest-download)

# Copies the file into the build-dir under googletest-download
configure_file(CMakeLists.txt.in
               ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)

# cmake the project
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# build the project which results in a download and build of the source.
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# Add the include directories this makes headers from
# gtest available as "gtest/getst.h"
include_directories("${gtest_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}/include")
