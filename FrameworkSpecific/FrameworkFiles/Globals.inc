[ ] 
[ ] // *************************************************************************************
[ ] // FILE NAME:	Globals.INC
[+] // VERSION:		STFT.0.1
	[ ] //
	[ ] // DESCRIPTION:
	[ ] //   This include file contains the global level constants.
	[ ] //
	[ ] // DEPENDENCIES:	include.inc
	[ ] //
	[ ] // DEVELOPED BY:	Bhagwat B. Kolde
	[ ] //					Software Test Automation Engineer
	[ ] //					Persistent
	[ ] //
	[ ] // PROJECT:			IV AND V COE
	[ ] //
	[ ] // REVISION HISTORY:
	[ ] //	 10/Oct/06	Bhagwat B. Kolde  Created
[ ] // *************************************************************************************
[ ] 
[ ] // ==========================================================
[+] // INCLUDED FILES
	[ ] use "..\..\FrameworkSpecific\FrameworkFiles\Includes.inc" 	
	[ ] use "..\..\FrameworkSpecific\FrameworkFiles\Config.inc" 
[ ] // ==========================================================
[ ] 
[ ] // ==========================================================
[+] // CONSTENT RECORD TYPES
	[ ] 
	[ ] 
	[ ] 
[ ] // ==========================================================
[ ] 
[ ] // ==========================================================
[+] // TEST SETUP CONSTENTS
	[ ] 
	[+] LIST OF STRING lsDEVELOPERS  = {...}
		[ ] "Bhagwat Kolde"
		[ ] "Parag Shah"
		[ ] "Aksht Sexsena"
		[ ] "Aparna Doshi"
		[ ] "Sonali Mahile"
		[ ] 
	[ ] STRING DEVELOPER = "Bhagwat Kolde"
	[ ] STRING sTCName= GetTestCaseName()
	[ ] STRING sTestCaseId =sTCName
	[ ] 
	[ ] 
[ ] // ==========================================================
[ ] 
[ ] // ==========================================================
[+] // XLS DEFAULT DATA CONSTANTS
	[ ] // Default Dtata
	[ ] const STRING PRODUCT_NAME		=	"Quicken Desktop" //GetDefData()[1][2]
	[ ] const STRING CURRENT_BUILD		=	"QW2013" //GetDefData()[2][2]
	[ ] const STRING DEFAULT_USER			=	"test" //GetDefData()[3][2]
	[ ] const STRING DEFAULT_PWD			=	"test" //GetDefData()[4][2]
	[ ] const STRING SEC_UID					=	"test" //GetDefData()[7][2]
	[ ] const STRING SEC_PASSWORD		=	"test" //GetDefData()[8][2]
	[ ] const STRING FIRST_NAME				=	"test" //GetDefData()[9][2]
	[ ] const STRING LAST_NAME				=	"test" //GetDefData()[10][2]
	[ ] const STRING EMAIL						=	"test" //GetDefData()[11][2]
	[ ] const STRING WORK_PHONE			=	"test" //GetDefData()[12][2]
	[ ] const STRING JOB_TITLE				=	"test" //GetDefData()[13][2]
	[ ] const STRING CITY						=	"test" //GetDefData()[14][2]
	[ ] const STRING STATE						=	"test" //GetDefData()[15][2]
	[ ] const STRING COUNTRY			=	"test" //GetDefData()[16][2]
	[ ] const STRING REGION				=	"test" //GetDefData()[17][2]
	[ ] const STRING WEB_SITE			=	"test" //GetDefData()[18][2]
	[ ] const STRING STREET_ADD			=	"test" //GetDefData()[19][2]
	[ ] const STRING MAIL_STOP			=	"test" //GetDefData()[20][2]
	[ ] const STRING POSTAL_CODE		=	"test" //GetDefData()[21][2]
	[ ] const STRING FAX_NUM			=	"test" //GetDefData()[22][2]
	[ ] const STRING BROWSER			=	"test" //GetDefData()[23][2]
	[ ] const STRING SUITE_NAME			=	"test" //GetDefData()[24][2]
	[ ] 
	[ ] 
[ ] // ==========================================================
[ ] 
[ ] // ==========================================================
[+] // OTHER CONSTANTS
	[ ] const STRING DATA_FILE_DIR 		= "..\..\ApplicationSpecific\Data\TestData"
	[ ] const STRING STR_NEW				= "New"
	[ ] const STRING STR_TRUE 			= "TRUE"
	[ ] const STRING STR_FALSE 			= "FALSE"
	[ ] 
	[ ] 
	[ ] const 	SQL_QUERY_START			= 	"SELECT * FROM "
	[ ] const 	XLS_CONNECT_PREFIX		= 	"DSN=Segue DDA Excel;DBQ="          // Updated by Udita
	[ ] const 	DB_CONNECT_SUFFIX		= 	";UID=;PWD=;"
	[ ] STRING  sDSN						=	"{XLS_CONNECT_PREFIX}{GetDirPath(CurrentPath)}{DATA_FILE_DIR}{DB_CONNECT_SUFFIX}"
	[ ] 
	[ ] // Unzip File
	[ ] STRING	sDATA_BACKUP = BLANK_STR		
	[ ] STRING	sDATA_RESTORE = BLANK_STR		
	[ ] 
	[ ] // Registry data type strings
	[ ] const STRING	sREG_BIN				= 	"REG_BINARY: "
	[ ] const STRING	sREG_DWORD		= 	"REG_DWORD: "
	[ ] 
	[ ] // Registry specific access rights
	[ ] const READ_CONTROL				= 	0x20000
	[ ] const SYNCHRONIZE				= 	0x100000
	[ ] const STD_RIGHTS_READ			= 	(READ_CONTROL)
	[ ] const STD_RIGHTS_WRITE			= 	(READ_CONTROL)
	[ ] const STD_RIGHTS_ALL				= 	0x001F0000
	[ ] const KEY_QUERY_VALUE			= 	0x1
	[ ] const KEY_SET_VALUE				= 	0x2
	[ ] const KEY_CREATE_SUB_KEY		= 	0x4
	[ ] const KEY_ENUM_SUB_KEYS		= 	0x8
	[ ] const KEY_NOTIFY					= 	0x10
	[ ] const KEY_CREATE_LINK			= 	0x20
	[ ] const KEY_READ						= 	((STD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUM_SUB_KEYS | KEY_NOTIFY) & (~SYNCHRONIZE))
	[ ] const KEY_WRITE					= 	((STD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY) & (~ SYNCHRONIZE))
	[ ] const KEY_ALL_ACCESS			= 	((STD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY | KEY_ENUM_SUB_KEYS | KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))
	[ ] 
	[ ] // Common base registry paths
	[ ] const STRING  REG_CAPCITY_PLANNER_PATH 	=	"Software\VMware, Inc.\VMware Capacity Planner\"
	[ ] const STRING  REG_CP_UI_PATH 			=	"{REG_CAPCITY_PLANNER_PATH}VMware Capacity Planner Data Manager\Settings"
	[ ] const STRING  REG_CP_DB_PATH 			=	"{REG_CAPCITY_PLANNER_PATH}Common\Settings"
	[ ] 
	[ ] // Table all template: Column template name
	[ ] // const INTEGER 	colTEMP_NAME = 2
	[ ] STRING gsDelim = "\" 
	[ ] const STRING sSINGLE_CHAR = "x"
	[ ] 
	[ ] // Sleep constants
	[ ] const INTEGER SHORT_SLEEP = 3
	[ ] const INTEGER MEDIUM_SLEEP = 5
	[ ] const INTEGER LONG_SLEEP = 10
	[ ] const INTEGER EXTRA_LONG_SLEEP = 50
	[ ] 
	[ ] STRING ROOT_PATH = "C:\automation"
	[ ] STRING FRM_PATH = ROOT_PATH + "\FrameworkSpecific"
	[ ] STRING APP_PATH = ROOT_PATH + "\ApplicationSpecific"
	[ ] 
	[ ] STRING EXL_PATH = APP_PATH + "..\..\ApplicationSpecific\Data\TestData\TestDriver.xls"
	[ ] STRING CSV_PATH = APP_PATH + "..\..\ApplicationSpecific\Data\TestReportt\CSVLogger.csv"
	[ ] 
	[ ] // Added by Udita on 6/1/2011
	[ ] STRING BACKUP_PATH=APP_PATH + "\Data\TestData\BACKUP"
	[ ] 
	[ ] 
[ ] // ==========================================================
[ ] 
[ ] // ==========================================================
[+] // TABLE COLUMN ENUMERATED TYPES
	[ ] 
	[ ] 
[ ] // ==========================================================
[ ] 
[+] // LIst Types
	[+] public LIST OF ANYTYPE lsListOfMonths ={...}
		[ ] "January"
		[ ] "February"
		[ ] "March"
		[ ] "April"
		[ ] "May"
		[ ] "June"
		[ ] "July"
		[ ] "August"
		[ ] "September"
		[ ] "October"
		[ ] "November"
		[ ] "December"
		[ ] 
	[ ] 
[ ] 
[ ] // ==========================================================
[-] // KEY CONSTENTS
	[ ] public const FILE_ATTRIB_NORMAL				= 0x80						// file normal attribute
	[ ] public const STRING	KEY_EXIT					= "<Alt-F4>"				// close app
	[ ] public const STRING	KEY_BACK				= "<Backspace>"				// get original page
	[ ] public const STRING	KEY_ENTER				= "<Enter>"					// Enter key
	[ ] public const STRING	KEY_TAB					= "<Tab>"					// Tab key
	[ ] public const STRING	KEY_UP					= "<Up>"					// Up Arrow key
	[ ] public const STRING	KEY_DN					= "<Down>"					// Down Arrow key
	[ ] public const STRING	KEY_LT					= "<Left>"					// Left Arrow key
	[ ] public const STRING	KEY_RT					= "<Right>"					// Right Arrow key
	[ ] public const STRING	KEY_SHIFT				= "<Shift>"					// Shift key
	[ ] public const STRING	KEY_EDIT_ALL			= "<Home><Shift-End>"		// select contents of a textfield
	[ ] public const STRING	KEY_EDIT_CLEAR		= KEY_EDIT_ALL + "<Delete>"	// delete contents of a textfield
	[ ] public const STRING BLANK_STR 				= ""						// Blank string value
	[ ] public const STRING	CHR_TAB					= Chr(9)					// Tab character
	[ ] public const STRING	CHR_NUL					= Chr(0)					// Null character
	[ ] public const STRING KEY_ESCAPE 				= "<Esc>"
	[ ] public const STRING KEY_ALT					= "<Alt>"
	[ ] public const STRING KEY_BACKSPACE 		= "<Backspace>"
	[ ] public const STRING KEY_CTL_BREAK 			= "<Break>"
	[ ] public const STRING KEY_CONTROL 			= "<Ctrl>"
	[ ] public const STRING KEY_RETURN 			= "<Enter>"
	[ ] public const STRING KEY_OPEN_BRACE 		= "<Shift-[>"
	[ ] public const STRING KEY_CLOSE_BRACE 		= "<Shift-]>"
	[ ] public const STRING KEY_F1 					= "<F1>"
	[ ] public const STRING KEY_F2 					= "<F2>"
	[ ] public const STRING KEY_F3 					= "<F3>"
	[ ] public const STRING KEY_F4 					= "<F4>"
	[ ] public const STRING KEY_F5 					= "<F5>"
	[ ] public const STRING KEY_F6 					= "<F6>"
	[ ] public const STRING KEY_F7 					= "<F7>"
	[ ] public const STRING KEY_F8 					= "<F8>"
	[ ] public const STRING KEY_F9 					= "<F9>"
	[ ] public const STRING KEY_RIGHT_BRACKET 	= "<Greater>"
	[ ] public const STRING KEY_LEFT_BRACKET 	= "<Less>"
	[ ] public const STRING KEY_PAGE_DOWN 		= "<PgDn>"
	[ ] public const STRING KEY_PAGE_UP 			= "<PgUp>"
	[ ] public const STRING KEY_SPACEBAR 			= "<Space>"
	[ ] public const STRING KEY_CTRL_HOME 		= "<Ctrl-Home>"
	[ ] public const STRING KEY_CTRL_SHIFT_END 	= "<Ctrl-Shift-End>"
	[ ] public const STRING KEY_DELETE 				= "<Delete>"
	[ ] public const STRING KEY_INSERT 				= "<Insert>"
	[ ] public const STRING KEY_CTRL_INSERT 		= "<Ctrl-Insert>"
	[ ] public const STRING KEY_CLOSE_CHILDWIN 	= "<Ctrl-F4>"
	[ ] public const STRING KEY_DBL_QUOTE 		= '"'
	[ ] public const STRING CHR_OpenBrace 			= Chr (123) // {
	[ ] public const STRING CHR_CloseBrace 			= Chr (125) // }
	[ ] public const STRING CHR_Indent 				= Chr (9) // <Tab>
	[ ] public const STRING KEY_CTRL_SHIFT_N		="<Ctrl-Shift-N>"	// // Account Actions on Register///
	[ ] public const STRING KEY_CTRL_H		             ="<Ctrl-h>"
	[ ] public const STRING KEY_CTRL_E		             ="<Ctrl-e>"
	[ ] public const STRING KEY_CTRL_S		             ="<Ctrl-s>"
	[ ] public const STRING KEY_CTRL_F		             ="<Ctrl-f>"
	[ ] public const STRING KEY_ALT_D		             ="<Alt-d>"
	[ ] public const STRING KEY_ALT_E		             ="<Alt-e>"
	[ ] public const STRING KEY_ALT_G		             ="<Alt-g>"
	[ ] public const STRING KEY_ALT_H		             ="<Alt-h>"
	[ ] public const STRING KEY_ALT_N		             ="<Alt-n>"
	[ ] public const STRING KEY_ALT_K		             ="<Alt-k>"
	[ ] public const STRING KEY_ALT_L		             ="<Alt-l>"
	[ ] public const STRING KEY_ALT_R		             ="<Alt-r>"
	[ ] public const STRING KEY_ALT_S		             ="<Alt-s>"
	[ ] public const STRING KEY_ALT_W		             ="<Alt-w>"	
	[ ] public const STRING KEY_ALT_Z		             ="<Alt-z>"		
	[ ] public const STRING KEY_CTRL_L		             ="<Ctrl-l>"
	[ ] public const STRING KEY_ESC		                   ="<ESC>"
	[ ] public const STRING KEY_SPACE	                   ="<Space>"
	[ ] public const STRING KEY_CTRL_SHIFT_E		="<Ctrl-Shift-e>"	// // Launches Edit Account dialog ///
	[ ] public const STRING KEY_CTRL_N              		="<Ctrl-n>"	           // // Moves to new row in the account register ///
	[ ] public const STRING KEY_CTRL_J		             ="<Ctrl-j>"		// Added by Suyash on 13th Feb 2013 for manage reminders dialog
	[ ] public const STRING KEY_CTRL_K		             ="<Ctrl-k>"		// Added by Suyash on 13th Feb 2013 for Calendar dialog
	[ ] public const STRING KEY_CTRL_SHIFT_O 		= "<Ctrl-Shift-o>"
	[ ] public const STRING KEY_CTRL_T 				= "<Ctrl-t>"
	[ ] public const STRING KEY_ALT_F4				="<Alt-f4>"
	[ ] public const STRING KEY_SHIFT_TAB			="<Shift-Tab>"
	[ ] public const STRING KEY_END					="<End>"
	[ ] public const STRING KEY_CTRL_END 			= "<Ctrl-End>"
	[ ] public const STRING KEY_CTRL_SHIFT_C		="<Ctrl-Shift-c>"	// // Launches Category List dialog ///
	[ ] public const STRING KEY_CTRL_Q		             ="<Ctrl-q>"
	[ ] public const STRING KEY_CTRL_B				="<Ctrl-b>"
	[ ] public const STRING KEY_CTRL_O				="<Ctrl-o>"
	[ ] public const STRING KEY_CTRL_P				="<Ctrl-p>"
	[ ] public const STRING KEY_SHIFT_Q				="<Shift-q>"
	[ ] public const STRING KEY_ALT_H_SHIFT_Q        ="<Alt-h><Shift-q>"
	[ ] public const STRING KEY_SHIFT_DOWN			="<Shift-down>" // //Added by Shrivardhan , used to select multiple items ///
	[ ] public const STRING KEY_CTRL_M		             ="<Ctrl-m>"  // //Added by Shrivardhan - for memorized payee list ...... use payee in register ///
	[ ] 
	[ ]  // Added By Dean Shortcut to Maximize Window
	[ ] public const STRING KEY_ALT_SPACE		="<Alt-Space>"            
	[ ] public const STRING KEY_X			="<x>"
	[ ] 
	[ ] public const STRING KEY_CTRL_SHIFT_H   ="<Ctrl-Shift-h>"
	[ ] public const STRING KEY_CTRL_Y	              ="<Ctrl-y>"
	[ ] public const STRING KEY_ALT_F		             ="<Alt-f>"	
	[ ] public const STRING KEY_D		="<d>"
[ ] 
[-] 
	[+] // void setCurrentSuiteId(Integer suiteID)
		[ ] // CURRENT_SUITE_ID = suiteID
		[ ] 
	[ ] 
	[+] //Integer getCurrentSuiteId()
		[ ] //return CURRENT_SUITE_ID
[ ] 
[ ] 
[ ] 
[ ] // ==========================================================
[ ] // *************************************************************************************
[ ] //	END OF INCLUDE FILE
[ ] // *************************************************************************************
[ ] 
