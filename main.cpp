#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<unistd.h>

/* Creating a Rand function so you don't know when does the traffic ligth
** is going to swap of color :)
** Would be way too easy otherwise
*/

static int  ft_rand(int nb)
{
    pid_t   pid;

//randomising a littl bit more our rand by mixing it with the time and the pid. Unfortunately I didn't fine any good func.
    pid = getpid();
    srand(time(NULL) * pid);
    return ((rand() % (nb + 1)));
}

int         main(void)
{
   int gd = DETECT, gm, midx, midy, last;
   char result;
   int score;
   char *stock;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   midx = getmaxx()/2;
   midy = getmaxy()/2;

   setcolor(RED);
   settextstyle(SCRIPT_FONT, HORIZ_DIR, 3);
   settextjustify(CENTER_TEXT, CENTER_TEXT);

/*
** Defining the policy:
**
** DEFAULT_FONT	0	8x8 bit-mapped font
** TRIPLEX_FONT	1	Stroked triplex font
** SMALL_FONT	2	Stroked small font
** SANS_SERIF_FONT	3	Stroked sans-serif font
** GOTHIC_FONT	4	Stroked gothic font
** SCRIPT_FONT	5	Stroked script font
** SIMPLEX_FONT	6	Stroked triplex script font
** TRIPLEX_SCR_FONT   	7	Stroked triplex script font
** COMPLEX_FONT	8	Stroked complex font
** EUROPEAN_FONT	9	Stroked European font
** BOLD_FONT	10	Stroked bold font
**
*/

   outtextxy(midx, midy-30, "Hi and welcome to the Traffic Light Game...");
   outtextxy(midx, midy-10, "Unfortunately only 2 person can play at the same time");
   outtextxy(midx, midy+10, "You have to press as quick as possible at Green Light");
   outtextxy(midx, midy+30, "First player plays with 'Q' and the second one with 'Y'");
   delay(10000);
   cleardevice();
   delay(1000);
   outtextxy(midx, midy+100, "Click On 'r' when you are ready");
   while (getch() != 'r')
    ;
   cleardevice();
   setcolor(WHITE);

/* Creating a Beautiful traffic light
*/

   settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy-50, 22);
   setfillstyle(SOLID_FILL,RED);
   floodfill(midx, midy-50,WHITE);
   setcolor(RED);
   outtextxy(midx,midy-50,"STOP");
   delay(ft_rand(10000));
   last = ft_rand(10000);
   graphdefaults();
   cleardevice();
   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy, 20);
   setfillstyle(SOLID_FILL,YELLOW);
   floodfill(midx, midy,WHITE);
   setcolor(YELLOW);
   outtextxy(midx-18,midy-3,"READY");

// randomisiang a lottle more our timing of light


   if (last <= 1000)
    delay(ft_rand(30000));
   else if (last <= 3000)
    delay(ft_rand(10000));
   else if (last <= 5000)
    delay(ft_rand(3000));
   else
    delay(ft_rand(1000));

// printing our last traffic light

   cleardevice();
   setcolor(WHITE);
   rectangle(midx-30,midy-80,midx+30,midy+80);
   circle(midx, midy+50, 22);
   setfillstyle(SOLID_FILL,GREEN);
   floodfill(midx, midy+50,WHITE);
   setcolor(GREEN);
   outtextxy(midx-7,midy+48,"GO");
   setcolor(GREEN);
   settextstyle(COMPLEX_FONT, HORIZ_DIR, 4);
   outtextxy(midx-100, midy+100, "  GREEEN");

// Time to decide who will be the faster

    score = 0;

    result = 'a';

// Kbhit is a non blokant function which means that it won't block my score incrementation whereas
// getch is because it wait you to hit a touch. Kbhit is from the conio.h lib.

    while (result != 'q' && result != 'Q' && result != 'Y' && result != 'y' && ++score)
    {
        if (kbhit())
            result = getch();
        if (score > 414748169)
            break;
    }
   delay(200);

// You won't have the answe rnow ...

   cleardevice();
   setcolor(RED);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   outtextxy(midx, midy-30, "AND OUR WINNER IS ........");
   delay(1000);
   outtextxy(midx, midy+30, "The player who played with");
   delay(4000);
   if (result == 'q' || result == 'Q')
    outtextxy(midx, midy+90, "Q");
   else if (score < 414748169)
    outtextxy(midx, midy+90, "Y");
   else
    outtextxy(midx, midy+90, "No One, Too Slow");

// As an information, the lower the time is the best it is :D.

   outtextxy(midx, midy+120, "Reaction time");
   if (score < 414748169)
    outtextxy(midx, midy+150, itoa(score, stock, 10));
   else
    outtextxy(midx, midy+150, "Too Slow...");
   delay(5000);
   closegraph();
   return 0;
}
