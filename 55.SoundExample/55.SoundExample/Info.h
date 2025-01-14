#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>

//---------------음악을 사용할 헤더추가
#pragma comment(lib,"winmm.lib")

using namespace std;

enum class MusicNumber
{
	TroyeSIvan = 1,
	Maroon5,
	YouDaEn ,
	AnnerMarie ,
	JangBeomJun ,
	GyungSeo ,
	AllTimeLow ,
	OnePiece ,
	PostMalone ,
	SungSiKyung ,
};

enum class MenuSelect
{
	DefaultPlay = 1,
	RandomPlay ,
	EXIT ,
};