 cmake_minimum_required(VERSION 3.16)

project(RoboticsServiceProcess VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=1)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTORCC ON)


set(INSTALL_DIR ${PROJECT_SOURCE_DIR}/../bin)

set(EXECUTABLE_OUTPUT_PATH ${INSTALL_DIR})


set(CMAKE_IGNORE_PATH "/usr/local/bin;/usr/local/lib;/usr/local/include")


find_package(Qt6 REQUIRED COMPONENTS Core Network Core5Compat)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GRPC REQUIRED grpc++)

pkg_check_modules(PROTOBUF REQUIRED protobuf)


set(SOURCES main.cpp singleapplication.cpp singleapplication.h)

qt_add_executable(RoboticsServiceProcess ${SOURCES})



target_include_directories(RoboticsServiceProcess PUBLIC

    ../Business

    ../CommonUtils

    ../DeviceConnectionManager

    ../PXREAGRPCServer

    ../PXREAService/linux_x86

    ../PXREARobotSDK
)


target_link_libraries(RoboticsServiceProcess PRIVATE

    Qt6::Core Qt6::Network Qt6::Core5Compat

    PXREAGRPCServer 

    Business 

    CommonUtils 

    DeviceConnectionManager

    PXREARobotSDK

    /usr/lib/x86_64-linux-gnu/libgrpc++.so

    /usr/lib/x86_64-linux-gnu/libprotobuf.so.23

    /usr/lib/x86_64-linux-gnu/libgrpc++_reflection.so

    pthread dl

)


if(UNIX)

    # add_custom_command(TARGET RoboticsServiceProcess POST_BUILD
    # 
    #     COMMAND ${CMAKE_COMMAND} -E copy_directory 
    # 
    #     "${CMAKE_PREFIX_PATH}/lib" "${INSTALL_DIR}/lib"
    # 
    #     COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/../Redistributable/linux/setting.ini" "${INSTALL_DIR}/"
    # 
    # )

endif() 
