object Prompt_Form: TPrompt_Form
  Left = 294
  Top = 231
  Width = 503
  Height = 324
  BorderIcons = []
  Caption = 'Prompt'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label_Prompt: TLabel
    Left = 0
    Top = 0
    Width = 495
    Height = 297
    Align = alClient
    Alignment = taCenter
    Caption = 'Please Waiting ......'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Layout = tlCenter
  end
  object Timer: TTimer
    Left = 32
    Top = 40
  end
end
