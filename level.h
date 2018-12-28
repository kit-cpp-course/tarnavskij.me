#pragma once

#include "renderSystem.h"

/////Константы: свойства объектов, уровни.

const int levelRows = screenRows;
const int levelColumns = screenColumns;



const unsigned char cellSymbol_Ship = 'S';
const unsigned char cellSymbol_Bullet = '|';
const unsigned char cellSymbol_Alien = 'X';
const unsigned char cellSymbol_FatAlien = 'F';
const unsigned char cellSymbol_DebuffAlien = 'D';
const unsigned char cellSymbol_TripleShoot = '!';



const unsigned char levelDataEasy[levelRows][levelColumns + 1] =
{
	"                                                                                ",
	"       XXXXXXXXXXXXXXXXXXXXXXX                     XXXXXXXXXXXXXXXXXXXXXX       ",
	"         X  XXXX XX XXXXXXX  XXXXXXXXXXXXXXXXXXXXXX  XXXXXXX XX XXXX  X         ",
	"       XXXXXXXXX    X  X  X  X  XXX  XXXXXX  XXX  X  X  X  X    XXXXXXXXX       ",
	"            XXXX    X  X  X  XXXXXXX  XXXX  XXXXXXX  X  X  X    XXXX            ",
	"            XXXX             X   XXXXXXXXXXXXXX   X             XXXX            ",
	"            X  X        XXXXXX    XXXXXXXXXXXX     XXXXXXXXX    X  X            ",
	"                                  XX  XXXX  XX                                  ",
	"                                  XX  X  X  XX                                  ",
	"                                  X          X                                  ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                       S                                        ",
};

const unsigned char levelDataNormal[levelRows][levelColumns + 1] =
{
	"                                                                                ",
	"       FXXXXFFFFXXXX          XXXXXXXXXXFXXXXXX            XXXXXFFFFXXXXF       ",
	"         X  XXXX XX XXXXXXX  XXXXXXXXXXXXXXXXXXXXXX  XXXXXXX XX XXXX  X         ",
	"       FXXXXXXXX    X  F  X  X  XXX  XXXXXX  XXX  X  X  F  X    XXXXXXXXF       ",
	"      XFXFXFXF         XF XF XF XF XF XF XF XF XF FX XF XF XF XF XF  XFXFXFXF   ",
	"            XFFX             X   XXXFXXXXXXXFXX   X             XFFX            ",
	"            F  X                 XXXXX     XX                   X  F            ",
	"                                   XF  XFX  FX                                  ",
	"                                  XX  X  X  XX                                  ",
	"                                  X          X                                  ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                       S                                        ",
};

const unsigned char levelDataHard[levelRows][levelColumns + 1] =
{
	"                                                                                ",
	"       FXXXXFFFFXXXXXXXX        XXXXXXXDFDXXXXXXXXXX         XXXFFFFXXXXF       ",
	"         X  XXXX XX XXXDDDX  X   XDDDDDDDDDXX    XX  XXDDDXX XX XXXX  X         ",
	"       FXXXX   X    X  F  X  X  XXX  XXXXXX  XXX  X  X  F  X    X   XXXXF       ",
	"            XXXF    X  X  X  XXXXFXX  XFFX  XXFXXXX  X  X  X    FXXX            ",
	"            XFFX             X   XXXFX     XFXX   X             XFFX            ",
	"            F  D                 XXXXXXDDDXXX                   D  F            ",
	"                                   XF  XFX  FX                                  ",
	"                                  XX  D   D XX                                  ",
	"                                  X          X                                  ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                                                                ",
	"                                       S                                        ",
};



