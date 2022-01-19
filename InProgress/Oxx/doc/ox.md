# Oxx

![Ox](ox.svg)

(Image by [UrticaDesign](https://pixabay.com/users/urticadesign-12321824/),
licensed under the [Pixabay License](https://pixabay.com/service/license/).)

**Ox**: a domestic bovine mammal (Bos taurus); broadly : a bovine mammal
[(Merriam Webster)](https://www.merriam-webster.com/dictionary/ox)

**Bulls and Cows**: \[A\] code-breaking mind or paper and pencil game for two or
more players... [(Wikipedia)](https://en.wikipedia.org/wiki/Bulls_and_Cows)

**Oxx**: A workshop for SOLID, GRASP, hexagonal architecture, implementing a
variant of Bulls and Cows in C++.

## Task

Implement a variant of Bulls and Cows in C++, using a hexagonal architecture and
the SOLID and GRASP guidelins.

## Game Progression

- The computer chooses a word from a dictionary and tells the player how many
  letters it contains.

- The player guesses a word and gets the following information for each letter:

    - `+` if the letter occurs in the solution in the same position as in the guess
    - `-` if the letter occurs in the solution, but in a different position
    - `.` if the letter does not appear in the solution

```
Guess the word!
The word to guess has 4 characters.
Please enter your guess:

able

Matches:
able
-..+

Please enter your guess:

gate

Matches:

able
-..+
gate
++.+

Please enter your guess:

game

Matches:
able
-..+
gate
++.+
game
++++

You won!
```

## Possible Variants

- **Text-based** or graphical user interface
- **One player** or multiple players
- **Human** or AI players
- Different levels of detail in the output/reporting of matches

## Layers

Which layers might be useful?

- `ox::core` (Determining partial/complete matches between words)
- `ox::game` (Rules and progression of the game)
- `ox::player` (Players, human and AI-based, strategies for AI players)
- `ox::data` (External data, e.g., dictionary and list of high scores)
- `ox::ui` (User interface, textual or graphical)

![Hexagonal Architecture](hexagon-ox.png)

You are unlikely to complete the implementation of the whole game in the time we
have for this exercise. Design the interaction between the layers and the
structure of the classes you want to use before implementing a lot of
functionality.

Pay attention that you keep a strict separation between the layers! Don't
perform any input/output operations or file accesses in layers other than the UI
layer.

The following implementation hints are just for one possible solution. You don't
have to follow them exactly. (Actually, it's much better if you come up with
your own solution and only refer to the hints if you get stuck.) Please think
about your own design before reading the hints.

### Implementation hints for the core layer

One possible way to implement the core layer is to have the following
interfaces/classes and functions:

```c++
class CharacterMatch;
```

to represent the coutcome for an individual character. Candidates for member
functions are:

- `char proposed_char()` to get the character that the user tried at a certain
  position
- `bool is_perfect_match()`
- `bool is_partial_match()`
- `char describe()`: returns`+` for perfect match, `-` for partial match, `.` otherwise

Maybe implement the different kinds of matches as subclasses of a common base.

```c++
std::unique_ptr<CharacterMatch>
get_character_match(char guess, std::size_t index, const std::string& solution);
```

`guess` is the proposed character at position `index` in the user's input,
`solution` is the word that the user is trying to guess. You cannot simply
compare two characters, since you need to know whether `guess` apears anywhere
in `solution` to decide whether it is a partial match.

```c++
class Match {
  // ...
private:
  // ...
  std::vector<std::unique_ptr<CharacterMatch>> character_matches{}
}
```

contains `CharacterMatch` objects for each character of a word and otherwise
functionality similar to `CharacterMatch`.

You may also want to have a logging interface (but not implementation) in this
layer.

### Implementation hints for the game layer

The following classes may be useful:

```c++
class Game;
}
```

Manages the state of the game, is responsible for determining when the game was
won or lost, etc.

```c++
enum class GameState {
  not_started, // perhaps
  in_progress, // perhaps
  won,
  lost,
}
```

An *abstract* class `Player` that provides the interface the Game uses to
interact with concrete player implementations. It should be possible for both
human players and automated players to be implemented using this class.

A class `Dictionary` to contain the set of possible words that provide a way to
get a random word.

Implement a game loop that repeatedly queries the player for a guess, processed
the guess, and provides feedback to the player. Do this only in terms of
abstract notifications, don't perform any input/output.

### Implementation hints for the player layer

Implement two different kinds of player:

- `RandomPlayer` generates nonsense words of a given length
- `DictionaryPlayer` draws random words from a dictionary

More advanced players that pick words on complete partial matches are of course
possible.

### Implementation of the data layer

This layer should contain functionality to read the game dictionary from a file
(or a database, if you are so inclined).

You may also want to implement storage for high score lists or other more
advanced features here (if your game layer supports these features).

### Implementation of the UI layer

- Implement a class `CliPlayer` that reads input from the terminal and passes it
  to the game.
- Implement some way for the notifications of the `Game` class to be displayed
  on the terminal.
- If you are familiar with a GUI framework, implement a way to play the game
  using a graphical user interface.
- If you have a logging interface, provide an implementation in this layer.
