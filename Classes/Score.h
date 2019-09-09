#ifndef __Score_H__
#define __Score_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "SimpleAudioEngine.h"
#include "HomeMenu.h"
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
#include "Game4.h"
#include "Game5.h"
#include "Game6.h"

USING_NS_CC;

using namespace cocos2d::ui;
using namespace cocos2d;
using namespace CocosDenshion;

class Score : public Scene
{
private:

public:

	static Scene* scene();
	virtual bool init();
	CREATE_FUNC(Score);

	void kembali(Ref* sender);//kembali ke menu pilihan game


	//background game//
	Sprite* bg_menu = Sprite::create("bg_game.jpg");
	Button* btn_back = Button::create("buttonback.png", "btnback_tekan.png", "btnback.png");


	//label//
	Label* label_benar = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_salah = Label::createWithTTF("", "fonts/arial.ttf", 100);
	Label* label_accuracy = Label::createWithTTF("", "fonts/arial.ttf", 30);

	float nilai;
	const char* nilai_benar;
	const char* nilai_salah;
	const char* nilai_accuracy;


	////////





};


#endif