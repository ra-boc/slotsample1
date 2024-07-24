# include <Siv3D.hpp>
# include "Common.hpp"
# include "Title.hpp"
# include "Game.hpp"




void Main()
{
	// 背景色を設定する
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 50, U"example/font/RocknRoll/RocknRollOne-Regular.ttf");
	FontAsset(U"TitleFont").setBufferThickness(4);
	FontAsset::Register(U"Menu", FontMethod::MSDF, 40, Typeface::Medium);
	//FontAsset::Register(U"Ranking", 40, Typeface::Heavy);
	FontAsset::Register(U"GameScore", 30, Typeface::Light);
	AudioAsset::Register(U"Brick", GMInstrument::Woodblock, PianoKey::C5, 0.2s, 0.1s);

	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);
	//manager.add<Ranking>(State::Ranking);

	// ゲームシーンから開始したい場合はこのコメントを外す
	manager.init(State::Title);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
	

	
}


