object Main: TMain
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 140
  ClientWidth = 353
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object TrayIcon: TTrayIcon
    PopupMenu = PopupMenu
    Visible = True
    Left = 32
    Top = 32
  end
  object PopupMenu: TPopupMenu
    Left = 120
    Top = 32
    object miAbout: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      OnClick = miAboutClick
    end
    object miSeparator: TMenuItem
      Caption = '-'
    end
    object miClose: TMenuItem
      Caption = #1047#1072#1082#1088#1099#1090#1100
      OnClick = miCloseClick
    end
  end
end
