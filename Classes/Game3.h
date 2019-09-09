#ifndef __Game3_H__
#define __Game3_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game3 : public Scene
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
	CREATE_FUNC(Game3);

	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");

	//ui game//
	Sprite* ui_play = Sprite::create("ui_game3.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* jawab1 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* jawab2 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* jawab3 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* jawab4 = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");

	//label//
	Label* label_waktu = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal3 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* tanda1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* tanda2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban3 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban4 = Label::createWithTTF("", "fonts/arial.ttf", 100);
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
	int soal1, soal2, soal3, jawaban;
	static float benar;
	static float salah;
	int hitung = 10000;
};

#endif