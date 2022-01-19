#include <iostream>
#include <string>

#include "cli.hpp"
#include "single_player_game.hpp"

using namespace std::string_literals;

class FixedDictionary : public oxx::game::Dictionary
{
public:
    std::string get_random_word() override;
};

std::string FixedDictionary::get_random_word() { return "house"s; }

int main()
{
    auto player{std::make_shared<oxx::cli::CommandLinePlayer>()};
    auto dictionary{std::make_shared<FixedDictionary>()};

    auto game{std::make_unique<oxx::game::SinglePlayerGame>(
        player, dictionary, std::make_unique<oxx::cli::CommandLineNotifier>())};

    game->new_game();
    game->run_game_loop();
    std::cout << game->get_result()->get_summary();

}
