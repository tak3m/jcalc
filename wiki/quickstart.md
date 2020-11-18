# jcalc - quickstart guide

## English

### First Steps

*"After downloading the (.zip) file containing the program for the correct operating system, what now?"*
1. Unzip it using a tool such as WinRAR, 7zip, or even the one included in your Operating System.
2. There, you will find 3 files. **The program itself** (.exe file for Windows, but for \*NIX systems such as Linux or MacOS it has no extension at all), a **LICENSE.TXT** (that says what you can do or not do with the program) and finally, **VERSION.TXT** (a file that you can read to know more about the version of the program that has just been installed.
3. To run the program, (on Windows) you only have to click on the executable file (.exe) "JCALC.EXE", or just simply run on the command prompt. Easy. On a *NIX system, however, you may have to open the program on the console, and run it by typing "./jcalc".

*"And... now what? I already know this stuff, alright?!"*

A message pops in. It says "JCALC>", and it's waiting for you to type in...

1. Type in a command. Let's see... if you wanted to know what's 1 + 1, you would type in "add 1 1", and then pressing ENTER.

*Wait, what? All that trouble for a simple 1 + 1 operation... That's insane!*

You would be absolutely right. This is something that I would call "fast calculation". You would be taking less time typing these commands than by using the built in calculator. Sometimes it's *quite* stressing. Sometimes it's *very*, *very*, *very* stressing. Hey- not everyone has a numpad, and even those who have one, still don't find it practical enough. So, hold on your horses, and start typing. Every time that you need to calculate something, don't even try to google it. Just use this program. **Quick, simple, efficient.**

### Basic commands

- add [x] [y] -> It's similar to 1 + 1, but you can keep adding ones and still count (add 1 1 1 1 1)
- sub [x] [y] -> It's similar to 1 - 1, but the first number is always positive and the next numbers will always be negative. (sub 1 1 1 1 = 1-1-1-1 = -2)
- mul [x] [y] -> It's similar to 1 * 1, and you can always keep adding numbers (mul 1 1 1 1 1 = 1 * 1 * 1 * 1 * 1 = 1)
- div [x] [y] -> It's similar to 1 / 1, and as always, you can keep adding more numbers...

*ADD for Add*\
*SUB for Subtract*\
*MUL for Multiply*\
*DIV for Divide*\

- pow [x] [y] -> It's similar to 3 ^ 2, but sadly it has fixed parameters. This means that it accepts only two parameters. Otherwise, the program will tell you that something's off.
- rt [x] [y] -> The root of a number. It's equal to x ^ (1 / y). If you wanted to know what's the square root of 9, you would type in "rt 9 2".

*POW for power*\
*RT for root\*

- sin [x] [y] -> The sine of an angle. By default, it accepts only degrees (e.g. "sin 30"). If you wanted radians or gradians, you would have to type "sin rad 3.14159" or "sin gra 10".
- cos [x] [y] -> Same as the other one, but with cossine.
- tan [x] [y] -> Of course it's the same.
- asin [x] [y] -> Yup. The same. But, with arc sine.
- acos [x] [y] -> I don't think I need to repeat myself, alright?
- atan [x] [y] -> That's right, go on...

### Variables
There are 16 variables that the user can use - var0 to var15. You can use them as you would use any other number in a function. For example: "add var0 1". If var0 equals 1, then the answer would be 2.

*How do you set a value on a variable?*

Easy, "var0 10" or "var1 33.9", or even "var2 3e+4"!

*How do you list every variable?*

Also easy! Just type in "mem list".

*Wait! Too many variables! I want to get rid of them!"

Don't panic. Type in "mem clear".

**You're all set. Many more will come. For every version, check the other informative markdown files for every version that gets released. It will get even better from here.**\
**Calculate efficiently.**\
