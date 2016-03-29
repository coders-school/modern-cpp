#!/bin/bash
apt-get -y update
apt-get -y install clang-3.5 clang-format-3.5 clang-modernize-3.5
apt-get -y install cmake
apt-get -y install libboost-all-dev
apt-get -y install google-mock
apt-get -y install qtcreator
apt-get -y install binutils
apt-get -y install git
apt-get -y install htop
apt-get -y install linux-tools

#ustawienie 2 procesorow na maszynie
#uzytkownik: nokia, haslo: nokia
#instalacje odpalac jako root (haslo nokia)
#mozna zamontowac sobie katalog, bedzie sie znajdowal w /media/sf_*** - dostep jako root