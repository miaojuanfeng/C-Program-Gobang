LRESULT CALLBACK Winpro(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK dialogpro(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
sock();
load(HINSTANCE hInstance);


void TransparentBlt2( HDC hdcDest,      // Ŀ��DC
int nXOriginDest,   // Ŀ��Xƫ��
int nYOriginDest,   // Ŀ��Yƫ��
int nWidthDest,     // Ŀ����
int nHeightDest,    // Ŀ��߶�
HDC hdcSrc,         // ԴDC
int nXOriginSrc,    // ԴX���
int nYOriginSrc,    // ԴY���
int nWidthSrc,      // Դ���
int nHeightSrc,     // Դ�߶�
UINT crTransparent  // ͸��ɫ,COLORREF����
);

int  Position(int x,int y,int *k,int *l);
int  Win();
int forbid1();
int forbid2(int x,int y);
int TurnBackRecord(int x,int y);
int TurnBack();
int Fight(int x,int y);