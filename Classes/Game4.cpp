#include "Game4.h"

Scene* Game4::scene()
{
	return Game4::create();
}
float Game4::benar = 0;
float Game4::salah = 0;

bool Game4::init()
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
	btn_back->addClickEventListener(CC_CALLBACK_1(Game4::kembali, this));

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
	button_start->addClickEventListener(CC_CALLBACK_1(Game4::mulaiGame, this));

	//waktu//
	label_waktu->setPosition(Vec2(384, 1000));
	label_waktu->setScale(0.f);
	this->addChild(label_waktu);
	///////
	
	//soal game//
	Soal1->setPosition(Vec2(768 / 2, 800));
	Soal2->setPosition(Vec2(768 / 2, 800));
	Soal3->setPosition(Vec2(768 / 2, 800));

	Soal1->setScale(0.f);
	Soal2->setScale(0.f);
	Soal3->setScale(0.f);

	Soal1->runAction(RepeatForever::create(RotateBy::create(3.0f, 360.f)));
	Soal2->runAction(RepeatForever::create(RotateBy::create(3.0f, 360.f)));
	Soal3->runAction(RepeatForever::create(RotateBy::create(3.0f, 360.f)));

	this->addChild(Soal1);
	this->addChild(Soal2);
	this->addChild(Soal3);
	/////////////

	//jawaban game//
	jawab1->setPosition(Vec2(200, 500));
	jawab2->setPosition(Vec2(600, 500));
	jawab3->setPosition(Vec2(400, 200));

	jawab_1->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	jawab_2->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	jawab_3->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));

	jawab_1->runAction(RepeatForever::create(RotateBy::create(2.f, 360.f)));
	jawab_2->runAction(RepeatForever::create(RotateBy::create(2.f, 360.f)));
	jawab_3->runAction(RepeatForever::create(RotateBy::create(2.f, 360.f)));

	jawab1->setScale(0.f);
	jawab2->setScale(0.f);
	jawab3->setScale(0.f);

	this->addChild(jawab1);
	this->addChild(jawab2);
	this->addChild(jawab3);
	jawab1->addChild(jawab_1);
	jawab2->addChild(jawab_2);
	jawab3->addChild(jawab_3);

	jawab1->addClickEventListener(CC_CALLBACK_1(Game4::jawaban_1, this));
	jawab2->addClickEventListener(CC_CALLBACK_1(Game4::jawaban_2, this));
	jawab3->addClickEventListener(CC_CALLBACK_1(Game4::jawaban_3, this));

	///////////////

	return true;
}
void Game4::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}
void Game4::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game4::penjadwalanWaktu), 0.0010f);
}
void Game4::penjadwalanWaktu(float dt)
{
	ui_play->setScale(0.f);
	label_waktu->setScale(1.f);
	jawab1->setScale(0.5f);
	jawab2->setScale(0.5f);
	jawab3->setScale(0.5f);
	jawab_1->setScale(1.f);
	jawab_2->setScale(1.f);
	jawab_3->setScale(1.f);
	button_start->setScale(0.f);
	
	
	if (mulai == 0)
	{
		int soal = random(1, 3);
		if (soal == 1 )
		{
			Soal1->setScale(0.5f);
			Soal2->setScale(0.f);
			Soal3->setScale(0.f);
			pilihan = 1;
		}
		else if (soal == 2)
		{
			Soal1->setScale(0.f);
			Soal2->setScale(0.5f);
			Soal3->setScale(0.f);
			pilihan = 2;
		}
		else if (soal == 3)
		{
			Soal1->setScale(0.f);
			Soal2->setScale(0.f);
			Soal3->setScale(0.5f);
			pilihan = 3;
		}
		mulai = 1;
	}




	//waktu//
	nilai_waktu = __String::createWithFormat("%d", waktu)->getCString();
	label_waktu->setString(nilai_waktu);

	hitung--;
	if (hitung % 1000 == 0)
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

	
	
	/////////

}

void Game4::jawaban_1(Ref* sender)
{
	
	mulai = 0;

	if (pilihan == 1)
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
void Game4::jawaban_2(Ref* sender)
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
	};

}
void Game4::jawaban_3(Ref* sender)
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