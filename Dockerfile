FROM --platform=linux/amd64 ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive
RUN apt update
RUN apt -y install build-essential wget nano gdb
RUN apt -y install vim
