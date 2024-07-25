# pragma once
# include "Common.hpp"
#include <Siv3D.hpp>

/// @brief スロットゲームの絵柄
struct Symbol
{
	/// @brief 絵柄
	Texture symbol;

	/// @brief 賞金
	int32 score;
};

// ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:

	const Font font{ FontMethod::MSDF, 48,
		U"example/font/RocknRoll/RocknRollOne-Regular.ttf" };

	// ゲーム開始の効果音
	const Audio soundStart{ Wave{ GMInstrument::Agogo,
		PianoKey::A3, 0.3s, 0.2s } };

	// リール停止の効果音
	const Audio soundStop{ Wave{ GMInstrument::SteelDrums,
		PianoKey::A3, 0.3s, 0.2s } };

	// 賞金獲得の効果音（ループ再生）
	const Audio soundGet{ Wave{ GMInstrument::TinkleBell,
		PianoKey::A6, 0.1s, 0.0s }, Loop::Yes };

	// 絵柄のリスト
	const Array<Symbol> symbols
	{
		{ Texture{ U"💎"_emoji }, 1000 },
		{Texture{U"7️⃣"_emoji}, 777},
		{ Texture{ U"💰"_emoji }, 300 },
		{ Texture{ U"🃏"_emoji }, 100 },
		{ Texture{ U"🍇"_emoji }, 30 },
		{ Texture{ U"🍒"_emoji }, 10 },
	};

	// 1 つのリールに用意される絵柄の基本リスト
	const Array<int32> symbolListBase =
	{ 0, 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5 };

	// 3 つのリールに用意される絵柄のリスト（基本リストをシャッフル）
	const std::array<Array<int32>, 3> symbolLists =
	{
		symbolListBase.shuffled(),
		symbolListBase.shuffled(),
		symbolListBase.shuffled()
	};

	// 3 つのリールの描画位置
	const std::array<Rect, 3> reels
	{
		Rect{ 80, 100, 150, 300 },
		Rect{ 230, 100, 150, 300 },
		Rect{ 380, 100, 150, 300 },
	};

	// 3 つのリールの描画位置
	const std::array<Rect, 3> reelbuttons
	{
		Rect{ 130, 100, 500, 30 },
		Rect{ 290, 100, 500, 30 },
		Rect{ 440, 100, 500, 30 },
	};

	// 所持金の描画位置
	const RoundRect moneyRect{ 560, 440, 190, 60, 20 };

	// 3 つのリールの回転量
	std::array<double, 3> rolls = { 0.0, 0.0, 0.0 };
	int32 stopCount = 3;
	int32 money = 1000;
};
