#include "Game3.h"

Scene* Game3::scene()
{
	return Game3::create();
}
float Game3::benar = 0;
float Game3::salah = 0;

bool Game3::init()
{
	if (!Scene::init())
	{
		return false;
	}
	benar = 0;
	salah = 0;
	bg_menu->setAnchorPoint(Vec2(0, 0));
	bg_menu->setScale(1.f);
	this->addChild(bg_menu);
	btn_back->setAnchorPoint(Vec2(0, 1));
	btn_back->setPosition(Vec2(0, 1366));
	this->addChild(btn_back);
	btn_back->addClickEventListener(CC_CALLBACK_1(Game3::kembali, this));

	ui_play->setPosition(Vec2(384, 683));
	ui_play->setScale(1.f);
	this->addChild(ui_play);
	button_start->setScale(1.f);
	button_start->setPosition(Vec2(768 / 2, 400));
	button_start->setAnchorPoint(Vec2(0.5, 0));
	this->addChild(button_start);
	auto label_start = Label::createWithTTF("START", "fonts/arial.ttf", 50);
	label_start->setPosition(Vec2(button_start->getContentSize().width / 2, button_start->getContentSize().height / 2));
	label_start->setScale(1.f);
	button_start->addChild(label_start);
	button_start->addClickEventListener(CC_CALLBACK_1(Game3::mulaiGame, this));
	
	//waktu//
	label_waktu->setPosition(Vec2(384, 1000));
	label_waktu->setScale(0.f);
	this->addChild(label_waktu);
	///////

	///soaal////
	label_soal1->setPosition(Vec2(300, 800));
	label_soal2->setPosition(Vec2(500, 800));
	label_soal3->setPosition(Vec2(700, 800));
	tanda1->setPosition(Vec2(400, 800));
	tanda2->setPosition(Vec2(600, 800));


	label_soal1->setScale(0.f);
	label_soal2->setScale(0.f);
	label_soal3->setScale(0.f);


	this->addChild(label_soal1);
	this->addChild(label_soal2);
	this->addChild(label_soal3);
	this->addChild(tanda1);
	this->addChild(tanda2);

	///////////

	//button jawab game//

	jawab1->setPosition(Vec2(768 / 2, 600));
	jawab2->setPosition(Vec2(768 / 2, 450));
	jawab3->setPosition(Vec2(768 / 2, 300));
	jawab4->setPosition(Vec2(768 / 2, 150));
	jawab1->setScale(0.f);
	jawab2->setScale(0.f);
	jawab3->setScale(0.f);
	jawab4->setScale(0.f);

	//label jawaban//
	label_jawaban1->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban2->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban3->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban4->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	////////////////

	this->addChild(jawab1);
	this->addChild(jawab2);
	this->addChild(jawab3);
	this->addChild(jawab4);
	jawab1->addChild(label_jawaban1);
	jawab2->addChild(label_jawaban2);
	jawab3->addChild(label_jawaban3);
	jawab4->addChild(label_jawaban4);
	////////////////////

	nilai_tanda1 = "";
	nilai_tanda2 = "";


	jawab1->addClickEventListener(CC_CALLBACK_1(Game3::jawaban_1, this));
	jawab2->addClickEventListener(CC_CALLBACK_1(Game3::jawaban_2, this));
	jawab3->addClickEventListener(CC_CALLBACK_1(Game3::jawaban_3, this));
	jawab4->addClickEventListener(CC_CALLBACK_1(Game3::jawaban_4, this));

	return true;
}
void Game3::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}
void Game3::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game3::penjadwalanWaktu), 0.0010f);
}

void Game3::penjadwalanWaktu(float dt)
{
	ui_play->setScale(0.f);
	label_waktu->setScale(1.f);
	label_soal1->setScale(1.f);
	label_soal2->setScale(1.f);
	jawab1->setScale(1.f);
	jawab2->setScale(1.f);
	jawab3->setScale(1.f);
	jawab4->setScale(1.f);
	button_start->setScale(0.f);
	
	int operation1;
	int operation2;

	log("%d", mulai);

	if (mulai == 0)
	{
		soal1 = random(1, 10);
		soal2 = random(1, 10);
		operation1 = random(1, 2);
		operation2 = random(1, 3);

		pilihan = random(1, 4);//letak jawaban
		int nilaiRandom1 = random(-30, 30); // jawaban random 1
		int nilaiRandom2 = random(-30, 30); // jawaban random 2
		int nilaiRandom3 = random(-30, 30); // jawaban random 3

		if (benar <= 2)
		{
			if (operation1 == 1)
			{
				jawaban = soal1 + soal2;
				nilai_tanda1 = "+";
			}
			if (operation1 == 2)
			{
				jawaban = soal1 - soal2;
				nilai_tanda1 = "-";
			}
		}
		else if (benar >= 3)
		{
			label_soal3->setScale(1.f);
			soal3 = random(1, 10);
			if (operation1 == 1)
			{
				jawaban = soal1 + soal2 + soal3;
				nilai_tanda1 = "+";
				nilai_tanda2 = "+";
			}
			if (operation1 == 2)
			{
				jawaban = soal1 - soal2 + soal3;
				nilai_tanda1 = "-";
				nilai_tanda2 = "+";
			}
			if (operation1 == 3)
			{ 
				jawaban = soal1 - soal2 - soal3;
				nilai_tanda1 = "-";
				nilai_tanda2 = "-";
			}
			nilai_soal3 = __String::createWithFormat("%d", soal3)->getCString();
			label_soal3->setString(nilai_soal3);

		}
		while ((nilaiRandom1 == jawaban) || (nilaiRandom2 == jawaban) || (nilaiRandom3 == jawaban)) // acak jika nilai random ada yg sama dengan jawaban
		{
			nilaiRandom1 = random(-30, 30); // jawaban random 1
			nilaiRandom2 = random(-30, 30); // jawaban random 2
			nilaiRandom3 = random(-30, 30); // jawaban random 3
		}

		if (pilihan == 1)
		{
			nilai_jawaban1 = __String::createWithFormat("%d", jawaban)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 2)
		{
			nilai_jawaban2 = __String::createWithFormat("%d", jawaban)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 3)
		{
			nilai_jawaban3 = __String::createWithFormat("%d", jawaban)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 4)
		{
			nilai_jawaban4 = __String::createWithFormat("%d", jawaban)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		mulai = 1;

		label_jawaban1->setString(nilai_jawaban1);
		label_jawaban2->setString(nilai_jawaban2);
		label_jawaban3->setString(nilai_jawaban3);
		label_jawaban4->setString(nilai_jawaban4);
	}

	nilai_soal1 = __String::createWithFormat("%d", soal1)->getCString();
	nilai_soal2 = __String::createWithFormat("%d", soal2)->getCString();
	label_soal1->setString(nilai_soal1);
	label_soal2->setString(nilai_soal2);


	tanda1->setString(nilai_tanda1);
	tanda2->setString(nilai_tanda2);

	


	nilai_waktu = __String::createWithFormat("%d", waktu)->getCString();
	label_waktu->setString(nilai_waktu);

	hitung--;
	if (hitung%1000 == 0)
	{
		waktu--;
	}

	if (waktu == 0)
	{
		this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.5f), CallFunc::create([&]
		{

			Director::getInstance()->replaceScene(Score::scene());
		})));
	}

}


void Game3::jawaban_1(Ref* sender)
{
	HomeMenu::btn_sound();
	mulai = 0;

	if (pilihan == 1)
	{
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}
	
}
void Game3::jawaban_2(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 2)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}
	
}
void Game3::jawaban_3(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 3)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}
	
}
void Game3::jawaban_4(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 4)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		HomeMenu::btn_wrong();
		salah += 1;
	}
		
	
}