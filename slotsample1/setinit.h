# include <Siv3D.hpp>
class setinit
{
	/// @brief スロットゲームの絵柄
	struct Symbol
	{
		/// @brief 絵柄
		Texture symbol;

		/// @brief 賞金
		int32 score;
	};

	// 背景色を設定する
	const int background;

	// フォント
	const Font font{ FontMethod::MSDF, 48,
		U"example/font/RocknRoll/RocknRollOne-Regular.ttf" };

	// ゲーム開始の効果音
	const Audio soundStart{ Wave{ GMInstrument::Agogo,
		PianoKey::A3, 0.3s, 0.2s } };
};

