Steps to Build the Capi Gain Shared Object:

1. Create a "build" folder in parallel to CMakeLists.txt

2. cmake -DCMAKE_C_COMPILER="/home/einfochips/Qualcomm/5.4.0.3/tools/HEXAGON_Tools/8.7.03/Tools/bin/hexagon-clang" ..

3. cmake --build .

4. python signer.py -t <QNX Serial No.> -d adsp -i libcapi_gain.so -o <Output Folder Name>

5. Push the shared library at: /mnt/etc/images/dsp

6. Push ACDB files at: /mnt/etc/acdb/adp_8295