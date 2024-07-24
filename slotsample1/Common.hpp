# pragma once
# include <Siv3D.hpp>



// シーンの名前
enum class State
{
	Title,
	Game,
	//Ranking,
};

// 共有するデータ
struct GameData
{
	// 直前のゲームのスコア
	Optional<int32> lastGameScore;


};

using App = SceneManager<State, GameData>;
