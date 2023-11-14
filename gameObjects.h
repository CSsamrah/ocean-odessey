#include <ctime>
#include <graphics.h>

const int SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
const int SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);
int score = 0;

class Fish {
private:
    int x, y; // Position of the fish

public:
    Fish() {
        x = 100;
        y = 100;
    }

    Fish(int initialX, int initialY) {
        x = initialX;
        y = initialY;
    }

    void draw() {
        // Fish drawing code here
        setcolor(RED);
        // fish (main character)
        arc(x, y, 30, 155, 50);  // body
        arc(x, y - 50, 215, 328, 50);

        arc(x, y - 20, 100, 205, 30);  // inner shades
        arc(x + 10, y - 20, 100, 213, 30);
        arc(x + 25, y - 20, 110, 218, 30);
        arc(x + 35, y - 20, 115, 220, 30);

        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x - 25, y - 30, RED);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x - 10, y - 10, RED);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x, y - 10, RED);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + 28, y - 25, RED);

        arc(x - 5, y - 45, 0, 100, 25);  // upper fin
        line(x - 10, y - 70, x, y - 50);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x, y - 55, RED);

        arc(x - 5, y - 5, 265, 360, 25);  // lower fin
        line(x - 10, y + 20, x, y);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x, y + 5, RED);

        line(x - 40, y - 20, x - 70, y - 40);  // tail
        line(x - 40, y - 20, x - 70, y);
        line(x - 70, y - 40, x - 70, y);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x - 60, y - 30, RED);

        setfillstyle(SOLID_FILL, RED);
        floodfill(x - 35, y - 30, RED);

        setcolor(BLACK);

        circle(x + 30, y - 30, 6);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(x + 30, y - 30, BLACK);

        setcolor(WHITE);
        arc(x + 45, y - 30, 200, 230, 25);  // mouth
        
        
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

class Obstacle {
protected:
    int x, y; // Position of the obstacle

public:
    Obstacle() {
        x = rand()% SCREEN_WIDTH;
        y = rand() % SCREEN_HEIGHT;
    }

    virtual void draw() = 0;
    virtual void move() = 0;

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

class Jellyfish : public Obstacle {
public:
    void draw() {
        // Jellyfish drawing code here
        setcolor(WHITE);
   
    arc(x,y,0,180,70);       // big arc
   

    line(x-70,y,x+70,y);     // bottom line
    arc(x,y+50,35,145,87);     // second small arc
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    floodfill(x-40,y-10,WHITE);

    // jellyfish lines 
    line(x-50,y-10,x-50,y+140);
    line(x-30,y-10,x-30,y+100);
    line(x-10,y-10,x-10,y+140);
    line(x+10,y-10,x+10,y+100);
    line(x+30,y-10,x+30,y+140);
    line(x+50,y-10,x+50,y+100);
    
    setfillstyle(SOLID_FILL,MAGENTA);    
    floodfill(x-40,y-40,WHITE);

    circle(x-20,y-45,7); //eyes
    circle(x+20,y-45,7);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x-20,y-45,WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x+20,y-45,WHITE);
    }
    

    void move() {
        x -= 6;
        if (x < 0) {
            x = SCREEN_WIDTH;
            y = rand() % (SCREEN_HEIGHT - 200);
        }
    }
};

class Starfish : public Obstacle {
public:
    void draw() {
        // Starfish drawing code here
        setcolor(LIGHTRED);
    
    line(x-35,y,x-50,y+40);
    line(x-35,y,x-20,y+40);
    line(x-20,y+40,x+20,y+40);
    line(x-50,y+40,x-90,y+40);
    line(x-90,y+40,x-58,y+60);
    line(x+20,y+40,x-10,y+60);
    line(x-58,y+60,x-75,y+89);
    line(x-10,y+60,x+8,y+89);
    line(x+8,y+89,x-30,y+70);
    line(x-75,y+89,x-29,y+70);
    setfillstyle(SOLID_FILL,LIGHTRED);
    floodfill(x-35,y+65,LIGHTRED);
    setcolor(BLACK);
    circle(x-43,y+47,4);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x-43,y+47,BLACK);
    circle(x-23,y+47,4);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(x-23,y+47,BLACK);
    arc(x-33, y+56, 180, 360,10); 
    }

    void move() {
        x -= 6;
        if (x < 0) {
            x = SCREEN_WIDTH;
            y = rand() % (SCREEN_HEIGHT - 200);
        }
    }
};

class Shark : public Obstacle {
public:
    void draw() {
        // Shark drawing code here
        int points[] = {x, y, x + 100, y - 50, x + 350, y, x + 200, y + 50, x, y};
        setcolor(BLUE);
        drawpoly(5, points);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(x + 150, y, BLUE);

        // Tail
        setcolor(LIGHTBLUE);
        line(x + 350, y, x + 400, y - 25);
        line(x + 400, y - 25, x + 400, y + 25);
        line(x + 400, y + 25, x + 350, y);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(x + 360, y, LIGHTBLUE);

        // Eye
        setcolor(BLACK);
        circle(x + 80, y - 25, 5);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(x + 82, y - 25, BLACK);

        // Upper Fin
        setcolor(BLUE);
        arc(x + 200, y - 40, 90, 180, 60);
        arc(x + 250, y - 40, 126, 185, 80);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(x + 142, y - 50, BLUE);

        // Lower Fin
        setcolor(BLUE);
        line(x + 140, y - 15, x + 190, y);
        line(x + 190, y, x + 140, y + 15);
        line(x + 140, y + 15, x + 140, y - 15);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(x + 142, y, BLUE);

        // Face
        // setcolor(BLACK);
        // setlinestyle(SOLID_LINE, 0, 4);
        // line(x + 70, y + 40, x + 100, y + 35);

        // Gills
        setlinestyle(SOLID_LINE, 0, 1);
        line(x + 100, y - 5, x + 105, y + 7);
        line(x + 105, y - 4, x + 110, y + 6);
        line(x + 110, y - 3, x + 115, y + 5);
    }

    void move() {   	
        x -= 6;
        if (x < 0) {
            x = SCREEN_WIDTH;
            y = rand() % (SCREEN_HEIGHT - 300);
        }
    }
};


class Gamesetup{
	public:
void gameworking() {
    // Game setup code here
for (int y = 550; y <= 700; y += 20){
for (int x = 0; x < getmaxx(); x += 40){
// Grass
setcolor(GREEN);
line(x, y, x + 4, y - 60);
line(x + 4, y - 60, x + 8, y);
}
}
// Rock
setcolor(BLACK);
setfillstyle(SOLID_FILL, BROWN);
fillellipse(200, 700, 1200, 150);
// Right ston
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(700, 550, 30, 45);
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(730, 555, 32, 45);
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(760, 560, 30, 35);
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(790, 565, 40, 25);
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(785, 570, 22, 20); 
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(700, 575, 22, 30);
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(760, 580, 22, 20); 
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(762, 585, 35, 20); 
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(785, 590, 22, 20); 
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(707, 595, 20, 10); 
// Left stone
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(139, 545, 12, 20); 
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(159, 550, 20, 10); 
setfillstyle(SOLID_FILL, LIGHTGRAY);
fillellipse(175, 555, 12, 20);
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(151, 560, 12, 16); 
setfillstyle(SOLID_FILL, DARKGRAY);
fillellipse(160, 565, 20, 10);
}
};
class Prey {
private:
    int x, y; // Position of the prey

public:
bool isDestroyed;
// friend void checkCollision(const Fish&,const Prey&);
    Prey() {
        x = rand() % SCREEN_WIDTH;
        y = rand() % SCREEN_HEIGHT-100;
        isDestroyed = false; // Initialize the flag to false
    }
void draw(){
    if(!isDestroyed){
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        ellipse(x, y, 0, 360, 24, 10);
        floodfill(x, y, YELLOW);

        line(x + 25, y, x + 40, y + 6);
        line(x + 25, y, x + 40, y - 6);
        line(x + 40, y - 5, x + 40, y + 7);

        ellipse(x + 10, y, 190, 240, 17, 17);
        ellipse(x - 20, y + 3, 320, 350, 28, 17);

        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        line(x - 21, y - 1, x - 15, y - 1);
        floodfill(x - 20, y - 1, BLACK);

        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL, MAGENTA);
        circle(x - 10, y, 3);
        floodfill(x - 10, y, MAGENTA);

        setcolor(WHITE);
    }
    
}
    void move() {
      if(!isDestroyed){  
        x -= 4;
        if (x < 0) {
            x = SCREEN_WIDTH;
            y = rand() % SCREEN_HEIGHT;
        }
    
    }
    }
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }



  
};

void checkCollisionofprey(const Fish& fish, Prey& prey) {
    int fishX = fish.getX();
    int fishY = fish.getY();
    int preyX = prey.getX();
    int preyY = prey.getY();

    if (!prey.isDestroyed) {
        // Collision with prey
        if (fishX - 40 <= preyX + 35 && fishX + 40 >= preyX - 35 && fishY - 20 <= preyY + 40 && fishY + 20 >= preyY - 40) {
            score += 10;
            prey.isDestroyed = true;

            // Create a new prey object
            Prey newPrey;
            prey = newPrey;
        }
    }
}
void Gameover(){
 initwindow(SCREEN_WIDTH,SCREEN_HEIGHT);
            setbkcolor(CYAN);
            cleardevice();
            settextstyle(GOTHIC_FONT, HORIZ_DIR , 10);
            char gameOverText[] = "GAME OVER ";
            outtextxy(0,200, gameOverText);
            std::stringstream ss;
    	ss << "Score: " << score;
    	std::string scoreString = ss.str(); // Create a non-const string
    	char* scoreText = &scoreString[0]; // Convert to C-style string
        settextstyle(GOTHIC_FONT, HORIZ_DIR , 10);
    	outtextxy(0, 400, scoreText);
            setcolor(WHITE);
            getch();
}
void checkCollision(const Fish& fish, const Obstacle& obstacle) {
    int fishX = fish.getX();
    int fishY = fish.getY();
    int obstacleX = obstacle.getX();
    int obstacleY = obstacle.getY();

    // Check for collision based on obstacle type
    if (dynamic_cast<const Starfish*>(&obstacle)) {
        // Collision with starfish
        if (fishX - 40 <= obstacleX + 20 && fishX + 40 >= obstacleX - 90 && fishY - 20 <= obstacleY + 89 && fishY + 20 >= obstacleY) {
            // Game over logic here
            Gameover();
        }
           
        }
    else if (dynamic_cast<const Shark*>(&obstacle)) {
        // Collision with shark
        if (fishX - 40 <= obstacleX + 400 && fishX + 40 >= obstacleX && fishY - 20 <= obstacleY + 50 && fishY + 20 >= obstacleY - 50) {
            // Game over logic here
            
          Gameover();
        }
           
        }
    else if (dynamic_cast<const Jellyfish*>(&obstacle)) {
        // Collision with jellyfish
        if (fishX - 40 <= obstacleX + 70 && fishX + 40 >= obstacleX - 70 && fishY - 20 <= obstacleY + 89 && fishY + 20 >= obstacleY - 50) {
            // Game over logic here
           Gameover();
            
        }
        
        }

	
}