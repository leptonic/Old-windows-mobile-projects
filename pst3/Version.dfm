object Version_Form: TVersion_Form
  Left = 322
  Top = 155
  Width = 520
  Height = 358
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Version Information'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 33
    Top = 24
    Width = 441
    Height = 227
    Caption = 'Version Information:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object Label2: TLabel
      Left = 31
      Top = 60
      Width = 126
      Height = 16
      Caption = 'SoftWare Version:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 65
      Top = 108
      Width = 92
      Height = 16
      Caption = 'EEP Version:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 67
      Top = 156
      Width = 90
      Height = 16
      Caption = 'FFS Version:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit_swVersion: TEdit
      Left = 184
      Top = 53
      Width = 225
      Height = 24
      ReadOnly = True
      TabOrder = 0
    end
    object Edit_ffsVersion: TEdit
      Left = 184
      Top = 149
      Width = 225
      Height = 24
      ReadOnly = True
      TabOrder = 1
    end
    object Edit_eepVersion: TEdit
      Left = 184
      Top = 101
      Width = 225
      Height = 24
      ReadOnly = True
      TabOrder = 2
    end
  end
  object Button_ReadVersion: TButton
    Left = 114
    Top = 277
    Width = 98
    Height = 33
    Caption = 'Read'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button_ReadVersionClick
  end
  object Button_Clear: TButton
    Left = 298
    Top = 277
    Width = 98
    Height = 33
    Caption = 'Clear '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button_ClearClick
  end
end
