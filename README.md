**Практикум №1 по предмету "Формальные языки и трансляции"**
-----------------------------------
В задаче нужно реализовать на языке С++ или Python некоторый алгоритм обработки регулярных выражений. В каждой задаче аргументами являются строка в алфавите {a, b, c, 1, ·, +, ∗}, а также некоторые дополнительные параметры. Если задача предполагает ответ "да/нет то необходи-
мо вывести yes в случае положительного ответа и no - в случае отрицательного. В случае, если ответ является целым числом или словом, необходимо
вывести это число или слово. В случае, если таких числа или слова не существует, необходимо вывести INF. В случае, если входная строка не является
корректным регулярным выражением в обратной польской записи, необходимо выдать сообщение error об ошибке. Дополнительные случаи оговорены
непосредственно при формулировке задачи. В дальнейшем предполагается,
что первым компонентом входа является регулярное выражение α в обратной польской записи, задающее язык L.
***
Вариант 19: Даны a, буква x. Найти максимальное k, такое что в L есть слова, заканчивающиеся на x^k.
***
В solve.py реализовано решение задачи. В automata.cpp реализовано построение автомата.
