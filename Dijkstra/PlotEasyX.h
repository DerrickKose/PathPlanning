#pragma once
#include <graphics.h>
#include <iostream>

constexpr auto swidth = 1200; // 窗口宽
constexpr auto sheight = 800; // 窗口高
constexpr auto proportion = 6; // 比例

class PlotEasyX
{
public:
	PlotEasyX(int ori_x, int ori_y, int len_x, int len_y, int spac_tick, LPCTSTR text_x, LPCTSTR text_y, int len_tick, int prop_x, int prop_y);
	void plotAxis(); // 坐标轴

public:
	int ori_x, ori_y, len_x, len_y, spac_tick, len_tick, prop_x, prop_y;
	//坐标原点，坐标长度，刻度间隔，刻度线长度，坐标比例
	LPCTSTR text_x, text_y; // 坐标文字
};

