#pragma once

//���ӿ� �ʿ��� ���̺귯��,������ ��� �ִ� ���
#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <limits>
#include <string>
#include <conio.h>	
#include <functional>


using namespace std;

enum class BLOCK
{
	ROAD = '0',
	WALL = '1',
	START = '2',
	EXIT = '3',
	BOMB = '4',
	ITEM = '5'
};

enum class DIR
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

#define RENDER_BUFFER_WIDTH 60
#define RENDER_BUFFER_HEIGHT 30

#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }	