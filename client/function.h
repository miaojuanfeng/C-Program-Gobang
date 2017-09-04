LRESULT CALLBACK Winpro(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK dialogpro(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
sock();
load(HINSTANCE hInstance);


void TransparentBlt2( HDC hdcDest,      // 目标DC
int nXOriginDest,   // 目标X偏移
int nYOriginDest,   // 目标Y偏移
int nWidthDest,     // 目标宽度
int nHeightDest,    // 目标高度
HDC hdcSrc,         // 源DC
int nXOriginSrc,    // 源X起点
int nYOriginSrc,    // 源Y起点
int nWidthSrc,      // 源宽度
int nHeightSrc,     // 源高度
UINT crTransparent  // 透明色,COLORREF类型
);

int  Position(int x,int y,int *k,int *l);
int  Win();
int forbid1();
int forbid2(int x,int y);
int TurnBackRecord(int x,int y);
int TurnBack();
int Fight(int x,int y);