# <docker> build -t e2node_tester:latest .
from ubuntu:20.04

# setup the container
RUN export DEBIAN_FRONTEND=noninteractive && apt-get  update 
RUN export DEBIAN_FRONTEND=noninteractive && \
	apt-get install -y build-essential cmake googletest \
	googletest-tools libgmock-dev libgtest-dev \
	libyaml-cpp-dev valgrind gcovr libsctp1 libsctp-dev

RUN mkdir /build
WORKDIR /build
COPY entrypoint.sh /
CMD /entrypoint.sh
# copy the script
# set the script to execute
