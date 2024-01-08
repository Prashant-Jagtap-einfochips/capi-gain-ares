#ifndef CAPI_GAIN_UTILS_H
#define CAPI_GAIN_UTILS_H
/* ======================================================================== */
/**
@file capi_gain_utils.h
   Header file to implement the capi gain module*/

/* =========================================================================
  Copyright (c) 2019-2021 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
  ========================================================================== */

/* =========================================================================
 * Edit History:
 * when         who         what, where, why
 * ----------   -------     -------------------------------------

   ========================================================================= */

/*------------------------------------------------------------------------
 * Include files
 * -----------------------------------------------------------------------*/
#ifndef CAPI_STANDALONE
#include "shared_lib_api.h"
#else
#include "capi_test_utils.h"
#endif

#include "gain_module_api.h"
//#include "../inc/capi_gain.h"
#include "../../lib/inc/gain_lib.h"

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

/*------------------------------------------------------------------------
 * Macros
 * -----------------------------------------------------------------------*/
// KPPS number for 8KHz sampling rate and mono channel
#define CAPI_GAIN_MODULE_MAX_OUT_PORTS 1
#define capi_gain_KPPS_8KHZ_MONO_CH 30
#define capi_gain_MAX_IN_PORTS 1
#define capi_gain_MAX_OUT_PORTS 1
#define Q13_UNITY_GAIN 0x2000

/********************************************** Bit Width Values ******************************************************/
/* Bit width (actual width of the sample in a word) */
#define BIT_WIDTH_16 16
#define BIT_WIDTH_24 24
#define BIT_WIDTH_32 32
/*********************************************************************************************************************/

static inline uint32_t gain_align_to_8_byte(const uint32_t num)
{
   return ((num + 7) & (0xFFFFFFF8));
}

/*------------------------------------------------------------------------
 * Structure definitions
 * -----------------------------------------------------------------------*/
/* Input/operating media format struct*/
typedef struct capi_gain_media_fmt_t
{
   capi_set_get_media_format_t    header;
   capi_standard_data_format_v2_t format;
   uint16_t                       channel_type[CAPI_MAX_CHANNELS_V2];
} capi_gain_media_fmt_t;

/* Struct to store current events info for the module*/
typedef struct capi_gain_events_info
{
   uint32_t enable;
   uint32_t kpps;
   uint32_t delay_in_us;
   uint32_t code_bw;
   uint32_t data_bw;
} capi_gain_events_info_t;

/* Struct to store gain module config*/
typedef struct capi_gain_configuration
{
   uint32_t enable;
   /* Gain in Q13 format, set in thie format*/
   uint16_t gain_q13;
   /* Gain stored in Q12 format t be sent to lib*/
   uint16_t gain_q12;
} capi_gain_configuration_t;

typedef struct capi_gain_t
{
   /* Function table for the gain module */
   capi_t vtbl;

   /* callback structure used to raise events to framework from the gain module*/
   capi_event_callback_info_t cb_info;

   /* heap id for gain module */
   capi_heap_id_t heap_info;

   /* Input/operating media format of the gain module*/
   capi_gain_media_fmt_t operating_media_fmt;

   /* Struct to store all info related to kpps, bandwidth and algorithmic delay*/
   capi_gain_events_info_t events_info;

   /* Struct to store gain configuration*/
   capi_gain_configuration_t gain_config;

} capi_gain_t;

#if defined(__cplusplus)
}
#endif // __cplusplus

/*------------------------------------------------------------------------
 * Function declarations
 * -----------------------------------------------------------------------*/
/* For all functions in capi_gain_utils being called from capi_gain*/

capi_err_t capi_gain_module_init_media_fmt_v2(capi_gain_media_fmt_t *media_fmt_ptr);

capi_err_t capi_gain_process_set_properties(capi_gain_t *me_ptr, capi_proplist_t *proplist_ptr);

capi_err_t capi_gain_process_get_properties(capi_gain_t *me_ptr, capi_proplist_t *proplist_ptr);

capi_err_t capi_gain_raise_events(capi_gain_t *me_ptr);

capi_err_t capi_gain_raise_process_event(capi_gain_t *me_ptr, uint32_t enable);

#endif // CAPI_GAIN_UTILS_H
