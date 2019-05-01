regular = input()
regular = list(regular)
x = input()
#print(regular)
stackSuf = []  # стек разбора выражения в котором для каждой части хранится длина максимального суффикса из x
INF = 1000000000000000000
stackLenOfWhole = []  # стек разбора выражения в котором для каждой части хранится длина максимальной строки
# состоящей только из x
for symb in regular:
    if symb == '.':
        SufFirst = stackSuf.pop()
        SufSecond = stackSuf.pop()
        LenOfWholeFirst = stackLenOfWhole.pop()
        LenOfWholeSecond = stackLenOfWhole.pop()
        stackSuf.append(max(SufFirst, LenOfWholeFirst + SufSecond))  # рассматриваем два случая, оставить суффикс тот же
        # или сделать вторую строку только из x, а в первой
        # взять максимальный суффикс
        stackLenOfWhole.append(LenOfWholeFirst + LenOfWholeSecond)
    elif symb == '*':
        SufFirst = stackSuf.pop()
        LenOfWholeFirst = stackLenOfWhole.pop()
        if LenOfWholeFirst > 0:  # если длина максимальной строки из х ненулевая, то оба параметра становятся бесконечностью
            stackSuf.append(INF)
            stackLenOfWhole.append(INF)
        else:  # иначе параметры не меняются
            stackSuf.append(SufFirst)
            stackLenOfWhole.append(-1)
    elif symb == '+':
        SufFirst = stackSuf.pop()
        SufSecond = stackSuf.pop()
        LenOfWholeFirst = stackLenOfWhole.pop()
        LenOfWholeSecond = stackLenOfWhole.pop()
        stackSuf.append(max(SufFirst, SufSecond))  # оба параметра меняются на максимальный в случае плюса
        stackLenOfWhole.append(max(LenOfWholeFirst, LenOfWholeSecond))
    else:  # иначе просто добавляем букву
        if symb == x:
            stackSuf.append(1)
            stackLenOfWhole.append(1)
        else:
            stackSuf.append(0)
            stackLenOfWhole.append(-1)
last = stackSuf.pop()
if last == INF:
    print("INF")
else:
    print(last)
