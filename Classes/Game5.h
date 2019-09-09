#ifndef __Game5_H__
#define __Game5_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game5 : public Scene
{
private:

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
	//void update(float dt);

	bool isTouchDown;

	float initialTouchPos[2];
	float currentTouchPos[2];

public:
	cocos2d::Size visibleSize;

	void kembali(Ref* sender);//kembali ke menu pilihan game
	void mulaiGame(Ref* sender);//mulai game


	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Game5);

	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");

	//ui game//
	Sprite* ui_play = Sprite::create("ui_game5.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	

	//Sprite Soal//
	Sprite* SoalBiruAtas = Sprite::create("game5/AtasBiru.png");
	Sprite* SoalPinkAtas = Sprite::create("game5/AtasPink.png");
	Sprite* SoalBiruBawah = Sprite::create("game5/BawahBiru.png");
	Sprite* SoalPinkBawah = Sprite::create("game5/BawahPink.png");
	Sprite* SoalBiruKanan = Sprite::create("game5/KananBiru.png");
	Sprite* SoalPinkKanan = Sprite::create("game5/KananPink.png");
	Sprite* SoalBiruKiri = Sprite::create("game5/KiriBiru.png");
	Sprite* SoalPinkKiri = Sprite::create("game5/KiriPink.png");
	//////////////

	//label//
	Label* label_waktu = Label::createWithTTF("", "fonts/arial.ttf", 100);
	////////


	const char*  nilai_waktu;

	void penjadwalanWaktu(float dt);
	int waktu = 20;
	int mulai = 0;
	int pilihan; // jawaban letak
	int soal1, soal2, soal3, jawaban;
	static float benar;
	static float salah;
	int hitung = 10000;
};


#endif