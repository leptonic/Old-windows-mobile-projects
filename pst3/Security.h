//---------------------------------------------------------------------------

#ifndef SecurityH
#define SecurityH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

int StringToChar(const char *pSrc, char* pDes, int nLen);
unsigned char StrToInt(char temp);
unsigned short IntToHex(char* str, int nLen);
//void (*rxdone)(unsigned char *rxdata, int rx_length);
/*unsigned short StringToInt(char *pStr, int nLenght);
typedef struct
{
    unsigned char nItem;
    unsigned char nFlag;
    unsigned short Mcc1;
    unsigned short Mcc2;
    unsigned short Mcc3;
    unsigned short Mcc4;
    unsigned char Mnc1;
    unsigned char Mnc2;
    unsigned char Mnc3;
    unsigned char Mnc4;
    unsigned char padding[2];
}MCC_MNC;

typedef struct
{
    unsigned char nItem;
    unsigned char nFlag;
    unsigned char nRandomPin;
    unsigned char PinState;
    char chPinDefault[8];
    char chPinLocked[8];
}SIM_LOCK;

typedef struct
{
    unsigned char nItem;
    unsigned char nFlag;
    unsigned char padding[2];
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
}OTHER_LOCK; */

/*typedef struct
{
    unsigned char nItem;
    unsigned char nFlag;
    unsigned char padding[2];
}GID1_LOCK;

typedef struct
{
    unsigned char nItem;
    unsigned char nFlag;
    unsigned char padding[2];
}GID2_LOCK;*/


//---------------------------------------------------------------------------
class TSecurity_Form : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl_Security;
    TTabSheet *TabSheet_MCC;
    TTabSheet *TabSheet_SIM;
    TTabSheet *TabSheet_Master;
        TGroupBox *GroupBox_MCC_LOCK;
    TRadioButton *RadioButton_MCC_Disable;
    TRadioButton *RadioButton_MCC_Enable;
    TButton *Button_MCC_Read;
    TButton *Button_MCC_Write;
    TGroupBox *GroupBox_SIM_Lock;
    TRadioButton *RadioButton_SIM_Enable;
    TRadioButton *RadioButton_SIM_Disable;
    TCheckBox *CheckBox_Random_SIM_PIN;
    TEdit *Edit_SIM_PIN_Default;
    TEdit *Edit_SIM_PIN_Locked;
    TComboBox *ComboBox_AutoSIMState;
    TButton *Button_SIM_Read;
    TButton *Button_SIM_Write;
        TGroupBox *GroupBox2;
    TRadioButton *RadioButton_IMSI_Enable;
    TRadioButton *RadioButton_IMSI_Disable;
    TButton *Button_IMSI_Read;
    TButton *Button_IMSI_Write;
    TButton *Button_IMSI_Reset;
    TTabSheet *TabSheet_Other;
    TGroupBox *GroupBox_Master_Reset;
    TButton *Button_Reset_Phone;
    TGroupBox *GroupBox_OtherLock;
    TGroupBox *GroupBox_AuotKeyLock;
    TGroupBox *GroupBox_Gid1Lock;
    TGroupBox *GroupBox_Gid2Lock;
    TButton *Button_OtherLock_Read;
    TButton *Button_OtherLock_Write;
    TRadioButton *RadioButton_AutoKey_Unlock;
    TRadioButton *RadioButton_AutoKeyLock;
    TRadioButton *RadioButton_Gid1_Unlock;
    TRadioButton *RadioButton_Gid1_Lock;
    TRadioButton *RadioButton_Gid2_Unlock;
    TRadioButton *RadioButton_Gid2_Lock;
    TLabel *Label_AutoSIM;
    TLabel *Labe_SIM_Default;
    TLabel *Label_SIM_Locked;
    TLabel *Label_MCC;
    TEdit *Edit_MCC1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit_MCC3;
    TEdit *Edit_MCC2;
    TEdit *Edit_MCC4;
    TButton *Button_MCCMNCClear;
    TButton *SIMLock_Clear;
        
    void __fastcall Button_MCC_WriteClick(TObject *Sender);
    void __fastcall Button_SIM_WriteClick(TObject *Sender);
    void __fastcall Button_SIM_ReadClick(TObject *Sender);
    void __fastcall Button_MCC_ReadClick(TObject *Sender);
    void __fastcall Button_MCCMNCClearClick(TObject *Sender);
    void __fastcall Button_IMSI_ReadClick(TObject *Sender);
    void __fastcall Button_IMSI_WriteClick(TObject *Sender);
    void __fastcall Button_OtherLock_ReadClick(TObject *Sender);
    void __fastcall Button_OtherLock_WriteClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button_Reset_PhoneClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button_IMSI_ResetClick(TObject *Sender);
    void __fastcall SIMLock_ClearClick(TObject *Sender);
    void __fastcall TabSheet_MCCShow(TObject *Sender);
    void __fastcall PageControl_SecurityChange(TObject *Sender);
    void __fastcall RadioButton_MCC_DisableClick(TObject *Sender);
    void __fastcall RadioButton_MCC_EnableClick(TObject *Sender);
    void __fastcall RadioButton_SIM_DisableClick(TObject *Sender);
    void __fastcall RadioButton_SIM_EnableClick(TObject *Sender);
    void __fastcall ComboBox_AutoSIMStateClick(TObject *Sender);
    void __fastcall RadioButton_IMSI_DisableClick(TObject *Sender);
    void __fastcall RadioButton_IMSI_EnableClick(TObject *Sender);
    
    
    
private:	// User declarations
public:		// User declarations
        __fastcall TSecurity_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSecurity_Form *Security_Form;
//---------------------------------------------------------------------------
#endif
