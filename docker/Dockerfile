FROM ubuntu:18.04

MAINTAINER Joe Yang

# configure time zone
ENV TZ=Asia/Taipei
RUN ln -snf /use/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# prepare utils
RUN apt-get update -y
RUN apt-get install -y vim htop git curl net-tools iputils-ping && \
    apt-get install -y zip unzip wget
RUN apt-get install -y build-essential qt5-default qt5-qmake

# install python env
RUN apt-get install -y python3 python3-dev python3-pip

# upgrade pip3
RUN pip3 install --upgrade pip

# install python lib
RUN pip3 install gcovr

WORKDIR /root

RUN rm -rf /var/lib/apt/lists/*

CMD /bin/bash
