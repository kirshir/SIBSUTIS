//GNU coding standards
#include <SFML/Graphics.hpp>
#include <array>
#include <stdlib.h>

using Grid = std::array<std::array<int, 4>, 4>;
int score = 0;

Grid new_grid() {
	Grid grid;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			grid[x][y] = 0;
		}
	}
	return grid;
}

void draw(sf::RenderWindow& window, const Grid& grid) {
	window.clear(sf::Color(255, 252, 242));
	
	sf::RectangleShape background(sf::Vector2f(600, 600));
    background.setFillColor(sf::Color(136, 125, 110)); 
    background.setPosition(100, 100);
    window.draw(background);
	
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			int number = grid[x][y];
			sf::Sprite numberSprite;
			std::string filename = "number_" + std::to_string(number) + ".png";
			sf::Texture texture;
			if (!texture.loadFromFile("images/" + filename)) {
				exit(1);
			}
			
			texture.setSmooth(true);
			numberSprite.setTexture(texture);
			numberSprite.setScale(134.0f / texture.getSize().x, 134.0f / texture.getSize().y);
			numberSprite.setPosition(x * 150 + 108, y * 150 + 108);
			window.draw(numberSprite);
		}
	}
	
	sf::Font font;
	font.loadFromFile("Font.ttf");
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(25);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(100.f, 30.f);
	scoreText.setString("Score:\n" + std::to_string(score));
	window.draw(scoreText);
		
	window.display();
}

void new_number(Grid &grid) {
	srand(time(NULL));
	while (true) {
		int x = rand() % 4;
		int y = rand() % 4;
		if (grid[x][y] == 0) {
			grid[x][y] = 2;
			return;
		}
	}
}

bool is_full(const Grid& grid) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (grid[x][y] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool checkWin(const Grid& grid) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (grid[x][y] == 2048) {
                return true;
            }
        }
    }
    return false;
}


void move_column(std::array<int, 4>& col, bool &ifMoved){
	for (int current = 3; current >= 0; current--) {
		int next = current - 1;
		while (next >= 0 && col[next] == 0) {
			next--;
		}
		if (next < 0) {
			break;
		}
		if (col[current] == col[next]) {
			col[current] *= 2;
			col[next] = 0;
			ifMoved = true;
			score += col[current];
		}
		if (col[current] == 0) {
			col[current] = col[next];
			col[next] = 0;
			current++;
			ifMoved = true;
		}
	}
}

void flip_over(Grid& grid) {
	for (int x = 0; x < 4; x++) {
		std::swap(grid[x][0], grid[x][3]);
		std::swap(grid[x][1], grid[x][2]);
	}
}

void transpose(Grid& grid) {
	std::swap(grid[0][1], grid[1][0]);
	std::swap(grid[0][2], grid[2][0]);
	std::swap(grid[0][3], grid[3][0]);
	std::swap(grid[1][2], grid[2][1]);
	std::swap(grid[1][3], grid[3][1]);
	std::swap(grid[2][3], grid[3][2]);
}

void moving(Grid& grid, int key) {
	bool ifMoved = false;
	if (key == sf::Keyboard::Down) {
		for (int x = 0; x < 4; x++) {
			move_column(grid[x], ifMoved);
		}
		if (ifMoved) {
			new_number(grid);
		}
	}
	
	if (key == sf::Keyboard::Up) {
		flip_over(grid);
		for (int x = 0; x < 4; x++) {
			move_column(grid[x], ifMoved);
		}
		flip_over(grid);
		if (ifMoved) {
			new_number(grid);
		}
	}
	
	if (key == sf::Keyboard::Right) {
		transpose(grid);
		for (int x = 0; x < 4; x++) {
			move_column(grid[x], ifMoved);
		}
		transpose(grid);
		if (ifMoved) {
			new_number(grid);
		}
	}
	
	if (key == sf::Keyboard::Left) {
		transpose(grid);
		flip_over(grid);
		for (int x = 0; x < 4; x++) {
			move_column(grid[x], ifMoved);
		}
		flip_over(grid);
		transpose(grid);
		if (ifMoved) {
			new_number(grid);
		}
	}
}

void drawMenu(sf::RenderWindow& window) {
	window.clear(sf::Color(255, 252, 242));
	
	sf::Font font;
	font.loadFromFile("Font.ttf");
	sf::Text text("Welcome to 2048!\nUse the arrows to play\nPress Enter to start the game\nPress esc to exit.", font);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::Black);
    text.setPosition(150, 300);
    
    sf::Text label("Made By Shirokov Kirill", font);
    label.setCharacterSize(10);
    label.setFillColor(sf::Color::Black);
    label.setPosition(340, 780);

    window.draw(text);
    window.draw(label);
	window.display();
}

void drawGameOver(sf::RenderWindow& window, const Grid& grid) {
	window.clear(sf::Color(255, 252, 242)); 

    sf::RectangleShape background(sf::Vector2f(600, 600));
    background.setFillColor(sf::Color(136, 125, 110));
    background.setPosition(100, 100);
    window.draw(background); 

    draw(window, grid);
	
	sf::Font font;
    font.loadFromFile("Font.ttf");
    sf::Text text("Game Over!\nPress Enter to play again\nPress esc to exit.", font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(110, 310);

    window.draw(text);
    window.display();
	
}

void drawVictory(sf::RenderWindow& window, const Grid& grid) {
    window.clear(sf::Color(255, 252, 242)); 

    sf::RectangleShape background(sf::Vector2f(600, 600));
    background.setFillColor(sf::Color(136, 125, 110));
    background.setPosition(100, 100);
    window.draw(background); 

    draw(window, grid);
    
    sf::Font font;
    font.loadFromFile("Font.ttf");
    sf::Text text("Congratulations!\nYou reached 2048!\nPress Enter to play again\nPress esc to exit.", font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(110, 265);

    window.draw(text);
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "2048");
	
	Grid grid;
	bool gameStarted = false;
	bool gameOver = false;
	bool gameOverDisplayed = false;
	bool gameWin = false;
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
        		if (event.key.code == sf::Keyboard::Escape) {
            		window.close();
       			}
       		}
            
            if (event.type == sf::Event::KeyPressed && !gameStarted && !gameOver) {
				if (event.key.code == sf::Keyboard::Return) {
					score = 0;
					gameStarted = true;
					grid = new_grid();
					new_number(grid);
				}
			}
			if (gameStarted && !gameOver && event.type == sf::Event::KeyPressed) {
				sf::Keyboard::Key key = event.key.code;
            	moving(grid, key);
            	if (is_full(grid)) {
            		draw(window, grid);
                    gameOver = true;
                }
                if (checkWin(grid)) {
                	draw(window, grid);
                	drawVictory(window, grid);
                	gameWin = true;
                	gameStarted = false;
                	gameOver = true;
				}
			}	
			if (gameOver && event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Return) {
					score = 0;
					gameStarted = true;
					gameOver = false;
					gameOverDisplayed = false;
					gameWin = false;
					grid = new_grid();
                    new_number(grid);
				}
			}
        }
		
		if (!gameStarted && !gameOver) {
			drawMenu(window);
		}
		else {
		    if (!gameOver) {
		        draw(window, grid);
		    }
		    else {
		        if (!gameOverDisplayed && !gameWin) {
		            drawGameOver(window, grid);
		            gameOverDisplayed = true;
		        }
		    }
		}
    }

    return 0;
}
