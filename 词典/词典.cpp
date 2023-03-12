#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define Nor if(B[b].x<5) B[b].x=5;
#define Out1 Bx1-Bvx1<=6||Bx1-Bvx1>=28||By1-Bvy1<=7||By1-Bvy1>=27
#define Out2 Bx2-Bvx2<=6||Bx2-Bvx2>=28||By2-Bvy2<=7||By2-Bvy2>=27
#define Chang1 {Bwhat1=0;Bvx1=Bvy1=0;memset(Bgo1,0,sizeof(Bgo1));}
#define Chang2 {Bwhat2=0;Bvx2=Bvy2=0;memset(Bgo2,0,sizeof(Bgo2));}
#define Chang3 {Bwhat3=0;Bvx3=Bvy3=0;memset(Bgo3,0,sizeof(Bgo3));}
using namespace std;
string i2s[2005]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118","119","120","121","122","123","124","125","126","127","128","129","130","131","132","133","134","135","136","137","138","139","140","141","142","143","144","145","146","147","148","149","150","151","152","153","154","155","156","157","158","159","160","161","162","163","164","165","166","167","168","169","170","171","172","173","174","175","176","177","178","179","180","181","182","183","184","185","186","187","188","189","190","191","192","193","194","195","196","197","198","199","200","201","202","203","204","205","206","207","208","209","210","211","212","213","214","215","216","217","218","219","220","221","222","223","224","225","226","227","228","229","230","231","232","233","234","235","236","237","238","239","240","241","242","243","244","245","246","247","248","249","250","251","252","253","254","255","256","257","258","259","260","261","262","263","264","265","266","267","268","269","270","271","272","273","274","275","276","277","278","279","280","281","282","283","284","285","286","287","288","289","290","291","292","293","294","295","296","297","298","299","300","301","302","303","304","305","306","307","308","309","310","311","312","313","314","315","316","317","318","319","320","321","322","323","324","325","326","327","328","329","330","331","332","333","334","335","336","337","338","339","340","341","342","343","344","345","346","347","348","349","350","351","352","353","354","355","356","357","358","359","360","361","362","363","364","365","366","367","368","369","370","371","372","373","374","375","376","377","378","379","380","381","382","383","384","385","386","387","388","389","390","391","392","393","394","395","396","397","398","399","400","401","402","403","404","405","406","407","408","409","410","411","412","413","414","415","416","417","418","419","420","421","422","423","424","425","426","427","428","429","430","431","432","433","434","435","436","437","438","439","440","441","442","443","444","445","446","447","448","449","450","451","452","453","454","455","456","457","458","459","460","461","462","463","464","465","466","467","468","469","470","471","472","473","474","475","476","477","478","479","480","481","482","483","484","485","486","487","488","489","490","491","492","493","494","495","496","497","498","499","500","501","502","503","504","505","506","507","508","509","510","511","512","513","514","515","516","517","518","519","520","521","522","523","524","525","526","527","528","529","530","531","532","533","534","535","536","537","538","539","540","541","542","543","544","545","546","547","548","549","550","551","552","553","554","555","556","557","558","559","560","561","562","563","564","565","566","567","568","569","570","571","572","573","574","575","576","577","578","579","580","581","582","583","584","585","586","587","588","589","590","591","592","593","594","595","596","597","598","599","600","601","602","603","604","605","606","607","608","609","610","611","612","613","614","615","616","617","618","619","620","621","622","623","624","625","626","627","628","629","630","631","632","633","634","635","636","637","638","639","640","641","642","643","644","645","646","647","648","649","650","651","652","653","654","655","656","657","658","659","660","661","662","663","664","665","666","667","668","669","670","671","672","673","674","675","676","677","678","679","680","681","682","683","684","685","686","687","688","689","690","691","692","693","694","695","696","697","698","699","700","701","702","703","704","705","706","707","708","709","710","711","712","713","714","715","716","717","718","719","720","721","722","723","724","725","726","727","728","729","730","731","732","733","734","735","736","737","738","739","740","741","742","743","744","745","746","747","748","749","750","751","752","753","754","755","756","757","758","759","760","761","762","763","764","765","766","767","768","769","770","771","772","773","774","775","776","777","778","779","780","781","782","783","784","785","786","787","788","789","790","791","792","793","794","795","796","797","798","799","800","801","802","803","804","805","806","807","808","809","810","811","812","813","814","815","816","817","818","819","820","821","822","823","824","825","826","827","828","829","830","831","832","833","834","835","836","837","838","839","840","841","842","843","844","845","846","847","848","849","850","851","852","853","854","855","856","857","858","859","860","861","862","863","864","865","866","867","868","869","870","871","872","873","874","875","876","877","878","879","880","881","882","883","884","885","886","887","888","889","890","891","892","893","894","895","896","897","898","899","900","901","902","903","904","905","906","907","908","909","910","911","912","913","914","915","916","917","918","919","920","921","922","923","924","925","926","927","928","929","930","931","932","933","934","935","936","937","938","939","940","941","942","943","944","945","946","947","948","949","950","951","952","953","954","955","956","957","958","959","960","961","962","963","964","965","966","967","968","969","970","971","972","973","974","975","976","977","978","979","980","981","982","983","984","985","986","987","988","989","990","991","992","993","994","995","996","997","998","999","1000","1001","1002","1003","1004","1005","1006","1007","1008","1009","1010","1011","1012","1013","1014","1015","1016","1017","1018","1019","1020","1021","1022","1023","1024","1025","1026","1027","1028","1029","1030","1031","1032","1033","1034","1035","1036","1037","1038","1039","1040","1041","1042","1043","1044","1045","1046","1047","1048","1049","1050","1051","1052","1053","1054","1055","1056","1057","1058","1059","1060","1061","1062","1063","1064","1065","1066","1067","1068","1069","1070","1071","1072","1073","1074","1075","1076","1077","1078","1079","1080","1081","1082","1083","1084","1085","1086","1087","1088","1089","1090","1091","1092","1093","1094","1095","1096","1097","1098","1099","1100","1101","1102","1103","1104","1105","1106","1107","1108","1109","1110","1111","1112","1113","1114","1115","1116","1117","1118","1119","1120","1121","1122","1123","1124","1125","1126","1127","1128","1129","1130","1131","1132","1133","1134","1135","1136","1137","1138","1139","1140","1141","1142","1143","1144","1145","1146","1147","1148","1149","1150","1151","1152","1153","1154","1155","1156","1157","1158","1159","1160","1161","1162","1163","1164","1165","1166","1167","1168","1169","1170","1171","1172","1173","1174","1175","1176","1177","1178","1179","1180","1181","1182","1183","1184","1185","1186","1187","1188","1189","1190","1191","1192","1193","1194","1195","1196","1197","1198","1199","1200","1201","1202","1203","1204","1205","1206","1207","1208","1209","1210","1211","1212","1213","1214","1215","1216","1217","1218","1219","1220","1221","1222","1223","1224","1225","1226","1227","1228","1229","1230","1231","1232","1233","1234","1235","1236","1237","1238","1239","1240","1241","1242","1243","1244","1245","1246","1247","1248","1249","1250","1251","1252","1253","1254","1255","1256","1257","1258","1259","1260","1261","1262","1263","1264","1265","1266","1267","1268","1269","1270","1271","1272","1273","1274","1275","1276","1277","1278","1279","1280","1281","1282","1283","1284","1285","1286","1287","1288","1289","1290","1291","1292","1293","1294","1295","1296","1297","1298","1299","1300","1301","1302","1303","1304","1305","1306","1307","1308","1309","1310","1311","1312","1313","1314","1315","1316","1317","1318","1319","1320","1321","1322","1323","1324","1325","1326","1327","1328","1329","1330","1331","1332","1333","1334","1335","1336","1337","1338","1339","1340","1341","1342","1343","1344","1345","1346","1347","1348","1349","1350","1351","1352","1353","1354","1355","1356","1357","1358","1359","1360","1361","1362","1363","1364","1365","1366","1367","1368","1369","1370","1371","1372","1373","1374","1375","1376","1377","1378","1379","1380","1381","1382","1383","1384","1385","1386","1387","1388","1389","1390","1391","1392","1393","1394","1395","1396","1397","1398","1399","1400","1401","1402","1403","1404","1405","1406","1407","1408","1409","1410","1411","1412","1413","1414","1415","1416","1417","1418","1419","1420","1421","1422","1423","1424","1425","1426","1427","1428","1429","1430","1431","1432","1433","1434","1435","1436","1437","1438","1439","1440","1441","1442","1443","1444","1445","1446","1447","1448","1449","1450","1451","1452","1453","1454","1455","1456","1457","1458","1459","1460","1461","1462","1463","1464","1465","1466","1467","1468","1469","1470","1471","1472","1473","1474","1475","1476","1477","1478","1479","1480","1481","1482","1483","1484","1485","1486","1487","1488","1489","1490","1491","1492","1493","1494","1495","1496","1497","1498","1499","1500"};
int num,k_num=0,s,x_num,jm,errors,findres,boxreturn,errorfind;
string res,f,t,k[100005][2],errornum,errorls,firname,finres[100005][2];//[多个库][项目][库:[0]=name,[1]=介绍]
bool returnn;
string x,errorinfo,eninfo,zykcd[10][10],ls[5],boxinnr;//[词典][信息(0为项目数)]
ofstream outFile;
ifstream inFile;
void inf(string inF){inFile.open(inF.data(),ios::in);}
void outf(string outF){outFile.open(outF.data(),ios::out);}
int fn(){return getch()-'0';};//faststdinnum
void error(int a){
//	inf("error.help");
	freopen("error.help","r",stdin);
	cin>>errors;
	if(errors<1){
		// system("explorer \"http://img.ess.ink:16055/%E8%AF%8D%E5%85%B8\"");
		MessageBox(NULL,"错误查询文件无法访问或错误\n请检查错误查询文件的完整性\n\n因此程序中止,或前往重新下载","警告",MB_SYSTEMMODAL|MB_OK|MB_ICONERROR);
		exit(0);
	}
	for(int j=1;j<=errors;j++){
		cin>>errornum>>eninfo>>errorinfo;
		if(errornum==i2s[a]) break;
	}
	// freopen("CON","r",stdin);
	errorls="程序错误:"+i2s[a]+"\n"+eninfo+"\n"+errorinfo+"\n\n按下确认继续...";
	MessageBox(NULL,errorls.data(),"错误",MB_SYSTEMMODAL|MB_OK|MB_ICONERROR);
	fclose(stdin);
	freopen("CON","r",stdin);
}
void color(int a){
	switch(a){
		case 0:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);break;
		case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);break;
		case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);break;
		case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);break;
		case 4:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);break;
		case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);break;
		case 6:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);break;
		case 7:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);break;
		case 8:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);break;
		case 9:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);break;
		case 10:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);break;
		case 11:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);break;
		case 12:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);break;
		case 13:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);break;
		case 14:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);break;
		default:error(100);
	} 
}
void new_k(){
	system("title 初始化库...");
	for(int i=1;i<=x_num;i++){
		cout<<"初始化库...("<<i<<"/"<<x_num<<")\n";
		k[i][0]="";k[i][1]="";
	}
}
void all_add(){
	if(boxreturn==IDNO){
		cout<<"请输入您的词典库文件名称(带后缀名)";
		cin>>firname;
		inf(firname);
	}else{
		if(boxreturn==IDYES) inf("data.cd");
		else return;
	}
//	new_k();
	system("title 读入库数据...");
	inFile>>x_num;
	if(x_num<1){
		error(101);
		return; 
	}
	boxreturn=MessageBox(NULL,"读取项目过程显示是否启用\n\ntips:打开会清晰看到读取项目的过程,但关闭后读取项目速度会更快","读入",MB_SYSTEMMODAL|MB_OKCANCEL|MB_ICONINFORMATION);
	for(int i=1;i<=x_num;i++){
		inFile>>k[i][0]>>k[i][1];
		if(boxreturn==1) cout<<"读入项目"<<i<<"的数据...("<<i<<"/"<<x_num<<") name:"<<k[i][0]<<" 简介:"<<k[i][1]<<"\n";
	}

	// fclose(stdin);
	// freopen("CON","r",stdin);
}
string findnr;
void find(){
	system("cls");
	system("title 词典 - 查询");
	cout<<" ______________________________________\n";
	cout<<"|词典 - 查询                     - □ ×|\n"; 
	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
	cout<<"|请输入查询的内容                      |\n";
	cout<<"|";cin>>f;
	findres=1;
	for(int i=1;i<=x_num;i++){
		//cout<<"正在查找"<<i<<"/"<<k_num<<" 内容:"<<k[i][0]<<"\n";
		if(k[i][1]==f||k[i][0]==f){
			finres[findres][0]=k[i][1];
			finres[findres][1]=k[i][0];
			findres++;
		}
	}
	system("cls");
	findres--;
	if(findres){
		for(int i=1;i<=findres;i++){
			x="词典 - "+i2s[findres]+" 个结果 - 第"+i2s[i]+"个";
			findnr="-------------------------\n"+finres[i][1]+"\n\n简介\n"+finres[i][0]+"\n-------------------------";
			MessageBox(NULL,findnr.data(),x.data(),MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION);
			// cout<<" ______________________________________\n";
			// cout<<"|"<<finres[i][1]<<"\n";
			// cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
			// cout<<"|简介:                                 |\n";
			// cout<<"|"<<finres[i][0];
		} 
	}else MessageBox(NULL,"很抱歉,没有在词库中寻找到您需要的内容","词典 - 无结果",MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION);
}
void Save_123(){
	system("cls");
	system("title 词典 - 导出调试库");
	cout<<" ______________________________________\n";
	cout<<"|词典 - 导出调试库               - □×|\n";
	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
	cout<<"|请输入调试库个数                      |\n";
	cout<<"|";
	scanf("%d",&k_num);
	outf("data.cd");
	outFile<<k_num<<"\n";
	ls[1]="确认生成 "+i2s[k_num]+" 个调试库?\n调试库算法:\n - name:i\n - 简介:i^3";
	if(MessageBox(NULL,ls[1].data(),"生成调试库",MB_SYSTEMMODAL|MB_OKCANCEL|MB_ICONINFORMATION)==2) return;
	for(int i=1;i<=k_num;i++) outFile<<i<<" "<<i*i*i<<"\n";
	MessageBox(NULL,"完成","生成调试库",MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION);
	num=1;
}
//void add(){
//	system("cls");
//	system("title 词典 - 添加");
//	cout<<" ______________________________________\n";
//	cout<<"|词典 - 添加                     - □×|\n";
//	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
//	cout<<"|请输入添加项目数                      |\n";
//	cout<<"|";scanf("%d",&s);
//	for(int i=1+k_num;i<=s+k_num;i++){
//		system("cls");
//		cout<<" ______________________________________\n";
//		cout<<"|请输入词条名称("<<i-k_num<<"/"<<s<<")";cin>>k[i][1];
//		cout<<" ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n";
//		system("cls");
//		cout<<" ______________________________________\n";
//		cout<<"|"<<"("<<i-k_num<<"/"<<s<<") "<<k[i][1];
//		cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
//		cout<<"|请输入词条简介:                       |\n";
//		cout<<"|";cin>>k[i][2];
//	}
//}
//void cdnew(int xh){
//	system("cls");
//	system("title 警告");
//	if(!MessageBox(NULL,"您确定要写入数据库吗","警告",MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION)-1)
//	// cout<<"  \n开始补充数据";
//	freopen("data.cd","w",stdout);
//	switch(xh){
//		case 1:{
//			cout<<"4 0\ntest test\n666 666 \n1 2\nqqq\nqq1";
//			break;
//		}
//	}
//	fclose(stdout);
//	freopen("CON","w",stdout);
//}
// void zyk(){
// 	system("cls");
// 	system("title 词典 - 资源库");
// 	cout<<" ___________________   ___________________\n\
// | 测试词典          | | 退出              |\n\
// |  序号 1           | |  其他序号         |\n\
// |                   | |                   |\n\
//  ￣￣￣￣￣￣￣￣￣￣  ￣￣￣￣￣￣￣￣￣￣\n\n键入序号:";
// 	num=fn();
// 	switch(num){
//    		case 1:{
//    		cdnew(1); 
// 		break;
// 	   }
// 	   default:return;
// 	}
// 	return;
// }
//void zjm(){
//	system("cls");
//	system("title 词典");
//	cout<<" ______________________________________\n";
//	cout<<"|词典                            - □×|\n";
//	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
//	cout<<"|词典 版本:3                           |\n";
//	cout<<"|程序制作:pieces                       |\n";
//	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
//	cout<<"|[1]    查询                           |\n";
//	cout<<"|[2]    添加                           |\n";
//	cout<<"|[3]    获取资源库                     |\n";
//	cout<<"|[4]    重新获取库                     |\n"; 
//	cout<<"|[5]    导出调试库 (即只包含数字的词典)|\n";
//	cout<<"|[6]    导出当前库                     |\n"; 
//	cout<<"|[7]    初始化库                       |\n"; 
//	cout<<"|[其他] 退出                           |\n";
//	cout<<"|______________________________________|\n";
//	cout<<"|请输入选择的功能序号                  |\n";
//	cout<<"|";num=fn();
//	switch(num){
//		case 1:find();break;
//		case 2:add();break;
//		case 3:zyk();break;
//		case 4:all_add();break;
//		case 5:Save_123();break;
//		case 7:new_k();break;
//		default:returnn=1;
//	}
//}
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE hInstance;
HINSTANCE hPrevInstance;LPSTR lpCmdLine;
int nCmdShow;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	system("title 词典");
	boxreturn=MessageBox(NULL,"作者对于C++语言Windows窗口GUI图形界面的技术不太好,部分功能可能需要您使用控制台(即后方的黑色窗口)\n按下按钮后可能经常会无响应,属于正常现象\n非常感谢您的理解和使用\n\n您要打开默认库data.cd吗?\n -   是 :读取默认库data.cd\n -   否 :将询问词典库名称\n - 取消:不读取库","词典",MB_SYSTEMMODAL|MB_YESNOCANCEL|MB_ICONQUESTION);
	all_add();
	WNDCLASSEX wc;
	memset(&wc,0,sizeof(wc));
	wc.cbSize=sizeof(wc);
	wc.style=CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc=WindowProc;
	wc.hInstance=hInstance;
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.lpszClassName="词典";
	RegisterClassEx(&wc);
	HWND hwnd=CreateWindowEx(0,"词典","词典",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);
	if(!hwnd) return 1;
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	MSG msg;
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch(uMsg){
		case WM_CREATE:{
			RECT rect;
			GetClientRect(hwnd, &rect);
			int width=rect.right-rect.left;
			int height=rect.bottom-rect.top;
			CreateWindow("STATIC","词典\n版本号:4\n按下按钮即可使用功能",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,50,20,500,50,hwnd,NULL,NULL,NULL);
			CreateWindow("BUTTON","查询",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,      50,100,125,250,hwnd,(HMENU)1,NULL,NULL);
			CreateWindow("BUTTON","重新获取库",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,175,100,125,250,hwnd,(HMENU)3,NULL,NULL);
			CreateWindow("BUTTON","输出调试库",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,300,100,125,250,hwnd,(HMENU)4,NULL,NULL);
			CreateWindow("BUTTON","清空词典",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,  425,100,125,250,hwnd,(HMENU)5,NULL,NULL);
			CreateWindow("BUTTON","打开词典Readme.md(Markdown介绍)",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,50,350,500,50,hwnd,(HMENU)6,NULL,NULL);
			CreateWindow("BUTTON","到网络上下载库",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,50,400,500,70,hwnd,(HMENU)7,NULL,NULL);
			CreateWindow("STATIC","\n获取内置库",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,650,20,500,50,hwnd,NULL,NULL,NULL);
			CreateWindow("BUTTON","数字互相对应的调试库 \n 123-123.cd",WS_VISIBLE|WS_CHILD|BS_DEFPUSHBUTTON,650,100,500,75,hwnd,(HMENU)8,NULL,NULL);
			/*
				解读CreateWindow()函数 (创建按钮函数)
				 CreateWindow(按钮类型,按钮标签,不知道,横向坐标(向右),竖向坐标(向下),按钮宽度(向右扩展),按钮长度(向下扩展),hwnd(不知道,但是盲猜是必要的),(HMENU)+按钮编号,NULL,NULL→这两个不知道是干啥的); 
				 由ChatGPT提供的解释
				CreateWindow() 是 Windows API 中的一个函数，用于创建一个窗口或对话框，并返回窗口或对话框的句柄。其函数原型如下：
				HWND CreateWindow(
					LPCTSTR lpClassName, // 窗口类名
					LPCTSTR lpWindowName, // 窗口标题
					DWORD dwStyle, // 窗口风格
					int x, // 窗口 X 坐标
					int y, // 窗口 Y 坐标
					int nWidth, // 窗口宽度
					int nHeight, // 窗口高度
					HWND hWndParent, // 父窗口句柄
					HMENU hMenu, // 菜单句柄或菜单 ID
					HINSTANCE hInstance, // 应用程序实例句柄
					LPVOID lpParam // 传递给 WM_CREATE 消息的参数
				);
		------- 下面是对函数参数的详细解释：

				lpClassName：要创建的窗口的类名，通常是已经在应用程序中注册过的窗口类名。如果是系统定义的控件，如按钮、文本框等，可以使用它们的预定义类名，如 BUTTON、EDIT 等。
				lpWindowName：窗口标题，可以是一个字符串常量或 NULL，如果为 NULL，窗口将没有标题栏。
				dwStyle：窗口的风格，是一个 32 位的二进制标志，包含多个窗口样式和属性。例如，WS_OVERLAPPEDWINDOW 表示创建一个带标题、边框和最大化/最小化按钮的窗口。更多窗口风格和属性请参考 MSDN 文档。
				x：窗口的 X 坐标，以屏幕左上角为原点，单位为像素。
				y：窗口的 Y 坐标，以屏幕左上角为原点，单位为像素。
				nWidth：窗口的宽度，单位为像素。
				nHeight：窗口的高度，单位为像素。
				hWndParent：父窗口的句柄，通常是该窗口的父级窗口或者是所属的对话框窗口的句柄。如果窗口没有父级，则为 NULL。
				hMenu：菜单的句柄或者菜单的 ID，如果窗口不需要菜单，则为 NULL。
				hInstance：窗口所属应用程序实例的句柄。
				lpParam：用于传递给 WM_CREATE 消息的参数，可以是任何类型的指针，通常用于传递应用程序的信息。
				在创建窗口后，程序员通常需要注册窗口消息处理函数以便对窗口消息进行处理。当窗口接收到不同的消息时，Windows 将会调用这些消息处理函数。
				
		------- lpClassName是CreateWindow函数的参数之一，它用于指定要创建的窗口类的名称。

				以下是一些常见的窗口类名：
				
				BUTTON：按钮控件类名。
				COMBOBOX：组合框控件类名。
				EDIT：编辑框控件类名。
				LISTBOX：列表框控件类名。
				STATIC：静态文本控件类名。
				SCROLLBAR：滚动条控件类名。
				TOOLBAR：工具栏控件类名。
				TOOLTIPS_CLASS：工具提示控件类名。
				TRACKBAR：滑动条控件类名。
				TREEVIEW：树形视图控件类名。
				STATUSCLASSNAME：状态栏控件类名。
				此外，您还可以使用自定义的窗口类名来创建自定义的窗口控件。在这种情况下，您需要先使用RegisterClass或RegisterClassEx函数注册一个新的窗口类，并使用注册时获得的类名来调用CreateWindow函数来创建控件。
				以下是 CreateWindow() 函数中 lpClassName 参数的一些示例：

				如果您想创建一个普通的窗口，可以将 lpClassName 设为 NULL 或者空字符串。
				CreateWindow(NULL, _T("My Window"), WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
				如果您想创建一个按钮，可以将 lpClassName 设为 "BUTTON"。
				CreateWindow(_T("BUTTON"), _T("Click Me!"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 100, 100, 80, 25, hWnd, (HMENU)IDC_BUTTON, hInstance, NULL);
				如果您想创建一个编辑框，可以将 lpClassName 设为 "EDIT"。
				CreateWindow(_T("EDIT"), _T("Input text here"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 150, 25, hWnd, (HMENU)IDC_EDIT, hInstance, NULL);
				如果您想创建一个列表框，可以将 lpClassName 设为 "LISTBOX"。
				CreateWindow(_T("LISTBOX"), NULL, WS_CHILD | WS_VISIBLE | LBS_STANDARD, 100, 100, 150, 100, hWnd, (HMENU)IDC_LISTBOX, hInstance, NULL);
				如果您想创建一个组合框，可以将 lpClassName 设为 "COMBOBOX"。
				CreateWindow(_T("COMBOBOX"), NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, 100, 100, 150, 200, hWnd, (HMENU)IDC_COMBOBOX, hInstance, NULL);
				以上示例仅供参考，您可以根据自己的需要选择合适的类名。同时需要注意的是，在使用某些类名时，需要包含相应的头文件或链接相应的库文件。
*************************************************** ************************* ************************* ************************* ************************* ************************* ************************* ************************* ************************* 
				解读MessageBox()函数 (消息弹窗box函数)
				 MessageBox(NULL→可能是必要的,消息正文内容,标题,这里是按钮包含的内容,用|分割,MB_OK是确认按钮,MB_ICONERROR是错误图标,MB_ICONINFORMATION是i信息图标);
				 由ChatGPT提供的解释 
				在 Windows.h 中，MessageBox() 函数的最后一个参数 flags 是一个整型值，它指定了显示消息框时的选项和按钮，可以是以下值之一或它们的组合：
				MB_OK：消息框包含一个“确定”按钮。
				MB_OKCANCEL：消息框包含“确定”和“取消”两个按钮。
				MB_ABORTRETRYIGNORE：消息框包含“终止”、“重试”和“忽略”三个按钮。
				MB_YESNOCANCEL：消息框包含“是”、“否”和“取消”三个按钮。
				MB_YESNO：消息框包含“是”和“否”两个按钮。
				MB_RETRYCANCEL：消息框包含“重试”和“取消”两个按钮。
				MB_ICONHAND：消息框包含一个手形图标。
				MB_ICONQUESTION：消息框包含一个问号图标。
				MB_ICONEXCLAMATION：消息框包含一个感叹号图标。
				MB_ICONASTERISK：消息框包含一个星号图标。
				MB_USERICON：消息框包含一个自定义图标，应使用 SetWindowLong 函数来设置 hIcon 成员。
				MB_TOPMOST：消息框显示在所有其他窗口的顶部。
				MB_SETFOREGROUND：指定消息框后，将其移到最前面。
				MB_DEFAULT_DESKTOP_ONLY：将消息框放置在桌面窗口的顶部。如果使用了 MB_TOPMOST 或 MB_SERVICE_NOTIFICATION，则忽略此标志。
				MB_SERVICE_NOTIFICATION：当设置了 MB_SERVICE_NOTIFICATION 标志时，表示应用程序是一个服务程序，应在用户没有登录的情况下显示消息框。
				
				当你使用MessageBox函数并将参数设置为MB_OKCANCEL时，MessageBox函数将返回一个整数值来指示用户点击了哪个按钮。如果用户点击"确定"按钮，函数返回值为IDOK(即1)，如果用户点击"取消"按钮，则函数返回值为IDCANCEL(即2)。
				你可以使用这个返回值来确定用户单击的是哪个按钮。
			*/
			break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case 1:MessageBox(NULL,"请查看控制台,若此窗口无响应是正常情况","查询内容",MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION);find();break;
//				case 2:zyk();break;
				case 3:boxreturn=MessageBox(NULL,"您要打开默认库data.cd吗?\n -   是 :读取默认库data.cd\n -   否 :将询问词典库名称\n - 取消:不读取库","词典",MB_SYSTEMMODAL|MB_YESNOCANCEL|MB_ICONQUESTION);all_add();break;
				case 4:MessageBox(NULL,"请查看控制台,若此窗口无响应是正常情况","导出调试库",MB_SYSTEMMODAL|MB_OK|MB_ICONINFORMATION);Save_123();break;
				case 5:{
					boxreturn=MessageBox(NULL,"确认清空词典吗?","清空词典",MB_SYSTEMMODAL|MB_OKCANCEL|MB_ICONQUESTION);
					/*修改指针:
						优点：速度快
						缺点：数据还在，处理不当可能会有漏洞*/
					if(boxreturn==IDOK) x_num=0;
					else MessageBox(NULL,"已取消","清空词典",MB_SYSTEMMODAL|MB_OK|MB_ICONASTERISK);
					break;
				}
				case 6:system("explorer Readme.md");break;
				case 7:MessageBox(NULL,"暂未开放...","网络词典库",MB_SYSTEMMODAL|MB_OK|MB_ICONASTERISK);break;
				case 8:{
					boxreturn=MessageBox(NULL,"确定将123-123.cd覆盖给data.cd?\n这将会丢失您data.cd中的内容！\n -   是 :执行\n - 取消:不执行","词典",MB_SYSTEMMODAL|MB_OKCANCEL|MB_ICONASTERISK);
					if(boxreturn==IDOK) system("copy 123-123.cd data.cd");
					else{
						MessageBox(NULL,"已取消","内置库",MB_SYSTEMMODAL|MB_OK|MB_ICONASTERISK);
						break; 
					}
					boxreturn=MessageBox(NULL,"您要打开默认库data.cd吗?\n -   是 :读取默认库data.cd\n -   否 :将询问词典库名称\n - 取消:不读取库","重读词典",MB_SYSTEMMODAL|MB_YESNOCANCEL|MB_ICONQUESTION);
					if(boxreturn==IDNO){
						cout<<"请输入您的词典库文件名称(带后缀名)";
						cin>>firname;
						inf(firname);
						all_add();
					}else{
						if(boxreturn==IDYES){
							inf("data.cd");
							all_add();
						}
					}
					break;
				}
				default:error(102);break;
			}
			break;
		} 
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		} 
		default:return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	// 关闭窗口
	EndDialog(hwnd,0);
	return 0;
}
//int main(){
//	all_add();
//	while(1){
//		zjm();
//		if(returnn) break;
//	}
//	return 0;
//} 

/*
Error.help

3
100 ERROR_COLOUR_NUMBER_ERROR 颜色数字调用错误
101 ERROR_NOT_FOUND_KU 未找到库
102 ERROR_CMD_NOT_FOUND 命令未找到
*/

/*
弹窗询问程序
  调用方式:tc.json
  第一行:窗口标题
  第二行:正文
#include<bits/stdc++.h>
using namespace std;
ifstream inFile;
ofstream outFile;
string tit,nr,ls,f;
int main(){
	inFile.open("tc.json",ios::in);
	inFile>>tit>>nr;
	system("cls");
	ls="title "+tit;
	system(ls.data());
	cout<<" ______________________________________\n";
	cout<<"|"<<tit<<"\n";
	cout<<"|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n";
	cout<<"|"<<nr<<"\n"; 
	cout<<"|";cin>>f;
	outFile.open("tc.json",ios::out);
	outFile<<f;
	return 0;
}
*/
