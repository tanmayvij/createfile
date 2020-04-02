# CREATEFILE PROGRAM
### Create large test files on your Windows or Linux server instantly for testing download and transfer speeds.

#### Compile:
g++ createfile.cpp -o createfile (Linux)

g++ createfile.cpp -o createfile.exe (Windows)

*You can use your favorite compiler on Windows if you don't have g++ installed.*

#### Usage:

createfile [file-name] [size] [optional: number system]

*Default number system is binary.*

#### Examples:

createfile test.bin 100M binary

The above command creates a file named test.bin in the current directory with a size of 100 MebiBytes (Binary, multiplier of 2^10)

To create a file of size 1 GigaByte (Decimal), use:

createfile hello.bin 1G decimal (Creates a file of size 1,000,000,000 bytes)

##### Supported Units:
* B (Bytes)
* K (KibiBytes/KiloBytes)
* M (MebiBytes/MegaBytes)
* G (GibiBytes/GigaBytes)

*Please note that a maximum of only 3 digits may be used to specify the size. Using more than 3 digits may result in unexpected errors.*

Example:

* 10240M (Incorrect)
* 10G (Correct)