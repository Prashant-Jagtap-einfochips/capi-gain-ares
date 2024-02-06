cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(capi_gain)

set(CMAKE_C_COMPILER "/home/einfochips/Qualcomm/5.4.0.3/tools/HEXAGON_Tools/8.7.03/Tools/bin/hexagon-clang")

#set(CMAKE_CXX_COMPILER "/home/einfochips/Qualcomm/5.4.0.3/tools/HEXAGON_Tools/8.7.03/Tools/bin/hexagon-clang++")

#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -W -fPIC -Wunused-parameter" )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mv68 -G0 -O2 -Wstrict-prototypes -fno-strict-aliasing -fno-zero-initialized-in-bss -fdata-sections -Wall -W -fPIC -Wunused-parameter" )


include_directories(
	"/home/einfochips/Qualcomm/5.4.0.3/incs"
	"/home/einfochips/Qualcomm/5.4.0.3/incs/stddef"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/api/ar_utils"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/api/ar_utils/hexagon/sim"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/gpr/platform/qurt/osal/api"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/spf/interfaces/module/capi"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/spf/interfaces/module/capi/adv"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/spf/interfaces/module/metadata/api"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/api/modules"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/api/apm"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/examples/decimate_tx_rx/inc/test_capi/inc"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/spf/interfaces/module/shared_lib_api/inc"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/platform/posal/inc"
	"/home/einfochips/Qualcomm/5.4.0.3/addons/audio/spf/incs/platform/posal/inc/hexagon"
	"./api"
	"./capi/inc"
	"./capi/src"
	)

add_library(capi_gain
	SHARED
	capi/src/capi_gain.c
	capi/src/capi_gain_utils.c
	lib/src/gain_lib.c
	)

