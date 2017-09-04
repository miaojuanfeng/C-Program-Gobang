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
)
{
HBITMAP hOldImageBMP, hImageBMP = CreateCompatibleBitmap(hdcDest, nWidthDest, nHeightDest); // ��������λͼ
HBITMAP hOldMaskBMP, hMaskBMP = CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);   // ������ɫ����λͼ
HDC  hImageDC = CreateCompatibleDC(hdcDest);
HDC  hMaskDC = CreateCompatibleDC(hdcDest);
hOldImageBMP = (HBITMAP)SelectObject(hImageDC, hImageBMP);
hOldMaskBMP = (HBITMAP)SelectObject(hMaskDC, hMaskBMP);
// ��ԴDC�е�λͼ��������ʱDC��
if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY);
else
StretchBlt(hImageDC, 0, 0, nWidthDest, nHeightDest,
hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, SRCCOPY);
// ����͸��ɫ
SetBkColor(hImageDC, crTransparent);
// ����͸������Ϊ��ɫ����������Ϊ��ɫ������λͼ
BitBlt(hMaskDC, 0, 0, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCCOPY);
// ����͸������Ϊ��ɫ���������򱣳ֲ����λͼ
SetBkColor(hImageDC, RGB(0,0,0));
SetTextColor(hImageDC, RGB(255,255,255));
BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
// ͸�����ֱ�����Ļ���䣬�������ֱ�ɺ�ɫ
SetBkColor(hdcDest,RGB(255,255,255));
SetTextColor(hdcDest,RGB(0,0,0));
BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
// "��"����,��������Ч��
BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCPAINT);
// �����ָ�
SelectObject(hImageDC, hOldImageBMP);
DeleteDC(hImageDC);
SelectObject(hMaskDC, hOldMaskBMP);
DeleteDC(hMaskDC);
DeleteObject(hImageBMP);
DeleteObject(hMaskBMP);
}