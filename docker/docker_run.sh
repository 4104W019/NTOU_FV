#!/bin/bash

docker run -ti --rm --name=qttest_runtime \
           -v $(pwd)/../Homework:/root/Homework \
           --privileged \
           -v ~/.vim:/root/.vim \
           -v ~/.vimrc:/root/.vimrc \
           $(whoami)_qttest_workspace
