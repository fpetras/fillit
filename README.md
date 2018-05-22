# Fillit

A program that takes a list of tetris pieces and arranges them in order to create the smallest square possible.

The main goal is to find the smallest square in a minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

## Installation:

`git clone https://github.com/fpetras/fillit.git && cd fillit && make`

## Usage:

`usage: ./fillit <pieces.fillit>`

Display and solve all of our testfiles:\
``for file in `find testfiles -type f -maxdepth 1` ; echo "\n\033[1;37m$file:\033[0m\n" && cat $file && ./fillit $file``

### In action:

![GIF](http://g.recordit.co/6gMVuH5vJa.gif)

### [Subject](https://github.com/fpetras/42-subjects/blob/master/fillit.en.pdf "fillit.en.pdf")

## Credits

|<img src="https://avatars2.githubusercontent.com/u/11819703" width="75px;"/>|<img src="https://avatars0.githubusercontent.com/u/34797639" width="75px;"/>|
| --------- | --------- |
| [Elouan Martinet](https://github.com/exagone313) | [Fabian Petras](https://github.com/fpetras) |
