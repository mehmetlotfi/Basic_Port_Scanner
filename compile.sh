#!/bin/bash
if [ "$EUID" -ne 0 ]; then
  echo "Please run this script as root privilege (use sudo)."
  exit 1
fi

if command -v apt &> /dev/null; then
  apt update
  apt install -y gcc
elif command -v yum &> /dev/null; then
  yum install -y gcc
elif command -v pacman &> /dev/null; then
  pacman -Sy --noconfirm gcc
else
  echo "Unsupported package manager. Please install dependencies manually. (gcc)"
  exit 1
fi
clear
gcc port_scanner.c -o port_scanner

if [ $? -eq 0 ]; then
  echo "Compilation successful. Executable 'port_scanner' created."
else
  echo "Compilation failed."
  exit 1
fi
echo "good luck"
echo "mehmet lotfi"
echo "github.com/mehmetlotfi"