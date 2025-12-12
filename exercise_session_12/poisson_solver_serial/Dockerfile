FROM ubuntu:24.04

RUN apt-get update -q && \
    apt-get install -y -q --no-install-recommends \
    g++ make

COPY . /ex2b
WORKDIR /ex2b
ENV CC=g++

RUN make all CC=g++ CPPFLAGS="-O3 -ffast-math"

CMD ./main