# Install script for directory: /home/apostolis/Desktop/CppTrader

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
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/libcpptrader.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE STATIC_LIBRARY FILES "/home/apostolis/Desktop/CppTrader/libcpptrader.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-example-itch_handler")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-itch_handler")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-example-market_manager")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-market_manager")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-example-matching_engine")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-example-matching_engine")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-performance-itch_handler")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-itch_handler")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-performance-market_manager")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-performance-market_manager_optimized")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-performance-market_manager_optimized_aggressive")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-market_manager_optimized_aggressive")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-performance-matching_engine")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-performance-matching_engine")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/apostolis/Desktop/CppTrader/bin" TYPE EXECUTABLE FILES "/home/apostolis/Desktop/CppTrader/cpptrader-tests")
  if(EXISTS "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/apostolis/Desktop/CppTrader/bin/cpptrader-tests")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/apostolis/Desktop/CppTrader/modules/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/apostolis/Desktop/CppTrader/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
