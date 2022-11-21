# LanguageAuthomatsAndCalculation
: Недетерминиран краен автомат

Да се реализира програма, която поддържа операции с недетерминиран краен автомат с ℇ-преходи. над азбука, състояща се от цифрите и малките латински букви. 

Автоматите да се сериализират по разработен от Вас формат. Всеки прочетен автомат да получава уникален идентификатор.

След като приложението отвори даден файл, то трябва да може да извършва посочените по-долу операции, в допълнение на общите операции (open, close, save, save as, help и exit):

list	Списък с идентификаторите на всички прочетени автомати
print <id>	Извежда информация за всички преходи в автомата
save <id> <filename>	Записва автомат във файл
empty <id>	Проверява дали езикът на автомата е празен
deterministic <id>	Проверява дали автомат е детерминиран
recognize <id> <word>	Проверява дали дадена дума е в езика на автомата
union <id1> <id2>	Намира обединението на два автомата и създава нов автомат. Отпечатва идентификатора на новия автомат
concat <id1> <id2>	Намира конкатенацията на два автомата и създава нов автомат. Отпечатва идентификатора на новия автомат
un <id>	Намира позитивна обвивка на автомат и създава нов автомат. Отпечатва идентификатора на новия автомат
reg <regex>	Създава нов автомат по даден регулярен израз (теорема на Клини). Отпечатва идентификатора на новия автомат


●	да се реализира мутатор, който детерминира даден автомат
●	да се реализира операция, която проверяват дали езикът на даден автомат е краен
 
