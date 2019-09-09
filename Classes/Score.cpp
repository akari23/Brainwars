#include "Score.h"

Scene* Score::scene()
{
	return Score::create();
}

bool Score::init()
{
	if (!Scene::init())
	{
		return false;
	}
	bg_menu->setAnchorPoint(Vec2(0, 0));
	bg_menu->setScale(1.f);
	this->addChild(bg_menu);
	btn_back->setAnchorPoint(Vec2(0, 1));
	btn_back->setPosition(Vec2(0, 1366));
	this->addChild(btn_back);
	btn_back->addClickEventListener(CC_CALLBACK_1(Score::kembali, this));

	/////////////////////////////////////////////////////////////////
	auto txt_benar = Label::createWithTTF("BENAR", "fonts/arial.ttf", 50);
	auto txt_salah = Label::createWithTTF("SALAH", "fonts/arial.ttf", 50);
	txt_benar->setPosition(Vec2(100, 1100));
	txt_salah->setPosition(Vec2(600, 1100));

	//benar & salah//
	label_benar->setPosition(Vec2(100, 1000));
	label_salah->setPosition(Vec2(600, 1000));
	this->addChild(label_benar);
	this->addChild(label_salah);
	this->addChild(txt_benar);
	this->addChild(txt_salah);

	
	
	/////////////////////score tiap game//////////////////////////
	if (HomeMenu::pilih_game == 1) // score mini game 1
	{
		nilai_benar = __String::createWithFormat("%.0f", Game1::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game1::salah)->getCString();
		if (Game1::benar == 0 && Game1::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game1::benar * 100 / (Game1::benar + Game1::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
		
	}
	else if (HomeMenu::pilih_game == 2) //score mini game 2
	{
		nilai_benar = __String::createWithFormat("%.0f", Game2::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game2::salah)->getCString();
		if (Game2::benar == 0 && Game2::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game2::benar * 100 / (Game2::benar + Game2::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
	}
	else if (HomeMenu::pilih_game == 3) //score mini game 3
	{
		nilai_benar = __String::createWithFormat("%.0f", Game3::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game3::salah)->getCString();
		if (Game3::benar == 0 && Game3::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game3::benar * 100 / (Game3::benar + Game3::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
	}
	else if (HomeMenu::pilih_game == 4) //score mini game 4
	{
		nilai_benar = __String::createWithFormat("%.0f", Game4::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game4::salah)->getCString();
		if (Game4::benar == 0 && Game4::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game4::benar * 100 / (Game4::benar + Game4::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
	}
	else if (HomeMenu::pilih_game == 5) //score mini game 5
	{
		nilai_benar = __String::createWithFormat("%.0f", Game5::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game5::salah)->getCString();
		if (Game5::benar == 0 && Game5::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game5::benar * 100 / (Game5::benar + Game5::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
	}
	if (HomeMenu::pilih_game == 6) // score mini game 1
	{
		nilai_benar = __String::createWithFormat("%.0f", Game6::benar)->getCString();
		nilai_salah = __String::createWithFormat("%.0f", Game6::salah)->getCString();
		if (Game6::benar == 0 && Game6::salah == 0)
		{
			nilai = 0;
		}
		else
		nilai = (Game6::benar * 100 / (Game6::benar + Game6::salah));
		nilai_accuracy = __String::createWithFormat("%.2f", nilai)->getCString();
	}
	//////////////////////////score///////////////////////////////////////// 
	

	label_benar->setString(nilai_benar);
	label_salah->setString(nilai_salah);


	auto accuracy_label = Label::createWithTTF("ACCURACY = ","fonts/arial.ttf", 30); //tulisan accuracy
	accuracy_label->setPosition(Vec2(300, (1366 / 2) + 100));
	this->addChild(accuracy_label);
	auto label_persen = Label::createWithTTF("%", "fonts/arial.ttf", 30); //tulisan accuracy
	label_persen->setPosition(Vec2(600, (1366 / 2) + 100));
	this->addChild(label_persen);
	label_accuracy->setPosition(Vec2(500, (1366 / 2) + 100));
	this->addChild(label_accuracy);
	label_accuracy->setString(nilai_accuracy);

	auto score_bar_bawah = Sprite::create("score_bar2.jpg");
	score_bar_bawah->setPosition(Vec2(768 / 2, 1366 / 2));
	this->addChild(score_bar_bawah, 0);

	auto score_bar = LoadingBar::create("score_bar1.jpg");
	score_bar->setPosition(Vec2(768/2,1366/2));
	score_bar->setDirection(ui::LoadingBar::Direction::LEFT);
	score_bar->setPercent(0);

	this->addChild(score_bar,1);
	this->schedule([=](float delta)
	{

		float percent = score_bar->getPercent();
		percent += 5;
		score_bar->setPercent(percent);
		if (percent >= nilai)
		{
			this->unschedule("updateLoadingBar");
		}
	}, 0.1f, "updateLoadingBar");
	//////////////////////////score/////////////////////////////////////////
	return true;
}

void Score::kembali(Ref* sender)
{

	HomeMenu::callBtnPlay = true;
	this->runAction(Sequence::createWithTwoActions(DelayTime::create(0.0f), CallFunc::create([&]
	{

		Director::getInstance()->replaceScene(HomeMenu::scene());
	})));
}