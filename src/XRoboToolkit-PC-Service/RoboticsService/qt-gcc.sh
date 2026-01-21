#!/bin/bash

# 기본값 설정
BUILD_NUM="0"
CLEAN_FLAG=false

# 인자 분석
for arg in "$@"
do
    if [ "$arg" == "--clean" ]; then
        CLEAN_FLAG=true
    elif [[ "$arg" =~ ^[0-9]+$ ]]; then
        BUILD_NUM="$arg"
    fi
done

echo "Target Build Number: $BUILD_NUM"
echo "Clean Build Enabled: $CLEAN_FLAG"

echo "set qt gcc compile env parameter..."
################################################################################
QT_GCC_64=/home/dyros/Qt/6.7.3/gcc_64
export QT6_TOOLS=/home/dyros/Qt/Tools
export PATH=$QT_GCC_64/bin:$QT6_TOOLS/CMake/bin:$QT6_TOOLS/Ninja:$PATH
export LD_LIBRARY_PATH=$QT_GCC_64/lib:$LD_LIBRARY_PATH
################################################################################

DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $DIR

PROJECT_DIR=$DIR
RELEASE_DIR=$DIR/RelWithDebInfo

# 빌드 디렉토리 생성
mkdir -p "$DIR/bin"
mkdir -p "$RELEASE_DIR"

# Clean 모드일 경우 기존 파일 삭제
if [ "$CLEAN_FLAG" = true ]; then
    echo "Cleaning build directories..."
    rm -rf "$DIR/bin/"* "$RELEASE_DIR/"*
fi

# CMake 구성 (Configure)
echo "Running CMake configuration..."
cmake -G "Ninja" -S "$PROJECT_DIR" -B "$RELEASE_DIR" \
      -DBUILD_LIB_PATH:STRING="$QT_GCC_64" \
      -DAUTO_BUILD_NUM:STRING="$BUILD_NUM" \
      -DCMAKE_BUILD_TYPE:STRING=RelWithDebInfo \
      -DCMAKE_PREFIX_PATH:PATH="$QT_GCC_64"

# 빌드 실행 (i9-12900H 20스레드 활용)
echo "Building with 20 threads..."
cmake --build "$RELEASE_DIR" --parallel 20

echo "Build completed."
