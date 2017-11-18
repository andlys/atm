# Install script for directory: /Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-config.cmake"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-config-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake"
         "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt/fmt-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt/CMakeFiles/Export/lib/cmake/fmt/fmt-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/fmt" TYPE FILE FILES "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt/CMakeFiles/Export/lib/cmake/fmt/fmt-targets-release.cmake")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt/libfmt.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfmt.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfmt.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfmt.a")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/fmt" TYPE FILE FILES
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/container.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/format.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/format.cc"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/ostream.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/ostream.cc"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/printf.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/printf.cc"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/string.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/time.h"
    "/Users/denysmelnychenko/Documents/C++/MOOP/atm/atm/lib/fmt-4.0.0/fmt/posix.h"
    )
endif()

