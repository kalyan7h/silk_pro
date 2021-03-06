﻿[ ] 
[ ] // *************************************************************************************
[ ] // FILE NAME:	Config.INC
[-] // VERSION:		STFT.0.1
	[ ] //
	[ ] // DESCRIPTION:
	[ ] //   This is configuration file used for all AUTs
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
[ ] // Path where log folder is located
[ ] public const STRING LOG_FOLDER= ROOT_PATH + "\Log"
[ ] 
[ ] // Handle of log file
[ ] public HANDLE LOG_FILE_HANDLE
[ ] 
[ ] // Generic defaults constants used across automation
[ ] public const STRING FAILED = "FAIL"
[ ] public const STRING PASSED = "PASS"
[ ] public String CURRENT_TEST_STATUS = PASSED //Setting the default to passed, in case of exception it will be set to failed
[ ] public const INTEGER DEFAULT_WAIT_TIME = 30
[ ] public const STRING WILDCARD = "*"
[ ] public const STRING DELIMITER = "\"
[ ] 
[ ] // Set below var to true, if you want to drop tables which contains previous result log data.
[ ] const boolean  bFlushPreviousData = False
[ ] 
[ ] //Config functions added by autolab team
[ ] 
[ ] //Function to determine if the test is running in autolab machine or not
[-] boolean IsAutolabMode ( )
	[ ] STRING sTaskInfoIni = "C:\Temp\TaskInfo.ini"
	[-] if (SYS_FileExists (sTaskInfoIni))
		[ ] return TRUE
	[-] else 
		[ ] return FALSE
[ ] 
[ ] //Function to determine if Quicken is installed by autolab or not
[-] boolean  IsQuickenInstalledByAutolab ()
	[ ] STRING sQuickenInstallLog = "C:\Results\InstallQuicken.log"
	[-] if (SYS_FileExists (sQuickenInstallLog))
		[ ] return TRUE
	[-] else 
		[ ] return FALSE
[ ] 
[ ] //Function to get the quicken build path from autolab build share
[-] string GetAutolabQuickenBuildPath ()
	[ ] HINIFILE hIni
	[ ] STRING sProject,sBuild,sAutolabBuildPath
	[ ] hIni = SYS_IniFileOpen ("C:\Temp\TaskInfo.ini")
	[ ] sProject = SYS_IniFileGetValue (hIni, "env","PROJECT")
	[ ] sBuild = SYS_IniFileGetValue (hIni, "env","BUILD")
	[ ] SYS_IniFileClose (hIni)
	[ ] sAutolabBuildPath = "R:\Quicken\{sProject}\{sBuild}"
	[ ] 
	[ ] return sAutolabBuildPath
