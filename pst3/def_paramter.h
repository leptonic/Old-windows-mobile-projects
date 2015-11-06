#ifndef _DEF_PARAMTER_H_
#define _DEF_PARAMTER_H_

#define MAX_SMS_TEXT_LENGTH 31
#define MAX_VOICEMAIL_NUMBER_LENGTH 42
#define OK 1
#define ERROR 0
#define COMMAND_CHAR 9
extern "C" void rxdone(unsigned char *rxdata, int rx_length);
/************ Command Type *************/
enum user_pts_command
{
  MCC_MNC_LOCK_SET = 0,
  MCC_MNC_LOCK_GET,
  SIM_LOCK_SET,
  SIM_LOCK_GET,
  IMSI_LOCK_SET,
  IMSI_LOCK_GET,
  IMSI_LOCK_RESET,
  MASTER_RESET_SET,
  DEFAULT_STARTUP_SET,
  OTHER_LOCK_SET,
  OTHER_LOCK_GET,
  VOICE_MAIL_SET,
  VOICE_MAIL_GET,
  SMS_TEMPLATE_SET,
  SMS_TEMPLATE_GET,
  BANNER_SET,
  BANNER_GET,
  EMERGENCY_NUMBER_SET,
  EMERGENCY_NUMBER_GET,
  V3_KEY_SET,
  V3_KEY_GET,
  CITY_CODE_GET,
  CITY_CODE_SET
};

/************     PRI Struct   *************/
typedef struct
{
    unsigned char nItem;
	char chVoiceNumber[MAX_VOICEMAIL_NUMBER_LENGTH];
	unsigned char padding;
}VOICE_MAIL;

typedef struct
{
    unsigned char nItem;
    BYTE index;
	WCHAR chSmsTemplate[MAX_SMS_TEXT_LENGTH];
	unsigned char padding[1];
}SMS_TEMPLATE;

typedef struct
{
    unsigned char nItem;        // Function Item.
    BYTE    index;              //NO. BMP picture.
    BYTE    nLen;               //bmp picture data length
    BYTE    nFrame;             //bmp data divided fraem count.
	BYTE    height;             //bmp picture height.
    BYTE    width;               //bmp picture width.
    BYTE	bits;		         // how may bits for one pixel.
    BYTE    p_bitmap[181];       // pointer to bitmap data
}SET_BANNER;

typedef struct
{
    unsigned char nItem;
	char chEmergencyNumber1[4];
	char chEmergencyNumber2[4];
	char chEmergencyNumber3[4];
	unsigned char padding[3];
}EMERGENCY_NUMBER;


/************     SECURITY Struct    *************/
typedef struct{
    unsigned char mcc[2];
    unsigned char mnc;
	unsigned char padding;
}MCCMNC_STRUCT;

typedef struct{
    unsigned char nItem;
    MCCMNC_STRUCT MCCMNC[4];
    unsigned char mccmnc_lock_available;
//	unsigned char padding[2];  /*temporary delete*/
}MCC_MNC; //16

typedef struct
{
    unsigned char nItem;
    char chPinDefault[8];
    char chPinLocked[8];
    unsigned char auto_pin_available;
    unsigned char radom_sim_pin;
    unsigned char auto_sim_pin_state;
}SIM_LOCK_1;

typedef struct
{
    unsigned char nItem;
	unsigned char nFlag;
    char chIMSINumber[10];
}IMSI_LOCK;

typedef struct
{
	unsigned char nItem;
	unsigned char padding[3];
}MASTER_RESET;

typedef struct
{
    unsigned char nItem;
    unsigned char nFlagAutokeyLock;
    unsigned char nFlagGid1;
    unsigned char nFlagGid2;
}OTHER_LOCK;

typedef struct
{
    unsigned char nItem;
    char manufacturer[2];
	char ver[2];
	char des3_km[161];
    //unsigned char padding;
}V3_KEY_TYPE;
typedef struct{	
        unsigned char nItem;
   char citycode_1[16][8]; 
}CITY_CODE;
extern VOICE_MAIL voice_mail;
extern SMS_TEMPLATE sms_template;
extern EMERGENCY_NUMBER emergency_number;
extern SET_BANNER set_banner ;
extern MCC_MNC mcc_mnc ;
extern SIM_LOCK_1 sim_lock ;
extern IMSI_LOCK imsi_lock ;
extern OTHER_LOCK other_lock;
extern SET_BANNER set_banner;
extern V3_KEY_TYPE v3_key;
extern CITY_CODE citycodes;
#endif
