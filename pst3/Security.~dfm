object Security_Form: TSecurity_Form
  Left = 287
  Top = 194
  Width = 581
  Height = 468
  ActiveControl = TabSheet_MCC
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Security Features'
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
  object PageControl_Security: TPageControl
    Left = 0
    Top = 8
    Width = 569
    Height = 425
    ActivePage = TabSheet_MCC
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControl_SecurityChange
    object TabSheet_MCC: TTabSheet
      Caption = 'MCC/MNC Lock'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnShow = TabSheet_MCCShow
      object GroupBox_MCC_LOCK: TGroupBox
        Left = 51
        Top = 53
        Width = 465
        Height = 209
        Caption = 'MCC/MNC Lock'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Label_MCC: TLabel
          Left = 34
          Top = 88
          Width = 87
          Height = 20
          Caption = 'MCC/MNC:'
        end
        object Label1: TLabel
          Left = 249
          Top = 88
          Width = 87
          Height = 20
          Caption = 'MCC/MNC:'
        end
        object Label2: TLabel
          Left = 34
          Top = 130
          Width = 87
          Height = 20
          Caption = 'MCC/MNC:'
        end
        object Label3: TLabel
          Left = 249
          Top = 130
          Width = 87
          Height = 20
          Caption = 'MCC/MNC:'
        end
        object Edit_MCC1: TEdit
          Left = 128
          Top = 84
          Width = 89
          Height = 28
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 5
          TabOrder = 0
        end
        object Edit_MCC3: TEdit
          Left = 128
          Top = 126
          Width = 89
          Height = 28
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 5
          TabOrder = 1
        end
        object Edit_MCC2: TEdit
          Left = 342
          Top = 84
          Width = 89
          Height = 28
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 5
          TabOrder = 2
        end
        object Edit_MCC4: TEdit
          Left = 342
          Top = 126
          Width = 89
          Height = 28
          ImeName = #26497#21697#20116#31508#36755#20837#27861
          MaxLength = 5
          TabOrder = 3
        end
      end
      object RadioButton_MCC_Disable: TRadioButton
        Left = 139
        Top = 98
        Width = 113
        Height = 17
        Caption = 'Disable'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton_MCC_DisableClick
      end
      object RadioButton_MCC_Enable: TRadioButton
        Left = 343
        Top = 98
        Width = 113
        Height = 17
        Caption = 'Enable'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = RadioButton_MCC_EnableClick
      end
      object Button_MCC_Read: TButton
        Left = 104
        Top = 296
        Width = 81
        Height = 30
        Caption = 'Read'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = Button_MCC_ReadClick
      end
      object Button_MCC_Write: TButton
        Left = 239
        Top = 296
        Width = 81
        Height = 30
        Caption = 'Write'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button_MCC_WriteClick
      end
      object Button_MCCMNCClear: TButton
        Left = 376
        Top = 296
        Width = 81
        Height = 33
        Caption = 'Clear'
        TabOrder = 5
        OnClick = Button_MCCMNCClearClick
      end
    end
    object TabSheet_SIM: TTabSheet
      Caption = 'SIM Lock and IMSI Lock'
      ImageIndex = 1
      object GroupBox_SIM_Lock: TGroupBox
        Left = 56
        Top = 13
        Width = 449
        Height = 215
        Caption = 'SIM Lock'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Label_AutoSIM: TLabel
          Left = 46
          Top = 57
          Width = 131
          Height = 16
          Caption = 'AutoSIM PIN State:'
        end
        object Labe_SIM_Default: TLabel
          Left = 65
          Top = 86
          Width = 113
          Height = 16
          Caption = 'SIM PIN Default:'
        end
        object Label_SIM_Locked: TLabel
          Left = 63
          Top = 120
          Width = 115
          Height = 16
          Caption = 'SIM PIN Locked:'
        end
        object Button_SIM_Read: TButton
          Left = 76
          Top = 178
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 0
          OnClick = Button_SIM_ReadClick
        end
        object Button_SIM_Write: TButton
          Left = 197
          Top = 178
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 1
          OnClick = Button_SIM_WriteClick
        end
        object SIMLock_Clear: TButton
          Left = 319
          Top = 178
          Width = 75
          Height = 25
          Caption = 'Clear'
          TabOrder = 2
          OnClick = SIMLock_ClearClick
        end
      end
      object RadioButton_SIM_Enable: TRadioButton
        Left = 144
        Top = 38
        Width = 113
        Height = 25
        Caption = 'Enable'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = RadioButton_SIM_EnableClick
      end
      object RadioButton_SIM_Disable: TRadioButton
        Left = 294
        Top = 38
        Width = 113
        Height = 25
        Caption = 'Disable'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        OnClick = RadioButton_SIM_DisableClick
      end
      object Edit_SIM_PIN_Default: TEdit
        Left = 248
        Top = 100
        Width = 192
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ImeName = #26497#21697#20116#31508#36755#20837#27861
        MaxLength = 8
        ParentFont = False
        TabOrder = 4
      end
      object Edit_SIM_PIN_Locked: TEdit
        Left = 248
        Top = 131
        Width = 192
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ImeName = #26497#21697#20116#31508#36755#20837#27861
        MaxLength = 8
        ParentFont = False
        TabOrder = 5
      end
      object ComboBox_AutoSIMState: TComboBox
        Left = 248
        Top = 69
        Width = 192
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ImeName = #26497#21697#20116#31508#36755#20837#27861
        ItemHeight = 16
        ParentFont = False
        TabOrder = 6
        OnClick = ComboBox_AutoSIMStateClick
        Items.Strings = (
          'Deactive'
          'Active')
      end
      object CheckBox_Random_SIM_PIN: TCheckBox
        Left = 251
        Top = 158
        Width = 149
        Height = 25
        Caption = 'Random SIM PIN'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
      end
      object GroupBox2: TGroupBox
        Left = 58
        Top = 245
        Width = 449
        Height = 132
        Caption = 'IMSI Lock'
        TabOrder = 7
        object RadioButton_IMSI_Enable: TRadioButton
          Left = 102
          Top = 38
          Width = 113
          Height = 17
          Caption = 'Enable'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = RadioButton_IMSI_EnableClick
        end
        object RadioButton_IMSI_Disable: TRadioButton
          Left = 264
          Top = 38
          Width = 113
          Height = 17
          Caption = 'Disable'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = RadioButton_IMSI_DisableClick
        end
        object Button_IMSI_Read: TButton
          Left = 45
          Top = 82
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 2
          OnClick = Button_IMSI_ReadClick
        end
        object Button_IMSI_Write: TButton
          Left = 197
          Top = 82
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 3
          OnClick = Button_IMSI_WriteClick
        end
        object Button_IMSI_Reset: TButton
          Left = 333
          Top = 82
          Width = 75
          Height = 25
          Caption = 'Reset'
          TabOrder = 4
          OnClick = Button_IMSI_ResetClick
        end
      end
    end
    object TabSheet_Master: TTabSheet
      Caption = 'Master Reset'
      ImageIndex = 2
      object GroupBox_Master_Reset: TGroupBox
        Left = 56
        Top = 80
        Width = 465
        Height = 177
        Caption = 'Master Reset'
        TabOrder = 0
        object Button_Reset_Phone: TButton
          Left = 144
          Top = 128
          Width = 169
          Height = 33
          Caption = 'Reset Phone'
          TabOrder = 0
          OnClick = Button_Reset_PhoneClick
        end
      end
    end
    object TabSheet_Other: TTabSheet
      Caption = 'Other Lock'
      ImageIndex = 3
      object GroupBox_OtherLock: TGroupBox
        Left = 37
        Top = 36
        Width = 497
        Height = 305
        Caption = 'Other Lock'
        TabOrder = 0
        object GroupBox_AuotKeyLock: TGroupBox
          Left = 32
          Top = 32
          Width = 201
          Height = 105
          Caption = 'Auto Key Lock'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          object RadioButton_AutoKey_Unlock: TRadioButton
            Left = 40
            Top = 40
            Width = 107
            Height = 17
            Caption = 'Unlock'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object RadioButton_AutoKeyLock: TRadioButton
            Left = 40
            Top = 72
            Width = 107
            Height = 17
            Caption = 'Lock'
            TabOrder = 1
          end
        end
        object GroupBox_Gid1Lock: TGroupBox
          Left = 32
          Top = 168
          Width = 201
          Height = 105
          Caption = 'Gid1 Lock'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          object RadioButton_Gid1_Unlock: TRadioButton
            Left = 32
            Top = 44
            Width = 104
            Height = 17
            Caption = 'Unlock'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object RadioButton_Gid1_Lock: TRadioButton
            Left = 32
            Top = 72
            Width = 104
            Height = 17
            Caption = 'Lock'
            TabOrder = 1
          end
        end
        object GroupBox_Gid2Lock: TGroupBox
          Left = 264
          Top = 168
          Width = 201
          Height = 105
          Caption = 'Gid2 Lock'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          object RadioButton_Gid2_Unlock: TRadioButton
            Left = 32
            Top = 40
            Width = 137
            Height = 17
            Caption = 'Unlock'
            Checked = True
            TabOrder = 0
            TabStop = True
          end
          object RadioButton_Gid2_Lock: TRadioButton
            Left = 32
            Top = 71
            Width = 145
            Height = 17
            Caption = 'Lock'
            TabOrder = 1
          end
        end
        object Button_OtherLock_Read: TButton
          Left = 328
          Top = 48
          Width = 75
          Height = 25
          Caption = 'Read'
          TabOrder = 3
          OnClick = Button_OtherLock_ReadClick
        end
        object Button_OtherLock_Write: TButton
          Left = 328
          Top = 96
          Width = 75
          Height = 25
          Caption = 'Write'
          TabOrder = 4
          OnClick = Button_OtherLock_WriteClick
        end
      end
    end
  end
end
