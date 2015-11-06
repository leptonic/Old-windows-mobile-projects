//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Version.h"
#include "dwdptest.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVersion_Form *Version_Form;

extern bool g_bOpenPort;
extern int g_hPort;
//---------------------------------------------------------------------------
__fastcall TVersion_Form::TVersion_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TVersion_Form::Button_ReadVersionClick(TObject *Sender)
{
    char strVersion[30] = {0};
    int eepVersion;
    unsigned short hwVersion;
    unsigned short ffsVersion ;
    dwd_bb_ver_enum_type bb_version;
    dwd_bb_rev_enum_type bb_revision;
    dwd_config_type config;
    dwd_get_eep_info_type eep_ptr;

    Edit_swVersion->Text = "";
    //Edit_BaseBand->Text = "";
    //Edit_hwVersion->Text = "";
    Edit_eepVersion->Text = "";
    Edit_ffsVersion->Text = "";
    //Edit_ffsVersion->Text = ffsVersion;
    //config.hw_version = 1025;
    //char hw[10];
    //itoa(config.hw_version, hw, 10);
    //Edit_hwVersion->Text = config.hw_version;
    if(g_bOpenPort)
    {
        //if(DWD_check_comm_link(g_hPort))
        //{
            if(DWD_get_sw_version(strVersion, g_hPort))
            {
                //解析出软件版本信息
                Edit_swVersion->Text = strVersion;
            }
            /*if(DWD_get_bb_version_revision(&bb_version,  &bb_revision, g_hPort))
            {
                switch(bb_version)
                {
                    case 0:
                    Edit_BaseBand->Text = "";
                    break;
                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;
                    default:
                    break;
                }
                //解析出Baseband Version
            }       //dwd_updated_config */
            if(DWD_get_config(dwd_updated_config , &config, g_hPort))
            {
                //解析出硬件版本信息与EEP版本信息
                //Edit_hwVersion->Text = config.hw_version;
                //Edit_eepVersion->Text = config.eep_revision;

            }
            //读取EEP版本
            if(DWD_get_eep_info(&eep_ptr, g_hPort))
            {
                Edit_eepVersion->Text = eep_ptr.org_version;
            }
            /*if(DWD_get_eep_version(&eepVersion, g_hPort))
            {
                Edit_eepVersion->Text =eepVersion;
            } */

            if(DWD_get_ffs_version(&ffsVersion, g_hPort))
            {
                Edit_ffsVersion->Text = ffsVersion;
            }
        }
        //Edit_HardWare->Text = "hardware";
    //}
}
//---------------------------------------------------------------------------

void __fastcall TVersion_Form::Button_ClearClick(TObject *Sender)
{
    Edit_swVersion->Text = "";
    //Edit_BaseBand->Text = "";
    //Edit_hwVersion->Text = "";
    Edit_eepVersion->Text = "";
    Edit_ffsVersion->Text = "";
}
//---------------------------------------------------------------------------


/*void __fastcall TVersion_Form::FormCreate(TObject *Sender)
{

} */
//---------------------------------------------------------------------------

void __fastcall TVersion_Form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Version_Form->Hide();
    MainForm->Show();
}
//---------------------------------------------------------------------------


