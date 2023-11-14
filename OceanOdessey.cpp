#include <ctime>
#include <graphics.h>
#include<gameObjects.h>


int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    initwindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    setbkcolor(CYAN);
    int page = 0;
    Fish fish;
    Jellyfish jellyfish;
    Starfish starfish;
    Shark shark;
    Prey prey;

    while (true) {
    Gamesetup Gs;
    Gs.gameworking();
    setactivepage(page);
    setvisualpage(1 - page);
    cleardevice(); // Clear the screen
        if (kbhit()) {
            char key = getch();
            if (key == 0 || key == 224) {
                key = getch();  // Read the extended key code

                switch (key) {
                    case 72:  // Up arrow
                        fish.move(0, -10);  // Move fish up
                        break;
                    case 80:  // Down arrow
                        fish.move(0, 10);  // Move fish down
                        break;
                    case 75:  // Left arrow
                        fish.move(-10, 0);  // Move fish left
                        break;
                    case 77:  // Right arrow
                        fish.move(10, 0);  // Move fish right
                }
            }
        }

        cleardevice();

        fish.draw();
        jellyfish.draw();
        starfish.draw();
        shark.draw();
        prey.draw();

        jellyfish.move();
        starfish.move();
        shark.move();
        prey.move();

        checkCollision(fish, jellyfish);
        checkCollision(fish, starfish);
        checkCollision(fish, shark);
        checkCollisionofprey(fish, prey);
    

        setcolor(BLACK);
    	std::stringstream ss;
    	ss << "Score: " << score;
    	std::string scoreString = ss.str(); // Create a non-const string
    	char* scoreText = &scoreString[0]; // Convert to C-style string
    	outtextxy(10, 10, scoreText);
        delay(10);
    	page = 1 - page;
    }

    closegraph();
    return 0;
}