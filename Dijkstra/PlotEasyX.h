#pragma once
#include <graphics.h>
#include <iostream>

constexpr auto swidth = 1200; // ���ڿ�
constexpr auto sheight = 800; // ���ڸ�
constexpr auto proportion = 6; // ����

class PlotEasyX
{
public:
	PlotEasyX(int ori_x, int ori_y, int len_x, int len_y, int spac_tick, LPCTSTR text_x, LPCTSTR text_y, int len_tick, int prop_x, int prop_y);
	void plotAxis(); // ������

public:
	int ori_x, ori_y, len_x, len_y, spac_tick, len_tick, prop_x, prop_y;
	//����ԭ�㣬���곤�ȣ��̶ȼ�����̶��߳��ȣ��������
	LPCTSTR text_x, text_y; // ��������
};

