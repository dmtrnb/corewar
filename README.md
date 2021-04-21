# Рекодинг легендарной игры Corewar

Этот проект выполнен в рамках Школы 21 (Ecole 42) в команде из трёх человек. Я отвечал за часть vm.

В игре есть арена, на которую в начале игры равноудалённо друг от друга выставляются игроки (от одного до четырёх). 
Арена закольцована. Игроки представляют из себя набор команд. Каждая команда занимает несколько ячеек арены 
(одна ячейка - один байт). Команд всего 16. Некоторые команды "пишут" на арену, некоторые "перекидывают" курсор, 
другие "клонируют" курсоры. Полное описание команд можно найти на просторах сети Internet.
Курсор - в начале игры на самую первую ячейку каждого игрока ставится курсор. Курсоры выполняют команды (или пытаются их выполнить)
по очереди, а затем перемещаются к следующей команде, или "телепортируются" исполняемой командой, или просто переходят 
на следующую ячейку, если команду невозможно выполнить.

Так как арена может быть модифицированна игроками, а курсоры могут двигаться, предугадать ход игры невозможно.
Цель игры - остаться последним живым игроком (да, для оповещения о своей живости есть отдельная команда).

Запуск игры возможен в контейнере:

$> docker-compose up

Запуск битвы между двумя игроками в визуальном режиме:

$> docker-compose exec corewar ./corewar -v players/cor/mise_a_jour_windows95.cor players/cor/zork.cor

Дамп арены после 1000 и одного шага битвы:

$> docker-compose exec corewar ./corewar -d 1001 players/cor/mise_a_jour_windows95.cor players/cor/zork.cor

Usage программы:

$> docker-compose exec corewar ./corewar


Если есть смелость и установлены make, gcc и библиотека ncurses, можно играть и без контейнеров:

$> make

$> ./corewar -v players/cor/mise_a_jour_windows95.cor players/cor/zork.cor
