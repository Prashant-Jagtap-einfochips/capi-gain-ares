This example will work with following installations
1. Install Qualcomm Package Manager 3
2. Install Hexagon sdk Version 5.4.0.3
3. Install  Audio1x Version 2.0.0.0


Build Steps:
Build gain module:
1. cd /capi-ares/capi-decimate-ares
2. mkdir build
3. cmake -DCMAKE_C_COMPILER="<SDK 5.4.0.3 PATH>/tools/HEXAGON_Tools/8.7.03/Tools/bin/hexagon-clang" ..
4. cmake --build .

Signing process:
1. python <SDK 5.4.0.3 PATH>/utils/scripts/signer.py sign -t <Device Serial No.> -d adsp -i libcapi_gain.so

Steps to be followed on device for testing of modules
1. reset
2. Connnect to the COM port of device and enter following commands
	- mq
	- audio_service -f /ifs/etc/lpass_cfg
	- mount -uw /mnt
	
3. Push acdb files at /mnt/etc/acdb/adp_8295 
4. Push .so files of data module at /mnt/etc/images/dsp
5. Reset device using "reset" command
6. Start Playback - audio_chime -g 21 <wav file path>
7. Connect to device using QACT 8.0.33 
8. Enable data module through QACT tool
9. Change other parameters of data module to check that data module is working properly
10. If the the QXDM(v5.2.510) dumps are taken then use QCAT v7.01.192 
