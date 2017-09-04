#define black 1             //����
#define white 2              //����
#define NONE 5               //����

#define	IDM_MAIN	1000	//�˵�
#define	IDA_MAIN	1001	//���̲˵�

#define	IDM_RESTART	1002	//"����"�˵���
#define	IDM_TURNBACK	1003	//"����"�˵���
#define IDM_EXIT        1004    //"�˳�"�˵�
#define	IDM_HEIZIJINSHOU 1005	//"���ӽ��ֲ˵���"
#define	IDM_HUANSE	1006	//"��ɫ�˵���"
#define IDM_HELP	1007	//"����"�˵���
#define IDM_OPEN    1008        //�򿪽���

#define ABOUTSDK        1009    //����SDK
#define ABOUTFIVECHESS  1010    //����������
#define ABOUTJINSHOU    1011    //���ڽ���
#define ABOUTZUOZE      1012    //��������
#define ABOUTAPI        1013    //����API

#define WM_ICON (WM_USER + 1)    //����ͼ����Ϣ

#define TIMERNUMBER 1           //����
#define TIMERBIRD 2             //��
#define TIMERBIRDKILL 3//ɾ��
#define TIMERWAITE 4//��
#define TIMERWAITEKILL 5//ɾ��
#define TIMERRABBIT 6//��
#define TIMERRABBITKILL 7//ɾ��
#define TIMERDOG 8//��
#define TIMERDOGKILL 9//ɾ��
#define TIMERKISS 10//��
#define TIMERKISSKILL 11//ɾ��
#define TIMERHAND 12//��
#define TIMERHANDKILL 13//ɾ��


#define msglinein 1//���ӷ�����
#define msgconnected 2//���ӷ�����
#define msgchess 3//����
#define msgchating 4//����
#define msglineout 5//����
#define msgrestart 7//����
#define msgback 8//����
#define msgyestoback 11//ͬ�����
#define msgnotoback 12//��ͬ�����
#define msgyestorestart 13//ͬ������
#define msgnotorestart 14//��ͬ������
#define msgchangecolor 15//��ɫ
#define msgyeschangecolor 16//ͬ�⻻ɫ
#define msgnochangecolor 17//��ͬ�⻻ɫ
#define msgchangerule 18//�ı����
#define msgyeschangerule 19//ͬ��ı����
#define msgnochangerule 20//��ͬ��ı����
#define msgblackwin 21//����ʤ
#define msgwhitewin 22//����ʤ
#define msgjinshou 23//���ӽ���

static HCURSOR hcursor[5];                           //�����
static HMENU hmenu[2],hMenu[2];                      //�˵����
static HBITMAP hbitmap[4],hbitmapnumber[10],         //ͼƬ���
       hbitmapsend[3],hbird[2],hwaite[5],hrabbit[15],
	   hdog[2],hkiss[5],hhand[2],hwin[4],hcom[5],himformation[2];

static	HWND hedit[3],hstatic,hcommand,Openannet;    //���ھ��
int sendornot=0,winpic=NONE;                         //���ͱ�ʾ��ʤ����ͼ��ʾ
int color=NONE,rule=NONE;                            //��ɫ������
char ip[20],staticcaption[100];                      //IP��ַ��static��ʾ����
char server[100],serverchange[100];                  //�����������Ϣ

static	PAINTSTRUCT ps;                              //�滭�ṹ��
static  RECT rc;                                     //�ػ������
static  RECT rc2,rc3,rc4,rc5,rc6,rc7,rcwin,rccom;    //�ػ������
static	HDC hdc,mdc,hdc2,mdc2,hdc3,mdc3,hdc4,mdc4,hdc5,mdc5; //�豸�ڴ�ռ�
static	HINSTANCE hinstance;            //����ʵ�����
 
int x,y;                                //�������
	
//char a[100];                            //����ƶ�ʱ��ʾ�������
static int times=0,bird=0,waite=0,rabbit=0,    //��̬ͼƬ��ʾ��ʾ
           rabbitnum=0,dog=0,dognum=0,kiss=0,
		   kissnum=0,hand=0,handnum=0;
static int birdx=-65;             //��ͼƬ����
static int rabbitmove=1,dogmove=1,kissmove=1,handmove=1,sendmove=1;//��̬ͼƬ��ʾ��ʾ
static int shownum=1;             //�˳�ͼƬ�ػ��ʾ

static int Chess[15][15];         //������������״��
static POINT posi[15][15];        //��¼���̽��������
static POINT posit[15][15];       //��¼��������
static int pox=0,poy=0;           //��¼�����������
static int order=NONE;            //�ڰ�����˳��
int i,j;                          //ѭ������
int result=0;                     //����ʤ���ж�
int destroy=0;                    //���ٴ���ռ��ʾ
int imformation=0;                //��������ʱ�ڴ����ϻ�ͼ��ʾ
HWND Hwnd;                        //���ھ��
HANDLE hsound;                    //sound�߳̾��
DWORD Id;                         //sound�߳�ID��

static SOCKET so;                 //�׽���
SOCKADDR_IN add,ser;              //SOCKADDR_IN�ṹ�����
int len;                          //SOCKADDR����

bool play=false,                  //�Ƿ񲥷ű�������
     paint=true;                  //�Ƿ��ػ���������
int switchsong=0;                 //��������ѡ��

struct Msg                        //��Ϣ�ṹ��
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