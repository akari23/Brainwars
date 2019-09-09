#ifndef __Game4_H__
#define __Game4_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game4 : public Scene
{
private:

public:
	void kembali(Ref* sender);//kembali ke menu pilihan game
	void mulaiGame(Ref* sender);//mulai game
	void jawaban_1(Ref* sender);//jawaban di button1
	void jawaban_2(Ref* sender);//jawaban di button2
	void jawaban_3(Ref* sender);//jawaban di button3
	void jawaban_4(Ref* sender);//jawaban di button4




	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Game4);

	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");

	//ui game//
	Sprite* ui_play = Sprite::create("ui_game4.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* jawab1 = Button::create("game4/gear1-1.jpg", "game4/gear1-1.jpg", "game4/gear1-1.jpg");//jawaban 1
	Button* jawab2 = Button::create("game4/gear2-1.jpg", "game4/gear2-1.jpg", "game4/gear2-1.jpg");//jawaban 2
	Button* jawab3 = Button::create("game4/gear3-1.jpg", "game4/gear3-1.jpg", "game4/gear3-1.jpg");//jawaban 3
	Sprite* jawab_1 = Sprite::create("game4/gear1-1.png");//gambar pada jawaban pilihan ke-1
	Sprite* jawab_2 = Sprite::create("game4/gear2-1.png");//gambar pada jawaban pilihan ke-2
	Sprite* jawab_3 = Sprite::create("game4/gear3-1.png");//gambar pada jawaban pilihan ke-3

	//soal game//
	Sprite* Soal1 = Sprite::create("game4/gear1.png");
	Sprite* Soal2 = Sprite::create("game4/gear2.png");
	Sprite* Soal3 = Sprite::create("game4/gear3.png");
	////////////

	//label//
	Label* label_waktu = Label::createWithTTF("", "fonts/arial.ttf", 100);
	////////

	const char* nilai_soal1;
	const char* nilai_soal2;
	const char* nilai_soal3;
	const char* nilai_tanda1;
	const char* nilai_tanda2;
	const char* nilai_jawaban1;
	const char* nilai_jawaban2;
	const char* nilai_jawaban3;
	const char* nilai_jawaban4;
	const char*  nilai_waktu;

	void penjadwalanWaktu(float dt);
	int waktu = 20;
	int mulai = 0;
	int pilihan; // jawaban letak
	//int soal1, soal2, soal3, jawaban;
	static float benar;
	static float salah;
	int hitung = 10000;

};

#endif