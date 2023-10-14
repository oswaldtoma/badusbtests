# Install script for directory: C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/UnitTest++")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/Debug/UnitTest++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/Release/UnitTest++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/MinSizeRel/UnitTest++.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/RelWithDebInfo/UnitTest++.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++" TYPE FILE FILES
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/AssertException.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/CheckMacros.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/Checks.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/CompositeTestReporter.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/Config.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/CurrentTest.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/DeferredTestReporter.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/DeferredTestResult.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/ExceptionMacros.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/ExecuteTest.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/HelperMacros.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/MemoryOutStream.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/ReportAssert.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/ReportAssertImpl.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/RequireMacros.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/RequiredCheckException.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/RequiredCheckTestReporter.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/Test.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestDetails.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestList.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestMacros.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestReporter.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestReporterStdout.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestResults.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestRunner.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TestSuite.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/ThrowingTestReporter.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TimeConstraint.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/TimeHelpers.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/UnitTest++.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/UnitTestPP.h"
    "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/XmlTestReporter.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/UnitTest++/Win32" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/UnitTest++/Win32/TimeHelpers.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/cmake/UnitTest++Config.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++/UnitTest++Targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++/UnitTest++Targets.cmake"
         "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++/UnitTest++Targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++/UnitTest++Targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets-debug.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets-minsizerel.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets-relwithdebinfo.cmake")
  endif()
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/UnitTest++" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/CMakeFiles/Export/37e4fcdf626b15f9de5e86725392a6d9/UnitTest++Targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/UnitTest++/lib/pkgconfig/UnitTest++.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/UnitTest++/lib/pkgconfig" TYPE FILE FILES "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/UnitTest++.pc")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Oswald/source/repos/BadUSB3/BadUSBTests/unittest-cpp-2.0.0/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
