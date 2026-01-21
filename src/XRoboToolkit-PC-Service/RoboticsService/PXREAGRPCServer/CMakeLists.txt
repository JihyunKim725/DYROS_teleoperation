cmake_minimum_required(VERSION 3.16)
project(PXREAGRPCServer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)

# [핵심] /usr/local 경로의 간섭을 차단하기 위한 설정
set(CMAKE_IGNORE_PATH "/usr/local/bin;/usr/local/lib;/usr/local/include")

find_package(Qt6 REQUIRED COMPONENTS Core Core5Compat Network)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GRPC REQUIRED grpc++)
pkg_check_modules(PROTOBUF REQUIRED protobuf)

set(PROTO_SRC_DIR "../PXREAService/linux_x86")

qt_add_library(PXREAGRPCServer SHARED
    ${PROTO_SRC_DIR}/PXREAService.grpc.pb.cc
    ${PROTO_SRC_DIR}/PXREAService.pb.cc
    FeedbackController.h
    FeedbackController.cpp
    PXREAGRPCServer.h
    PXREAGRPCServer.cpp
)


target_include_directories(PXREAGRPCServer PUBLIC 
    ${PROTO_SRC_DIR}
    ../Business
    ../DeviceConnectionManager
)

# 시스템 라이브러리(.so.23)와 절대 경로로 링크하여 버전 혼선 방지
target_link_libraries(PXREAGRPCServer PUBLIC 
    Qt6::Core Qt6::Core5Compat Qt6::Network
    /usr/lib/x86_64-linux-gnu/libgrpc++.so
    /usr/lib/x86_64-linux-gnu/libgrpc.so
    /usr/lib/x86_64-linux-gnu/libgpr.so
    /usr/lib/x86_64-linux-gnu/libprotobuf.so.23
    /usr/lib/x86_64-linux-gnu/libgrpc++_reflection.so
    pthread dl
)
