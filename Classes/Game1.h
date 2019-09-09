#ifndef __Game1_H__
#define __Game1_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game1 : public Scene
{
private:

public:


	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Game1);

	void kembali(Ref* sender);//kembali ke menu pilihan game
	void mulaiGame(Ref* sender);//mulai game

	//button game action//

	void btnTambahAction(Ref* sender);
	void btnKurangAction(Ref* sender);
	void btnKaliAction(Ref* sender);
	void btnBagiAction(Ref* sender);

	/////////////////////


	//ui start game//
	Sprite* ui_play = Sprite::create("ui_game1.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
		

	//background game//
	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");


	//waktu//
	void penjadwalanWaktu(float dt);
	int waktu = 20;

	Label* label_samadengan = Label::createWithTTF(" = ", "fonts/arial.ttf",100);
	Label* garis = Label::createWithTTF(" ___ " , "fonts/arial.ttf",100);
	Label* label_waktu = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_hasil = Label::createWithTTF("", "fonts/arial.ttf", 100);
	const char* hasil_string;

	//button//
	Button* btnTambah = Button::create("game1/buttonplus.jpg", "game1/buttonplus_tekan.jpg", "game1/buttonplus.jpg");
	Button* btnKurang = Button::create("game1/buttonminus.jpg", "game1/buttonminus_tekan.jpg", "game1/buttonminus.jpg");
	Button* btnKali   = Button::create("game1/buttonkali.jpg", "game1/buttonkali_tekan.jpg", "game1/buttonkali.jpg");
	Button* btnBagi   = Button::create("game1/buttonbagi.jpg", "game1/buttonbagi_tekan.jpg", "game1/buttonbagi.jpg");
	/////////
	int mulai;
	int hitung = 100000;
	int operation;
	static float benar;
	static float salah;


	bool freeze;
};

#endif