function CodeDefine() { 
this.def = new Array();
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:40,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:77,type:"fcn"};
this.def["rtDW"] = {file: "PARQUEADERO_MODELO_c.html",line:47,type:"var"};
this.def["rtPrevZCX"] = {file: "PARQUEADERO_MODELO_c.html",line:50,type:"var"};
this.def["rtU"] = {file: "PARQUEADERO_MODELO_c.html",line:53,type:"var"};
this.def["rtY"] = {file: "PARQUEADERO_MODELO_c.html",line:56,type:"var"};
this.def["PARQUEADERO_MODELO.c:rtM_"] = {file: "PARQUEADERO_MODELO_c.html",line:59,type:"var"};
this.def["rtM"] = {file: "PARQUEADERO_MODELO_c.html",line:60,type:"var"};
this.def["PARQUEADERO_MODELO.c:rt_ZCFcn"] = {file: "PARQUEADERO_MODELO_c.html",line:65,type:"fcn"};
this.def["PARQUEADERO_MODELO_step"] = {file: "PARQUEADERO_MODELO_c.html",line:138,type:"fcn"};
this.def["PARQUEADERO_MODELO_initialize"] = {file: "PARQUEADERO_MODELO_c.html",line:331,type:"fcn"};
this.def["RT_MODEL"] = {file: "PARQUEADERO_MODELO_h.html",line:44,type:"type"};
this.def["DW"] = {file: "PARQUEADERO_MODELO_h.html",line:55,type:"type"};
this.def["PrevZCX"] = {file: "PARQUEADERO_MODELO_h.html",line:60,type:"type"};
this.def["ExtU"] = {file: "PARQUEADERO_MODELO_h.html",line:66,type:"type"};
this.def["ExtY"] = {file: "PARQUEADERO_MODELO_h.html",line:73,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:98,type:"type"};
this.def["ZCDirection"] = {file: "zero_crossing_types_h.html",line:31,type:"type"};
this.def["ZCSigState"] = {file: "zero_crossing_types_h.html",line:34,type:"type"};
this.def["ZCEventType"] = {file: "zero_crossing_types_h.html",line:47,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["PARQUEADERO_MODELO_c.html"] = "../PARQUEADERO_MODELO.c";
	this.html2Root["PARQUEADERO_MODELO_c.html"] = "PARQUEADERO_MODELO_c.html";
	this.html2SrcPath["PARQUEADERO_MODELO_h.html"] = "../PARQUEADERO_MODELO.h";
	this.html2Root["PARQUEADERO_MODELO_h.html"] = "PARQUEADERO_MODELO_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["zero_crossing_types_h.html"] = "../zero_crossing_types.h";
	this.html2Root["zero_crossing_types_h.html"] = "zero_crossing_types_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","PARQUEADERO_MODELO_c.html","PARQUEADERO_MODELO_h.html","rtwtypes_h.html","zero_crossing_types_h.html"];