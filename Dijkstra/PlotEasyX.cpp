#include "PlotEasyX.h"

PlotEasyX::PlotEasyX(int ori_x, int ori_y, int len_x, int len_y, int spac_tick, LPCTSTR text_x, LPCTSTR text_y, int len_tick, int prop_x, int prop_y)
{
	this->ori_x = ori_x;
	this->ori_y = ori_y;
	this->len_x = len_x;
	this->len_y = len_y;
	this->spac_tick = spac_tick;
	this->len_tick = len_tick;
	this->text_x = text_x;
	this->text_y = text_y;
	this->prop_x = prop_x;
	this->prop_y = prop_y;
}

void PlotEasyX::plotAxis()
{
	setbkcolor(WHITE); // 背景颜色
	setlinecolor(BLACK); // 边框颜色
	setlinestyle(PS_SOLID, 2); // 设置线样式为实线3px
	cleardevice(); //清除屏幕内容
	setorigin(ori_x, ori_y); // 设定坐标原点
	line(0, 0, len_x, 0); // 绘制X轴
	line(0, 0, 0, -len_y); // 绘制Y轴

	settextcolor(BLACK); //文本颜色
	settextstyle(20, 0, _T("宋体")); // 字体高度20px，宽度自适应，字体

	RECT rX, rY;
	rX.left = len_x + 30;
	rX.right = rX.left + textwidth(text_x);
	rX.top = -textheight(text_x) / 2;
	rX.bottom = rX.top + textheight(text_x);
	outtextxy(rX.left, rX.top, text_x); // 显示X轴名称

	rY.right = textwidth(text_y) / 2;
	rY.left = rY.right - textwidth(text_y);
	rY.bottom = -len_y - 20;
	rY.top = rY.bottom - textheight(text_y);
	outtextxy(rY.left, rY.top, text_y); // 显示Y轴名称

	settextstyle(15, 0, _T("宋体"));
	TCHAR num[8] = { 0 };
	RECT r_num;

	for (int i = spac_tick; i <= len_x; i += spac_tick)
	{
		line(i, 0, i, -len_tick);
		_stprintf_s(num, 8, _T("%d"), i / prop_x);
		r_num.left = i - textwidth(num) / 2;
		r_num.top = 5;
		outtextxy(r_num.left, r_num.top, num);
	}

	for (int i = -spac_tick; i >= -len_x; i += spac_tick)
	{
		line(0, i, -len_tick, i);
		_stprintf_s(num, 8, _T("%d"), -i / prop_y);
		r_num.left = - textwidth(num) - 5;
		r_num.top = i - textwidth(num) / 2;
		outtextxy(r_num.left, r_num.top, num);
	}
}
