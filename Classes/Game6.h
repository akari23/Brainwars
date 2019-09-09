#ifndef __Game6_H__
#define __Game6_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Score.h"
USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Game6 : public Scene
{
private:


public:
	

	void kembali(Ref* sender);//kembali ke menu pilihan game
	void mulaiGame(Ref* sender);//mulai game


	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Game6);

	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");

	//ui game//
	Sprite* ui_play = Sprite::create("ui_game6.jpg");
	Button* button_start = Button::create("btn_awal.jpg", "btn_tekan.jpg", "btn_awal.jpg");


	//Sprite Soal//
	Sprite* soal_Gunting = Sprite::create("game6/soal_gunting.png");
	Sprite* soal_Batu = Sprite::create("game6/soal_batu.png");
	Sprite* soal_Kertas = Sprite::create("game6/soal_kertas.png");
	//////////////

	//jawaban///
	Button* jawab_Gunting = Button::create("game6/jawab_gunting.png", "game6/jawab_gunting.png", "game6/jawab_gunting.png");
	Button* jawab_Batu = Button::create("game6/jawab_batu.png", "game6/jawab_batu.png", "game6/jawab_batu.png");
	Button* jawab_Kertas = Button::create("game6/jawab_kertas.png", "game6/jawab_kertas.png", "game6/jawab_kertas.png");
	///////////

	//fungsi jawaban button//
	void btnGunting(Ref* sender);
	void btnBatu(Ref* sender);
	void btnKertas(Ref* sender);
	/////////////////////////

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