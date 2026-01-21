cmake_minimum_required(VERSION 3.14)

project(PXREARobotSDK LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_host_system_information(RESULT ISA_NAME QUERY OS_PLATFORM)
message("OS_PLATFORM: ${ISA_NAME}")

# 설치 경로 설정
if(WIN32)
    set(INSTALL_DIR ${PROJECT_SOURCE_DIR}/../SDK/win/64)
else()
    if(ISA_NAME STREQUAL "aarch64")
        set(INSTALL_DIR ${PROJECT_SOURCE_DIR}/../SDK/linux_aarch64/64)
    else()
        set(INSTALL_DIR ${PROJECT_SOURCE_DIR}/../SDK/linux/64)
    endif()
endif()

add_compile_definitions(_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)

# -----------------------------------------------------------
# 종속성 패키지 찾기 (Ubuntu 표준 PkgConfig 사용)
# -----------------------------------------------------------
if(UNIX)
    find_package(Threads REQUIRED)
    find_package(PkgConfig REQUIRED)
    
    # pkg-config를 통해 grpc++와 protobuf 라이브러리 정보를 가져옵니다.
    pkg_check_modules(GRPC REQUIRED grpc++ grpc)
    pkg_check_modules(PROTOBUF REQUIRED protobuf)
endif()

# -----------------------------------------------------------
# 라이브러리 타겟 정의
# -----------------------------------------------------------
if(WIN32)
    add_definitions(-DPXREACLIENTSDK_LIBRARY)
    add_library(PXREARobotSDK SHARED
        ../PXREAService/PXREAService.grpc.pb.cc
        ../PXREAService/PXREAService.pb.cc
        ../PXREAService/PXREAService.grpc.pb.h
        ../PXREAService/PXREAService.pb.h
        PXREARobotSDK.cpp
        PXREARobotSDK.h
    )
    target_include_directories(PXREARobotSDK PUBLIC
        ../GrpcSDK/include
        ../PXREAService
    )
else()
    # Linux 환경
    if(ISA_NAME STREQUAL "aarch64")
        set(PROTO_PATH "../PXREAService/linux_aarch64")
    else()
        set(PROTO_PATH "../PXREAService/linux_x86")
    endif()

    add_library(PXREARobotSDK SHARED
        ${PROTO_PATH}/PXREAService.grpc.pb.cc
        ${PROTO_PATH}/PXREAService.pb.cc
        ${PROTO_PATH}/PXREAService.grpc.pb.h
        ${PROTO_PATH}/PXREAService.pb.h
        PXREARobotSDK.cpp
        PXREARobotSDK.h
    )

    # PkgConfig에서 찾아낸 시스템 헤더 경로를 명시적으로 추가합니다.
    target_include_directories(PXREARobotSDK PUBLIC
        ${PROTO_PATH}
        ${GRPC_INCLUDE_DIRS}
        ${PROTOBUF_INCLUDE_DIRS}
    )
endif()

# -----------------------------------------------------------
# 링크 설정
# -----------------------------------------------------------
if(WIN32)
    target_compile_definitions(PXREARobotSDK PUBLIC WINDOWS_x86)
    # Windows 링크 로직 (생략)
else()
    # Linux 링크 설정
    target_compile_definitions(PXREARobotSDK PUBLIC PXREAROBOTSDK_LIBRARY)
    if(ISA_NAME STREQUAL "aarch64")
        target_compile_definitions(PXREARobotSDK PUBLIC LINUX_aarch64)
    else()
        target_compile_definitions(PXREARobotSDK PUBLIC LINUX_x86)
    endif()

    # PkgConfig에서 찾아낸 라이브러리들을 링크합니다.
    target_link_libraries(PXREARobotSDK PUBLIC
        ${GRPC_LIBRARIES}
        ${PROTOBUF_LIBRARIES}
        Threads::Threads
        dl
    )

    # Post-build: 라이브러리 복사
    add_custom_command(TARGET PXREARobotSDK
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/libPXREARobotSDK.so" ${INSTALL_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/PXREARobotSDK.h" ${PROJECT_SOURCE_DIR}/../SDK/include/
    )
endif()
