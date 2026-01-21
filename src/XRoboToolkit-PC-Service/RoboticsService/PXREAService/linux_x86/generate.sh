#!/bin/bash
echo "start generate proto..."

# 실제 확인된 경로로 설정
PROTOC_BIN=/usr/local/bin/protoc
GRPC_PLUGIN_BIN=/usr/bin/grpc_cpp_plugin

# 기존 파일 삭제
rm -f *.pb.h *.pb.cc *.grpc.pb.h *.grpc.pb.cc

# 파일 재생성
$PROTOC_BIN --cpp_out=. PXREAService.proto
$PROTOC_BIN --grpc_out=. --plugin=protoc-gen-grpc=$GRPC_PLUGIN_BIN PXREAService.proto

echo "done."
