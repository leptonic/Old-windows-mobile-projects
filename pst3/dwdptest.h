/**
 *       Copyright (C) Infineon Techonologies Denmark A/S. All rights reserved.
 *
 * This document contains proprietary information belonging to Infineon Techonologies Denmark A/S.
 * Passing on and copying of this document, use and communication
 * of its contents is not permitted without prior written authorisation.
 *
 * Description:  This files contains the interface description for
* production test dll for all the DWD platform.
 *
 * Revision Information:
 *   File name: \dwdsrc_int\DWDIO_MULTIBAND\Src\dwdptest.h
 *   Version: \main\53
 *   Date: 2006-09-08 10:05:44
 *   Comment:
 *     dwdio.dll v25.0-
 *     Mature OnlineMode
 *     New generic function added to PC3, Customer, XDRV, OSC.
 *     See release note for more details.
 */

/* Defines for 16 bit and 32 bit integers: */
#ifndef DwdptestH
#define DwdptestH

#ifdef __BORLANDC__	
#define DWD_HINSTANCE HINSTANCE
#else
#define DWD_HINSTANCE  unsigned int
#endif

#define int16 short int
#define int32 int
#define Bool unsigned char
#define UINT8 unsigned char
#define SINT8 signed char
#define SINT16 signed short int
#define UINT16 unsigned short int
#define SINT32 signed int
#define UINT32 unsigned int

#define DLL_HANDLE 2


#define DWD_SET_IF_FREQ_1696MHZ(handle) DWD_set_rf_channel(  dwd_tx_arfcn_tp, 512, handle )
#define DWD_SET_IF_FREQ_1712MHZ(handle) DWD_set_rf_channel(  dwd_tx_arfcn_tp, 790, handle )

#define DWD_RTC_TIME_STRING_LENGTH 8
#define DWD_RTC_DATE_STRING_LENGTH 10

/*---------------------------------------------*/
#define MMI_GREETING_TEXT_LENGTH	32

/*---------------------------------------------*/
/* Enumerations and types                      */
/*---------------------------------------------*/
#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_gsm_900,
  dwd_dcs_1800,
  dwd_gsm_850,
  dwd_pcs_1900
}dwd_rf_band_type;

#else
enum dwd_rf_band
{
  dwd_gsm_900,
  dwd_dcs_1800,
  dwd_gsm_850,
  dwd_pcs_1900
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_900_1800 = 0,
  dwd_850_1900,
  dwd_900_1800_1900,
  dwd_850_900_1800_1900,
  dwd_850_1800_1900
}dwd_rf_bands_support;
#else
enum dwd_rf_bands_support
{
  dwd_900_1800 = 0,
  dwd_850_1900,
  dwd_900_1800_1900,
  dwd_850_900_1800_1900,
  dwd_850_1800_1900
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_error,
  dwd_ok
}dwd_result_codes;

#else
enum dwd_result_codes
{
  dwd_error,
  dwd_ok
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_in_line_mode,
  dwd_calib_mode,
  dwd_mmi_mode
}dwd_test_modes_type;

#else
enum dwd_test_modes
{
  dwd_in_line_mode,
  dwd_calib_mode,
  dwd_mmi_mode
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_rx_cont,
  dwd_tx_cont,
  dwd_rx_burst,
  dwd_tx_burst,
  dwd_mon_burst,
  dwd_rxtxmon,
  dwd_stop,
  dwd_tx_calib_gmsk,
  dwd_tx_calib_edge,
  dwd_rx_calib,
  dwd_adc_calib
}dwd_rf_modes_type;
#else
enum dwd_rf_modes
{
  dwd_rx_cont,
  dwd_tx_cont,
  dwd_rx_burst,
  dwd_tx_burst,
  dwd_mon_burst,
  dwd_rxtxmon,
  dwd_stop,
  dwd_tx_calib_gmsk,
  dwd_tx_calib_edge,
  dwd_rx_calib,
  dwd_adc_calib
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_rx_arfcn_tp,
  dwd_tx_arfcn_tp,
  dwd_mon_arfcn_tp
}dwd_arfcn_tps_type;

#else
enum dwd_arfcn_tps
{
  dwd_rx_arfcn_tp,
  dwd_tx_arfcn_tp,
  dwd_mon_arfcn_tp
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_rx_gain_tp,
  dwd_mon_gain_tp,
  dwd_rx_2_gain_tp,
  dwd_rx_3_gain_tp,
  dwd_rx_4_gain_tp
}dwd_gain_tps_type;
#else
enum dwd_gain_tps
{
  dwd_rx_gain_tp,
  dwd_mon_gain_tp,
  dwd_rx_2_gain_tp,
  dwd_rx_3_gain_tp,
  dwd_rx_4_gain_tp
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_external_pa_ramp,
  dwd_internal_pa_ramp
}dwd_ramp_mode_type;
#else
enum dwd_ramp_mode
{
  dwd_external_pa_ramp,
  dwd_internal_pa_ramp
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
   dwd_high   /* all ones*/,
   dwd_random /* all random*/,
   dwd_normal /*normal burst including training sequence*/,
   dwd_edge_high,
   dwd_edge_random,
   dwd_edge_normal,
   dwd_edge_low,
   dwd_low
}dwd_gmsk_modes_type;
#else
enum dwd_gmsk_modes
{
   dwd_high   /* all ones*/,
   dwd_random /* all random*/,
   dwd_normal /*normal burst including training sequence*/,
   dwd_edge_high,
   dwd_edge_random,
   dwd_edge_normal,
   dwd_edge_low,
   dwd_low
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_original_config,
  dwd_updated_config
}dwd_config_tp_type;
#else
enum dwd_config_tp
{
  dwd_original_config,
  dwd_updated_config
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_in_line,
  dwd_calib,
  dwd_mmi
}dwd_test_station_tp_type;
#else
enum dwd_test_station_tp
{
  dwd_in_line,
  dwd_calib,
  dwd_mmi
};
#endif

#ifdef TYPEDEF_ENUMS
typedef  enum 
{
  dwd_low_ch,
  dwd_high_ch,
  dwd_mid_low_ch,
  dwd_mid_high_ch
}dwd_ch_high_low_tps;
#else
enum dwd_ch_high_low_tps
{
  dwd_low_ch,
  dwd_high_ch,
  dwd_mid_low_ch,
  dwd_mid_high_ch
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum
{
  dwd_treat_1800_as_1800 = 0,
  dwd_treat_1800_as_1900 = 1
}dwd_treat_type;

#else
enum
{
  dwd_treat_1800_as_1800 = 0,
  dwd_treat_1800_as_1900 = 1
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_get_tag_parms_offset,
  dwd_reset_p_lock,
  dwd_read_p_lock,
  dwd_enable_p_lock,
  dwd_reset_s_lock,
  dwd_read_s_lock,
  dwd_enable_s_lock,
  dwd_read_pers,
  dwd_write_pers,
  dwd_reset_pers,
  dwd_write_sio_config,
  dwd_reset_dyn_nv_to_default,
  dwd_get_static_checksum,
  dwd_get_nof_stored_exceptions=0x1021, //to be compatible with ee_testinterface
  dwd_get_exception_data=0x1027, //to be compatible with ee_testinterface
  dwd_get_exception_data_init=0x1033 //to be compatible with ee_testinterface
}dwd_ee_opcode_type;
#else
enum dwd_ee_opcode
{
  dwd_get_tag_parms_offset,
  dwd_reset_p_lock,
  dwd_read_p_lock,
  dwd_enable_p_lock,
  dwd_reset_s_lock,
  dwd_read_s_lock,
  dwd_enable_s_lock,
  dwd_read_pers,
  dwd_write_pers,
  dwd_reset_pers,
  dwd_write_sio_config,
  dwd_reset_dyn_nv_to_default,
  dwd_get_static_checksum,
  dwd_get_nof_stored_exceptions=0x1021, //to be compatible with ee_testinterface
  dwd_get_exception_data=0x1027, //to be compatible with ee_testinterface
  dwd_get_exception_data_init=0x1033 //to be compatible with ee_testinterface
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_send_instruction_data,
  dwd_send_display_data,
  dwd_first_v_ram_data,
  dwd_intermediate_v_ram_data,
  dwd_last_v_ram_data,
  dwd_lcd_start_demo,
  dwd_lcd_stop_demo,
  dwd_lcd_read_register,
  dwd_lcd_write_register,
  dwd_lcd_set_pixel,
  dwd_lcd_max_opcodes
}dwd_lcd_opcode_type;
#else
enum dwd_lcd_opcode
{
  dwd_send_instruction_data,
  dwd_send_display_data,
  dwd_first_v_ram_data,
  dwd_intermediate_v_ram_data,
  dwd_last_v_ram_data,
  dwd_lcd_start_demo,
  dwd_lcd_stop_demo,
  dwd_lcd_read_register,
  dwd_lcd_write_register,
  dwd_lcd_set_pixel,
  dwd_lcd_max_opcodes
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_findfirst,
  dwd_findnext,
  dwd_get_file_info,
  dwd_create,
  dwd_get_free_id,
  dwd_open,
  dwd_close,
  dwd_read,
  dwd_write,
  dwd_delete,
  dwd_file_exists,
  dwd_clean_flash,
  dwd_initialize,
  dwd_deactivate,
  dwd_close_cb,
  dwd_create_cb,
  dwd_write_cb,
  dwd_read_cb,
  dwd_append,
  dwd_append_cb,
  dwd_modify,
  dwd_modify_cb,
  dwd_delete_cb,
  dwd_rename,
  dwd_rename_cb,
  dwd_get_nof_files,
  dwd_get_nof_files_by_type,
  dwd_get_free_space,
  dwd_get_free_space_by_type,
  dwd_get_free_space_in_global_pool,
  dwd_get_raw_free_space_by_type,
  dwd_get_raw_free_space_in_global_pool,
  dwd_create_static,
  dwd_create_static_cb,
  dwd_get_free_static_space,
  dwd_get_file_name,
  dwd_get_file_id,
  dwd_copy_cb,
  dwd_load_to_lfa_cb,
  dwd_get_lfa_ref,
  dwd_get_lfa_info,
  dwd_read_lfa_data,
  dwd_create_factory_default,
  dwd_create_factory_default_cb,
  dwd_restart,
  dwd_restore_factory_default,
  dwd_restore_factory_default_cb,
  dwd_ffs_get_version,
  dwd_ffs_get_revision,
  dwd_ffs_get_parameters,
  dwd_ffs_get_features,
  dwd_get_reserved_space_by_type,
  dwd_get_reserved_space_in_global_pool,
  dwd_get_used_space,
  dwd_get_used_space_by_type,
  dwd_get_used_space_in_global_pool,
  dwd_calculate_file_overhead,
  dwd_truncate,
  dwd_truncate_cb,
  dwd_ffs_configuration,
  dwd_ffs_performance_measurement,
  dwd_streaming_read_perf_measure,
  dwd_streaming_write_perf_measure,
  dwd_init_data_perf_measure,
  dwd_streaming_test,
  dwd_set_drm_attributes,
  dwd_get_file_id_from_handle,
  dwd_mkdir,
  dwd_rmdir,
  dwd_isdir,
  dwd_setcwd,
  dwd_getcwd,
  dwd_dir_initialize,
  dwd_ffirst,
  dwd_fnext,
  dwd_ready_cb,
  dwd_create_dynamic_factory,
  dwd_create_dynamic_factory_cb,
  dwd_get_block_info,
  dwd_ffs_lock_unlock_background_gc,
  dwd_ffs_gc_cleanup,
  dwd_restore_all_factory_default,
  dwd_restore_all_factory_default_cb,
  dwd_clean_flash_special,
  dwd_get_block_statistics,
  dwd_streaming_read_fn_perf_measure,
  dwd_streaming_write_fn_perf_measure,
  dwd_streaming_file_copy_test 
}dwd_ffs_opcode_type;
#else
enum dwd_ffs_opcode
{
  dwd_findfirst,
  dwd_findnext,
  dwd_get_file_info,
  dwd_create,
  dwd_get_free_id,
  dwd_open,
  dwd_close,
  dwd_read,
  dwd_write,
  dwd_delete,
  dwd_file_exists,
  dwd_clean_flash,
  dwd_initialize,
  dwd_deactivate,
  dwd_close_cb,
  dwd_create_cb,
  dwd_write_cb,
  dwd_read_cb,
  dwd_append,
  dwd_append_cb,
  dwd_modify,
  dwd_modify_cb,
  dwd_delete_cb,
  dwd_rename,
  dwd_rename_cb,
  dwd_get_nof_files,
  dwd_get_nof_files_by_type,
  dwd_get_free_space,
  dwd_get_free_space_by_type,
  dwd_get_free_space_in_global_pool,
  dwd_get_raw_free_space_by_type,
  dwd_get_raw_free_space_in_global_pool,
  dwd_create_static,
  dwd_create_static_cb,
  dwd_get_free_static_space,
  dwd_get_file_name,
  dwd_get_file_id,
  dwd_copy_cb,
  dwd_load_to_lfa_cb,
  dwd_get_lfa_ref,
  dwd_get_lfa_info,
  dwd_read_lfa_data,
  dwd_create_factory_default,
  dwd_create_factory_default_cb,
  dwd_restart,
  dwd_restore_factory_default,
  dwd_restore_factory_default_cb,
  dwd_ffs_get_version,
  dwd_ffs_get_revision,
  dwd_ffs_get_parameters,
  dwd_ffs_get_features,
  dwd_get_reserved_space_by_type,
  dwd_get_reserved_space_in_global_pool,
  dwd_get_used_space,
  dwd_get_used_space_by_type,
  dwd_get_used_space_in_global_pool,
  dwd_calculate_file_overhead,
  dwd_truncate,
  dwd_truncate_cb,
  dwd_ffs_configuration,
  dwd_ffs_performance_measurement,
  dwd_streaming_read_perf_measure,
  dwd_streaming_write_perf_measure,
  dwd_init_data_perf_measure,
  dwd_streaming_test,
  dwd_set_drm_attributes,
  dwd_get_file_id_from_handle,
  dwd_mkdir,
  dwd_rmdir,
  dwd_isdir,
  dwd_setcwd,
  dwd_getcwd,
  dwd_dir_initialize,
  dwd_ffirst,
  dwd_fnext,
  dwd_ready_cb,
  dwd_create_dynamic_factory,
  dwd_create_dynamic_factory_cb,
  dwd_get_block_info,
  dwd_ffs_lock_unlock_background_gc,
  dwd_ffs_gc_cleanup,
  dwd_restore_all_factory_default,
  dwd_restore_all_factory_default_cb,
  dwd_clean_flash_special,
  dwd_get_block_statistics,
  dwd_streaming_read_fn_perf_measure,
  dwd_streaming_write_fn_perf_measure,
  dwd_streaming_file_copy_test 
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_none                   =0,
  dwd_fat_fs_present         =1,
  dwd_ffs_present            =2,
  dwd_bt_present             =4,
  dwd_mmc_present            =8,
  dwd_aud_ma2_present        =16,
  dwd_aud_ma3_present        =32,
  dwd_fm_radio_present       =64,
  dwd_mpeg3_present          =128,
  dwd_voicerec_present       =256,
  dwd_l1_workbench_present   =512,
  dwd_wap_present            =1024,
  dwd_cam_present	     =2048,
  dwd_edge_present           =4096,
  dwd_led_backlight_present  =8192,
  dwd_irda_present           =16384,
  dwd_nand_present           =0x00008000,
  dwd_util_present           =0x00010000,
  dwd_mon_sig_present        =0x00020000,
  dwd_umts_present           =0x00040000,
  dwd_pcm_player_present     =0x00080000
}dwd_features_present_codes_type;
#else
enum dwd_features_present_codes
{
  dwd_none                   =0,
  dwd_fat_fs_present         =1,
  dwd_ffs_present            =2,
  dwd_bt_present             =4,
  dwd_mmc_present            =8,
  dwd_aud_ma2_present        =16,
  dwd_aud_ma3_present        =32,
  dwd_fm_radio_present       =64,
  dwd_mpeg3_present          =128,
  dwd_voicerec_present       =256,
  dwd_l1_workbench_present   =512,
  dwd_wap_present            =1024,
  dwd_cam_present	     =2048,
  dwd_edge_present           =4096,
  dwd_led_backlight_present  =8192,
  dwd_irda_present           =16384,
  dwd_nand_present           =0x00008000,
  dwd_util_present           =0x00010000,
  dwd_mon_sig_present        =0x00020000,
  dwd_umts_present           =0x00040000,
  dwd_pcm_player_present     =0x00080000
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_afr_start,
  dwd_afr_stop,
  dwd_mute,
  dwd_set_station,
  dwd_afr_read_current_status,
  dwd_afr_read_config,
  dwd_afr_write_config,
  dwd_afr_get_seek_result,
  dwd_afr_measure_rssi,
  dwd_afr_get_rssi_result
 }dwd_afr_opcode_type;
#else
enum dwd_afr_opcode
{
  dwd_afr_start,
  dwd_afr_stop,
  dwd_afr_mute,
  dwd_afr_set_station,
  dwd_afr_read_current_status,
  dwd_afr_read_config,
  dwd_afr_write_config,
  dwd_afr_get_seek_result,
  dwd_afr_measure_rssi,
  dwd_afr_get_rssi_result
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum
{
  dwd_not_allowed,		/* not allowed in search mode */
  dwd_level_5,			/* low; level ADC output = 5.*/
  dwd_level_7,			/* mid; level ADC output = 7.*/
  dwd_level_10			/* high; level ADC output = 10.*/
}dwd_adc_level_type;
#else
enum
{
  dwd_not_allowed,		/* not allowed in search mode */
  dwd_level_5,			/* low; level ADC output = 5.*/
  dwd_level_7,			/* mid; level ADC output = 7.*/
  dwd_level_10			/* high; level ADC output = 10.*/
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum
{
  dwd_off,			/* Station preset */
  dwd_manualUp,			/* Manual one step up */
  dwd_manualDown,		/* Manual one step down */
  dwd_autoUp,			/* Auto seek up */
  dwd_downAuto			/* Auto seek down */
}dwd_seek_type;
#else
enum
{
  dwd_off,			/* Station preset */
  dwd_manualUp,			/* Manual one step up */
  dwd_manualDown,		/* Manual one step down */
  dwd_autoUp,			/* Auto seek up */
  dwd_downAuto			/* Auto seek down */
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum
{
  dwd_afr_mono,
  dwd_afr_stereo
}dwd_stereo_mono_type;
#else
enum
{
  dwd_afr_mono,
  dwd_afr_stereo
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_cam_sensor_wr,
  dwd_cam_sensor_rd,
  dwd_cam_vc_wr_data,
  dwd_cam_vc_rd_data,
  dwd_cam_viewfinder,
  dwd_cam_freeze_picture,
  dwd_cam_lcd_transparent,
  dwd_cam_start_preview_mode1,
  dwd_cam_start_preview_mode2,
  dwd_cam_start_preview_mode3,
  dwd_cam_stop_preview,
  dwd_cam_sleep,
  dwd_cam_status,
  dwd_cam_take_picture,
  dwd_cam_get_jpeg_file_size,
  dwd_cam_get_jpeg_picture,
  dwd_cam_put_jpeg_picture,
  dwd_cam_max_opcodes
}dwd_cam_opcode_type;
#else
enum dwd_cam_opcode
{
  dwd_cam_sensor_wr,
  dwd_cam_sensor_rd,
  dwd_cam_vc_wr_data,
  dwd_cam_vc_rd_data,
  dwd_cam_viewfinder,
  dwd_cam_freeze_picture,
  dwd_cam_lcd_transparent,
  dwd_cam_start_preview_mode1,
  dwd_cam_start_preview_mode2,
  dwd_cam_start_preview_mode3,
  dwd_cam_stop_preview,
  dwd_cam_sleep,
  dwd_cam_status,
  dwd_cam_take_picture,
  dwd_cam_get_jpeg_file_size,
  dwd_cam_get_jpeg_picture,
  dwd_cam_put_jpeg_picture,
  dwd_cam_max_opcodes
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_preview_mode1,
  dwd_preview_mode2,
  dwd_preview_mode3
}dwd_start_preview_mode_type;

#else
enum dwd_start_preview_mode
{
  dwd_preview_mode1,
  dwd_preview_mode2,
  dwd_preview_mode3
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_chr_get_main_control_status,
  dwd_chr_get_measurement_control_status,
  dwd_chr_get_charger_control_status,
  dwd_chr_get_capacity_control_status,
  dwd_chr_set_reverse_charging,
  dwd_chr_get_charger_type,
  dwd_chr_lock_unlock_charger
}dwd_chr_generic_type;
#else
enum dwd_chr_generic
{
  dwd_chr_get_main_control_status,
  dwd_chr_get_measurement_control_status,
  dwd_chr_get_charger_control_status,
  dwd_chr_get_capacity_control_status,
  dwd_chr_set_reverse_charging,
  dwd_chr_get_charger_type,
  dwd_chr_lock_unlock_charger
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_gtb_transfer_ffs_file_to_ram_1,
  dwd_gtb_store_ram_1_data_to_ffs_file,
  dwd_gtb_transfer_ffs_file_to_ram_2,
  dwd_gtb_store_ram_2_data_to_ffs_file,
  dwd_reprog_dsp_patch
}dwd_gtb_opcode_type;
#else
enum dwd_gtb_opcode
{
  dwd_gtb_transfer_ffs_file_to_ram_1,
  dwd_gtb_store_ram_1_data_to_ffs_file,
  dwd_gtb_transfer_ffs_file_to_ram_2,
  dwd_gtb_store_ram_2_data_to_ffs_file,
  dwd_reprog_dsp_patch
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_bb_none = 0,
  dwd_egold_plus_v1_2 = 2,
  dwd_egold_v3 = 4,
  dwd_sgold = 8,
  dwd_sgold_lite = 16,
  dwd_sglite_v1_1 = 32,
  dwd_egold_lite = 64,
  dwd_egold_radio = 65,
  dwd_sgold2 = 128,
  dwd_sgold3 = 129,
  dwd_egold_voice = 130
}dwd_baseband_present_codes_type;
#else
enum dwd_baseband_present_codes
{
  dwd_bb_none = 0,
  dwd_egold_plus_v1_2 = 2,
  dwd_egold_v3 = 4,
  dwd_sgold = 8,
  dwd_sgold_lite = 16,
  dwd_sglite_v1_1 = 32,
  dwd_egold_lite = 64,
  dwd_egold_radio = 65,
  dwd_sgold2 = 128,
  dwd_sgold3 = 129,
  dwd_egold_voice = 130
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_rf_none = 0,
  dwd_smarti_plus_b1 = 2,
  dwd_smarti_plus_c1 = 4,
  dwd_smarti_plus_c2 = 8,
  dwd_smarti_dc = 16,
  dwd_smarti_dc_plus_v1 = 32,
  dwd_smarti_dc_plus_v2 = 64,
  dwd_smarti_sd = 128,
  dwd_smarti_sd2_v1x = 129, // SMARTi SD2 v1.x (discontinued)
  dwd_smarti_sd2_v2x = 130, // SMARTi SD2 v2.x (supported by official SMARTi SD2 Thorboard by N7, to be discontinued)
  dwd_smarti_sd2_v3x = 131, // SMARTi SD2 v3.x (discontinued)
  dwd_smarti_sd2_A1 = 132, // SMARTi SD2 A1 (supported by modified SMARTi SD2 Thorboard by N7, BP2_GLOBE3)
  dwd_smarti_sd9 = 512,
  dwd_smarti_sdB1 = 1024,
  dwd_smarti_u_v11 = 2048,
  dwd_smarti_sdB2 = 4096,
  dwd_smarti_pm = 8192,
  dwd_smarti_sd3_A0 = 16384,
  dwd_smarti_sd3_v1 = 16385,
  dwd_smarti_pm2 = 32768
}dwd_rf_present_codes_type;
#else
enum dwd_rf_present_codes
{
  dwd_rf_none = 0,
  dwd_smarti_plus_b1 = 2,
  dwd_smarti_plus_c1 = 4,
  dwd_smarti_plus_c2 = 8,
  dwd_smarti_dc = 16,
  dwd_smarti_dc_plus_v1 = 32,
  dwd_smarti_dc_plus_v2 = 64,
  dwd_smarti_sd = 128,
  dwd_smarti_sd2_v1x = 129, // SMARTi SD2 v1.x (discontinued)
  dwd_smarti_sd2_v2x = 130, // SMARTi SD2 v2.x (supported by official SMARTi SD2 Thorboard by N7, to be discontinued)
  dwd_smarti_sd2_v3x = 131, // SMARTi SD2 v3.x (discontinued)
  dwd_smarti_sd2_A1 = 132, // SMARTi SD2 A1 (supported by modified SMARTi SD2 Thorboard by N7, BP2_GLOBE3)
  dwd_smarti_sd9 = 512,
  dwd_smarti_sdB1 = 1024,
  dwd_smarti_u_v11 = 2048,
  dwd_smarti_sdB2 = 4096,
  dwd_smarti_pm = 8192,
  dwd_smarti_sd3_A0 = 16384,
  dwd_smarti_sd3_v1 = 16385,
  dwd_smarti_pm2 = 32768,
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
   dwd_acc_type,
   dwd_acc_status
}dwd_acc_opcode_type;
#else
enum dwd_acc_opcode
{
   dwd_acc_type,
   dwd_acc_status
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
 {
   dwd_vib_start,
   dwd_vib_stop,
   dwd_vib_pause,
   dwd_vib_status
 }dwd_vib_opcode_type;
#else
enum dwd_vib_opcode
 {
   dwd_vib_start,
   dwd_vib_stop,
   dwd_vib_pause,
   dwd_vib_status
 };
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_umts_fdd_non_sig_mode,
  dwd_umts_fdd_sig_mode
}dwd_umts_fdd_test_mode_type;
#else
enum dwd_umts_fdd_test_mode
{
  dwd_umts_fdd_non_sig_mode,
  dwd_umts_fdd_sig_mode
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{ 
  dwd_mmci_hw_check,
  dwd_mmci_ll_read,
  dwd_mmci_ll_write,
  dwd_mmci_ll_erase
}dwd_mmci_opcode_type;
#else
enum dwd_mmci_opcode
{ 
  dwd_mmci_hw_check,
  dwd_mmci_ll_read,
  dwd_mmci_ll_write,
  dwd_mmci_ll_erase
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_gdd_unknown,

  dwd_gdd_set_buf,
  dwd_gdd_get_buf,

  /* GDD interface... */
  dwd_gdd_init,
  dwd_gdd_init_rtos_resources,
  dwd_gdd_request_access_semaphore,
  dwd_gdd_release_access_semaphore,
  dwd_gdd_request_api_semaphore,
  dwd_gdd_release_api_semaphore,
  dwd_gdd_request_api_result_semaphore,
  dwd_gdd_release_api_result_semaphore,
  dwd_gdd_tx_msg,
  dwd_gdd_get_main_state,
  dwd_gdd_start_high_level_timer,
  dwd_gdd_high_level_timeout_func,
  dwd_gdd_stop_high_level_timer,
  dwd_gdd_alloc,
  dwd_gdd_send,

  /* LLC interface... */
  dwd_gdd_llc_init,
  dwd_gdd_llc_rxi,
  dwd_gdd_llc_txi,
  dwd_gdd_llc_txi_tab,
  dwd_gdd_llc_rxd,
  dwd_gdd_llc_txd,
  dwd_gdd_llc_hw_reset,
  dwd_gdd_llc_await_timeout,
  dwd_gdd_llc_await_gdc_int,
  dwd_gdd_llc_prepare_package_transfer,

  /* LCD interface... */
  dwd_gdd_lcd_control,
  dwd_gdd_lcd_init,
  dwd_gdd_lcd_update,
  dwd_gdd_lcd_uniform_update,
  dwd_gdd_lcd_test_image_start,
  dwd_gdd_lcd_set_contrast,
  dwd_gdd_lcd_get_contrast_limits,
  dwd_gdd_lcd_set_power_save_mode,
  dwd_gdd_lcd_shutdown,
  dwd_gdd_lcd_set_pixel,

  /* CAM interface... */
  dwd_gdd_cam_control,
  dwd_gdd_cam_enable,
  dwd_gdd_cam_disable,
  dwd_gdd_cam_capture,
  dwd_gdd_cam_get_picture,
  dwd_gdd_cam_put_picture,
  dwd_gdd_cam_set_compression,
  dwd_gdd_cam_get_picture_size,
  dwd_gdd_cam_set_brightness,
  dwd_gdd_cam_get_brightness_limits,
  dwd_gdd_cam_set_contrast,
  dwd_gdd_cam_get_contrast_limits,
  dwd_gdd_cam_close_shot,
  dwd_gdd_cam_set_antiflicker_mode,
  dwd_gdd_cam_set_twilight_mode,
  dwd_gdd_cam_set_image_format,
  dwd_gdd_cam_decode_jpeg_picture,
  dwd_gdd_cam_get_rgb_picture,

  /* GDC interface... */
  dwd_gdd_gdc_control,


  /* Additional features... */

  /* capabilities */
  dwd_gdd_get_hw_id,
  dwd_gdd_get_hw_capabilities,

  /* video */
  dwd_gdd_video_playback_enable,
  dwd_gdd_video_playback_disable,
  dwd_gdd_video_playback_frame,

  dwd_gdd_video_capture_enable,
  dwd_gdd_video_capture_disable,

  dwd_gdd_set_video_buf,
  dwd_gdd_get_video_buf,

  dwd_gdd_set_video_nof_frames,
  dwd_gdd_get_video_nof_frames,

  dwd_gdd_get_video_statistics,
  dwd_gdd_get_last_video_results,

  /* overlay */
  dwd_gdd_cam_set_overlay_mask,
  dwd_gdd_lcd_repeat_onoff,

  /* GDD version */
  dwd_gdd_sw_if_ver,

  /* Dump Data opcodes */
  dwd_gdd_dump_cam_picture,

  /* number of gdd opcodes */
  dwd_gdd_nof_opcodes 
}dwd_gdd_opcode_type;
#else
enum dwd_gdd_opcode
{
  dwd_gdd_unknown,

  dwd_gdd_set_buf,
  dwd_gdd_get_buf,

  /* GDD interface... */
  dwd_gdd_init,
  dwd_gdd_init_rtos_resources,
  dwd_gdd_request_access_semaphore,
  dwd_gdd_release_access_semaphore,
  dwd_gdd_request_api_semaphore,
  dwd_gdd_release_api_semaphore,
  dwd_gdd_request_api_result_semaphore,
  dwd_gdd_release_api_result_semaphore,
  dwd_gdd_tx_msg,
  dwd_gdd_get_main_state,
  dwd_gdd_start_high_level_timer,
  dwd_gdd_high_level_timeout_func,
  dwd_gdd_stop_high_level_timer,
  dwd_gdd_alloc,
  dwd_gdd_send,

  /* LLC interface... */
  dwd_gdd_llc_init,
  dwd_gdd_llc_rxi,
  dwd_gdd_llc_txi,
  dwd_gdd_llc_txi_tab,
  dwd_gdd_llc_rxd,
  dwd_gdd_llc_txd,
  dwd_gdd_llc_hw_reset,
  dwd_gdd_llc_await_timeout,
  dwd_gdd_llc_await_gdc_int,
  dwd_gdd_llc_prepare_package_transfer,

  /* LCD interface... */
  dwd_gdd_lcd_control,
  dwd_gdd_lcd_init,
  dwd_gdd_lcd_update,
  dwd_gdd_lcd_uniform_update,
  dwd_gdd_lcd_test_image_start,
  dwd_gdd_lcd_set_contrast,
  dwd_gdd_lcd_get_contrast_limits,
  dwd_gdd_lcd_set_power_save_mode,
  dwd_gdd_lcd_shutdown,
  dwd_gdd_lcd_set_pixel,

  /* CAM interface... */
  dwd_gdd_cam_control,
  dwd_gdd_cam_enable,
  dwd_gdd_cam_disable,
  dwd_gdd_cam_capture,
  dwd_gdd_cam_get_picture,
  dwd_gdd_cam_put_picture,
  dwd_gdd_cam_set_compression,
  dwd_gdd_cam_get_picture_size,
  dwd_gdd_cam_set_brightness,
  dwd_gdd_cam_get_brightness_limits,
  dwd_gdd_cam_set_contrast,
  dwd_gdd_cam_get_contrast_limits,
  dwd_gdd_cam_close_shot,
  dwd_gdd_cam_set_antiflicker_mode,
  dwd_gdd_cam_set_twilight_mode,
  dwd_gdd_cam_set_image_format,
  dwd_gdd_cam_decode_jpeg_picture,
  dwd_gdd_cam_get_rgb_picture,

  /* GDC interface... */
  dwd_gdd_gdc_control,


  /* Additional features... */

  /* capabilities */
  dwd_gdd_get_hw_id,
  dwd_gdd_get_hw_capabilities,

  /* video */
  dwd_gdd_video_playback_enable,
  dwd_gdd_video_playback_disable,
  dwd_gdd_video_playback_frame,

  dwd_gdd_video_capture_enable,
  dwd_gdd_video_capture_disable,

  dwd_gdd_set_video_buf,
  dwd_gdd_get_video_buf,

  dwd_gdd_set_video_nof_frames,
  dwd_gdd_get_video_nof_frames,

  dwd_gdd_get_video_statistics,
  dwd_gdd_get_last_video_results,

  /* overlay */
  dwd_gdd_cam_set_overlay_mask,
  dwd_gdd_lcd_repeat_onoff,

  /* GDD version */
  dwd_gdd_sw_if_ver,

  /* Dump Data opcodes */
  dwd_gdd_dump_cam_picture,

  /* Used by N7 to get LCD type */
  dwd_gdd_get_main_sub_hw_id,

  // Gdd info function as per GDD V2.0.  
  dwd_gdd_info,

  /* for IF22 */
  dwd_gdd_cam_set_capture_image_format_22,
  dwd_gdd_cam_enable_22,
  dwd_gdd_cam_get_view_image_rect_22,
  dwd_gdd_cam_capture_22,
  dwd_gdd_cam_set_image_scaling_22,
  dwd_gdd_cam_set_frame_rate_22,
  dwd_gdd_video_capture_enable_22,
  dwd_gdd_video_capture_pause_22,
  dwd_gdd_video_playback_enable_22,
  dwd_gdd_cam_get_video_frame_rect_22,
  dwd_gdd_cam_set_multi_shot_configuration_22,
  dwd_gdd_cam_get_multishot_picture_size_22,
  dwd_gdd_cam_set_filter_type_22,
  dwd_gdd_cam_get_multishot_picture_22,
  dwd_gdd_cam_vf_restart_22,
  dwd_gdd_cam_vf_hide_22,
  dwd_gdd_cam_vf_show_22,
  dwd_gdd_lcd_get_contrast_limits_22,
  dwd_gdd_lcd_update_22,

  /* number of gdd opcodes */
  dwd_gdd_nof_opcodes 
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
  { 
     dwd_POW_get_mirrors,              /*  0 */
     dwd_POW_setReg,			  /*  1 */
     dwd_POW_getReg,			  /*  2 */
     dwd_POW_get_power_chip_version,	  /*  3 */
     dwd_POW_setRESCTRL,		  /*  4 */
     dwd_POW_getRESCTRL,		  /*  5 */
     dwd_POW_allOFF,			  /*  6 */
     dwd_POW_setPWCTRL3_LRF3,	  /*  7 */
     dwd_POW_setVSIM1,		  /*  8 */
     dwd_POW_setVSIM2,		  /*  9 */
     dwd_POW_setCHCTRL1,		  /* 10 */
     dwd_POW_getCHCTRL1,		  /* 11 */
     dwd_POW_setCHG,			  /* 12 */
     dwd_POW_setLMMC,		  /* 13 */
     dwd_POW_setCHCTRL2,		  /* 14 */
     dwd_POW_getCHCTRL2,		  /* 15 */
     dwd_POW_setINTCTRL1,		  /* 16 */
     dwd_POW_getINTCTRL1,		  /* 17 */
     dwd_POW_setINTCTRL2,		  /* 18 */
     dwd_POW_getINTCTRL2,		  /* 19 */
     dwd_POW_setLEDCTRL1,		  /* 20 */
     dwd_POW_getLEDCTRL1,		  /* 21 */
     dwd_POW_setLED_PWM,		  /* 22 */
     dwd_POW_setLEDCTRL2,		  /* 23 */
     dwd_POW_getLEDCTRL2,		  /* 24 */
     dwd_POW_setVIBRATORCTRL,	  /* 25 */
     dwd_POW_getVIBRATORCTRL,	  /* 26 */
     dwd_POW_setLED,			  /* 27 */
     dwd_POW_setDRVCTRL_SLED1,	  /* 28 */
     dwd_POW_setDRVCTRL_SLED2,	  /* 29 */
     dwd_POW_setUSBCTRL,		  /* 30 */
     dwd_POW_getUSBCTRL,		  /* 31 */
     dwd_POW_setAUDCTRL,		  /* 32 */
     dwd_POW_getAUDCTRL,		  /* 33 */
     dwd_POW_getErrorFlags,		  /* 34 */
     dwd_POW_getInterruptFlags,	  /* 35 */
     dwd_POW_getChargerStatus,	  /* 36 */
     dwd_POW_setSDBB,		  /* 37 */
     dwd_POW_setLRFC,		  /* 38 */
     dwd_POW_setLRF0,		  /* 39 */
     dwd_POW_setLANA,		  /* 40 */
     dwd_POW_setLRF1,		  /* 41 */
     dwd_POW_setLRF2,		  /* 42 */
     dwd_setLED_current,               /* 43 */
     dwd_POW_max_opcodes
}dwd_pow_opcodes_type;
#else
enum dwd_pow_opcodes
  { 
     dwd_POW_get_mirrors,              /*  0 */
     dwd_POW_setReg,			  /*  1 */
     dwd_POW_getReg,			  /*  2 */
     dwd_POW_get_power_chip_version,	  /*  3 */
     dwd_POW_setRESCTRL,		  /*  4 */
     dwd_POW_getRESCTRL,		  /*  5 */
     dwd_POW_allOFF,			  /*  6 */
     dwd_POW_setPWCTRL3_LRF3,	  /*  7 */
     dwd_POW_setVSIM1,		  /*  8 */
     dwd_POW_setVSIM2,		  /*  9 */
     dwd_POW_setCHCTRL1,		  /* 10 */
     dwd_POW_getCHCTRL1,		  /* 11 */
     dwd_POW_setCHG,			  /* 12 */
     dwd_POW_setLMMC,		  /* 13 */
     dwd_POW_setCHCTRL2,		  /* 14 */
     dwd_POW_getCHCTRL2,		  /* 15 */
     dwd_POW_setINTCTRL1,		  /* 16 */
     dwd_POW_getINTCTRL1,		  /* 17 */
     dwd_POW_setINTCTRL2,		  /* 18 */
     dwd_POW_getINTCTRL2,		  /* 19 */
     dwd_POW_setLEDCTRL1,		  /* 20 */
     dwd_POW_getLEDCTRL1,		  /* 21 */
     dwd_POW_setLED_PWM,		  /* 22 */
     dwd_POW_setLEDCTRL2,		  /* 23 */
     dwd_POW_getLEDCTRL2,		  /* 24 */
     dwd_POW_setVIBRATORCTRL,	  /* 25 */
     dwd_POW_getVIBRATORCTRL,	  /* 26 */
     dwd_POW_setLED,			  /* 27 */
     dwd_POW_setDRVCTRL_SLED1,	  /* 28 */
     dwd_POW_setDRVCTRL_SLED2,	  /* 29 */
     dwd_POW_setUSBCTRL,		  /* 30 */
     dwd_POW_getUSBCTRL,		  /* 31 */
     dwd_POW_setAUDCTRL,		  /* 32 */
     dwd_POW_getAUDCTRL,		  /* 33 */
     dwd_POW_getErrorFlags,		  /* 34 */
     dwd_POW_getInterruptFlags,	  /* 35 */
     dwd_POW_getChargerStatus,	  /* 36 */
     dwd_POW_setSDBB,		  /* 37 */
     dwd_POW_setLRFC,		  /* 38 */
     dwd_POW_setLRF0,		  /* 39 */
     dwd_POW_setLANA,		  /* 40 */
     dwd_POW_setLRF1,		  /* 41 */
     dwd_POW_setLRF2,		  /* 42 */
     dwd_setLED_current,               /* 43 */
     dwd_POW_max_opcodes
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
    dwd_pow_ptest_result_OK,
    dwd_pow_ptest_result_FAIL,
    dwd_pow_ptest_result_NOT_IMPLEMENTED,
    dwd_pow_ptest_result_MOD_TEST_NOT_ACTIVE
}dwd_pow_result_code_type;

#else
enum dwd_pow_result_code
{
    dwd_pow_ptest_result_OK,
    dwd_pow_ptest_result_FAIL,
    dwd_pow_ptest_result_NOT_IMPLEMENTED,
    dwd_pow_ptest_result_MOD_TEST_NOT_ACTIVE
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
   dwd_util_lm_get_instantaneous_load,
   dwd_util_lm_start_load_meter,
   dwd_util_lm_stop_load_meter,
   dwd_util_lm_resume_load_meter,
   dwd_util_lm_update_values_to_phone_tool,
   dwd_util_lm_calibrate_load_meter
}dwd_util_opcode_type;

#else
enum dwd_util_opcode
{
   dwd_util_lm_get_instantaneous_load,
   dwd_util_lm_start_load_meter,
   dwd_util_lm_stop_load_meter,
   dwd_util_lm_resume_load_meter,
   dwd_util_lm_update_values_to_phone_tool,
   dwd_util_lm_calibrate_load_meter
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_sig_gprs_not_attached,
  dwd_sig_gprs_attached
}dwd_sig_gprs_type;
#else
enum dwd_sig_gprs
{
  dwd_sig_gprs_not_attached,
  dwd_sig_gprs_attached
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_non_sig_dont_use_calib_parm,
  dwd_non_sig_use_calib_parm
 }dwd_inline_opcode_type;
#else
enum dwd_inline_opcode
{
  dwd_non_sig_dont_use_calib_parm,
  dwd_non_sig_use_calib_parm
 };
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
{
  dwd_fs_open,
  dwd_fs_read,
  dwd_fs_read_max,
  dwd_fs_write,
  dwd_fs_truncate,
  dwd_fs_flush,
  dwd_fs_close,
  dwd_fs_findfirst,
  dwd_fs_findnext,
  dwd_fs_finddone,
  dwd_fs_mkdir,
  dwd_fs_rmdir,
  dwd_fs_isdir,
  dwd_fs_getcwd,
  dwd_fs_setcwd,
  dwd_fs_delete,
  dwd_fs_rename,
  dwd_fs_get_attributes,
  dwd_fs_set_attributes,
  dwd_fs_seek,
  dwd_fs_stat,
  dwd_fs_diskopen,
  dwd_fs_diskclose,
  dwd_fs_diskabort,
  dwd_fs_diskinfo,
  dwd_fs_assign_driveletter,
  dwd_fs_format,
  dwd_fs_free,
  dwd_fs_set_default_device,
  dwd_fs_get_default_device,
  dwd_fs_disk_flush,
  dwd_fs_get_last_error,
  dwd_fs_get_last_device_error,
  dwd_fs_read_streaming,
  dwd_fs_write_streaming,
  dwd_fs_initialize,
  dwd_fs_deactivate,
  dwd_fs_get_version, // Not used
  dwd_fs_get_parameters,
  dwd_fs_get_features,
  dwd_fs_performance_measurement,
  dwd_fs_register_device,  // Not used
  dwd_fs_get_registered_devices,
  dwd_fs_register_media_status_notification,
  dwd_fs_device_notify,
  dwd_fs_ioctl,
  dwd_fs_check_disk
}dwd_fs_opcode_type;
#else
enum dwd_fs_opcode
{
  dwd_fs_open,
  dwd_fs_read,
  dwd_fs_read_max,
  dwd_fs_write,
  dwd_fs_truncate,
  dwd_fs_flush,
  dwd_fs_close,
  dwd_fs_findfirst,
  dwd_fs_findnext,
  dwd_fs_finddone,
  dwd_fs_mkdir,
  dwd_fs_rmdir,
  dwd_fs_isdir,
  dwd_fs_getcwd,
  dwd_fs_setcwd,
  dwd_fs_delete,
  dwd_fs_rename,
  dwd_fs_get_attributes,
  dwd_fs_set_attributes,
  dwd_fs_seek,
  dwd_fs_stat,
  dwd_fs_diskopen,
  dwd_fs_diskclose,
  dwd_fs_diskabort,
  dwd_fs_diskinfo,
  dwd_fs_assign_driveletter,
  dwd_fs_format,
  dwd_fs_free,
  dwd_fs_set_default_device,
  dwd_fs_get_default_device,
  dwd_fs_disk_flush,
  dwd_fs_get_last_error,
  dwd_fs_get_last_device_error,
  dwd_fs_read_streaming,
  dwd_fs_write_streaming,
  dwd_fs_initialize,
  dwd_fs_deactivate,
  dwd_fs_get_version, // Not used
  dwd_fs_get_parameters,
  dwd_fs_get_features,
  dwd_fs_performance_measurement,
  dwd_fs_register_device,  // Not used
  dwd_fs_get_registered_devices,
  dwd_fs_register_media_status_notification,
  dwd_fs_device_notify,
  dwd_fs_ioctl,
  dwd_fs_check_disk
};
#endif

#ifdef TYPEDEF_ENUMS
typedef enum 
 { 
   dwd_btd_reset,
   dwd_btd_setup_rf_test_mode,
   dwd_btd_set_tx_burst_mode,
   dwd_btd_set_tx_continuous_mode,
   dwd_btd_set_rx_continuous_mode,
   dwd_btd_get_bluemoon_version,
   dwd_btd_setup_pcm_loopback,
   dwd_btd_check_host_interface,
   dwd_bt_hw_info,
   dwd_btd_initialize,
   dwd_btd_set_tx_burst_mode_extended,
   dwd_btd_set_afh_channel_map,
   dwd_btd_set_tx_continuous_mode_extended,
   dwd_btd_check_sleepx_signal,
   dwd_btd_setup_rf_test_mode_extended
 }dwd_btd_opcode_type;
#else
enum dwd_btd_opcode
 { 
   dwd_btd_reset,
   dwd_btd_setup_rf_test_mode,
   dwd_btd_set_tx_burst_mode,
   dwd_btd_set_tx_continuous_mode,
   dwd_btd_set_rx_continuous_mode,
   dwd_btd_get_bluemoon_version,
   dwd_btd_setup_pcm_loopback,
   dwd_btd_check_host_interface,
   dwd_bt_hw_info,
   dwd_btd_initialize,
   dwd_btd_set_tx_burst_mode_extended,
   dwd_btd_set_afh_channel_map,
   dwd_btd_set_tx_continuous_mode_extended,
   dwd_btd_check_sleepx_signal,
   dwd_btd_setup_rf_test_mode_extended
 };
#endif

typedef enum
{
  dwd_audio_mode_normal,
  dwd_audio_mode_headset,
  dwd_audio_mode_handsfree
}dwd_audio_mode_type;

typedef enum
{
  dwd_normal_mode,
  dwd_not_applicable,
  dwd_ptest_mode
}dwd_mode_type;

typedef enum
{
  dwd_at_hash_on,
  dwd_at_hash_off
}dwd_v24_mode_type;

typedef enum
{
	DWD_BAUDRATE_1200,
	DWD_BAUDRATE_2400,
	DWD_BAUDRATE_4800,
	DWD_BAUDRATE_9600,
	DWD_BAUDRATE_19200,
	DWD_BAUDRATE_38400,
	DWD_BAUDRATE_57600,
	DWD_BAUDRATE_115200,
	DWD_BAUDRATE_230400,
	DWD_BAUDRATE_460800,
	DWD_BAUDRATE_921600
}dwd_baud_rate_type;

typedef enum
{
  dwd_rtc_setting_ok,
  dwd_rtc_register_access_failed,
  dwd_rtc_nvram_access_failed,
  dwd_rtc_limits_exceeded,
  dwd_rtc_alarm_program_failed,
  dwd_rtc_no_alarm,
  dwd_rtc_setting_invalid, 
  dwd_rtc_default_error
}dwd_rtc_result_type;

typedef enum
{
  dwd_no_fcb_sb_found,
  dwd_only_fcb_found,
  dwd_fcb_sb_found
} dwd_wrk_fcb_sb_result_type;

typedef enum
{
  dwd_trx_gprs = 0,
  dwd_trx_egprs
} dwd_trx_mode;

typedef enum
{
  dwd_led_blue = 0,
  dwd_led_red,
  dwd_led_green,
  dwd_led_blue_red,
  dwd_led_blue_green,
  dwd_led_red_green,
  dwd_led_red_blue_green,
  dwd_led_nof_colors
} dwd_led_color_type;

typedef enum
{
  dwd_rach_tsc_0 = 0,
  dwd_rach_tsc_1 = 1,
  dwd_rach_tsc_2 = 2
} dwd_tsc_type;

typedef enum
{
  dwd_rach_ab_8    = 15,
  dwd_rach_ab_11   = 16,
  dwd_rach_ab_11_e = 17
} dwd_block_format_type;

typedef enum
{
  dwd_prach_chn = 12,
  dwd_rach_chn = 13
} dwd_channel_type;

typedef enum
{
 dwd_led_unknown,
 dwd_led_get_hw_id,
 dwd_led_get_hw_capabilities,
 dwd_led_init,
 dwd_led_color_info,
 dwd_led_timer_info,
 dwd_led_get_nof_hw_timers,
 dwd_led_get_nof_colors,
 dwd_led_get_rtt_status,
 dwd_led_get_main_state,
 dwd_led_get_status,
 dwd_led_flash,
 dwd_led_flash_once,
 dwd_led_all_off,
 dwd_led_on,
 dwd_led_off,
 dwd_led_colorstream,
 dwd_led_reset,
 /* number of led opcodes */
 dwd_led_nof_opcodes
}dwd_led_opcode; 

typedef enum
{
  dwd_bb_ver_invalid,
  dwd_bb_ver_sgold,
  dwd_bb_ver_sgoldlite,
  dwd_bb_ver_sgold2,
  dwd_bb_ver_egoldradio,
  dwd_bb_ver_sgold3 = dwd_bb_ver_egoldradio
}dwd_bb_ver_enum_type;

typedef enum
{
  dwd_bb_rev_invalid,
  dwd_bb_rev10,
  dwd_bb_rev11,
  dwd_bb_rev11a,
  dwd_bb_rev11b,
  dwd_bb_rev12,
  dwd_bb_rev20
}dwd_bb_rev_enum_type;

typedef enum 
{ 
  dwd_bb_rev_unknown, 
  dwd_bb_rev22f,    
  dwd_bb_rev22g,    
  dwd_bb_rev22h 
} dwd_bb_EGR_rev_enum_type;


typedef enum{  /* Values not to be changed. */
 GDD_MAIN_LCD = 250,
 GDD_SUB_LCD,
 GDD_GDC,
 GDD_CAM,
 GDD_MAIN_CAM = GDD_CAM,
 GDD_SUB_CAM,
 GDD_HW_ID_NONE,
 GDD_MAX_HW_ID 
}gdd_hw_id_type;

typedef enum
{
 dwd_btd_tx_power_offset_0_db = 0,
 dwd_btd_tx_power_offset_minus_1_5_db = 1,
 dwd_btd_tx_power_offset_minus_3_db = 2,
 dwd_btd_tx_power_offset_1_5_db = 3
}dwd_btd_tx_power_offset_type;

typedef enum
{
 dwd_btd_bmu_tx_power_offset_minus_4_db = 0,
 dwd_btd_bmu_tx_power_offset_minus_2_db = 1,
 dwd_btd_bmu_tx_power_offset_nominal = 2,
 dwd_btd_bmu_tx_power_offset_2_db = 3
}dwd_btd_bmu_tx_power_offset_type;
		
typedef enum
{
 dwd_btd_baud_115200 = 0x70,
 dwd_btd_baud_230400 = 0x37,
 dwd_btd_baud_460800 = 0x1B,
 dwd_btd_baud_921600 = 0x0D
}dwd_btd_baud_rate_type;

typedef enum
{
dwd_btd_bmu_baud_9600 = 0x00,
dwd_btd_bmu_baud_19200 = 0x01,
dwd_btd_bmu_baud_38400 = 0x02,
dwd_btd_bmu_baud_57600 = 0x03,
dwd_btd_bmu_baud_115200 = 0x04,
dwd_btd_bmu_baud_230400 = 0x05,
dwd_btd_bmu_baud_460800 = 0x06,
dwd_btd_bmu_baud_921600 = 0x07,
dwd_btd_bmu_baud_1843200 = 0x08,
dwd_btd_bmu_baud_3250000 = 0x09
}dwd_btd_bmu_baud_rate_type;	


typedef enum
{
  dwd_chr_no_charger,
  dwd_chr_standard_charger,
  dwd_chr_usb_charger
} dwd_chr_charger_type; 

/*---------------------------------------------*/
/* Structures and types                        */
/*---------------------------------------------*/
typedef signed char dwd_rxlev_offset_table_type[70];
typedef signed char dwd_rxlev_offset_table_v2_type[5];
typedef signed char dwd_edge_txcorr_type[32];

typedef signed char dwd_ch_comp_rxlev_offset_table_type[8];

typedef struct
{
   signed char rampup;
   signed char rampdown;
} dwd_pa_timing_elm_type;

typedef dwd_pa_timing_elm_type  pa_timing_offset_table_type[16];

typedef signed int16 dwd_pa_offset_comp_table_type[16];

typedef struct
{
  signed int16 pa_ch_comp0;
  signed int16 pa_ch_comp1;
  signed int16 pa_ch_comp2;
  signed int16 pa_ch_comp3;
}dwd_pa_ch_comp_elm_type;

typedef dwd_pa_ch_comp_elm_type pa_ch_comp_type[16];

typedef unsigned int16 pa_ch_comp_limit_type[4]; // used by DWD_get_gmsk_pa_ch_comp_boundary & DWD_get_edge_pa_ch_comp_boundary

typedef struct
{
  signed char pa_temp_comp0;
  signed char pa_temp_comp1;
  signed char pa_temp_comp2;
  signed char pa_temp_comp3;
  signed char pa_temp_comp4;
}dwd_pa_temp_comp_elm_type;

typedef dwd_pa_temp_comp_elm_type pa_temp_comp_type[16];


typedef unsigned char dwd_pa_vhome_offset_comp_table_type[16];

typedef struct
{
  signed int16 vbat_gain;
  signed int16 vbat_offset;
  signed int16 tbat_gain;
  signed int16 tbat_offset;
  signed int16 tenv_gain;
  signed int16 tenv_offset;
  signed int16 btec_gain;
  signed int16 btec_offset;
  signed int16 tvco_gain;
  signed int16 tvco_offset;
} dwd_adc_adjusted_comp_parms_type;

typedef struct
{
  signed int16 vbat_gain;
  signed int16 vbat_offset;
  signed int16 tbat_gain;
  signed int16 tbat_offset;
  signed int16 tenv_gain;
  signed int16 tenv_offset;
  signed int16 btec_gain;
  signed int16 btec_offset;
  signed int16 tvco_gain;
  signed int16 tvco_offset;
  signed int16 current_gain;
  signed int16 current_offset;
  signed int16 accid_gain;
  signed int16 accid_offset;
}dwd_adc_adjusted_comp_parms_v2_type;

typedef struct
{
  signed int16   vbat_adc_value;  /* Used for battery voltage */
  signed int16   tbat_adc_value;  /* Used for detection of external equipment */
  signed int16   tenv_adc_value;  /* Used for RF temperature  */
  signed int16   btec_adc_value;  /* Used for battery ID */
  signed int16   tvco_adc_value;  /* Not used in Neon */
} dwd_adc_meas_type;

typedef struct
{
  signed int16   vbat_adc_value;  /* Used for battery voltage */
  signed int16   tbat_adc_value;  /* Used for detection of external equipment */
  signed int16   tenv_adc_value;  /* Used for RF temperature  */
  signed int16   btec_adc_value;  /* Used for battery ID */
  signed int16   tvco_adc_value;  /* Not used in Neon */
  signed int16   curr_adc_value;  /* Used in SGOLD */
  signed int16   accid_adc_value; /*Used in SGOLD*/
} dwd_adc_meas_v2_type;

typedef struct
{
  unsigned int16 default_dac_value;
  unsigned int16 dac_step_gsm_in_hz;
} dwd_afc_comp_type;

typedef struct
{
   signed char imei[16];
   unsigned int32 serial_number;
} dwd_ms_id_type;

typedef struct
{
  unsigned int16 id;
  unsigned int16 hw_version;
  unsigned char eep_version;
  unsigned char eep_revision;
} dwd_config_type;

typedef dwd_config_type dwd_updated_config_type;
typedef dwd_config_type dwd_original_config_type;

typedef struct
{
  unsigned int16 result;
  unsigned int16 nof_tests;
  unsigned int16 version;
  unsigned int16 sw_version;
  unsigned int16 spec;
  unsigned int16 testsite_id;
} dwd_test_station_type;

typedef dwd_test_station_type dwd_inline_test_type;
typedef dwd_test_station_type dwd_calib_test_type;
typedef dwd_test_station_type dwd_mmi_test_type;

typedef struct
{
  unsigned char year;
  unsigned char month;
  unsigned char week;
  unsigned char day;
} dwd_production_date_type;

typedef struct
{
  unsigned int16 param_1;
  unsigned int16 param_2;
  unsigned int16 param_3;
  unsigned int16 param_4;
  unsigned int16 param_5;
  unsigned int16 param_6;
  unsigned int16 param_7;
  unsigned int16 param_8;
  unsigned int16 param_9;
} dwd_customer_parm_type;

typedef struct
{
  unsigned int32           serial_no;
  unsigned int16           testseries_id;
  dwd_config_type          orig_conf;
  dwd_config_type          upd_conf;
  dwd_test_station_type    in_line;
  dwd_test_station_type    calib;
  dwd_test_station_type    mmi;
  dwd_production_date_type date;
  dwd_customer_parm_type   cust_parms;
} dwd_production_parm_type;

typedef struct
{
  unsigned int16 static_size;
  unsigned int16 dynamic_size;
  unsigned int16 org_version;
  unsigned long eep_start_addr;
  unsigned int16 upd_revision;
} dwd_get_eep_info_type;

typedef struct
{
  unsigned char number[20];
} dwd_pn_type;

typedef unsigned char dwd_rtc_time_type[DWD_RTC_TIME_STRING_LENGTH + 1];
typedef unsigned char dwd_rtc_date_type[DWD_RTC_DATE_STRING_LENGTH + 1];

typedef struct
{
 unsigned int16 year;
 unsigned char month;
 unsigned char day;
}dwd_rtc_date_val_type;

typedef struct
{
 unsigned char hour;
 unsigned char minute;
 unsigned char second;
 }dwd_rtc_time_val_type;


typedef struct 
{
  dwd_rtc_date_val_type date;
  dwd_rtc_time_val_type time;
 }dwd_rtc_event_datetime_type;

typedef struct
{
 unsigned char string[10];
} dwd_hw_ver_string_type;

typedef struct
{
  unsigned char return_code;
  char  MUTE; /*boolean: If MUTE = 1, then L and R audio muted. If MUTE = 0, then audio not muted.*/
  signed char SSL;	/* Search Stop Level.*/
  char 	HLSI; /*Boolean : HIGH/LOW Side Injection. If HLSI = 1, then HIGH side LO injection. If HLSI = 0, then LOW side LO injection.*/
  char	MS; /*Boolean:	 Mono/Stereo. If MS = 1, then forced mono. If MS = 0, then stereo ON.*/
  char	ML;	/* Boolean: Mute Left. If ML = 1, then left audio channel muted and forced mono. If ML = 0, then not muted.*/
  char	MR;	/* Boolean: Mute Right. If MR = 1, then right audio channel muted and forced mono. If MR = 0, then not muted.*/
  char	BL;	/* Boolean: Band Limits. If BL = 1, then Japan FM band. If BL = 0, then US/Europe FM band.*/
  char	HCC; /* Boolean: High Cut Control. If HCC = 1, then high cut control is ON. If HCC = 0, then high cut control is OFF.*/
}dwd_afr_config_data_type;

typedef struct
{
  unsigned char return_code;
  unsigned char signal_level;
  unsigned int frequency;
  char stereo;
}dwd_afr_read_current_status_type;

typedef struct
{
  unsigned char key[16];
} dwd_cust_key_type;


typedef struct
{
 unsigned int16 reg;
 unsigned int16 value;
} dwd_cam_reg_type;

/*-------------------------------------------------------------------------*/
/*----------------------- S-GOLD Workbench struct -------------------------*/
typedef enum
{
  through_txrach = 0, 
  through_corach = 1 
}dwd_rach_type;  /* T_ATCTST_RACH_TYPE;*/

typedef enum
{
   dwd_loopback_decoded_block,
   dwd_loopback_burst_by_burst,
   dwd_loopback_asym_burst_by_burst,
   dwd_loopback_tx_mixed
} dwd_loopback_mode_type; /* T_DWD_LOOPBACK_MODE_TYPE; */

typedef enum
{
   dwd_cs1,
   dwd_cs2,
   dwd_cs3,
   dwd_cs4,
   dwd_mcs1,
   dwd_mcs2,
   dwd_mcs3,
   dwd_mcs4,
   dwd_mcs5,
   dwd_mcs6,
   dwd_mcs7,
   dwd_mcs8,
   dwd_mcs9
} dwd_cs_type;  

typedef struct /*T_DWD_HOPPING_RF_s*/
{
  unsigned char maio;
  unsigned char hsn;
}dwd_hopping_rf; /*T_DWD_HOPPING_RF;*/


typedef struct /*T_DWD_SINGLE_RF_s*/
{
  unsigned int16  arfcn;
}dwd_single_rf; /*T_DWD_SINGLE_RF;*/


typedef enum
{
  single_rf,
  hopping_rf
}dwd_chn_selpresent; /*T_DWD_CHN_SELPresent; */

typedef struct /*T_DWD_CHN_SEL_s*/
{
  dwd_chn_selpresent present; /*T_DWD_CHN_SELPresent Present;*/
  union
  {
   dwd_single_rf single_rf; /*T_DWD_SINGLE_RF  single_rf;*/
   dwd_hopping_rf hopping_rf; /*T_DWD_HOPPING_RF  hopping_rf;*/
  } U;
}dwd_chn_sel;/*T_DWD_CHN_SEL;*/

typedef struct /*T_DWD_CHANNEL_DESCRIPTION_s*/
{
  dwd_chn_sel       chan_sel; /*T_DWD_CHN_SEL  chan_sel;*/
  unsigned char     channel_type;
  unsigned char     subchannel;
  unsigned char     timeslot_no;
  unsigned char     tsc;
}dwd_channel_description; /*T_DWD_CHANNEL_DESCRIPTION;*/

typedef struct
{
  unsigned int16  A[64];
}dwd_ma_field; /*T_DWD_MA_FIELD;*/


typedef struct /*T_DWD_MOBILE_ALLOCATION_s*/
{
  unsigned int16  rf_chan_cnt;
  dwd_ma_field    rf_chan_no; /*T_DWD_MA_FIELD   rf_chan_no;*/
}dwd_mobile_allocation; /*T_DWD_MOBILE_ALLOCATION;*/


typedef struct /*T_DWD_L1_CHANNEL_ELEM_s*/
{
  dwd_channel_description description; /*T_DWD_CHANNEL_DESCRIPTION  description;*/
  dwd_mobile_allocation   frequency_list; /*T_DWD_MOBILE_ALLOCATION    frequency_list;*/
} dwd_l1_channel_elem; /*T_DWD_L1_CHANNEL_ELEM;*/

typedef struct
{
  unsigned int16 A[8];
} dwd_timeslot_source; /*T_DWD_TIMESLOT_SOURCE; */

typedef struct
{
 unsigned int16 modul;
 signed int16   ioffs;
 signed int16   qoffs;
 unsigned int16 rms;
 signed int16   nsr;
 signed int16   toffs;
 unsigned int16 berl;
 unsigned int16 berh;
 unsigned int16 qual;
 signed int16   foffs;
 unsigned int16 chanord;
 unsigned int16 m_beph;
 unsigned int16 m_bepl;
signed int16   cv_bep;
}dwd_equ_data; /*T_ATCTST_EQU_DATA*/


typedef unsigned int16  dwd_timeslot_allocation; /*T_ATCTST_TIMESLOT_ALLOCATION;*/
typedef unsigned int16  dwd_radio_freq_no; /*T_ATCTST_RADIO_FREQ_NO; */

typedef unsigned short         dwd_radion_freq_no; /* T_ATCTST_RADIO_FREQ_NO; */
typedef unsigned char          dwd_txpwr; /* T_ATCTST_TXPWR; */

typedef struct /*T_ATCTST_AMR_CONFIG_s */
{
    unsigned char  acs;
    unsigned char amr_thrsh[6];
} dwd_amr_config_type;

typedef struct
{
 unsigned int16 id;
 unsigned char dsp_pipe;
 unsigned char nof_parms;
 unsigned int16 parms[22];  
}dwd_dsp_cmd_elm_type;

typedef dwd_dsp_cmd_elm_type dsp_cmd_type[1];

typedef struct
{
  unsigned char color[10];
  unsigned int16 total_time[10];
  unsigned int16 on_time[10];
} dwd_colorstream_type;

typedef struct
{
  signed int16       filter_in_1[5];
  signed int16       filter_in_2[5];
  signed int16       filter_out_1[5];
  signed int16       filter_out_2[5];

  signed int16       scal_in;
  signed int16       scal_out;
  signed int16       scal_mic;
  signed int16       scal_rec;
  signed int16       gain_out;
  signed int16       mic_mute_on;
  signed int16       side_tone_fact;
  signed int16       side_tone_val;
  signed int16       fill_1[4];
  signed int16       hf_on;
  signed int16       hf_analog_gain;
  signed int16       fill_2[3];
  signed int16       dtx_on;

  signed int16       mix_fact_speech;
  signed int16       mix_fact_tone;
  signed int16       hf_step_width;
  signed int16       hf_lms_length;
  signed int16       hf_lms_offset;
  signed int16       hf_block_length;
  signed int16       hf_rxtx_relation;
  signed int16       fill_3[3];
  signed int16       hf_add_atten;
  signed int16       hf_min_atten;
  signed int16       hf_max_atten;

  signed int16       vgtx;
  signed int16       mic_1_2_on; /* 0 = mic 1, otherwise mic 2 */

  signed int16       vg1_on;
  signed int16       vg2_on;
  signed int16       vg1rx;
  signed int16       vg2rx;

  unsigned char      aud_main_state;
  unsigned char      aud_buz_state;
  unsigned char      aud_ear_state;
  unsigned char      aud_mic_state;
  unsigned char      audio_mode;
}DWD_get_audio_data_con_type;

typedef struct
{
  signed int16       freq1;
  signed int16       amp1;
  signed int16       freq2;
  signed int16       amp2;
  signed int16       freq3;
  signed int16       amp3;
  unsigned int16     duration;
}dwd_aud_tone_type;

typedef enum 
{
  dwd_aud_handset_mic,
  dwd_aud_headset_mic,
  dwd_aud_I2S1_rx,  /*aud_bt_headset*/
  dwd_aud_tty_uplink,
  dwd_aud_uplink_source_end
}dwd_aud_uplink_source_enum;

typedef enum
{
  dwd_aud_normal_earpiece,
  dwd_aud_mono_headset,
  dwd_aud_stereo_headset,
  dwd_aud_backspeaker,
  dwd_aud_I2S1_tx, // Bluetooth
  dwd_aud_tty_downlink,
  dwd_aud_downlink_source_end
}dwd_aud_downlink_source_enum;

typedef struct
{
	Bool earpiece;
    Bool mono_headset;
    Bool stereo_headset;
    Bool accessory;
    Bool back_speaker;
    Bool voice_memo_in;
    Bool i2s1_tx_bt_carkit;
    Bool i2s2_tx;
    Bool tty;
}DWD_SGOLD_downlink_data;

typedef struct
{
	Bool handset;
	Bool headset;
    Bool voice_memo;
    Bool i2s1_rx_bt;
    Bool i2s2_rx;
    Bool tty1;
}DWD_SGOLD_uplink_data;

typedef struct {
	signed int16 a0;
	signed int16 a1;
	signed int16 a2;
	signed int16 b1;
	signed int16 b2; 
}DWD_SGOLD_biquad_filters;

typedef struct
{

	Bool vmicmode;
	signed int16 mic; 	// 0 - None
		  		// 1 - MIC1
		  		// 2 - MIC2
	Bool veppn;
	signed int16 veppa;
	signed int16 rxgainpa;
	signed int16 outsel;
	signed int16 outsell;
	signed int16 rxgainlo;
	Bool txgain0;
	Bool txgain1;
	Bool txgain2;
    Bool txgain3; // used by SGOLD2
}DWD_SGOLD_AFE_params;

typedef struct {
	signed int16 duration;
	signed int16 freq1;
	signed int16 freq2;
	signed int16 freq3;
	signed int16 amp1;
	signed int16 amp2;
	signed int16 amp3;
}DWD_SGOLD_tonegen;

typedef struct {
	signed int16 on;
        signed int16 analog_gain;
        signed int16 lms_length;
        signed int16 step_width;
        signed int16 lms_offset;
        signed int16 block_length;
        signed int16 rxtx_relation;
        signed int16 add_atten;
        signed int16 min_atten;
        signed int16 max_atten;
        signed int16 nr_u_fak_0;
        signed int16 nr_sw_2;
        signed int16 nr_u_fak;
}DWD_SGOLD_handsfree;

typedef struct {
	signed int16 scal_in;
	signed int16 scal_mic;
	signed int16 mix_i2s1;
	signed int16 scal_out;
	signed int16 scal_rec;
	signed int16 mix_afe;
	signed int16 scal_sapp;
	signed int16 scal_ext;
	signed int16 side_ton;
	signed int16 gain_out;
	signed int16 delta0;
	signed int16 lambda0;
	signed int16 delta1;
	signed int16 ton_mix;
	signed int16 speech_mix;
	signed int16 kappa0;
	signed int16 kappa1;
	signed int16 lambda1;
	signed int16 alpha0;
	signed int16 alpha1;
	signed int16 gamma0;
	signed int16 mic_mute;
	signed int16 beta0;
	signed int16 beta1;
	signed int16 gamma1;
}DWD_SGOLD_dsp_params;

typedef struct {
	Bool usehex;
	unsigned int volume_step;
	unsigned int dai_mode; 
	unsigned int i2s1_mode;
	unsigned int i2s2_mode;
}DWD_SGOLD_misc_params;


typedef struct {
	DWD_SGOLD_misc_params misc_params;
	DWD_SGOLD_dsp_params dsp_params;
	DWD_SGOLD_AFE_params afe_params;
	DWD_SGOLD_uplink_data uplink_data;
	DWD_SGOLD_downlink_data downlink_data;
	DWD_SGOLD_biquad_filters biquad_in1;
	DWD_SGOLD_biquad_filters biquad_in2;
	DWD_SGOLD_biquad_filters biquad_out1;
	DWD_SGOLD_biquad_filters biquad_out2;
	DWD_SGOLD_handsfree handsfree;
	DWD_SGOLD_tonegen tonegen;
}DWD_SGOLD_AUDIO_data;

// Used by One Second Calibration
typedef struct
{
  unsigned int16 channel_no[50];
}dwd_tx_rx_calib_ch_type;

typedef struct
{
  unsigned char p_lowband[7];
  unsigned char p_highband[7];
}dwd_tx_calib_power_level_type;

typedef struct
{
  unsigned int16 afc_delta_list[10];
}dwd_afc_delta_type; 

typedef struct
{
 unsigned int16 rx_gain[7];
}dwd_rx_gain_setting_type; 

typedef struct
{
 unsigned int16 center_ch[4];
}dwd_rx_center_ch_type; 

typedef struct
{
  unsigned int16 rms[7];
  signed int16 freqoffset;
}dwd_rx_afc_calib_data_type;  

typedef struct
{
  unsigned int16 rms[7];
  signed int16 freqoffset;
  unsigned int16 channel;
}dwd_rx_afc_calib_data_type_v2;


typedef struct
{
 unsigned int16 voltageList[2];
}dwd_adc_calib_voltagelist_type;

typedef struct
{
  signed char ch_comp_rxlev[8];
  signed char rxlev_offset[70];
}dwd_rx_calib_result_type;

typedef struct
{
 unsigned int32 led_on_red;
 unsigned int32 led_on_green;
 unsigned int32 led_on_blue;
 unsigned int32 led_on_white;
 unsigned int32 total_time;
 unsigned int32 on_time;
 unsigned int32 repeat;
 unsigned int32 led_type;
}dwd_led_on_type;

typedef struct
{
 unsigned int32 fade;
 unsigned int32 led_type;
}dwd_led_off_type; 

typedef unsigned char dwd_btd_address_type[6];

typedef struct
{
 unsigned char lm_chip;
 unsigned char lm_x;
 unsigned char lm_y;
 unsigned char lm_z;
 unsigned char bb_chip;
 unsigned char bb_y;
 unsigned char bb_x;
 }dwd_btd_bms_firmware_version_type; // Bluemoon single cellular

 typedef struct
 {
 unsigned char hw_variant;
 unsigned char hw_revision;
 unsigned char hw_sub_revision;
 unsigned char fw_variant;
 unsigned char fw_revision;
 unsigned char fw_sub_revision;
 unsigned char fw_build_number1;
 unsigned char fw_build_number2;
 unsigned char fw_build_number3;
 unsigned char fw_patch_number;
 }dwd_btd_bmu_firmware_version_type;

typedef unsigned char dwd_called_number_type[20]; 

typedef struct
{
  unsigned int32  baud_rate_max;
  unsigned int32  mo_block_width_max;
  unsigned int32  mt_block_width_max;
  unsigned int32  mo_transfer_width_min;
  unsigned int32  mo_transfer_width_max;
  unsigned int32  mt_transfer_width_min;
  unsigned int32  mt_transfer_width_max;
}dwd_start_online_mode_type;

typedef unsigned char dwd_sec_code_type[32]; 

typedef struct
{
unsigned char id_chip[16];
unsigned char id_flash[16];
unsigned char pub_key_hash[20];
}dwd_sec_get_hw_details_type;

typedef struct {
unsigned char imei_label[16];
unsigned char imei_flash[16];
unsigned char imei_otp[16];
}dwd_sec_get_imeis_type;

typedef struct{
unsigned char soft_imei[14];
}dwd_sec_store_soft_imei_type; 

typedef struct
{
 unsigned int16	freq;			
 unsigned int16	amplitude;		
}dwd_tone_value_elm_type;

typedef struct
{
 dwd_tone_value_elm_type tone_value[3];
}dwd_tone_value_type;

typedef struct
{
 unsigned int16 freq_mid;
 unsigned int16 UpperLimit;
 unsigned int16 LowerLimit;
}dwd_mic_value_elm_type;

typedef struct
{
 dwd_mic_value_elm_type mic_value[6];
}dwd_mic_value_type; 

typedef struct
{
 unsigned int16 NoOfFs;
 unsigned int16 NoInLim;
 unsigned int16 ScalIn_Ref;
 unsigned int16 Ppeak;
 unsigned int16 Npeak;
 unsigned int16 Levelfx[6];	
 unsigned int16 result;	
}dwd_audio_measure_result_type;

typedef unsigned char dwd_btd_channel_map_type[10];

typedef struct
{
 unsigned char runtime; //not used currently
 unsigned int16 FFT_PosF1;
 unsigned int16 FFT_UpLimF1;
 unsigned int16 FFT_LowLimF1;
}dwd_AUD_start_FFT_type;

typedef struct
{
 unsigned int32 mo_trans_width;
 unsigned int32 mt_trans_width;
 unsigned int32 mo_block_width;
 unsigned int32 mt_block_width;
}dwd_dwdio_capability_type; 


/*-------------------------------------------------------------------------*/
/*----------exportet function from dwdio.dll  -------------------------------------*/
/*-------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILD_DLL
#define IMPORT_EXPORT __declspec(dllexport)
//#define IMPORT_EXPORT extern ADD BY LF
#else
#define IMPORT_EXPORT __declspec(dllimport)
//#define IMPORT_EXPORT extern ADD BY LF
#endif

#ifndef STDCALL //#ifdef STDCALL Modify by LF 07.06.26
#define CALL_CONVENTION __stdcall
#else
#define CALL_CONVENTION __cdecl
#endif
/*--------------------------------------------------------------------------*/
/* Function used to set up communication. These functions are  described in chapter 3 */
/* in the poduction_test_pc_dll document */
/*--------------------------------------------------------------------------*/
//extern __stdcall bool DWD_set_com_port(unsigned char com_port, int *handle);//Add by LF 
//extern __stdcall bool DWD_check_comm_link(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_com_port(unsigned char com_port, int *handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_close_com_port(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_comm_link(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_baud_rate(int baud, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_DTR(Bool value, int handle); // "true" is the default value
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_RTS(Bool value, int handle); // "false" is the default value
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_v24_mode(dwd_v24_mode_type mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_CTS(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_ms_baudrate(dwd_baud_rate_type baudrate, int handle);
/*---------------------------------------------------------------------------*/
/* Function used to set different test mode. These function are described in chapter 4 in the */
/* production_test_pc_dll document */
/*---------------------------------------------------------------------------*/ 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_test_mode(unsigned int16 mode, unsigned int16 arfcn, int handle);  /* IN LINE, CALIB, MMI */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_umts_fdd_test_mode(unsigned int16 mode, unsigned int16 uarfcn, unsigned int16 primary_sc, int handle);
 /*-----------------------Ends here--------------------------------------------*/

/* ---------------------------------------------------------------------------*/
/* Functions used to RF test. These function is described in Chapter 5 in the */
/* production_test_pc_dll document */ 
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dut_in_idle( Bool *in_idle, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_clear_rxlev(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rxlev(signed char *rxlev_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_pa_offset(unsigned char band, unsigned int16 txpwr, signed int16 offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_pa_timing_offset(unsigned char band, unsigned int16 txpwr,signed char rampup_offset, signed char rampdown_offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rxlev_ch_comp_offset(unsigned char band,dwd_ch_comp_rxlev_offset_table_type *rxlev_ch_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_vhome_offset(unsigned char band, unsigned int16  txpwr, unsigned char offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_edge_pa_ch_comp(unsigned char band, unsigned int16 txpwr, dwd_pa_ch_comp_elm_type *offset, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_gmsk_pa_ch_comp(unsigned char band, unsigned int16 txpwr, dwd_pa_ch_comp_elm_type *offset, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_max_pa_ch_comp(unsigned char band, unsigned char ch_high_low, signed char offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_setup_emergency_call(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_treat_1800_as_1900(unsigned int16 mode, unsigned int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sig_poll_gprs_attached( unsigned char *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sig_gprs_attach_req(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_xbandselect(unsigned int16 band1,unsigned int16 band2,unsigned int16 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bandquery(unsigned int32 *band_list, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_setup_call(unsigned int16 length, dwd_called_number_type number, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_get_generic_info(unsigned int16 *supported,unsigned int16 *nof_sub_bands, unsigned int16 *ant_ext_in_support,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_get_hf_corr_values(unsigned int16 *supported, unsigned int16 *hf_corr_850,unsigned int16 *hf_corr_900, unsigned int16 *hf_corr_1800, unsigned int16 *hf_corr_1900, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_set_antenna_ch_compensation(unsigned int16 band, unsigned int16 ch_range,unsigned int16 offset,unsigned int16 *supported,  int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_set_max_pa_ch_comp_offset(unsigned int16 band, unsigned int16 ch_range,unsigned int16 offset,unsigned int16 *supported,  int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_edge_pa_timing_offset( unsigned char band, unsigned int16 txpwr, signed char rampup_offset, signed char rampdown_offset, int handle );
 
/* NON-Signaling test mode functions */ 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_change_pa_level( unsigned char txpwr, unsigned char txpwr2, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_change_pa_level_v2(unsigned char txpwr1, unsigned char txpwr2, unsigned char txpwr3, unsigned char txpwr4, int handle);

 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_iqrms( unsigned int16 *iqrms, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_iqrms_sample_number( int16 nof_samples, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_gmsk_mode( unsigned int16 mode, unsigned int16 tsc /*training sequence*/,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rf_channel(unsigned int16 arfcn_tp, unsigned int16 arfcn, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rf_mode(unsigned int16 mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rf_gain(unsigned int16 gain_tp, signed char gain, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rf_gain_v2(unsigned int16 gain_tp, signed int16 gain, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_non_sig_set_calib_parm(unsigned char setting, int handle);

 /* Function used in NON-signaling and Signalling mode */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rf_temp( signed char *rf_temp, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_pmb_temp_offset(signed int16 rf_temp_offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_afc(unsigned int16 dac_value, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_afc_v2( unsigned int16 dac_xocal, unsigned int16 dac_xotune, int handle );

/* additional functions */ 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_power_saving(Bool on, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_pa_dac16_range(unsigned int16 band, unsigned char high_txpwr, unsigned char low_txpwr, unsigned int16 *result, unsigned int16 *data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_pa_dac16_range(unsigned int16 band, unsigned char high_txpwr, unsigned char low_txpwr, unsigned int16 *result, unsigned int16 *data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_max_pa_offsets(unsigned char band, unsigned int16 *max_pa_levels_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_serial_interface_mode(dwd_mode_type mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_sw_version(char *sw_version, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_bands_supported(unsigned char *band, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sw_reset(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_power_ramp(unsigned char band, unsigned int16 pa_level, unsigned int16 *ramp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_power_ramp(unsigned char band, unsigned int16 pa_level, unsigned int16 *ramp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_get_mult_rx_iqrms(unsigned int16 *iqrms, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_set_nof_rx_slot(unsigned char nof_rx_slot, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_set_nof_slot(unsigned char nof_tx_slot, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_set_power_ramp_mode(unsigned char mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_set_power_ramps(unsigned int16 *power_ramp1_ptr, unsigned int16 *power_ramp2_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rxlev_gain_offset(unsigned char band,dwd_rxlev_offset_table_type *rxlev_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rxlev_gain_offset_v2( unsigned char band, dwd_rxlev_offset_table_v2_type *rxlev_offsets_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rxlev_gain_offset(unsigned char band,dwd_rxlev_offset_table_type *rxlev_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_rxlev_gain_offset_v2( unsigned char band, dwd_rxlev_offset_table_v2_type *rxlev_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_rxlev_gain_offset(unsigned char band,dwd_rxlev_offset_table_type *rxlev_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_rxlev_gain_offset_v2( unsigned char band,dwd_rxlev_offset_table_v2_type *rxlev_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_txcorr(unsigned char band, dwd_edge_txcorr_type *txcorr,int handle); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_edge_txcorr( unsigned char band,dwd_edge_txcorr_type *txcorr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_get_xo_source(Bool *result, int handle);
 
 
 /* OneSecond Calibration functions */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_set_tx_calib_channel(unsigned int16 nof_ch, dwd_tx_rx_calib_ch_type *ch, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_set_tx_calib_power_levels(dwd_tx_calib_power_level_type *ptr, int handle); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_set_rx_calib_channel(unsigned int16 nof_ch, dwd_tx_rx_calib_ch_type *ch, unsigned int16 NofAfcDelta, unsigned int16 AfcUpdateDist, dwd_afc_delta_type *afc_delta,
 	                          unsigned int16 FchDist, dwd_rx_center_ch_type *CenterCh, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_set_rx_calib_gain(dwd_rx_gain_setting_type *rxgain, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_rx_afc_calib_status(unsigned int16 *status,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_rx_afc_calib_result(unsigned char band,dwd_rx_calib_result_type *RxCalibResult,unsigned int16 *DacValue, unsigned int16 *DacStepGsmInHz, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_rx_afc_calib_data(unsigned int16 channel, dwd_rx_afc_calib_data_type *RxMeasData, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_rx_afc_calib_data_v2(unsigned int16 band, dwd_rx_afc_calib_data_type_v2 *RxMeasData, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_set_adc_calib(unsigned int16 NofSamples, unsigned int16 NofVolt,dwd_adc_calib_voltagelist_type *VoltageList, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_adc_calib_status(unsigned int16 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_adc_calib_result(dwd_adc_adjusted_comp_parms_type *comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_get_xocal(unsigned int16 *xocal,unsigned int16 *xotune, unsigned int16 *dac_step, int handle);

/* UMTS */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_umts_fdd_coprocessor_cmd(unsigned int16 nof_send_bytes, unsigned char *psend, unsigned int16 *nof_receive_bytes, unsigned char *preceive, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_init_rx_cal(unsigned int16 uiUarfcn, unsigned char uiRxMode, unsigned char uiLnaGainMode,unsigned int16 uiPGC_gain, char* rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_set_rx_lna_mode(unsigned char uiLnaMode, char* rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_get_rx_pgc_rssi(signed char *riRxPgcDac, signed int16 *ruiRssiLevel, char *rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_rx_uarfcn(unsigned int16 uiUarfcn, char *rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_init_tx_Cal(unsigned int16 uiUarfcn, unsigned char uiTxMode, unsigned int16 uiBetaC, unsigned int16 uiBetaD,
signed int16 iTxOffsetI, signed int16 iTxOffsetQ, signed char iTxGainI, signed char iTxGainQ, char *rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_set_tx_Gain(unsigned char uiPaMode, unsigned int16 uiVgaGain, unsigned char uiPaBias, char *rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_set_tx_uarfcn(unsigned int16 uiUarfcn, char *rsErrorMsg, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_ucal_set_interface(int handle);
/*---------------------------------------------------------------------------*/
/* Functions used in Base band test. These function are described in chapter 6 in the          */
/* production_test_pc_dll document												 */
/*---------------------------------------------------------------------------*/
  IMPORT_EXPORT Bool CALL_CONVENTION DWD_meas_all_adc(dwd_adc_meas_type *meas_ptr, int handle);
  IMPORT_EXPORT Bool CALL_CONVENTION DWD_meas_all_adc_direct(signed int16 *vbat,signed int16 *tbat,
				      signed int16 *tenv,signed int16 *btec, signed int16 *tvco, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_meas_all_adc_v2( dwd_adc_meas_v2_type *meas_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_meas_all_adc_direct_v2(signed int16 *vbat,signed int16 *tbat,
	  signed int16 *tenv,signed int16 *btec, signed int16 *tvco,signed int16 *curr, int handle );
   
/* IRDA */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_enter_irda_test_mode(unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_exit_irda_test_mode(unsigned int16 *result,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_receive_irda_data(unsigned int16 pattern, unsigned int16 timeout, unsigned int32 baudrate, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_receive_irda_data_v2(unsigned int16 pattern, unsigned int16 timeout, unsigned int32 baudrate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_irda_data(unsigned int16 pattern,unsigned int32 baudrate, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_irda_data_v2(unsigned int16 pattern,unsigned int32 baudrate, unsigned int16 timeout, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_irda_test_result(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_irda_data_continuous(unsigned int16 ibaudrate, unsigned int16 cmd, unsigned int16 *result,int handle);

/* LED test */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_change_intensity(unsigned char color,unsigned char intensity,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_color_off(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_set_color(unsigned int16 color, unsigned int16 time_on, unsigned int16 total_time, unsigned int16 action, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_set_colorstream(unsigned char nof_color,dwd_colorstream_type *color , int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_set_photolight(unsigned int16 action, unsigned int16 intensity, unsigned int16 total_time, unsigned int16 on_time,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_on(dwd_led_on_type *data, signed int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_off(dwd_led_off_type *data, signed int32 *status, int handle);
  
/* Backlight test */ 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bl_get_intensity(unsigned char lcd_tp, unsigned int16 *intensity,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bl_get_status(unsigned int16 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_keypad_backlight_init(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_lcd_backlight_init(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_keypad_backlight(unsigned char action, unsigned int16 fade, unsigned int16 intensity, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_lcd_backlight(unsigned char lcd_tp, unsigned char action, unsigned int16 fade, unsigned int16 intensity,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_switch_off_back_light(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_switch_on_back_light(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bl_set_backlight(unsigned char action,unsigned int16 *result,	int handle);
   
/* Vibrator */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_switch_vibrator_on(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_switch_vibrator_on_continus( int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_switch_vibrator_off(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_vibrator_on(unsigned int16 intensity, unsigned int16 mode, unsigned int16 channel,unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_vibrator_off(unsigned int16 *result, int handle);

/* Real time clock (RTC) */   
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_rtc(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rtc_date_time(dwd_rtc_date_type *date, dwd_rtc_time_type *time,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_program_rtc_date_time(dwd_rtc_date_type *date, dwd_rtc_time_type *time, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_set_date_val(dwd_rtc_date_val_type *date_val, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_get_date_val(dwd_rtc_date_val_type *date_val, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_set_time_val(dwd_rtc_time_val_type *time_val, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_get_time_val(dwd_rtc_time_val_type *time_val, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_set_event_date_time(dwd_rtc_event_datetime_type *event, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_get_event_date_time(dwd_rtc_event_datetime_type *event, dwd_rtc_result_type *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_clear_event_date_time(dwd_rtc_result_type *result, int handle);
      
/* SIM test */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_verify_sim_connection( Bool *sim_ok, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_configure_sim_simulation(unsigned int16 enable_simulation,unsigned int16 *result,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_sim_icc_id(unsigned int16 *result, unsigned char *icc_id, int handle);

/* Charger test */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_charger_inserted(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_charge_mode(unsigned char on, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_chr_set_reverse_charging(unsigned char enable_reverse_charging,unsigned int16 *result,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_chr_get_charger_type(unsigned int16 *result, dwd_chr_charger_type *charger, int handle);
   
/* Graphic device */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_lcd_contrast(unsigned int16 contrast, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_pixel(unsigned char x, unsigned char y, unsigned int16 nof_input_bytes, unsigned char *data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_lcd_test_image(unsigned int16 pattern, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_read_lcd_register(unsigned char address,unsigned char *data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_write_lcd_register(unsigned char address, unsigned char data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_camera_status(unsigned int16 *status,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sleep_camera(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_preview(unsigned int16 mode, unsigned int16 framerate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_preview(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_take_picture(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_put_jpeg_picture(char *filename,unsigned int16 left,unsigned int16 top,unsigned int16 right,unsigned int16 buttom,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_picture(char *filename, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_lcd_contrast_v2(unsigned int32 hw_id, unsigned int32 contrast,unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_lcd_set_pixel(unsigned int32 hw_id,unsigned int32 x, unsigned int32 y, unsigned char data, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_lcd_test_image_v2(unsigned int32 hw_id, unsigned int32 pattern,unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_lcd_contrast_limits(unsigned int32 hw_id, unsigned int32 *min_value, unsigned int32 *def_value, unsigned int32 *max_value, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_cam_enable(unsigned int32 left, unsigned int32 top, unsigned int32 right, unsigned int32 bottom, unsigned int32 * status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_cam_disable(unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_cam_capture(unsigned int32 hw_id, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_compression(unsigned int32 compression,unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_brightness(unsigned int32 brightness, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_get_cam_brightness_limits(unsigned int32 hw_id, unsigned int32 *min_value, unsigned int32 *max_value, 
                                     unsigned int32 *def_value, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_antiflicker_mode(unsigned int32 antiflicker_mode, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_twilight_mode(unsigned int32 twilight_mode, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_image_format(unsigned int32 image_format, unsigned int32 * status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_set_cam_contrast(unsigned int32 contrast, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_get_cam_contrast_limits(unsigned int32 hw_id, unsigned int32 *min_value, unsigned int32 *max_value,
				    unsigned int32 *def_value, unsigned int32 *status, int handle);
 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_read_llc_register(unsigned int32 hw_id, unsigned int32 Register, unsigned int32 *value, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_write_llc_register(unsigned int32 hw_id, unsigned int32 Register, unsigned int32 value, unsigned int32 *status, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_gdd_data_stream(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned char *poutput,unsigned int16 timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_get_lcd_id(unsigned int16 hw_id, unsigned int32 *lcd_id, unsigned int32 *result, int handle);
   
/* KEY test */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_current_key_matrix(unsigned int32 *keymatrix, int handle ); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_current_key_matrix_64bit(unsigned int32 *key_matrix_bit0_31, unsigned int32 *key_matrix_bit32_63 , int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_keyflip_status(unsigned int16 *status,int handle);
 IMPORT_EXPORT long CALL_CONVENTION DWD_get_keypad_reference_matrix(void);
 IMPORT_EXPORT long CALL_CONVENTION DWD_get_keypad_reference_matrix_64(void);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_keypad_reference_matrix(unsigned int32 matrix);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_keypad_reference_matrix_64(unsigned int32 matrix);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_poll_keyboard_result( Bool *result, unsigned int32 *keymatrix, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_poll_keyboard_result_64bit( Bool *result0_31, Bool *result32_63, unsigned int32 *keymatrix0_31, unsigned int32 *keymatrix32_63, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_key_board_test(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_on_key_status(unsigned int16 *status,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_poll_key_matrix_result(unsigned int32 *key_matrix, int handle);

 /* Audio test */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_audio_data(DWD_get_audio_data_con_type *data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_audio(Bool on, unsigned char volume, int handle); // Volume must be in the interval [0;8]
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_audiomode(unsigned char mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_ear_piece(dwd_audio_mode_type mode, unsigned char volume, int handle);  // Volume must be in the interval [0;8]
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_mic(dwd_audio_mode_type mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_speakeramp_handsfree(unsigned char  mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_volumestep(unsigned char  step,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_buzzer_tune(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_buzzer_tune(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_melody_tune(unsigned int16 tune, unsigned char volume, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_melody_tune_hp(unsigned int16 tune, unsigned int16 volume, unsigned int16 timeout, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_melody_tune(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_play_buzzer_tone(unsigned int16 freq, unsigned char duty_cycle, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_intern_poly_ringer(unsigned char tone_id, unsigned int16 nof_repeats,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_intern_poly_ringer(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_extern_poly_ringer(unsigned char tone_id, unsigned int16 nof_repeats,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_extern_poly_ringer(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_audio_uplink_path(unsigned int16 path, unsigned int16 enable, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_audio_downlink_path(unsigned int16 path, unsigned int16 enable, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_update_audio_path(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_audio_parms( unsigned int16  parm_id, signed int16 *data,unsigned int16 nof_bytes, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_buzzer_melody(unsigned char ring_tune, unsigned char duty_cycle,unsigned int16 repeats, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_aud_excute_audio_measurement (unsigned int16 nof_frames, unsigned int16 average_exponent, dwd_tone_value_type *tone_val, 
 dwd_mic_value_type *mic_val, unsigned int16 ref_level, unsigned int16 qformat, unsigned int16 audio_dev_mode, unsigned int16 volume_level, unsigned int16 ref_scal_in,
 unsigned int16 ref_scal_out, dwd_audio_measure_result_type *audio_measure_result, int handle);

/* USB */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_usb_attach_status(unsigned int16 *status, int handle);
   
/* Bluetooth */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_enter_rf_test_mode(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_sw_reset(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_setup_pcm_loopback(Bool turn_on_off, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_check_host_interface(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_check_pcm_interface(Bool *error, unsigned char period, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_tx_burst_mode(unsigned char packet, unsigned char tx_interval, unsigned char tx_channel,
 	                             unsigned char tx_coarse, unsigned char tx_fine, unsigned char pattern, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_tx_cw_mode(unsigned char tx_channel, unsigned char tx_coarse, unsigned char tx_fine,
 	                             unsigned char pattern, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_rx_cw_mode(unsigned char rx_channel,  int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_bluemoon_firmware_version(void *version,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_hw_info(unsigned int16 *bluemoon_type, unsigned int16 *serial_interface_type, unsigned int16 *bluetooth_init, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_init(Bool action, Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_tx_burst_extended_mode(unsigned char packet, unsigned char tx_interval, unsigned char tx_channel,
unsigned char tx_coarse, unsigned char tx_fine, unsigned char pattern,unsigned char hopping, unsigned char whitening, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_afh_channel_map(unsigned char afh_mode, dwd_btd_channel_map_type *ch_map, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_set_tx_cw_extended_mode(unsigned char tx_channel, unsigned char tx_coarse, unsigned char tx_fine, unsigned char pattern,unsigned char offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_check_sleepx_signal(Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_enter_rf_test_mode_extended(dwd_btd_address_type *bluetooth_address, Bool *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_start_fft_test(dwd_AUD_start_FFT_type *fft_data, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_fft_test_result(unsigned int16 *result, int handle);

/* Additional functions */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_battery_status(unsigned char *dest, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_charger_status(unsigned char *dest, int handle); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_capacity_status_direct(  unsigned int16 *capacity_state, unsigned int16 *level,unsigned int16 *availcap,
 	                             unsigned int16 *lastdchg, unsigned int16 *compcap, unsigned int16 *ccr,unsigned int16 *dcr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_charger_status_direct(unsigned int16 *battery_id, unsigned int16 *battery_voltage,unsigned int16 *battery_low_warning,
				     signed char *battery_temperature, signed char *environment_temperature, unsigned int16 *charger_on,unsigned int16 *gl1_mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_gg(Bool *ok, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_battery_info(unsigned char *dest, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_external_keypress(signed int16 key, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_extern_flip_key_simulation(signed int16 keyflip_state, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_external_longkeypress(signed int16 key_value, unsigned int32 delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_bb_version_revision(dwd_bb_ver_enum_type *bb_version, dwd_bb_rev_enum_type *bb_revision, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_mmci_hw_check(signed int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_power_down_mode(unsigned int16 mode, unsigned int32 nof_frames, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_egoldradio_version_revision(dwd_bb_ver_enum_type *bb_version, dwd_bb_EGR_rev_enum_type *bb_revision, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_chr_get_measurement_control_status(unsigned int16 *state, unsigned int16 *battery_id, unsigned int16 *mean_vbat_idle, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_hw_coding( unsigned int16 *hw_coding, unsigned int16 *result, int handle);
/*---------------------------------------------------------------------------*/
/* security function which are described in chapter 7 in production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_ms_id(dwd_ms_id_type *id_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_program_pers_code(unsigned char nof_input_bytes,unsigned char *pers_code,unsigned char *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_user_cmd(unsigned char *data, unsigned char length, 
 	                             void (*rxdone)(unsigned char *rxdata,int16 rx_length),int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_cust_key(dwd_cust_key_type *key);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_imei(signed char imei[14], Bool *already_programmed, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_sec_version(unsigned char *sec_version,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_verify_system_code(unsigned int16 code_id, unsigned int16 code_length, dwd_sec_code_type *code, unsigned int16 *result,  int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_clear_system_code(unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_get_hw_detail(dwd_sec_get_hw_details_type *hw_details, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_get_security_status(unsigned int16 *result,unsigned int16 *sw_version_length, unsigned int16 *boot_core_state,
unsigned int16 *system_access_level, unsigned int16 *key_type, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_freeze_imei(unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_program_data(unsigned char *data, unsigned int16 *result_cause, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_get_lock_status(unsigned int16 *result,unsigned int16 *nof_status_data, unsigned char *status_data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_get_imeis(unsigned int16 *result, dwd_sec_get_imeis_type *imeis, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_store_soft_imei(dwd_sec_store_soft_imei_type *imei, unsigned int16 *result, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_user_cmd_v2(unsigned char *data, unsigned char length,void (*rxdone)(unsigned char *rxdata, int16 rx_length),int handle);
/*---------------------------------------------------------------------------*/
/* Functions to the Non - Volatile memory (NV). These function are described in chapter 8 in */
/* the production_test_pc_dll document. */
/*---------------------------------------------------------------------------*/
/* Production parms */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_config(unsigned char config_id, dwd_config_type *config, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_config(unsigned char config_id, dwd_config_type *config, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_customer_parms(dwd_customer_parm_type *customer, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_customer_parms(dwd_customer_parm_type *customer, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_pn_number(dwd_pn_type *number, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_pn_number(dwd_pn_type *number,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_production_date(dwd_production_date_type *date, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_production_date(dwd_production_date_type *date, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_serial_number(unsigned int32 *serial_number, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_serial_number(unsigned int32 serial_number, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_test_station_parms(unsigned char test_station_id, dwd_test_station_type *parms, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_test_station_parms(unsigned char test_station_id, dwd_test_station_type *parms, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_testseries_id(unsigned int16 *testseries_id, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_testseries_id(unsigned int16 testseries_id, int handle);
 
/* RF Parameters */ 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_pa_offset(unsigned char band,dwd_pa_offset_comp_table_type *pa_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_pa_offset(unsigned char band,dwd_pa_offset_comp_table_type *pa_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_vhome_offset(unsigned char band,dwd_pa_vhome_offset_comp_table_type *vhome_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_vhome_offset(unsigned char band,dwd_pa_vhome_offset_comp_table_type *vhome_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_pa_timing_offset(unsigned char band,pa_timing_offset_table_type *timing_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_pa_timing_offset(unsigned char band,pa_timing_offset_table_type *timing_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_max_pa_ch_comp(signed char *offset_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_max_pa_ch_comp(unsigned char band, unsigned char ch_high_low, signed char offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_gmsk_pa_ch_comp(unsigned char band,pa_ch_comp_type *pa_ch_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_gmsk_pa_ch_comp(unsigned char band,pa_ch_comp_type *pa_ch_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_gmsk_pa_temp_comp(unsigned char band,pa_temp_comp_type *pa_temp_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_gmsk_pa_ch_comp_boundary(unsigned char band, pa_ch_comp_limit_type *limits_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_gmsk_pa_temp_comp(unsigned char band,pa_temp_comp_type *pa_temp_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_pa_ch_comp_boundary(unsigned char band, pa_ch_comp_limit_type *limits_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_pa_ch_comp(unsigned char band,pa_ch_comp_type *pa_ch_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_edge_pa_ch_comp(unsigned char band,pa_ch_comp_type *pa_ch_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_pa_temp_comp(unsigned char band,pa_temp_comp_type *pa_temp_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_edge_pa_temp_comp(unsigned char band,pa_temp_comp_type *pa_temp_comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_edge_pa_timing_offset( unsigned char band,pa_timing_offset_table_type *timing_offsets_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_edge_pa_timing_offset(unsigned char band, pa_timing_offset_table_type *timing_offsets_ptr,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rxlev_ch_comp_offset(unsigned char band, dwd_ch_comp_rxlev_offset_table_type *rxlev_ch_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_rxlev_ch_comp_offset(unsigned char band,dwd_ch_comp_rxlev_offset_table_type *rxlev_ch_offsets_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_rxlev_tmp_comp(signed char *tmp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_rxlev_tmp_comp(unsigned char band, signed char *tmp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_pmb_temp_offset(signed int16 *rf_temp_offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_pmb_temp_offset(signed int16 rf_temp_offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_adc(dwd_adc_adjusted_comp_parms_type *comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_adc_v2(dwd_adc_adjusted_comp_parms_v2_type *comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_adc(dwd_adc_adjusted_comp_parms_type *comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_adc_v2( dwd_adc_adjusted_comp_parms_v2_type *comp_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_adc_direct(signed int16 vbat_gain, signed int16 vbat_offset, signed int16 tbat_gain,
						   signed int16 tbat_offset, signed int16 tenv_gain, signed int16 tenv_offset, signed int16 btec_gain,
						   signed int16 btec_offset, signed int16 tvco_gain, signed int16 tvco_offset, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_adc_direct_v2(signed int16 vbat_gain, signed int16 vbat_offset, signed int16 tbat_gain,
						signed int16 tbat_offset, signed int16 tenv_gain, signed int16 tenv_offset, signed int16 btec_gain,
						signed int16 btec_offset, signed int16 tvco_gain, signed int16 tvco_offset, signed int16 current_gain,
						signed int16 current_offset, signed int16 accid_gain, signed int16 accid_offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_afc(dwd_afc_comp_type *comp_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_afc(dwd_afc_comp_type *comp_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_afc_extended( dwd_afc_comp_type *comp_ptr, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_afc_extended( dwd_afc_comp_type *comp_ptr, int handle );
/* GDD */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_lcd_contrast(unsigned char *contrast, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_lcd_contrast(unsigned char contrast, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_lcd_contrast_sub_display( unsigned char *contrast, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_sub_lcd_contrast(unsigned char contrast, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_lcd_contrast_v2(unsigned int16 hw_id, unsigned int16 *lcd_id, unsigned char *contrast, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_lcd_contrast_v2(unsigned int16 hw_id, unsigned int16 lcd_id, unsigned char contrast, int handle);

/* AUDIO */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_audio_parms(signed int16 *scal_in, signed int16 *scal_out, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_audio_parms(signed int16 scal_in, signed int16 scal_out, int handle);

/* Bluetooth */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_address(dwd_btd_address_type *btd_address, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_get_address(dwd_btd_address_type *btd_address, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_store_address(dwd_btd_address_type *btd_address, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_store_address(dwd_btd_address_type *btd_address, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_tx_power_offset(dwd_btd_tx_power_offset_type *offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_get_tx_power_offset(dwd_btd_bmu_tx_power_offset_type *offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_store_tx_power_offset(dwd_btd_tx_power_offset_type *offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_store_tx_power_offset(dwd_btd_bmu_tx_power_offset_type *offset, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_baud_rate(dwd_btd_baud_rate_type *baudrate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_get_baud_rate(dwd_btd_bmu_baud_rate_type *baudrate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_store_baud_rate(dwd_btd_baud_rate_type *baud_rate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_bmu_store_baud_rate(dwd_btd_bmu_baud_rate_type *baud_rate, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_device_name(unsigned char *btd_device_name, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_store_device_name(unsigned char *btd_device_name, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_get_mode(Bool *OnOff, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_btd_store_mode(Bool OnOff, int handle);
 
/* EE generic function */
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dump_dynamic(unsigned char *data, int nof_bytes, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dump_parameter(unsigned char *data_start, unsigned short int size,
                                     unsigned short int start_addr,unsigned short int dynamic_start_addr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dump_static(unsigned char *data, int remaining_to_process, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dump_static_wchksum(unsigned char *data, int remaining_to_process,unsigned int16 chksum,Bool *chksum_ok, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_eep_info(dwd_get_eep_info_type *eep_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_eep_revision(unsigned int16 *eep_revision,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_eep_version(int *eep_version, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_generic_tag_parms(char *parm_name,void *data, unsigned int nof_bytes,char *tag_name,unsigned char *tag,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_generic_tag_parms(char *parm_name,void *data,unsigned int nof_bytes,char *tag_name,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_parameters(unsigned char *dest, int nof_bytes,
                                      unsigned short int start_addr, unsigned short int dynamic_start_addr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_parm_xx(char *parameter_name, unsigned int nof_bytes, void *data_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_dynamic_parm_xx(char * parameter_name, unsigned int nof_bytes, void *data_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_parm_xx(char *parameter_name, unsigned int nof_bytes, void *data_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_dynamic_parm_xx(char *parameter_name, unsigned int nof_bytes, void *data_ptr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_read_dynamic_nv(unsigned short int start_addr, unsigned short int nof_bytes, void *pdest, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_read_static_nv(unsigned short int start_addr, unsigned short int nof_bytes, void *pdest,  int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_reset_dyn_nv_to_default(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_item_in_nv_mem(unsigned short int item_index, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_to_nv_memory(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_to_nv_wchksum(Bool *checksum_ok,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_store_to_dynamic_nv_memory(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_write_dynamic_nv(unsigned int16 start_addr, unsigned int16 nof_bytes, void *psrc, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_write_static_nv(unsigned int16 start_addr, unsigned int16 nof_bytes, void *psrc, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_set_eep_cfg_filename(char *eep_input_name,int handle);
 IMPORT_EXPORT void CALL_CONVENTION DWD_use_eep_archive(Bool use);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ee_freeze_calib_data(unsigned int32 *result, int handle);
     
/*---------------------------------------------------------------------------*/
/* FFS functions. These functions are desribed in chapter 9 in the production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_ffs_version( unsigned int16 *ffs_version, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_ffs_revision( unsigned int16 *ffs_revision, int handle );
 
/*---------------------------------------------------------------------------*/
/* Workbench functions. These function are described in chapter 10 in the production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_get_ptm(unsigned int32 *fn, dwd_equ_data *equ_data, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_get_si(unsigned int16 *status, unsigned int16 *metric, unsigned char *channel_type, unsigned int16 *arfcn,
                                     unsigned long *fn, unsigned int16 *rms, signed int16 *toffs,signed int32 *qual, signed int16 *foffs, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_fcb_sb(unsigned int16 arfcn, unsigned char fcb_only, unsigned char *fcb_result,
                                      signed int16 *freq_offs, unsigned int16 *qual, unsigned int16 *rms, unsigned char *bsic,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_idle(unsigned int16 arfcn, unsigned char txpwr, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_ptm(unsigned int16 trx_mode, dwd_timeslot_allocation uplnk, dwd_timeslot_allocation downlnk,
                                     dwd_radio_freq_no arfcn, dwd_timeslot_source timeslot_source, dwd_loopback_mode_type loopback_mode, 
                                     unsigned int16 tx_mix_control_cs, dwd_cs_type tx_mix_any_other_cs,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_rach(unsigned int16 ch_req_msg, dwd_tsc_type tsc, unsigned int16 timing_advance, dwd_block_format_type access_burst_type,
                                     dwd_channel_type  channel_type, dwd_radio_freq_no arfcn, dwd_txpwr cs_txpwr, dwd_txpwr ps_txpwr, unsigned char iq_swap,
                                     unsigned int16 bsic, dwd_rach_type rachtype, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_rxlev_band(unsigned char band, unsigned int16 start_arfcn,
                                      unsigned char nof_arfcn_in,unsigned char *nof_arfcn_out, unsigned char *rxlev,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_si(unsigned int16 arfcn,unsigned int16 si_read_mode,unsigned int16 si_indicator,unsigned char pbcch_lr_start,
                                      unsigned char bcch_descr_psi1_repeat_period, unsigned char bcch_descr_bs_pbcch_blks, unsigned char bcch_descr_pb,unsigned char bcch_descr_tsc,
                                      unsigned char bcch_descr_tn,unsigned char bcch_descr_chan_sel_present,unsigned int16 bcch_descr_chan_sel_union_rf,
				      unsigned int16 bcch_descr_mobile_alloc_rf_chan_cnt,unsigned int16 *bcch_descr_mobile_alloc_rf_chan_no, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_tch(unsigned int32 ta, dwd_l1_channel_elem chan, dwd_amr_config_type amr_config, unsigned char audio_enable, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_start_tch_loop(unsigned char tch_loop_mode, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_fcb_sb(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_ptm(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_rach(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_rxlev_band(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_si(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_wrk_stop_tch(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_fwval_setup_adjust_mode(unsigned char flags, int handle); 

/*---------------------------------------------------------------------------*/
/* Generic test benc function described in chapter 11 in the production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gtb_generic(unsigned int16 opcode, unsigned char fileID, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gtb_generic_timeout_delay(unsigned int16 opcode, unsigned char fileID,unsigned int timeout_delay, int handle);

/*---------------------------------------------------------------------------*/
/* Debugging functions described in chapter 12 in the production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_memory_read(unsigned char *dest, unsigned int16 nof_bytes, unsigned int32 address, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ram_modify(unsigned int32 address, unsigned int16 nof_bytes, unsigned char *src, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_trace(void);
 IMPORT_EXPORT void CALL_CONVENTION DWD_stop_trace(void);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_clear_excp_log( int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_provoke_excp(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_trace_extended(char *path,char *filename , int handle );
 IMPORT_EXPORT void CALL_CONVENTION DWD_stop_trace_extended(int write_method, int handle );
/*---------------------------------------------------------------------------*/
/* Misc. function described in chapter 13 in production_test_pc_dll document */
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_monitor_pin_generic_func(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_cam_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_afr_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_afr_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput,unsigned int timeout_delay,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_mmci_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_mmci_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_lcd_generic_func(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *input,unsigned int16 *nof_output_bytes, unsigned char *output, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_pow_management_generic_func(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtt_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sec_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_sim_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_vib_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_aud_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_aud_generic_longint(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_aud_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_aud_generic_longint_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gdd_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bluetooth_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bluetooth_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_acc_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes,unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_chr_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ffs_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ffs_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_util_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_util_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ftl_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ftl_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_nand_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_nand_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_fs_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char* pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_fs_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle); 
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char* pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_led_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gtl_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char* pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gtl_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ee_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ee_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_key_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_key_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_fs_ms_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_fs_ms_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ver_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_ver_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_trap_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_trap_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_emd_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_emd_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rtc_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_iic_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_iic_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_spcu_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_spcu_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_cgu_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_cgu_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_gti_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_atc_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_atc_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_pmu_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_pmu_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dma_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_dma_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_inl_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_cc_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_cc_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bl_generic(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char* pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_bl_generic_timeout_delay(unsigned int16 opcode, unsigned int16 nof_input_bytes, unsigned char * pinput, unsigned int16 * nof_output_bytes, unsigned char * poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_pc3_pow_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_pc3_pow_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 * nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_xdrv_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_xdrv_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 * nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_osc_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 * nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_customer_generic(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_customer_generic_timeout_delay(unsigned int16 opcode, unsigned int32 nof_input_bytes, unsigned char *pinput, unsigned int16 * nof_output_bytes, unsigned char *poutput, unsigned int timeout_delay, int handle);
/*---------------------------------------------------------------------------*/
/* Other functions. These are described in chapter 14 in production_test_pc_dll document  */       
/*---------------------------------------------------------------------------*/
 IMPORT_EXPORT DWD_HINSTANCE CALL_CONVENTION DWD_Get_DLL_Handle(void);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_baseband_present(unsigned int16 *baseband, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_hasp_id(unsigned int32 *id, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_features_present(unsigned int32 *features, int handle);
 IMPORT_EXPORT int  CALL_CONVENTION DWD_get_AT_wrapped_len(unsigned char *data_src, int src_len);
 IMPORT_EXPORT void CALL_CONVENTION DWD_get_buffers(unsigned char **rx,unsigned char **tx, unsigned char **txAT);
 IMPORT_EXPORT int  CALL_CONVENTION DWD_get_com_port_for_handle( int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_dll_version(char *dll_version);
 IMPORT_EXPORT void CALL_CONVENTION DWD_external_debug_message_displayer(void (*show_func)(char *msg));
 IMPORT_EXPORT void CALL_CONVENTION DWD_external_msg_handler(Bool (*process)(void));

/* This is used if it is unacceptable that the calling application can't
   process messages while the DLL is waiting for a respons or sendning
   large amounts of data. The function pointer given to this function
   should process the incomming Windows messages, and return 'true' if
   the calling application has been terminated, i.e. received a WM_QUIT
   message (false otherwise). This function will be called from within
   the DLL during lengthy operations. Note, this will allow the user to
   request a new mobile communication command before a previous one is
   done. The DLL will handle this by returning with error on the new
   request.

   The code for this function for e.g. Borland C++ Builder should be:

   bool process_msg(void)
   {
     Application->ProcessMessages();
     return (Application->Terminated);
   }

   To activate this function: DWD_external_msg_handler(process_msg);
   To deativate: DWD_external_msg_handler(NULL); // this is default 
*/
 IMPORT_EXPORT int  CALL_CONVENTION DWD_get_mail(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rf_present(unsigned int32 *rf, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rx_monitor_start(int handle, void (*process_line)(unsigned char *, int));
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_rx_monitor_stop(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_at_command(unsigned char *at_cmd_str,unsigned char len, unsigned int wait_for_response_timer, unsigned int wait_for_char,unsigned char *at_cmd_resp_str, Bool *timeout, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_buffer(int handle, int length);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_buffer_special(int handle, int length);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_dsp_cmd(unsigned int16 nof_dsp_cmd, dsp_cmd_type *data,int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_user_command(unsigned int16 id,unsigned char *data,unsigned char length,
                                     void (*rxdone)(unsigned char *rxdata,int rx_length),int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_user_command_timeout(unsigned int16 id, unsigned char *data,unsigned char length,
                                     void (*rxdone)(unsigned char *rxdata,int rx_length),unsigned int timeout,int handle);
 IMPORT_EXPORT int CALL_CONVENTION DWD_wrap_AT_data(unsigned char *dest, unsigned char *data_src, int src_len);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_instantaneous_load(unsigned char *load, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_trap_version(unsigned int16 *trap_version,int handle);
 IMPORT_EXPORT char * CALL_CONVENTION DWD_get_last_error(void);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_dll_id_no(unsigned int16 *id);
 IMPORT_EXPORT unsigned int CALL_CONVENTION DWD_Get_ComWindowsHandle(int handle);
 IMPORT_EXPORT void CALL_CONVENTION DWDIO_SetTimeOutDelay(unsigned int delay);
 IMPORT_EXPORT unsigned long CALL_CONVENTION DWDIO_GetTimeoutDelay(void);
 IMPORT_EXPORT void CALL_CONVENTION DWDIO_ResetTimeoutDelay(void);
 IMPORT_EXPORT void CALL_CONVENTION DWD_interrupt_requested_mail(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_atcpwroff(int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_send_atcfun_startup_cmd(int handle);
 IMPORT_EXPORT void CALL_CONVENTION current_directory(char *path);
 IMPORT_EXPORT void CALL_CONVENTION set_current_directory(char *path);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_for_ptest(Bool *result, int handle);
 IMPORT_EXPORT int CALL_CONVENTION DWD_get_handle_for_com_port(unsigned char comport);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_product_name( char *product_name, int handle );
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_check_for_eep_cfg_file(int handle);
 IMPORT_EXPORT char * CALL_CONVENTION DWD_get_eep_cfg_filename(void);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_get_used_eep_static_patch_concept(void);
 IMPORT_EXPORT void CALL_CONVENTION DWD_use_ffs_extended_buffer_size(Bool extended_buffer);
 IMPORT_EXPORT void CALL_CONVENTION DWD_get_dwdio_capability(unsigned int32 version_no, dwd_dwdio_capability_type *capability);
/*--------------------------------------------------------------------*/ 
/*--------------- Miscellaneous functions --------------------------------*/
#ifdef DEBUG_INFO
 IMPORT_EXPORT void CALL_CONVENTION DWD_debug_message_handler(void (*show_line_func)(char *));
#endif
#ifdef ONLINE_MODE_SUPPORT
IMPORT_EXPORT Bool CALL_CONVENTION DWD_start_online_mode(unsigned char ver, unsigned char rev, unsigned int32 baudrate_max, unsigned int32 mo_block_width_max, 
unsigned int32 mt_block_width_max, unsigned int32 mo_trans_width_min, unsigned int32 mo_trans_width_max, unsigned int32 mt_trans_width_min,
unsigned int32 mt_trans_width_max, unsigned int16 dma_monitor_count, unsigned int16 *cause,unsigned char *version, unsigned char *revision, unsigned int32 *baudrate,
unsigned int32 *mo_block_width, unsigned int32 *mt_block_width,unsigned int32 *mo_trans_width,unsigned int32 *mt_trans_width, unsigned int16 *dma_monitor, int handle);

 IMPORT_EXPORT Bool CALL_CONVENTION DWD_stop_online_mode(unsigned int16 *cause, int handle);
 IMPORT_EXPORT Bool CALL_CONVENTION DWD_online_loopback(unsigned int16 nof_input_bytes, unsigned char *pinput,unsigned int16 *nof_output_bytes, unsigned char *poutput, int handle);
#endif

 IMPORT_EXPORT void CALL_CONVENTION DWD_online_mode_status(int *status);

#ifdef __cplusplus
}
#endif
#endif
//---------------------------- End of file --------------------------------------

