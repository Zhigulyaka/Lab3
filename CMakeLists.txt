cmake_minimum_required(VERSION 2.8) #�������� ������ CMake.

set(PROJECT_NAME Lab3) #������� ������� ��������� ���������� � ������ �������
project(${PROJECT_NAME}) # �������� �������


set(stacklib stacklib) #���������� � ������ ����������
set(test test) #���������� ��������� ����������
set(gtest gtest) #���������� � ������ ���������� Google Tests

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #��������� ���������� CMAKE_CONFIGURATION_TYPES �� ��������� "Debug;Release" � ������/�������� Configs, ���������� ����������� � ����������� ����� ��������� �� ���� ������,
if(NOT CMAKE_BUILD_TYPE) # �������� ��������� � ����������� ��������� ������
  set(CMAKE_BUILD_TYPE Release) #���� ��� �� ������������� Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklib) #��������� ���������� "${CMAKE_CURRENT_SOURCE_DIR}/stacklib" � ����������� �������� ���������� ������
#${CMAKE_CURRENT_SOURCE_DIR} - ����������� ���������� � ������� ������� ����������


add_subdirectory(stacklib)
add_subdirectory(test)
add_subdirectory(gtest)

#file(GLOB hdrs "*.h*") #��������� � ���������� hdrs ��� ����� � ����������� .h
#file(GLOB srcs "*.cpp") #��������� � ���������� srcs ��� ����� � ����������� .cpp

#include_directories(lib1)
#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #������� ������ � ������ �� ���������� ${PROJECT_NAME}, � ���� ����������� ����� �� ���������� ${srcs} � ${hdrs}


 #�������� ������ � ������������� lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #���������� � ������� � ������ ${PROJECT_NAME} ���������� � ������ ${MyLib1}