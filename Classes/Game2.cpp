#include "Game2.h"

Scene* Game2::scene()
{
	return Game2::create();
}

float Game2::benar = 0;
float Game2::salah = 0;

bool Game2::init()
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
	btn_back->addClickEventListener(CC_CALLBACK_1(Game2::kembali, this));


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
	button_start->addClickEventListener(CC_CALLBACK_1(Game2::mulaiGame, this));


	///soal////
	Soal1->setPosition(Vec2(768 / 2 - 100, 700));
	Soal2_tambah->setPosition(Vec2(768 / 2 + 100, 700));
	Soal2_kurang->setPosition(Vec2(768/ 2 + 100, 700));
	label_waktu->setPosition(Vec2(384, 1000));

	Soal1->setScale(0.f);
	Soal2_tambah->setScale(0.f);
	Soal2_kurang->setScale(0.f);
	label_waktu->setScale(0.f);

	label_soal1->setPosition(Vec2(Soal1->getContentSize().width / 2, Soal1->getContentSize().width / 2));
	label_soal2->setPosition(Vec2(Soal1->getContentSize().width / 2, Soal1->getContentSize().width / 2));
	label_soal3->setPosition(Vec2(Soal1->getContentSize().width / 2, Soal1->getContentSize().width / 2));

	this->addChild(Soal1);
	this->addChild(Soal2_tambah);
	this->addChild(Soal2_kurang);
	this->addChild(label_waktu);
	Soal1->addChild(label_soal1);
	Soal2_tambah->addChild(label_soal2);
	Soal2_kurang->addChild(label_soal3);
	//////////

	//button game//
	button_lanjut->setPosition(Vec2(768 / 2, 1366 / 2 - 300));
	button_lanjut->setScale(0.f);
	auto label_lanjut = Label::createWithTTF("NEXT", "fonts/arial.ttf", 50);
	label_lanjut->setPosition(Vec2(button_lanjut->getContentSize().width / 2, button_lanjut->getContentSize().height / 2));
	this->addChild(button_lanjut);
	button_lanjut->addChild(label_lanjut);

		//button jawaban//
	

	jawab1->setPosition(Vec2(300, 700));
	jawab2->setPosition(Vec2(500, 700));
	jawab3->setPosition(Vec2(300, 500));
	jawab4->setPosition(Vec2(500, 500));
	jawab1->setScale(0.f);
	jawab2->setScale(0.f);
	jawab3->setScale(0.f);
	jawab4->setScale(0.f);
	this->addChild(jawab1);
	this->addChild(jawab2);
	this->addChild(jawab3);
	this->addChild(jawab4);

		//label jawaban//
	label_jawaban1->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban2->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban3->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	label_jawaban4->setPosition(Vec2(jawab1->getContentSize().width / 2, jawab1->getContentSize().height / 2));
	jawab1->addChild(label_jawaban1);
	jawab2->addChild(label_jawaban2);
	jawab3->addChild(label_jawaban3);
	jawab4->addChild(label_jawaban4);
		////////////////

	jawab1->addClickEventListener(CC_CALLBACK_1(Game2::jawaban_1, this));
	jawab2->addClickEventListener(CC_CALLBACK_1(Game2::jawaban_2, this));
	jawab3->addClickEventListener(CC_CALLBACK_1(Game2::jawaban_3, this));
	jawab4->addClickEventListener(CC_CALLBACK_1(Game2::jawaban_4, this));
	button_lanjut->addClickEventListener(CC_CALLBACK_1(Game2::next_game, this));
		/////////////////
	/////////////


	return true;
}

void Game2::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}

void Game2::mulaiGame(Ref* sender)
{
	HomeMenu::btn_sound();
	schedule(schedule_selector(Game2::penjadwalanWaktu), 0.0010f);
}
void Game2::penjadwalanWaktu(float dt)
{
	
	ui_play->setScale(0.f);
	button_start->setScale(0.f);
	label_waktu->setScale(1.f);


	
	if (mulai == 0) // masuk ke soal
	{
		jawab1->setScale(0.f);
		jawab2->setScale(0.f);
		jawab3->setScale(0.f);
		jawab4->setScale(0.f);

		button_lanjut->setScale(1.f);
		Soal1->setScale(1.f);
		int soal1 = random(1, 10);
		int soal2 = random(1, 10);
		int operation = random(1, 2);
		if (operation == 1)
		{
			Soal2_tambah->setScale(1.f);
			Soal2_kurang->setScale(0.f);
			nilai = soal1 + soal2;
		}
		else
		{	
			Soal2_tambah->setScale(0.f);
			Soal2_kurang->setScale(1.f);
			nilai = soal1 - soal2;
		}
		nilai_soal1 = __String::createWithFormat("%d", soal1)->getCString();
		nilai_soal2 = __String::createWithFormat("%d", soal2)->getCString();
		label_soal1->setString(nilai_soal1);
		label_soal2->setString(nilai_soal2);
		label_soal3->setString(nilai_soal2);

		pilihan = random(1, 4); // letak posisi jawaban
		int nilaiRandom1 = random(-10, 20); // jawaban random 1
		int nilaiRandom2 = random(-10, 20); // jawaban random 2
		int nilaiRandom3 = random(-10, 20); // jawaban random 3
		log("nilai nilai = %d", nilai);
		log("nilai 1 = %d", nilaiRandom1);
		log("nilai 2 = %d", nilaiRandom2);
		log("nilai 3 = %d", nilaiRandom3);
		log("benar = %.2f", benar);
		log("salah = %.2f", salah);
		while ((nilaiRandom1 == nilai) || (nilaiRandom2 == nilai) || (nilaiRandom3 == nilai)) // acak jika nilai random ada yg sama dengan jawaban
		{
			nilaiRandom1 = random(-10, 20); // jawaban random 1
			nilaiRandom2 = random(-10, 20); // jawaban random 2
			nilaiRandom3 = random(-10, 20); // jawaban random 3
		}
		
		if (pilihan == 1)
		{
			nilai_jawaban1 = __String::createWithFormat("%d", nilai)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 2)
		{
			nilai_jawaban2 = __String::createWithFormat("%d", nilai)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 3)
		{
			nilai_jawaban3 = __String::createWithFormat("%d", nilai)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban4 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}
		else if (pilihan == 4)
		{
			nilai_jawaban4 = __String::createWithFormat("%d", nilai)->getCString();
			nilai_jawaban2 = __String::createWithFormat("%d", nilaiRandom1)->getCString();
			nilai_jawaban3 = __String::createWithFormat("%d", nilaiRandom2)->getCString();
			nilai_jawaban1 = __String::createWithFormat("%d", nilaiRandom3)->getCString();
		}

		
		label_jawaban1->setString(nilai_jawaban1);
		label_jawaban2->setString(nilai_jawaban2);
		label_jawaban3->setString(nilai_jawaban3);
		label_jawaban4->setString(nilai_jawaban4);

		mulai = 1;
	}

	

	nilai_waktu = __String::createWithFormat("%d", waktu)->getCString();
	label_waktu->setString(nilai_waktu);

	
	
	log("%d", hitung);
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
void Game2::next_game(Ref* sender)
{
	HomeMenu::btn_sound();
	mulai = 1; // masuk ke jawaban dan keluar dari soal
	Soal1->setScale(0.f);
	Soal2_tambah->setScale(0.f);
	Soal2_kurang->setScale(0.f);
	button_lanjut->setScale(0.f);
	jawab1->setScale(1.f);
	jawab2->setScale(1.f);
	jawab3->setScale(1.f);
	jawab4->setScale(1.f);
}

void Game2::jawaban_1(Ref* sender)
{

	mulai = 0;

	if (pilihan == 1)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		salah += 1;
		HomeMenu::btn_wrong();
		
	}
	schedule(schedule_selector(Game2::penjadwalanWaktu), 0.0010f);
}
void Game2::jawaban_2(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 2)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		salah += 1;
		HomeMenu::btn_wrong();
	}
	schedule(schedule_selector(Game2::penjadwalanWaktu), 0.0010f);
}
void Game2::jawaban_3(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 3)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		salah += 1;
		HomeMenu::btn_wrong();
	}
	schedule(schedule_selector(Game2::penjadwalanWaktu), 0.0010f);
}
void Game2::jawaban_4(Ref* sender)
{
	
	mulai = 0;
	if (pilihan == 4)
	{
		HomeMenu::btn_sound();
		benar += 1;
	}
	else
	{
		salah += 1;
		HomeMenu::btn_wrong();
	}
	schedule(schedule_selector(Game2::penjadwalanWaktu), 0.0010f);
}