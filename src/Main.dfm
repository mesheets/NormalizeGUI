�
 TNORMALIZE_MAIN 0G  TPF0TNormalize_MainNormalize_MainLeft	Top� BorderIconsbiSystemMenu
biMinimize BorderStylebsSingleCaption@Normalize GUI v0.2.1 by Bruce Heller, Normalize by Manuel KasperClientHeight�ClientWidth�Color	clBtnFaceFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style Menu	MainMenu1OldCreateOrderPositionpoScreenCenterPixelsPerInch`
TextHeight 	TGroupBox
Method_boxLeftTop� Width�HeightYCaption	Method : TabOrder  TRadioButtonMethod_scanLeftTopWidth� HeightCaption
Find peaksChecked	TabOrder TabStop	OnClickMethod_scanClick  TRadioButtonMethode_ratioLeftTop(WidthHeightCaption.Don't find peaks but multiply each sample by :TabOrderOnClickMethode_ratioClick  TRadioButtonMethod_levelLeftTop@WidthHeightCaption&Don't find peaks; amplify by (in dB) :TabOrderOnClickMethod_levelClick  TEditmultiplyLeftTop'Width!HeightTabStopEnabledReadOnly	TabOrderText1  
TScrollBarmultiply_barLeft8Top*Width� HeightLargeChange
Max�MinPageSize PositiondTabOrderOnChangemultiply_barChange  TEditamplifyLeftTop?Width!HeightTabStopEnabledReadOnly	TabOrderText1  
TScrollBaramplify_barLeft8TopAWidth� HeightLargeChange
Max�MinPageSize PositiondTabOrderOnChangeamplify_barChange   	TGroupBoxOptions_boxLeftTop� Width�Height� Caption
Options : TabOrder TLabelpercent_lblLeftTopWidthxHeightCaptionNormalize to (in percent) :  TLabel
buffer_lblLeftTopAWidth� HeightCaption!Specify I/O buffer size (in KB) :  TEditpercentLeftTopWidth!HeightReadOnly	TabOrder Text100  TUpDown
percent_upLeft1TopWidthHeight	AssociatepercentMinPositiondTabOrderWrap  	TCheckBox	abort_lblLeftTop)WidthHeightCaption0Abort if gain increase is smaller than (in dB) :TabOrderOnClickabort_lblClick  TEditabortLeftTop'Width!HeightTabStopEnabledReadOnly	TabOrderText1  
TScrollBar	abort_barLeft8Top)Width� HeightLargeChange
Max�MinPageSize PositiondTabOrderOnChangeabort_barChange  TEditbufferLeftTop@Width,HeightReadOnly	TabOrderText64  
TScrollBar
buffer_barLeft@TopBWidth� HeightLargeChangeMax @MinPageSize Position@SmallChangeTabOrderOnChangebuffer_barChange  	TCheckBoxpromptLeftTopYWidth�HeightCaption$prompt before starting normalizationEnabledTabOrderOnClickpromptClick  	TCheckBox
dont_abortLeftTopqWidth�HeightCaption9don't abort batch if user skips normalization of one fileEnabledTabOrder   TButton	normalizeLeft� ToppWidthKHeightCaptionNormalize !EnabledTabOrderOnClicknormalizeClick  	TGroupBoxinput_output_boxLeftTop0Width�HeightICaptionInput / OutputTabOrder TLabel
InWave_lblLeftTopWidthdHeightCaptionInput PCM WAV file :ParentShowHintShowHint	  	TCheckBoxOutWave_lblLeftTop(Width� HeightCaptionOutput PCM WAV file :ParentShowHintShowHint	TabOrder OnClickOutWave_lblClick  TEditInWaveLeft� TopWidth� HeightTabStopParentShowHintReadOnly	ShowHint	TabOrder  TButtonInWave_bttnLeft�TopWidthHeightCaption...ParentShowHintShowHint	TabOrderOnClickInWave_bttnClick  TEditOutWaveLeft� Top$Width� HeightTabStopEnabledParentShowHintReadOnly	ShowHint	TabOrder  TButtonOutWave_bttnLeft�Top$WidthHeightCaption...EnabledParentShowHintShowHint	TabOrderOnClickOutWave_bttnClick   	TGroupBoxprocess_boxLeftTop Width�Height)CaptionProcessTabOrder TRadioButton
singlefileLeftTopWidth� HeightCaptionSingle file processChecked	ParentShowHintShowHint	TabOrder TabStop	OnClicksinglefileClick  TRadioButton	directoryLeft� TopWidth� HeightCaptionDirectory process (batch)ParentShowHintShowHint	TabOrderOnClickdirectoryClick   TOpenDialogOpenDialog1
DefaultExtWAVFilterPCM WAV file (*.wav)|*.wavOptionsofHideReadOnlyofPathMustExistofFileMustExistofEnableSizing LeftToph  	TMainMenu	MainMenu1Left Toph 	TMenuItemFile1CaptionFile 	TMenuItemOpen1Caption	Open fileOnClick
Open1Click  	TMenuItemOpendirectory1CaptionOpen directoryOnClickOpendirectory1Click  	TMenuItemQuit1CaptionQuitOnClick
Quit1Click   	TMenuItem	Language1CaptionLanguage 	TMenuItemSelectlanguage1CaptionSelect languageOnClickSelectlanguage1Click   	TMenuItemAbout1CaptionAbout 	TMenuItemAbout2CaptionAboutOnClickAbout2Click    TSaveDialogSaveDialog1
DefaultExtWAVFilterPCM WAV file (*.wav)|*.wavOptionsofOverwritePromptofHideReadOnlyofPathMustExistofCreatePromptofEnableSizing Left8Toph   