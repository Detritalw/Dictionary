; �ýű�ʹ�� HM VNISEdit �ű��༭���򵼲���

; ��װ�����ʼ���峣��
!define PRODUCT_NAME "�ʵ�"
!define PRODUCT_VERSION "4"
!define PRODUCT_PUBLISHER "Detrital"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\�ʵ�.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

SetCompressor lzma

; ------ MUI �ִ����涨�� (1.67 �汾���ϼ���) ------
!include "MUI.nsh"

; MUI Ԥ���峣��
!define MUI_ABORTWARNING
!define MUI_ICON "dictionary.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; ��ӭҳ��
!insertmacro MUI_PAGE_WELCOME
; ���Э��ҳ��
!define MUI_LICENSEPAGE_CHECKBOX
!insertmacro MUI_PAGE_LICENSE "Readme.md"
; ���ѡ��ҳ��
!insertmacro MUI_PAGE_COMPONENTS
; ��װĿ¼ѡ��ҳ��
!insertmacro MUI_PAGE_DIRECTORY
; ��ʼ�˵�����ҳ��
var ICONS_GROUP
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "�ʵ�"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${PRODUCT_STARTMENU_REGVAL}"
!insertmacro MUI_PAGE_STARTMENU Application $ICONS_GROUP
; ��װ����ҳ��
!insertmacro MUI_PAGE_INSTFILES
; ��װ���ҳ��
!define MUI_FINISHPAGE_RUN "$INSTDIR\�ʵ�.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\Readme.md"
!insertmacro MUI_PAGE_FINISH

; ��װж�ع���ҳ��
!insertmacro MUI_UNPAGE_INSTFILES

; ��װ�����������������
!insertmacro MUI_LANGUAGE "SimpChinese"

; ��װԤ�ͷ��ļ�
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; ------ MUI �ִ����涨����� ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "�ʵ�(4)��װ���� - dictionary Four Setup.exe"
InstallDir "$PROGRAMFILES\�ʵ�"
InstallDirRegKey HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
ShowInstDetails show
ShowUnInstDetails show

Section "��Ҫ����" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "�ʵ�.exe"

; ������ʼ�˵���ݷ�ʽ
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateDirectory "$SMPROGRAMS\$ICONS_GROUP"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\�ʵ�.lnk" "$INSTDIR\�ʵ�.exe"
  CreateShortCut "$DESKTOP\�ʵ�.lnk" "$INSTDIR\�ʵ�.exe"
  CreateDirectory "C:\Windows"
  CreateShortCut "C:\Windows\�ʵ�.lnk" "$INSTDIR\�ʵ�.exe"
  CreateShortCut "C:\Windows\dictionary.lnk" "$INSTDIR\�ʵ�.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "�����ļ�error.help" SEC02

; ������ʼ�˵���ݷ�ʽ
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "���ÿ�" SEC03
  File "123-123.cd"

; ������ʼ�˵���ݷ�ʽ
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "readme.md�Ķ���!�ļ�" SEC04
  File "Readme.md"

; ������ʼ�˵���ݷ�ʽ
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "ͼ�����ݷ�ʽ" SEC05
  File "dictionary.ico"
  File "�ʵ�.exe"

; ������ʼ�˵���ݷ�ʽ
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "Դ�ļ�[����Ҫ��װ]" SEC06
  File "�ʵ�.cpp"

; ������ʼ�˵���ݷ�ʽ
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
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\�ʵ�.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\�ʵ�.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

#-- ���� NSIS �ű��༭�������� Function ���α�������� Section ����֮���д���Ա��ⰲװ�������δ��Ԥ֪�����⡣--#

; �����������
!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC01} "����Ҫ��װ�Ĵʵ�.exe��Ҫ�Ŀ�ִ���ļ���"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC02} "����Ҫ��װ�Ĵ����ļ������������ϵͳ�����������Ⲣ�������������װ��������ʱϵͳ������������"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC03} "���õĿ⡣"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC04} "ReadmeReadme.md�ǳ���markdownԴ�ļ�,Ϊ���͸��ļ������ļ������ݵ�˵��,�����ۿ���Ҫʹ��markdown�鿴��������Ҫ��װ��"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC05} "��װ�����ͼ�꣬��Ҫ�����в��������ã���Ҳ��֪����ô�㣩������Ҫ��װ����Ҫ����Ŀ�ݷ�ʽ���ǳ����ã���������ʧȥ��ȱʧ������Ҫ�ĵط������ƹ�ȥ������Ҫ��װ"
  !insertmacro MUI_DESCRIPTION_TEXT ${SEC06} "������Ҫ�����Դ�ļ����롣��ע�⣡���ļ��а���֪ʶ��Ȩ����Ʒ������⣬�����ʹ�á���˱����Ϊ��Դ��Ŀ������Ҫ��װ�������ο���"
!insertmacro MUI_FUNCTION_DESCRIPTION_END

/******************************
 *  �����ǰ�װ�����ж�ز���  *
 ******************************/

Section Uninstall
  !insertmacro MUI_STARTMENU_GETFOLDER "Application" $ICONS_GROUP
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\�ʵ�.cpp"
  Delete "$INSTDIR\�ʵ�.exe"
  Delete "$INSTDIR\dictionary.ico"
  Delete "$INSTDIR\Readme.md"
  Delete "$INSTDIR\123-123.cd"
  Delete "$INSTDIR\�ʵ�.exe"

  Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
  Delete "C:\Windows\dictionary.lnk"
  Delete "C:\Windows\�ʵ�.lnk"
  Delete "$DESKTOP\�ʵ�.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\�ʵ�.lnk"

  RMDir "C:\Windows"
  RMDir "$SMPROGRAMS\$ICONS_GROUP"

  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd

#-- ���� NSIS �ű��༭�������� Function ���α�������� Section ����֮���д���Ա��ⰲװ�������δ��Ԥ֪�����⡣--#

Function un.onInit
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "��Ҫ�뿪��м�������������ø��õ�...�β�����м�ύ���������?��мһֱ�ڵȺ���!Detritalw@outlook.com.��ȷʵҪж��$(^Name)��...?" IDYES +2
  Abort
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name)�Ѿ�ɾ���ˣ����ܻ�û��ɾ�ɾ����������ǹ���ģ���м�ȴ������´ε�����"
FunctionEnd
