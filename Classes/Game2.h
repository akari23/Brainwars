#ifndef __Game2_H__
#define __Game2_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game2 : public Scene
{
private:

public:

	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Game2);

	void kembali(Ref* sender);//kembali ke menu pilihan game
	void mulaiGame(Ref* sender);//
	void next_game(Ref* sender);//fungsi untuk menjawab soal
	//jawaban//
	void jawaban_1(Ref* sender);
	void jawaban_2(Ref* sender);
	void jawaban_3(Ref* sender);
	void jawaban_4(Ref* sender);
	//////////

	void penjadwalanWaktu(float dt);
	int waktu = 20;

	//ui start game//
	Sprite* ui_play = Sprite::create("ui_game2.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");
	Button* button_lanjut = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg"); // button lanjut
	Button* jawab1 = Button::create("game2/jawab.png", "game2/jawab.png", "game2/jawab.png");
	Button* jawab2 = Button::create("game2/jawab.png", "game2/jawab.png", "game2/jawab.png");
	Button* jawab3 = Button::create("game2/jawab.png", "game2/jawab.png", "game2/jawab.png");
	Button* jawab4 = Button::create("game2/jawab.png", "game2/jawab.png", "game2/jawab.png");


	//background game//
	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");

	//sprite minigame//
	Sprite* Soal1 = Sprite::create("game2/blue.png");
	Sprite* Soal2_tambah = Sprite::create("game2/blue.png"); 
	Sprite* Soal2_kurang = Sprite::create("game2/yellow.png");
	//////////////////

	//label//
	Label* label_waktu = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_soal3 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban1 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban2 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban3 = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_jawaban4 = Label::createWithTTF("", "fonts/arial.ttf", 100);

	const char* nilai_soal1;
	const char* nilai_soal2;
	const char* nilai_jawaban1;
	const char* nilai_jawaban2;
	const char* nilai_jawaban3;
	const char* nilai_jawaban4;
	const char*  nilai_waktu;
	////////

	int hitung = 10000;//nilai pengurangan schedule
	int mulai;
	int nilai;//nilai jawaban
	int pilihan;//letak jawaban
	static float benar;
	static float salah;
};

#endif