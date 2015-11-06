object PRI_Form: TPRI_Form
  Left = 257
  Top = 168
  Width = 591
  Height = 450
  ActiveControl = TabSheet_VoiceMail
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'PRI Functions and Features'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl_PRI: TPageControl
    Left = 0
    Top = 0
    Width = 569
    Height = 417
    ActivePage = TabSheet_VoiceMail
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    object TabSheet_VoiceMail: TTabSheet
      Caption = 'Voice Mail'
      object GroupBox_VoiceMail: TGroupBox
        Left = 64
        Top = 67
        Width = 433
        Height = 233
        Caption = 'Voice Mail'
        TabOrder = 0
        object Label_VoiceNumber: TLabel
          Left = 55
          Top = 62
          Width = 59
          Height = 16
          Caption = 'Number:'
        end
        object Edit_VoiceMail: TEdit
          Left = 122
          Top = 56
          Width = 249
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 42
          TabOrder = 0
        end
        object Button_VoiceMail_Read: TButton
          Left = 39
          Top = 144
          Width = 80
          Height = 31
          Caption = 'Read'
          TabOrder = 1
          OnClick = Button_VoiceMail_ReadClick
        end
        object Button_VoiceMail_Write: TButton
          Left = 177
          Top = 144
          Width = 80
          Height = 31
          Caption = 'Write'
          TabOrder = 2
          OnClick = Button_VoiceMail_WriteClick
        end
      end
      object Button_VoiceMail_Clear: TButton
        Left = 381
        Top = 209
        Width = 80
        Height = 31
        Caption = 'Clear'
        TabOrder = 1
        OnClick = Button_VoiceMail_ClearClick
      end
    end
    object TabSheet_SMS: TTabSheet
      Caption = 'SMS Template'
      ImageIndex = 1
      object GroupBox2: TGroupBox
        Left = 40
        Top = 8
        Width = 489
        Height = 369
        Caption = 'Sms Template'
        TabOrder = 0
        object Label_SMS1: TLabel
          Left = 46
          Top = 24
          Width = 13
          Height = 16
          Caption = '1:'
        end
        object Label_SMS2: TLabel
          Left = 46
          Top = 54
          Width = 13
          Height = 16
          Caption = '2:'
        end
        object Label_SMS3: TLabel
          Left = 46
          Top = 85
          Width = 13
          Height = 16
          Caption = '3:'
        end
        object Label_SMS4: TLabel
          Left = 46
          Top = 116
          Width = 13
          Height = 16
          Caption = '4:'
        end
        object Label_SMS5: TLabel
          Left = 46
          Top = 146
          Width = 13
          Height = 16
          Caption = '5:'
        end
        object Label_SMS6: TLabel
          Left = 46
          Top = 177
          Width = 13
          Height = 16
          Caption = '6:'
        end
        object Label_SMS7: TLabel
          Left = 46
          Top = 208
          Width = 13
          Height = 16
          Caption = '7:'
        end
        object Label_SMS8: TLabel
          Left = 46
          Top = 238
          Width = 13
          Height = 16
          Caption = '8:'
        end
        object Label_SMS9: TLabel
          Left = 46
          Top = 269
          Width = 13
          Height = 16
          Caption = '9:'
        end
        object Label_SMS10: TLabel
          Left = 38
          Top = 300
          Width = 21
          Height = 16
          Caption = '10:'
        end
        object Edit_SMSTemplate1: TEdit
          Left = 83
          Top = 20
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 0
        end
        object Edit_SMSTemplate2: TEdit
          Left = 83
          Top = 50
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 1
        end
        object Edit_SMSTemplate3: TEdit
          Left = 83
          Top = 81
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 2
        end
        object Edit_SMSTemplate4: TEdit
          Left = 83
          Top = 112
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 3
        end
        object Edit_SMSTemplate5: TEdit
          Left = 83
          Top = 142
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 4
        end
        object Edit_SMSTemplate6: TEdit
          Left = 83
          Top = 173
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 5
        end
        object Edit_SMSTemplate7: TEdit
          Left = 83
          Top = 204
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 6
        end
        object Edit_SMSTemplate8: TEdit
          Left = 83
          Top = 234
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 7
        end
        object Edit_SMSTemplate9: TEdit
          Left = 83
          Top = 265
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 8
        end
        object Edit_SMSTemplate10: TEdit
          Left = 83
          Top = 296
          Width = 349
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 30
          TabOrder = 9
        end
        object Button_ReadSMS: TButton
          Left = 74
          Top = 332
          Width = 79
          Height = 29
          Caption = 'Read'
          TabOrder = 10
          OnClick = Button_ReadSMSClick
        end
        object Button_WriteSMS: TButton
          Left = 214
          Top = 332
          Width = 79
          Height = 29
          Caption = 'Write '
          TabOrder = 11
          OnClick = Button_WriteSMSClick
        end
        object Button_SMS_Clear: TButton
          Left = 354
          Top = 332
          Width = 79
          Height = 29
          Caption = 'Clear'
          TabOrder = 12
          OnClick = Button_SMS_ClearClick
        end
      end
    end
    object TabSheet_Banner: TTabSheet
      Caption = 'Banner'
      ImageIndex = 3
      object GroupBox4: TGroupBox
        Left = 41
        Top = 51
        Width = 481
        Height = 257
        Caption = 'Set Banner'
        TabOrder = 0
        object Label_Banner_File1: TLabel
          Left = 32
          Top = 51
          Width = 35
          Height = 16
          Caption = 'File1'
        end
        object Label_Banner_File2: TLabel
          Left = 32
          Top = 108
          Width = 35
          Height = 16
          Caption = 'File2'
        end
        object Edit_Banner_File1: TEdit
          Left = 89
          Top = 45
          Width = 263
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          TabOrder = 0
        end
        object Edit_Banner_File2: TEdit
          Left = 90
          Top = 103
          Width = 263
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          TabOrder = 1
        end
        object Button_Banner_Open1: TButton
          Left = 377
          Top = 47
          Width = 75
          Height = 25
          Caption = 'Open'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Button_Banner_Open1Click
        end
        object Button_Banner_Open2: TButton
          Left = 379
          Top = 104
          Width = 75
          Height = 25
          Caption = 'Open'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = Button_Banner_Open2Click
        end
        object Button_SetBanner: TButton
          Left = 180
          Top = 184
          Width = 113
          Height = 30
          Caption = 'Set Banner'
          TabOrder = 4
          OnClick = Button_SetBannerClick
        end
      end
    end
    object TabSheet_Emergency: TTabSheet
      Caption = 'Emergency Number'
      ImageIndex = 4
      object GroupBox_Emergency_Number: TGroupBox
        Left = 56
        Top = 65
        Width = 441
        Height = 249
        Caption = 'Emergency Number'
        TabOrder = 0
        object Label_EM_Number1: TLabel
          Left = 68
          Top = 50
          Width = 67
          Height = 16
          Caption = 'Number1:'
        end
        object Label_EM_Number2: TLabel
          Left = 68
          Top = 96
          Width = 67
          Height = 16
          Caption = 'Number2:'
        end
        object Label_EM_Number3: TLabel
          Left = 68
          Top = 143
          Width = 67
          Height = 16
          Caption = 'Number3:'
        end
        object Edit_EM_Number1: TEdit
          Left = 151
          Top = 44
          Width = 223
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 3
          TabOrder = 0
        end
        object Edit_EM_Number3: TEdit
          Left = 151
          Top = 137
          Width = 223
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 3
          TabOrder = 1
        end
        object Button_EM_Read: TButton
          Left = 47
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 2
          OnClick = Button_EM_ReadClick
        end
        object Button_EM_Write: TButton
          Left = 178
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 3
          OnClick = Button_EM_WriteClick
        end
        object Edit_EM_Number2: TEdit
          Left = 151
          Top = 90
          Width = 223
          Height = 24
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 3
          TabOrder = 4
        end
        object Button_EM_Clear: TButton
          Left = 315
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Clear'
          TabOrder = 5
          OnClick = Button_EM_ClearClick
        end
      end
    end
  end
  object OpenDialog_Banner: TOpenDialog
    Left = 616
  end
end
