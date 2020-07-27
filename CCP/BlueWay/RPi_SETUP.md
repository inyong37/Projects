### 2017 Raspbian은 RPi 3B+에서 작동 안됨.
### 2018 Raspbian은 RPi 3B에서 작동 됨.

# SWAP
$ df
$ free -h
$ sudo /etc/init.d/dphys-swapfile stop
$ sudo nano /etc/dphys-swapfile
CONF_SWAPSIZE = 4096
$ sudo /etc/init.d/dphys-swapfile start
$ df
$ free -h

# FFMPEG
# https://m.blog.naver.com/PostView.nhn?blogId=chandong83&logNo=220851288433&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
$ git clone https://github.com/FFmpeg/FFmpeg.git
$ cd FFmpeg
$ sudo ./configure --arch=armel --target-os=linux --enable-gpl --enable-libx264 --enable-nonfree
$ make -j4
$ sudo make install

# DOCKER
# https://medium.freecodecamp.org/the-easy-way-to-set-up-docker-on-a-raspberry-pi-7d24ced073ef
$ curl -fsSL get.docker.com -o get-docker.sh && sh get-docker.sh
$ sudo groupadd docker
$ sudo gpasswd -a $USER docker
$ docker run hello-world

# TENSORFLOW 1
# https://m.blog.naver.com/PostView.nhn?blogId=chandong83&logNo=221334936927&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
$ sudo apt install libatlas-base-dev
$ pip3 install tensorflow
$ sudo apt-get install python3-matplotlib

# TENSORFLOW 2
# https://www.tensorflow.org/install/source_rpi
$ sudo apt install libatlas-base-dev
$ sudo CI_DOCKER_EXTRA_PARAMS="-e CI_BUILD_PYTHON=python3 -e CROSSTOOL_PYTHON_INCLUDE_PATH=/usr/include/python3.4" \
    tensorflow/tools/ci_build/ci_build.sh PI-PYTHON3 \
    tensorflow/tools/ci_build/pi/build_raspberry_pi.sh
$ sudo tensorflow/tools/ci_build/ci_build.sh PI \
    tensorflow/tools/ci_build/pi/build_raspberry_pi.sh PI_ONE
$ pip install tensorflow-version-cp34-none-linux_armv7l.whl

# REFERENCE
# https://www.raspberrypi.org/forums/viewtopic.php?p=1312517 밑에서 3번째, 4번째
$ sudo apt install libqt4-test
$ sudo apt install libatlas3-base libsz2 libharfbuzz0b libtiff5 libjasper1 libilmbase12 libopenexr22 libilmbase12 libgstreamer1.0-0 libavcodec57 libavformat57 libavutil55 libswscale4 libqtgui4 libqt4-test libqtcore4
$ pip3 install opencv-python
$ sudo pip3 install opencv-contrib-python libwebp6
