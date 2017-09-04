#define black 1             //黑子
#define white 2              //白子
#define NONE 5               //无子

#define	IDM_MAIN	1000	//菜单
#define	IDA_MAIN	1001	//托盘菜单

#define	IDM_RESTART	1002	//"重来"菜单项
#define	IDM_TURNBACK	1003	//"悔棋"菜单项
#define IDM_EXIT        1004    //"退出"菜单
#define	IDM_HEIZIJINSHOU 1005	//"黑子禁手菜单项"
#define	IDM_HUANSE	1006	//"换色菜单项"
#define IDM_HELP	1007	//"帮助"菜单项
#define IDM_OPEN    1008        //打开界面

#define ABOUTSDK        1009    //关于SDK
#define ABOUTFIVECHESS  1010    //关于五子棋
#define ABOUTJINSHOU    1011    //关于禁手
#define ABOUTZUOZE      1012    //关于作者
#define ABOUTAPI        1013    //关于API

#define WM_ICON (WM_USER + 1)    //托盘图标消息

#define TIMERNUMBER 1           //数字
#define TIMERBIRD 2             //鸟
#define TIMERBIRDKILL 3//删鸟
#define TIMERWAITE 4//等
#define TIMERWAITEKILL 5//删等
#define TIMERRABBIT 6//兔
#define TIMERRABBITKILL 7//删兔
#define TIMERDOG 8//狗
#define TIMERDOGKILL 9//删狗
#define TIMERKISS 10//吻
#define TIMERKISSKILL 11//删吻
#define TIMERHAND 12//手
#define TIMERHANDKILL 13//删手


#define msglinein 1//连接服务器
#define msgconnected 2//连接服务器
#define msgchess 3//落子
#define msgchating 4//聊天
#define msglineout 5//离线
#define msgrestart 7//重来
#define msgback 8//悔棋
#define msgyestoback 11//同意悔棋
#define msgnotoback 12//不同意悔棋
#define msgyestorestart 13//同意重来
#define msgnotorestart 14//不同意重来
#define msgchangecolor 15//换色
#define msgyeschangecolor 16//同意换色
#define msgnochangecolor 17//不同意换色
#define msgchangerule 18//改变规则
#define msgyeschangerule 19//同意改变规则
#define msgnochangerule 20//不同意改变规则
#define msgblackwin 21//黑子胜
#define msgwhitewin 22//白子胜
#define msgjinshou 23//黑子禁手

static HCURSOR hcursor[5];                           //鼠标句柄
static HMENU hmenu[2],hMenu[2];                      //菜单句柄
static HBITMAP hbitmap[4],hbitmapnumber[10],         //图片句柄
       hbitmapsend[3],hbird[2],hwaite[5],hrabbit[15],
	   hdog[2],hkiss[5],hhand[2],hwin[4],hcom[5],himformation[2];

static	HWND hedit[3],hstatic,hcommand,Openannet;    //窗口句柄
int sendornot=0,winpic=NONE;                         //发送标示，胜利贴图标示
int color=NONE,rule=NONE;                            //颜色，规则
char ip[20],staticcaption[100];                      //IP地址，static显示标题
char server[100],serverchange[100];                  //保存服务器消息

static	PAINTSTRUCT ps;                              //绘画结构体
static  RECT rc;                                     //重绘矩形区
static  RECT rc2,rc3,rc4,rc5,rc6,rc7,rcwin,rccom;    //重绘矩形区
static	HDC hdc,mdc,hdc2,mdc2,hdc3,mdc3,hdc4,mdc4,hdc5,mdc5; //设备内存空间
static	HINSTANCE hinstance;            //窗体实例句柄
 
int x,y;                                //鼠标坐标
	
//char a[100];                            //鼠标移动时显示鼠标坐标
static int times=0,bird=0,waite=0,rabbit=0,    //动态图片显示标示
           rabbitnum=0,dog=0,dognum=0,kiss=0,
		   kissnum=0,hand=0,handnum=0;
static int birdx=-65;             //鸟图片坐标
static int rabbitmove=1,dogmove=1,kissmove=1,handmove=1,sendmove=1;//动态图片显示标示
static int shownum=1;             //退出图片重绘标示

static int Chess[15][15];         //保存棋盘落子状况
static POINT posi[15][15];        //记录棋盘交叉点坐标
static POINT posit[15][15];       //记录悔棋坐标
static int pox=0,poy=0;           //记录鼠标落子坐标
static int order=NONE;            //黑白落子顺序
int i,j;                          //循环变量
int result=0;                     //落子胜负判断
int destroy=0;                    //销毁窗体空间标示
int imformation=0;                //程序启动时在窗体上画图标示
HWND Hwnd;                        //窗口句柄
HANDLE hsound;                    //sound线程句柄
DWORD Id;                         //sound线程ID号

static SOCKET so;                 //套接字
SOCKADDR_IN add,ser;              //SOCKADDR_IN结构体变量
int len;                          //SOCKADDR长度

bool play=false,                  //是否播放背景音乐
     paint=true;                  //是否重绘棋盘文字
int switchsong=0;                 //背景音乐选择

struct Msg                        //消息结构体
{
   int type;
   char position[20];
   char chat[500];
   char server[100];
   int pox;
   int poy;
   int color;
   int rule;
}sendmessage,revmessage,sendmessage2;