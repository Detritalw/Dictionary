; 该脚本使用 HM VNISEdit 脚本编辑器向导产生

; 安装程序初始定义常量
!define PRODUCT_NAME "词典"
!define PRODUCT_VERSION "4"
!define PRODUCT_PUBLISHER "Detrital"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\词典.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

SetCompressor lzma

; ------ MUI 现代界面定义 (1.67 版本以上兼容) ------
!include "MUI.nsh"

; MUI 预定义常量
!define MUI_ABORTWARNING
!define MUI_ICON "dictionary.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; 欢迎页面
!insertmacro MUI_PAGE_WELCOME
; 许可协议页面
!define MUI_LICENSEPAGE_CHECKBOX
!insertmacro MUI_PAGE_LICENSE "Readme.md"
; 组件选择页面
!insertmacro MUI_PAGE_COMPONENTS
; 安装目录选择页面
!insertmacro MUI_PAGE_DIRECTORY
; 开始菜单设置页面
var ICONS_GROUP
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "词典"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${PRODUCT_STARTMENU_REGVAL}"
!insertmacro MUI_PAGE_STARTMENU Application $ICONS_GROUP
; 安装过程页面
!insertmacro MUI_PAGE_INSTFILES
; 安装完成页面
!define MUI_FINISHPAGE_RUN "$INSTDIR\词典.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\Readme.md"
!insertmacro MUI_PAGE_FINISH

; 安装卸载过程页面
!insertmacro MUI_UNPAGE_INSTFILES

; 安装界面包含的语言设置
!insertmacro MUI_LANGUAGE "SimpChinese"

; 安装预释放文件
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; ------ MUI 现代界面定义结束 ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "词典(4)安装程序 - dictionary Four Setup.exe"
InstallDir "$PROGRAMFILES\词典"
InstallDirRegKey HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
ShowInstDetails show
ShowUnInstDetails show

Section "主要程序" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "词典.exe"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateDirectory "$SMPROGRAMS\$ICONS_GROUP"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\词典.lnk" "$INSTDIR\词典.exe"
  CreateShortCut "$DESKTOP\词典.lnk" "$INSTDIR\词典.exe"
  CreateDirectory "C:\Windows"
  CreateShortCut "C:\Windows\词典.lnk" "$INSTDIR\词典.exe"
  CreateShortCut "C:\Windows\dictionary.lnk" "$INSTDIR\词典.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "错误文件error.help" SEC02

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "内置库" SEC03
  File "123-123.cd"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "readme.md阅读我!文件" SEC04
  File "Readme.md"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "图标与快捷方式" SEC05
  File "dictionary.ico"
  File "词典.exe"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "源文件[不必要安装]" SEC06
  File "词典.cpp"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -AdditionalIcons
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk" "$INSTDIR\uninst.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\词典.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\词典.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

; 区段组件描述
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} "必须要安装的词典.exe主要的可执行文件。"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC02} "必须要安装的错误文件调查包，用于系统自主查找问题并反馈，如果不安装发生错误时系统会自主弹出。"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC03} "内置的库。"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC04} "ReadmeReadme.md是常用markdown源文件,为解释该文件夹下文件的内容的说明,完整观看需要使用markdown查看器。不必要安装。"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC05} "安装程序的图标，主要程序中不能起作用（我也不知道怎么搞），不必要安装。主要程序的快捷方式，非常有用！您可以在失去、缺失或是需要的地方来复制过去。不必要安装"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC06} "这是主要程序的源文件代码。请注意！此文件中包含知识产权，设计法律问题，请合理使用。因此本软件为开源项目。不必要安装，仅供参考。"
!insertmacro MUI_FUNCTION_DESCRIPTION_END

/******************************
 *  以下是安装程序的卸载部分  *
 ******************************/

Section Uninstall
  !insertmacro MUI_STARTMENU_GETFOLDER "Application" $ICONS_GROUP
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\词典.cpp"
  Delete "$INSTDIR\词典.exe"
  Delete "$INSTDIR\dictionary.ico"
  Delete "$INSTDIR\Readme.md"
  Delete "$INSTDIR\123-123.cd"
  Delete "$INSTDIR\词典.exe"

  Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
  Delete "C:\Windows\dictionary.lnk"
  Delete "C:\Windows\词典.lnk"
  Delete "$DESKTOP\词典.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\词典.lnk"

  RMDir "C:\Windows"
  RMDir "$SMPROGRAMS\$ICONS_GROUP"

  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "不要离开碎屑！明明可以做得更好的...何不向碎屑提交错误或建议呢?碎屑一直在等候您!Detritalw@outlook.com.您确实要卸载$(^Name)吗...?" IDYES +2
  Abort
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name)已经删除了！可能会没有删干净，但绝不是故意的，碎屑等待您的下次到来！"
FunctionEnd
