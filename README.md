## 🚀 How to Compile & Run
This program scan  open port on your target host.

To compile the project, use the provided script:

```bash
chmod +x compile.sh
sudo ./compile.sh
```
Or manually:

  Requirements:
  
  1- C compiler (like gcc)
  

  Install these according to your package manager, for example for Debian based systems with root privilege:

  ```bash
    apt-get install -y gcc
  ```
  After gcc compiler (or any c compiler) are fully installed, it is time to compile the port_scanner.c file:
  
  To do this, enter:
  ```bash
  gcc port_scanner.c -o port_scanner
  ```


After compiling, the (port_scanner) executable file is ready for you.
To create a (port_scanner) code, run the (port_scanner) program and execute the following commands (which are also in the program's usage):

```bash
./port_scanner <target-ip>
```
This program displays all open port numbers on the target-ip host on the screen (STDOUT).

for example:
```bash
./QRdecoder 192.168.1.1
```
To access this scanner file from anywhere, you can add the executable file (port_scanner) to your shell PATH.

The purpose of this program release is to understand how to program a Basic Port scanner with C.
## Mehmet Lotfi
## Youtube  Channel : @Khorshid_Computer
## Telegram Channel : @Source_Code_Store