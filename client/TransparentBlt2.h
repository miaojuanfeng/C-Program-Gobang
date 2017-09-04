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
)
{
HBITMAP hOldImageBMP, hImageBMP = CreateCompatibleBitmap(hdcDest, nWidthDest, nHeightDest); // 创建兼容位图
HBITMAP hOldMaskBMP, hMaskBMP = CreateBitmap(nWidthDest, nHeightDest, 1, 1, NULL);   // 创建单色掩码位图
HDC  hImageDC = CreateCompatibleDC(hdcDest);
HDC  hMaskDC = CreateCompatibleDC(hdcDest);
hOldImageBMP = (HBITMAP)SelectObject(hImageDC, hImageBMP);
hOldMaskBMP = (HBITMAP)SelectObject(hMaskDC, hMaskBMP);
// 将源DC中的位图拷贝到临时DC中
if (nWidthDest == nWidthSrc && nHeightDest == nHeightSrc)
BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hdcSrc, nXOriginSrc, nYOriginSrc, SRCCOPY);
else
StretchBlt(hImageDC, 0, 0, nWidthDest, nHeightDest,
hdcSrc, nXOriginSrc, nYOriginSrc, nWidthSrc, nHeightSrc, SRCCOPY);
// 设置透明色
SetBkColor(hImageDC, crTransparent);
// 生成透明区域为白色，其它区域为黑色的掩码位图
BitBlt(hMaskDC, 0, 0, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCCOPY);
// 生成透明区域为黑色，其它区域保持不变的位图
SetBkColor(hImageDC, RGB(0,0,0));
SetTextColor(hImageDC, RGB(255,255,255));
BitBlt(hImageDC, 0, 0, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
// 透明部分保持屏幕不变，其它部分变成黑色
SetBkColor(hdcDest,RGB(255,255,255));
SetTextColor(hdcDest,RGB(0,0,0));
BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hMaskDC, 0, 0, SRCAND);
// "或"运算,生成最终效果
BitBlt(hdcDest, nXOriginDest, nYOriginDest, nWidthDest, nHeightDest, hImageDC, 0, 0, SRCPAINT);
// 清理、恢复
SelectObject(hImageDC, hOldImageBMP);
DeleteDC(hImageDC);
SelectObject(hMaskDC, hOldMaskBMP);
DeleteDC(hMaskDC);
DeleteObject(hImageBMP);
DeleteObject(hMaskBMP);
}