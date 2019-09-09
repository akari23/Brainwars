#include "SceneMenu.h"
#include "HelloWorldScene.h"
#include "HomeMenu.h"



Scene* SceneMenu::scene()
{
	return SceneMenu:: create();
}

bool SceneMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
		
	 bg = Sprite::create("bg.jpg");
	bg->setPosition(Vec2(384, 683));
	this->addChild(bg);



	/////////Menu awal/////////////////////
	icon = Sprite::create("icon_logo.png");
	icon->setScale(0.15f);
	icon->setPosition(384,900);
	icon->setOpacity(0);
	icon->runAction(FadeIn::create(1.f));
	this->addChild(icon);
	
	////////////////////////////////////
	
	label_brain = Label::createWithTTF("BRAIN", "fonts/arial.ttf", 50);
	label_brain->enableBold();
	label_brain->enableShadow();
	label_brain->setColor(Color3B::RED);
	label_brain->setPosition(Vec2(300, 760));
	label_brain->setOpacity(0);
	label_brain->runAction(FadeIn::create(5.f));
	this->addChild(label_brain,0);

	label_wars = Label::createWithTTF("WARS", "fonts/arial.ttf", 50);
	label_wars->setColor(Color3B::WHITE);
	label_wars->setPosition(Vec2(450, 760));
	label_wars->setOpacity(0);
	label_wars->runAction(FadeIn::create(10.f));
	this->addChild(label_wars, 0);
	
	
	schedule(schedule_selector(SceneMenu::penjadwalanWaktu), 1.0f);



	return true;
}

void SceneMenu::penjadwalanWaktu(float dt)
{
	
	waktu--;
	if (waktu == 0)
	{
		this->removeChild(label_brain);
		this->removeChild(label_wars);


		//BUTTON
		button_start = Button::create("start.png", "start.png", "start.png");
		button_start->setPosition(Vec2(400, 760));
		button_start->setOpacity(0);
		this->addChild(button_start);
		this->schedule([=](float delta)
		{
			float percent = button_start->getOpacity(	);
			percent += 50;
			button_start->setOpacity(percent);

		}, 0.1f, "UpdateLoading");
		button_start->addClickEventListener(CC_CALLBACK_1(SceneMenu::ButtonStartCallBack, this));
		//////
		
	}
}

void SceneMenu::ButtonStartCallBack(Ref* sender) //ketika button ditekan
{
	HomeMenu::btn_sound();
	bg->runAction(FadeOut::create(3.f));
	button_start->setScale(0.f);
	auto loading_label = Label::createWithTTF("Loading...", "fonts/arial.ttf", 50);
	loading_label->setPosition(Vec2(400, 760));
	loading_label->setOpacity(0);
	this->addChild(loading_label,1);
	this->schedule([=](float delta)
	{
		float percent = loading_label->getOpacity();
		percent += 30;
		loading_label->setOpacity(percent);

	}, 0.1f, "LoadingkeMenu");


	this->runAction(Sequence::createWithTwoActions(DelayTime::create(5.f), CallFunc::create([&]
	{
		
		Director::getInstance()->replaceScene(TransitionFade::create(1, HomeMenu::scene(), Color3B(0, 255, 255)));

	})));
}
