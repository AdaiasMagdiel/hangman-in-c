# Hangman in C

Hangman in C is a simple console-based game implemented as a study project for the C programming language. The game allows players to guess letters to unveil a hidden word.

## Instalation

To download the repository, you can use Git with the following command:

```bash
git clone https://github.com/AdaiasMagdiel/hangman-in-c.git
```

## How to Compile

To compile the program, use the following command:

```bash
gcc -o hangman word.c main.c
```

## How to Run

After compilation, you can run the program using:

```bash
./hangman
```

On Windows:

```bash
hangman.exe
```

## Adding More Words

You can add more words in `words.txt`. The program read this file and choose a random word to play.

## License

This project is open source and released under the MIT License. See the [LICENSE](LICENSE) file for details.

## How to Play

- The game will prompt you to guess a letter.
- If the letter is part of the hidden word, it will be revealed.
- If the letter is not in the word, you will lose an attempt.
- The game continues until you correctly guess the word or run out of attempts.

Enjoy playing Hangman in C!
