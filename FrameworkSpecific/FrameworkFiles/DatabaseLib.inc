﻿[ ] 
[ ] // *************************************************************************************
[ ] // FILE NAME:	DatabaseLib.INC
[+] // VERSION:		STFT.0.1
	[ ] //
	[ ] // DESCRIPTION:
	[ ] //   This include file contains the library functions for Access Database and storing results in it.
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
[-] // INCLUDED FILES
	[ ] use "..\..\FrameworkSpecific\FrameworkFiles\Includes.inc" 	
	[ ] // ==========================================================
[ ] 
[ ] private type OBJECT is WINDOW		
[ ] OBJECT Access = AccessDB()
[ ] 
[ ] private type OBJECT_SUITE is WINDOW	
[ ] OBJECT_SUITE Suites = Suite()
[ ] 
[ ] private type OBJECT_TC is WINDOW
[ ] OBJECT_TC Testcases = TestCase()
[ ] 
[ ] private type OBJECT_STEP is WINDOW
[ ] OBJECT_STEP Steps = Step()
[ ] 
[ ] private type OBJECT_Env is WINDOW	
[ ] OBJECT_Env Environments = Environment()
[ ] 
[ ] String CURRENT_TEST_RUN_ID
[ ] LIST of  LIST of String lsToolId 
[ ] STRING sAccessDB_Name = "{ROOT_PATH}\ApplicationSpecific\Data\TestData\TestDB.mdb"
[ ] 
[ ]  INTEGER CURRENT_SUITE_ID
[ ] 
[+] type REC_SUITE is record
	[ ] STRING SUITE 
	[ ] STRING START_TIME
	[ ] STRING TESTRUNID
	[ ] STRING TOOLID
	[ ] INTEGER ID
[ ] REC_SUITE recSuite
[ ] 
[+] type REC_STEP is record
	[ ] STRING STEP
	[ ] STRING DESC_NAME
	[ ] STRING RESULT
	[ ] STRING TESTCASE
	[ ] STRING TESTRUNID
	[ ] STRING INFO
	[ ] STRING SCREENSHOT
	[ ] STRING TOOLID
[ ] REC_STEP recStep
[ ] 
[+] type REC_TESTCASE is record 
	[ ] STRING TESTCASE
	[ ] STRING DESC_NAME
	[ ] STRING RESULT
	[ ] STRING TESTRUNID
	[ ] STRING TOOLID 
	[ ] //Added by Laxmikant
	[ ] INTEGER SUITEID
	[ ] 
[ ] REC_TESTCASE recTestcase
[ ] 
[+] type REC_ENV is record
	[ ] STRING TOOLID
	[ ] STRING TESTRUNID
	[ ] STRING OSNAME
	[ ] STRING BROWSER
	[ ] STRING BUILD
	[ ] STRING APPNAME
	[ ] STRING MACHINENAME
	[ ] 
	[ ] 
[ ] REC_ENV recEnv
[ ] 
[+] public winclass Step
	[ ] 
	[ ] // Name of the steps table in database
	[ ] String STEPS_TABLE = "STEPS"
	[ ] 
	[ ] //SQL query for creating of STEPS table in database
	[ ] String CREATE_STEPS_TABLE = "CREATE TABLE {STEPS_TABLE} (STEP PRIMARY KEY, DESC_NAME Text, RESULT Text NOT NULL, TESTCASE Text NOT NULL, TESTRUNID Text NOT NULL, INFO Text, SCREENSHOT Text, TOOLID Text NOT NULL)"
	[ ] 
	[ ] // SQL query for deleting rows of STEPS table in database
	[ ] String DELETE_STEPS_TABLE = "DELETE * FROM " + STEPS_TABLE
	[ ] 
	[+] VOID saveStepTable(STRING sResult, STRING sStepName, STRING sStepDescName, STRING sShot, STRING sMsg optional)
		[ ] Integer i
		[ ] 
		[ ] LIST OF STRING lsRecordFields, lsRecordValues = {}
		[ ] 
		[ ] recStep.STEP = sStepName
		[ ] recStep.DESC_NAME = sStepDescName
		[ ] recStep.RESULT = sResult
		[ ] recStep.TESTCASE = sTestCaseId
		[ ] recStep.TESTRUNID = CURRENT_TEST_RUN_ID
		[ ] recStep.INFO = sMsg
		[ ] recStep.SCREENSHOT = sShot
		[ ] recStep.TOOLID = "3"  //lsToolId[1][1] - by Laxmikant
		[ ] //recStep.TOOLID = lsToolId[1][1]
		[ ] 
		[ ] lsRecordFields = FieldsOfRecord(REC_STEP)
		[ ] lsRecordValues = {recStep.STEP , recStep.DESC_NAME, recStep.RESULT, recStep.TESTCASE, recStep.TESTRUNID, recStep.INFO, recStep.SCREENSHOT, recStep.TOOLID}
		[ ] 
		[ ] Access.insertLogDataIntoDB(STEPS_TABLE, lsRecordFields, lsRecordValues)
	[ ] 
	[+] // String generateStepName()
		[ ] // List OF List of String lsStepData =  objAccess.executeSelect(sAccessDB_Name, "SELECT STEP FROM STEPS")
		[ ] // STRING sStepName, sStepCount
		[ ] // LIST liStepno= {}
		[ ] // Integer i=1
		[+] // if (ListCount(lsStepData)>0)
			[-] // for (i=1;i<=ListCount(lsStepData);i++)
				[ ] // sStepCount =subStr(lsStepData[i][1], 5)
				[ ] // ListAppend( liStepno, Val(sStepCount))
			[ ] // ListSort (liStepno)
			[ ] // sStepName = "STEP{liStepno[ListCount(liStepno)] +1 }"
		[ ] // 
		[-] // else
			[ ] // sStepName = "STEP1"
		[ ] // 
		[ ] // return sStepName
	[ ] 
	[+] String captureSnapShot(String sStepID)
		[ ] STRING BMP_FILE = "D:\SilkFramework\Automation\ApplicationSpecific\Bitmaps"
		[ ] STRING sFName ="NA"
		[ ] WINDOW wActiveWin
		[ ] 
		[ ] // capturing window for faild Step
		[+] do
			[ ] 
			[+] if MessageBox.Exists()
				[ ] MessageBox.CaptureBitmap("{BMP_FILE}\{sStepID}.bmp")
				[ ] MessageBox.Close()
			[ ] 
			[+] // else if DialogBox.Exists()
				[ ] // DialogBox.CaptureBitmap("{GetDirPath(CurrentPath)}Bitmaps\{sTCId}.bmp")
				[ ] // DialogBox.Close()
			[ ] 
			[-] else
				[ ] wActiveWin=Browser.GetActive()
				[ ] wActiveWin.CaptureBitmap("{BMP_FILE}\{sStepID}.bmp")
			[ ] sFName="..\Bitmaps\{sTCId}.bmp"
		[-] except
			[ ] // if no active window found, logging message to test driver.
			[ ] sFName = "No active window found"
		[ ] return sFName
	[ ] 
[ ] 
[+] public winclass AccessDB
	[ ] 
	[ ] STRING sDSN = "DSN=MS Access Database"
	[ ] 
	[+] VOID  getConnection(String sDB_Name, String  sUserName optional, String sPassword optional)
		[ ] 
		[ ] STRING gsDSNConnect
		[-] if (sUserName != NULL && sPassword !=NULL)
			[ ] gsDSNConnect= "{sDSN};DBQ={sDB_Name};UID={sUserName};PWD={sPassword}"
		[+] else
			[ ] gsDSNConnect= "{sDSN};DBQ={sDB_Name}"
			[ ] 
		[ ] DB_Connect(gsDSNConnect)
		[ ] 
	[ ] 
	[+] VOID execute(String sDBName,  String sQuery)
		[ ] 
		[-] do
			[ ] 
			[ ] HDATABASE hdbc
			[ ] HSQL hstmnt
			[ ] STRING gsDSNConnect= "{sDSN};DBQ={sDBName}"
			[ ] 
			[ ] hdbc = DB_Connect(gsDSNConnect)
			[ ] 
			[ ] hstmnt = DB_ExecuteSql(hdbc, sQuery)
			[ ] 
			[ ] DB_FinishSQL (hstmnt)
			[ ] 
			[ ] DB_Disconnect (hdbc)
			[ ] 
		[-] except
			[ ] 
			[ ] Log.Error("execute", "Failed to Inset in Database{ExceptData()}")
	[ ] 
	[+] // LIST OF LIST OF STRING executeSelect(String sDBName, String sQuery)
		[ ] // 
		[ ] // LIST OF LIST OF STRING lsQueryData ={}
		[ ] // 
		[ ] // List Of STRING sRowData ={}
		[ ] // Integer i =1
		[-] // do
			[ ] // 
			[ ] // HDATABASE hdbc
			[ ] // HSQL hstmnt
			[ ] // STRING gsDSNConnect= "{sDSN};DBQ={sDBName}"
			[ ] // 
			[ ] // hdbc = DB_Connect(gsDSNConnect)
			[ ] // 
			[ ] // hstmnt = DB_ExecuteSql(hdbc, sQuery)
			[ ] // 
			[-] // while (DB_FetchNext (hstmnt, sRowData))
				[ ] // i++
				[ ] // ListAppend(lsQueryData, sRowData)
				[ ] // 
			[ ] // DB_FinishSQL(hstmnt)
			[ ] // 
			[ ] // DB_Disconnect(hdbc)
			[ ] // 
			[ ] // return lsQueryData
		[-] // except
			[ ] // Log.Error("executeSelect", ExceptData())
			[ ] // return lsQueryData
			[ ] // 
	[ ] 
	[-] VOID insertLogDataIntoDB(String table, LIST OF STRING  lsRecordFields,  List of ANYTYPE lsRecordVals )
		[ ] 
		[ ] String sQuery = generateQuery(table, lsRecordFields, lsRecordVals)
		[ ] Access.execute(sAccessDB_Name, sQuery)
		[ ] 
	[ ] 
	[ ] 
	[+] STRING generateQuery(String table, List of STRING  lsRecordFields,  List of ANYTYPE lsRecordVals)
		[ ] Integer i
		[ ] STRING sQuery, cols ="" ,colVals = ""
		[-] for(i=1 ; i<=ListCount (lsRecordFields); i++)
			[-] if(lsRecordFields !=null)
				[ ] cols = cols + "{lsRecordFields[i]}"
				[ ] cols = cols +","
				[ ] colVals =colVals + "'{lsRecordVals[i]}'"
				[ ] colVals =colVals +","
			[-] else
				[ ]  break
		[ ] cols= Left (Trim(cols), Len(cols)-1)
		[ ] colVals= Left (Trim(colVals), Len(colVals)-1)
		[ ] sQuery = "INSERT INTO {table} ( {cols}) VALUES ({colVals})"
		[ ] return sQuery
	[ ] 
	[+] INTEGER getSuiteID (String sDBName, String sQuery)
		[-] do
			[ ] 
			[ ] HDATABASE hdbc
			[ ] HSQL hstmnt
			[ ] STRING gsDSNConnect= "{sDSN};DBQ={sDBName}"
			[ ] 
			[ ] Integer suiteID, ID
			[ ] 
			[ ] hdbc = DB_Connect(gsDSNConnect)
			[ ] 
			[ ] hstmnt = DB_ExecuteSql(hdbc, sQuery)
			[ ] 
			[ ] DB_FetchNext (hstmnt, ID)
			[ ] 
			[ ] suiteID = ID
			[ ] 
			[ ] DB_FinishSQL(hstmnt)
			[ ] 
			[ ] DB_Disconnect(hdbc)
			[ ] 
			[ ] return suiteID
		[-] except
			[ ] Log.Error("executeSelect", ExceptData())
			[ ] return suiteID
			[ ] 
		[ ] 
[ ] 
[-] public winclass TestCase
	[ ] // Name of the TestCase  table in database
	[ ] String TEST_CASES_TABLE = "TESTCASES"
	[ ] 
	[ ] //SQL query for creating of TESTCASES  table in database
	[ ] STRING CREATE_TESTCASES_TABLE = "CREATE TABLE " + TEST_CASES_TABLE + " (TESTCASE Text, DESC_NAME Text, RESULT Text NOT NULL,  TESTRUNID Text NOT NULL,  TOOLID Text NOT NULL, SUITEID NUMBER PRIMARY KEY)"
	[ ] 
	[ ] // SQL query for deleting rows of STEPS table in database
	[ ] String DELETE_TESTCASES_TABLE = "DELETE * FROM " + TEST_CASES_TABLE
	[ ] 
	[ ] 
	[-]  void SaveTestcaseDetails(String sResult, String sTestId)
		[ ]  
		[ ] LIST OF STRING lsRecordFields= {}
		[ ] LIST OF ANYTYPE lsRecordValues 
		[ ] STRING sTestCaseId 
		[ ] 
		[ ] // // //Generate TestCase ID
		[ ] // // //sTestCaseId = generateTCId()
		[ ] 
		[ ] recTestcase.TESTCASE =sTestId
		[ ] recTestcase.DESC_NAME = sTCName
		[ ] recTestcase.RESULT = sResult
		[ ] recTestcase.TESTRUNID = CURRENT_TEST_RUN_ID
		[ ] //testRunId="1"
		[ ] recTestcase.TOOLID = "3" //lsToolId[1][1] - by Laxmikant
		[ ] //recTestcase.SUITEID = suite.ID
		[ ] //recTestcase.TOOLID = lsToolId[1][1]
		[ ] 
		[ ] 
		[ ] lsRecordFields = FieldsOfRecord(REC_TESTCASE)
		[ ] lsRecordValues = {recTestcase.TESTCASE, recTestcase.DESC_NAME ,recTestcase.RESULT, recTestcase.TESTRUNID, recTestcase.TOOLID, CURRENT_SUITE_ID}
		[ ] 
		[ ] //Insert values in TEstcases Table
		[ ] Access.insertLogDataIntoDB(TEST_CASES_TABLE,lsRecordFields, lsRecordValues)
		[ ] 
	[ ] 
	[ ] 
	[ ] //Not being used by Laxmikant
	[+] String generateTCId()
		[ ] List OF List of String lsTCData =  objAccess.executeSelect(sAccessDB_Name, "SELECT TESTCASE FROM TESTCASES")
		[ ] STRING sTestcaseName, sTCCount
		[ ] LIST liTCno= {}
		[ ] Integer i=1
		[-] if (ListCount(lsTCData)>0)
			[-] for (i=1;i<=ListCount(lsTCData);i++)
				[ ] sTCCount =subStr(lsTCData[i][1], 4)
				[ ] ListAppend( liTCno, Val(sTCCount))
			[ ] ListSort (liTCno)
			[ ] sTestcaseName = "TC_{liTCno[ListCount(liTCno)] +1 }"
		[ ] 
		[-] else
			[ ] sTestcaseName = "TC_1"
		[ ] 
		[ ] return sTestcaseName
		[ ] 
[ ] 
[+] public winclass Suite
	[ ] // This class serves an interface for other logger classes to obtain information
	[ ] // about currently running suite
	[ ] 
	[ ] // Name of the suites table in database
	[ ] String SUITES_TABLE = "SUITES"
	[ ] 
	[ ] //SQL query for creating of SUITES table in database
	[ ] String CREATE_SUITES_TABLE = "CREATE TABLE {SUITES_TABLE} (ID COUNTER PRIMARY KEY, SUITE Text NOT NULL, START_TIME Text, END_TIME Text, TESTRUNID Text NOT NULL, TOOLID Text NOT NULL)"
	[ ] 
	[ ] // SQL query for deleting rows of SUITES table in database
	[ ] String DELETE_SUITES_TABLE = "DELETE * FROM " + SUITES_TABLE
	[ ] 
	[ ] //Laxmikant
	[ ] INTEGER ID
	[ ] 
	[-] INTEGER createSuite(String name)
		[ ] DATETIME DayAndTime
		[ ] STRING sTime
		[ ] STRING sDate
		[ ] List of String lsRecordFields, lsRecordValues
		[ ] 
		[+] do
			[ ]  createDBTables()
			[ ] // get current date and time
			[ ]  sDate =DateStr()
			[ ]  sTime =TimeStr()
			[ ]  
			[ ] CURRENT_TEST_RUN_ID = GetField(sDate,"/",1)+GetField(sDate,"/",2)+GetField(sDate,"/",3)+GetField(sTime,":",1)+GetField(sTime,":",2)+GetField(sTime,":",3)
			[ ] 
			[ ] //CURRENT_TEST_RUN_ID ='{DateStr()}{Space(1)}{ TimeStr()}'
			[ ] String strtTime = '{DateStr()}{Space(1)}{ TimeStr()}'
			[ ] lsToolId = Access.executeSelect(sAccessDB_Name, "Select TOOLID from TOOLDETAILS where TOOLNAME='SILK'")
			[ ] 
			[ ] //added by Laxmikant
			[ ] name = name + CURRENT_TEST_RUN_ID
			[ ] Log.Message ("Suite name in Database is", name)
			[ ] 
			[ ] recSuite.TESTRUNID = CURRENT_TEST_RUN_ID
			[ ] recSuite.SUITE = name
			[ ] recSuite.START_TIME =strtTime
			[ ] recSuite.TOOLID = lsToolId[1][1]
			[ ] lsRecordFields = {"SUITE", "START_TIME", "TESTRUNID", "TOOLID"}
			[ ] lsRecordValues = { recSuite.SUITE, recSuite.START_TIME,recSuite.TESTRUNID, recSuite.TOOLID}
			[ ]  Access.insertLogDataIntoDB(SUITES_TABLE, lsRecordFields , lsRecordValues)
			[ ] Print("Entered Values in DB")
			[ ] Environments.setEnvTable(CURRENT_TEST_RUN_ID)  ///Set Values in environment table
			[ ] //List of Anytype tempSuiteIds
			[ ] Integer tempSuiteIds = Access.getSuiteID(sAccessDB_Name, "Select ID from SUITES where SUITE='{name}'")
			[ ] //this.ID = tempSuiteIds
			[ ] //recTestcase.SUITEID=tempSuiteIds
			[ ] CURRENT_SUITE_ID = tempSuiteIds
			[ ] Print("Value of CURRENT_SUITE_ID: {Str(tempSuiteIds)}")
			[ ] setCurrentTestRunID(CURRENT_TEST_RUN_ID)
			[ ] 
		[-] except
			[ ] Print(Exceptdata())
		[ ] return tempSuiteIds
		[ ] 
	[ ] //  * Drops and creates database tables in which the test results will be stored.
	[ ] //  * Deletes table rows only if 'FlushResultsData' flag in config.inc file set to  true
	[+] VOID createDBTables()
		[-] if(bFlushPreviousData)
			[ ] Access.execute(sAccessDB_Name, Steps.DELETE_STEPS_TABLE)
			[ ] Access.execute(sAccessDB_Name,Testcases.DELETE_TESTCASES_TABLE)
			[ ] Access.execute(sAccessDB_Name, Environments.DELETE_ENVIRONMENT_TABLE)
			[ ] Access.execute(sAccessDB_Name, DELETE_SUITES_TABLE)
	[ ] 
	[+] VOID setSuiteEndTime()
		[ ] String sEndTime = '{DateStr()}{Space(1)}{ TimeStr()}'
		[ ] String sUpdateQuery = "Update SUITES SET  END_TIME = '{sEndTime}' WHERE ID ={CURRENT_SUITE_ID}"
		[ ] Access.execute(sAccessDB_Name,sUpdateQuery)
		[ ] 
	[ ] 
	[ ] 
[ ] 
[+] public winclass Environment
	[ ] String ENVIRONMENT_TABLE = "ENVIRONMENT"
	[ ] 
	[ ] //ARRAY[7] OF STRING ENVIRONMENT_TABLE_COLS  = {"TOOLID", "TESTRUNID", "OSNAME", "BROWSER","BUILD", "APPNAME", "MACHINENAME"}
	[ ] 
	[ ] String CREATE_ENVIRONMENT_TABLE = "CREATE TABLE {ENVIRONMENT_TABLE} (ID COUNTER PRIMARY KEY, TOOLID Text , TESTRUNID Text NOT NULL, OSNAME Text, BROWSER Text, BUILD Text, APPNAME Text, MACHINENAME Text)"
	[ ] 
	[ ] // SQL query for deleting rows of ENVIRNMENT  table in database
	[ ] String DELETE_ENVIRONMENT_TABLE = "DELETE * FROM " + ENVIRONMENT_TABLE
	[ ] 
	[-] VOID setEnvTable(String testRunId)
		[ ] // Name of the Environment table in database
		[ ] STRING sOSName = SYS_GetName ()
		[ ] STRING sOSVersion = SYS_GetVersion ()
		[ ] STRING sMachineName =SYS_GetEnv("COMPUTERNAME")
		[ ] LIST OF STRING lsRecordFields, lsRecordValues
		[ ] 
		[ ] recEnv.TOOLID= lsToolId[1][1]
		[ ] recEnv.TESTRUNID = testRunId
		[ ] recEnv.OSNAME = "{sOSName}  {sOSVersion}"
		[ ] recEnv.BROWSER = BROWSER
		[ ] recEnv.BUILD = CURRENT_BUILD
		[ ] recEnv.APPNAME =PRODUCT_NAME
		[ ] recEnv.MACHINENAME = sMachineName
		[ ] 
		[ ] lsRecordFields = FieldsOfRecord(REC_ENV)
		[ ] lsRecordValues = {recEnv.TOOLID,  recEnv.TESTRUNID, recEnv.OSNAME, recEnv.BROWSER, recEnv.BUILD, recEnv.APPNAME, recEnv.MACHINENAME }
		[ ] 
		[ ] Access.insertLogDataIntoDB(ENVIRONMENT_TABLE, lsRecordFields, lsRecordValues)
[ ] 
[-] // public void GenerateHtmlReport()
	[ ] // STRING sCmdLine, sReportPath ,sCurrDir
	[ ] // Integer iReturn 
	[ ] // sReportPath = "{ROOT_PATH}\ApplicationSpecific\Data\TestReport"
	[ ] // 
	[ ] // sCurrDir ="{ROOT_PATH}\jdk1.5.0_05\bin"
	[ ] //  SYS_SetDir (sCurrDir)
	[ ] // //Parameters to Reportgenerator.bat are TestRunId, DB_path, ToolID,  ReportPath
	[ ] // Print("Parameters for command line")
	[ ] // //Print({CURRENT_TEST_RUN_ID})
	[ ] // Print({sAccessDB_Name})
	[ ] // //Print({CURRENT_SUITE_ID})
	[ ] // Print({sReportPath})
	[ ] // 
	[ ] // sCmdLine = "ReportGenerator.bat  {CURRENT_TEST_RUN_ID} {sAccessDB_Name} {"3"} {sReportPath}"
	[ ] // SYS_Execute("cd D:\Quicken\jdk1.5.0_05\bin")
	[ ] // iReturn = SYS_Execute(sCmdLine)
	[ ] // Print(iReturn)
[ ] 
[ ] 
