//---------------------------------------------------------------------------
#include <inifiles.hpp>
#include   <registry.hpp>
#include <vcl.h>
#pragma hdrstop

#include "V3_KEY.h"
#include "def_paramter.h"
#include "dwdptest.h"
#include "Main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_V3KEY *Form_V3KEY;
//extern int StringToChar(const char *pSrc, char* pDes, int nLen);
extern bool g_bOpenPort;
extern int g_hPort;
extern bool g_bTimeout;
//---------------------------------------------------------------------------
__fastcall TForm_V3KEY::TForm_V3KEY(TComponent* Owner)
    : TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TForm_V3KEY::Button_WriteClick(TObject *Sender)
{
    String strcode[512];
    char strcode_1[16][8]={"1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567","1234567"};

     CITY_CODE  citycodes;
    String strtemp[16];
    memset(&citycodes, 0, sizeof(citycodes));
    citycodes.nItem = CITY_CODE_SET;

   for(int i=0;i<512;i++)
    {
    strcode[i]="1234567";
    }
  
    for(int i=0;i<16;i++)
    {
    strcpy(citycodes.citycode_1[i], strcode_1[i]);

   }

    Button_Write->Enabled = false;
    Button_Read->Enabled = false;
    Button_Clear->Enabled = false;
    bool bResult;
    if(g_bOpenPort)
    {
         try
         {
		 	DWDIO_SetTimeOutDelay(50);
             //DWD_user_command_timeout(COMMAND_CHAR, (unsigned char *)&mcc_mnc, sizeof(mcc_mnc), rxdone2, 200000, g_hPort);
             bResult = DWD_user_command(COMMAND_CHAR, (unsigned char *)&citycodes, sizeof(citycodes), rxdone, g_hPort);
         }
         catch(...)
         {
             ShowMessage("Write ERROR");
             Button_Write->Enabled = true;
             Button_Read->Enabled = true;
             Button_Clear->Enabled = true;
             return;
         }
		 if(!bResult)
         {
            g_bTimeout = true;
			ShowMessage("TimeOut, Please Checking Connection and DUT is on!");
            Button_Write->Enabled = true;
            Button_Read->Enabled = true;
            Button_Clear->Enabled = true;
            return;
         }
    }
    Button_Write->Enabled = true;
    Button_Read->Enabled = true;
    Button_Clear->Enabled = true;
}
//---------------------------------------------------------------------------

bool TForm_V3KEY::Check_Character(String str, int nLen)
{
    char strTemp[36];
    if(str == "")
    {
        return false;
    }
    memset(strTemp, 0, sizeof(strTemp));
    memcpy(strTemp, str.c_str(), nLen);
    for(int i = 0; i < nLen; i++)
    {
        if(strTemp[i] < '0' || (strTemp[i] > '9' && strTemp[i] < 'A') || strTemp[i] > 'F')
        {
            return false;
        }
    }
    //return false;
    return true;
}

/*************************************************************
字符串转换成字节数组, 如"12345678"转换成0x12, 0x34, 0x56, 0x78
输入: pSrc 源字符串
      nLen 源字符串长度
输出: pDes 目标数据指针
**************************************************************/
int TForm_V3KEY::StringToChar(const char *pSrc, unsigned char* pDes, int nLen)
{
    unsigned char ch;
    int j = 0;
    for(int i = 0; i < nLen; i += 2)
    {
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            *pDes = (*pSrc - 0x30) << 4;
        }
        if(*pSrc >= 'A' && *pSrc <= 'F')
        {
            *pDes = (*pSrc - 0x37) << 4;
        }
        pSrc++;
        if(*pSrc >= '0' && *pSrc <= '9')
        {
            *pDes |= *pSrc - 0x30;
        }
        if(*pSrc >= 'A' && *pSrc <= 'F')
        {
            *pDes |= *pSrc - 0x37;
        }
        //*pDes = (*pDes << 4) | ch;
        pSrc++;
        pDes++;
        j++;

    }
    *pDes = '\0';
    return j; //(nLen/2);
}
void __fastcall TForm_V3KEY::Button_ReadClick(TObject *Sender)
{
    unsigned char nItem = CITY_CODE_GET;
    char chcode_1[16][8];

    memset(chcode_1, 0, sizeof(chcode_1));


    Button_Clear->Enabled = false;
    Button_Write->Enabled = false;
    Button_Read->Enabled = false;

    if(g_bOpenPort)
    {
        try
        {
			DWDIO_SetTimeOutDelay(50);

	        if(DWD_user_command(COMMAND_CHAR, &nItem, 1, rxdone, g_hPort))
	        {

                memcpy(chcode_1[0], citycodes.citycode_1[0], 8);
                Edit1->Text = chcode_1[0];

	        }
			else
			{
				ShowMessage("TimeOut, Please Checking the ComPort Connected!");
                Button_Write->Enabled = true;
                Button_Read->Enabled = true;
                Button_Clear->Enabled = true;
				return;
			}
        }
        catch(...)
        {
            ShowMessage("Read V3_KEY ERROR");
            Button_Write->Enabled = true;
            Button_Read->Enabled = true;
            Button_Clear->Enabled = true;
			return;
        }
    }
    Button_Write->Enabled = true;
    Button_Read->Enabled = true;
    Button_Clear->Enabled = true;
}
//---------------------------------------------------------------------------
/*************************************************************
字符串转换成字节数组, 如0x12, 0x34, 0x56, 0x78转换成"12345678"
输入: pSrc 源字符串
      nLen 源字符串长度
输出: pDes 目标数据指针
**************************************************************/
int TForm_V3KEY::ByteToString(const unsigned char *pSrc, char* pDes, int nLen)
{
    const char tab[] = "0123456789ABCDEF";
    for(int i = 0; i < nLen; i++)
    {
        *pDes++ = tab[*pSrc >> 4];
        //pDes++;
        *pDes++ = tab[*pSrc & 0x0F];
        pSrc++;
    }
    *pDes = '\0';
    return nLen * 2;
}

void __fastcall TForm_V3KEY::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Form_V3KEY->Hide();
    MainForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm_V3KEY::Button2Click(TObject *Sender)  //save
{
  char   dir[MAX_PATH];
  char   *tfile   =   "/City_code.ini";
  ::GetCurrentDirectory(MAX_PATH,dir);
  strcat(dir,tfile);
  TIniFile     *ini   =   new   TIniFile(dir);

  for(int i=1 ; i<513; i++)
 {
  String name_tem;
  name_tem=IntToStr(i);
 TEdit   *Labels=(TEdit   *)FindComponent("Edit"+(String)i);
  ini->WriteString("CityCode_Data",name_tem,Labels->Text);
 }



 delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm_V3KEY::Button1Click(TObject *Sender)  //load
{
  char   dir[MAX_PATH];
  char   *tfile   =   "/City_code.ini";
  ::GetCurrentDirectory(MAX_PATH,dir);
  strcat(dir,tfile);

   TIniFile     *ini   =   new   TIniFile(dir);
  //Edit2->Text=ini->ReadString("Data","479","");

    for(int i=1 ; i<513; i++)
 {
 
  String name_tem;
  name_tem=IntToStr(i);
 TEdit   *Labels=(TEdit   *)FindComponent("Edit"+(String)i);
    Labels->Text=ini->ReadString("CityCode_Data",name_tem,"");
 
 }


 delete ini;

} 
//---------------------------------------------------------------------------

void __fastcall TForm_V3KEY::Button3Click(TObject *Sender)
{
 for(int i=1 ; i<513; i++)
 {
 TEdit   *Labels=(TEdit   *)FindComponent("Edit"+(String)i);
 Labels->Text="777";
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm_V3KEY::Button_ClearClick(TObject *Sender)
{
  for(int i=1 ; i<513; i++)
 {
 TEdit   *Labels=(TEdit   *)FindComponent("Edit"+(String)i);
 Labels->Text="";
 }
}
//---------------------------------------------------------------------------

