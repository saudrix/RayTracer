# Install script for directory: C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/ext/zlib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/lib/zlibstatic.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/build/x64-Debug (par défaut)/ext_build/zlib/zlibstatic.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/include/zconf.h;C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/include/zlib.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/include" TYPE FILE FILES
    "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/build/x64-Debug (par défaut)/ext_build/zlib/zconf.h"
    "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/ext/zlib/zlib.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/share/man/man3/zlib.3")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/share/man/man3" TYPE FILE FILES "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/ext/zlib/zlib.3")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/share/pkgconfig/zlib.pc")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/install/x64-Debug (par défaut)/share/pkgconfig" TYPE FILE FILES "C:/Users/Simon/Documents/Cours/3A/Prog3D/TD1_RayTraycing/mds3d_td1/out/build/x64-Debug (par défaut)/ext_build/zlib/zlib.pc")
endif()

