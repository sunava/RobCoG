# Prerequisites:

* ubuntu 18.04
* docker
* kubernetes
* agones
* mongodb
* ROS
* swipl
* knowrob
* knowrob_ameva

## Docker

* from https://docs.docker.com/engine/install/ubuntu/

 
  * `$ sudo apt-get update && sudo apt-get install apt-transport-https ca-certificates curl gnupg lsb-release`
  * `$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg`
  * `$ echo \
  "deb [arch=amd64 signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null`
  * `$ sudo apt-get update && sudo apt-get install docker-ce docker-ce-cli containerd.io` 
  
## Kubernetes

* create cluster with `kubeadm` (https://kubernetes.io/docs/setup/production-environment/tools/kubeadm/create-cluster-kubeadm/):
 
 * 

## Agones

*

## MongoDB

* from https://docs.mongodb.com/manual/tutorial/install-mongodb-on-ubuntu/:

### libmongoc:

* from http://mongoc.org/libmongoc/current/installing.html

  * `$ sudo apt-get install libmongoc-1.0-0`

## ROS

* from https://wiki.ros.org/melodic/Installation/Ubuntu

 * `$ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'`
 * `$ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654`
 * `$ sudo apt update && sudo apt install ros-melodic-desktop`
 * `$ echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc`
 * `$ source ~/.bashrc`



## Prolog

* from https://www.swi-prolog.org/build/PPA.html:

  * `$ sudo apt-add-repository ppa:swi-prolog/stable`
  * `$ sudo apt-get update && sudo apt-get install swi-prolog`

  
## KnowRob

  * `$ sudo apt install python-rosdep2 python-wstool rosbash`
  * `$ cd ~ && mkdir catkin_ws && cd catkin_ws && rosdep update`
  * `$ wstool init src`
  * `$ cd src`
  * `$ wstool merge https://raw.github.com/knowrob/knowrob/master/rosinstall/knowrob-base.rosinstall`
  * `$ wstool update`
  * `$ rosdep install --ignore-src --from-paths .`
  * `$ cd ~/catkin_ws && catkin_make`
  * `$ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc`  
  * `$ source ~/.bashrc`

### knowrob_ameva

* websockets:

  * `$ sudo apt-get install libwebsockets-dev`

* protobuf (https://github.com/protocolbuffers/protobuf/blob/master/src/README.md):

  * `$ sudo apt-get install autoconf automake libtool curl make g++ unzip`
  * `$ cd ~ && mkdir thirdparty && cd thirdparty`
  * `$ git clone https://github.com/protocolbuffers/protobuf.git`
  * `$ cd protobuf`
  * `$ git submodule update --init --recursive`
  * `$ ./autogen.sh`
  * `$ ./configure`
  * `$ make`
  * `$ make check`
  * `$ sudo make install`
  * `$ sudo ldconfig`


* knowrob_ameva:

  * `$ cd ~/catkin_ws/src`
  * `$ git clone https://github.com/robcog-iai/knowrob_ameva.git`
  * `$ cd ~/catkin_ws && catkin_make knowrob_ameva`