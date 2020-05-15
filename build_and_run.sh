#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

readonly BUILD_DIR=cmake-build-release
readonly EXECUTABLE=EightPuzzle

function build() {
  cmake -H. -B${BUILD_DIR} -DCMAKE_BUILD_TYPE=Release
  make -C ${BUILD_DIR}
}

function run() {
  cd ${BUILD_DIR}
  ./${EXECUTABLE}
}

build
run
