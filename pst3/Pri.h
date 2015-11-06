//---------------------------------------------------------------------------

#ifndef PriH
#define PriH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>

void ReadRowDataToBitBuff(unsigned char RowBuff[], int RowLen, BYTE BitBuff[]);
int bmpconvert(const char *pSrc, unsigned char BinBuff[]);
//---------------------------------------------------------------------------
class TPRI_Form : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl_PRI;
    TTabSheet *TabSheet_VoiceMail;
    TTabSheet *TabSheet_SMS;
    TTabSheet *TabSheet_Banner;
    TTabSheet *TabSheet_Emergency;
    TGroupBox *GroupBox_VoiceMail;
    TLabel *Label_VoiceNumber;
    TEdit *Edit_VoiceMail;
    TButton *Button_VoiceMail_Read;
    TButton *Button_VoiceMail_Write;
    TGroupBox *GroupBox2;
    TLabel *Label_SMS1;
    TLabel *Label_SMS2;
    TLabel *Label_SMS3;
    TLabel *Label_SMS4;
    TLabel *Label_SMS5;
    TLabel *Label_SMS6;
    TLabel *Label_SMS7;
    TLabel *Label_SMS8;
    TLabel *Label_SMS9;
    TLabel *Label_SMS10;
    TEdit *Edit_SMSTemplate1;
    TEdit *Edit_SMSTemplate2;
    TEdit *Edit_SMSTemplate3;
    TEdit *Edit_SMSTemplate4;
    TEdit *Edit_SMSTemplate5;
    TEdit *Edit_SMSTemplate6;
    TEdit *Edit_SMSTemplate7;
    TEdit *Edit_SMSTemplate8;
    TEdit *Edit_SMSTemplate9;
    TEdit *Edit_SMSTemplate10;
    TButton *Button_ReadSMS;
    TButton *Button_WriteSMS;
    TGroupBox *GroupBox4;
    TLabel *Label_Banner_File1;
    TLabel *Label_Banner_File2;
    TEdit *Edit_Banner_File1;
    TEdit *Edit_Banner_File2;
    TButton *Button_Banner_Open1;
    TButton *Button_Banner_Open2;
    TOpenDialog *OpenDialog_Banner;
    TGroupBox *GroupBox_Emergency_Number;
    TLabel *Label_EM_Number1;
    TLabel *Label_EM_Number2;
    TLabel *Label_EM_Number3;
    TEdit *Edit_EM_Number1;
    TEdit *Edit_EM_Number3;
    TButton *Button_EM_Read;
    TButton *Button_EM_Write;
    TEdit *Edit_EM_Number2;
    TButton *Button_SetBanner;
    TButton *Button_EM_Clear;
    TButton *Button_VoiceMail_Clear;
    TButton *Button_SMS_Clear;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button_Banner_Open1Click(TObject *Sender);
    void __fastcall Button_Banner_Open2Click(TObject *Sender);
    /*void __fastcall Button_Banner_Open3Click(TObject *Sender);
    void __fastcall Button_Banner_Open4Click(TObject *Sender);
    void __fastcall Button_Banner_Open5Click(TObject *Sender);
    void __fastcall Button_Banner_Open6Click(TObject *Sender);*/
    void __fastcall Button_VoiceMail_WriteClick(TObject *Sender);
    void __fastcall Button_VoiceMail_ReadClick(TObject *Sender);
    void __fastcall Button_EM_WriteClick(TObject *Sender);
    void __fastcall Button_EM_ReadClick(TObject *Sender);
    void __fastcall Button_EM_ClearClick(TObject *Sender);
    void __fastcall Button_VoiceMail_ClearClick(TObject *Sender);
    void __fastcall Button_WriteSMSClick(TObject *Sender);
    void __fastcall Button_ReadSMSClick(TObject *Sender);
    void __fastcall Button_SetBannerClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button_SMS_ClearClick(TObject *Sender);
    
    

private:	// User declarations
public:		// User declarations
    __fastcall TPRI_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPRI_Form *PRI_Form;
//---------------------------------------------------------------------------
#endif
